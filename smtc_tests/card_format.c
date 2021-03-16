#include <stdbool.h>
#include <string.h>
#include "storage_mgr.h"
#include "crc.h"
#include "card_format.h"

static wiegand_format_t const wf_none_ =
                                {
                                  .parity_bit_mask = WF_NOT_BIT_MASK,
                                  .groups = {
                                    {.mask=WF_NOT_BIT_MASK, .type=WPT_ABS, .pos=WF_NOT_BIT_POS},
                                    {.mask=WF_NOT_BIT_MASK, .type=WPT_ABS, .pos=WF_NOT_BIT_POS},
                                    {.mask=WF_NOT_BIT_MASK, .type=WPT_ABS, .pos=WF_NOT_BIT_POS}
                                  },
                                  .code_len = WF_NOT_CODE_LEN,
                                  .code_type = WCT_NONE
                                };

static wiegand_format_t wf_formats_[WF_FORMATS_NUM] __attribute__((section(".ccmram")));

static inline bool format_empty_(wiegand_format_t const * wf)
{
  return wf->parity_bit_mask == wf_none_.parity_bit_mask
         || wf->code_type == wf_none_.code_type
         || wf->code_len == wf_none_.code_len;
}

static void unpack_(wiegand_format_t * dest, uint8_t const * src)
{
  memcpy(&dest->parity_bit_mask, src, sizeof(uint64_t));
  src += sizeof(uint64_t);
  memcpy(&dest->groups[0].mask, src, sizeof(uint64_t));
  src += sizeof(uint64_t);
  memcpy(&dest->groups[1].mask, src, sizeof(uint64_t));
  src += sizeof(uint64_t);
  memcpy(&dest->groups[2].mask, src, sizeof(uint64_t));
  src += sizeof(uint64_t);
  dest->groups[0].pos  = *src++;
  dest->groups[1].pos  = *src++;
  dest->groups[2].pos  = *src++;
  dest->groups[0].type = *src++;
  dest->groups[1].type = *src++;
  dest->groups[2].type = *src++;
  dest->code_len       = *src++;
  dest->code_type      = *src;
}

static void pack_(uint8_t * dest, wiegand_format_t const * src)
{
  memcpy(dest, &src->parity_bit_mask, sizeof(uint64_t));
  dest += sizeof(uint64_t);
  memcpy(dest, &src->groups[0].mask, sizeof(uint64_t));
  dest += sizeof(uint64_t);
  memcpy(dest, &src->groups[1].mask, sizeof(uint64_t));
  dest += sizeof(uint64_t);
  memcpy(dest, &src->groups[2].mask, sizeof(uint64_t));
  dest += sizeof(uint64_t);
  *dest++ = src->groups[0].pos;
  *dest++ = src->groups[1].pos;
  *dest++ = src->groups[2].pos;
  *dest++ = src->groups[0].type;
  *dest++ = src->groups[1].type;
  *dest++ = src->groups[2].type;
  *dest++ = src->code_len;
  *dest   = src->code_type;
}

void wf_purge_table(void)
{
  for (int i = 0; i < WF_FORMATS_NUM; ++i)
    {
      wf_formats_[i] = wf_none_;
    }
}

wiegand_format_t const * wf_lookup_by_code_length(int const len, int * start)
{
  if (start && *start >= 0)
    {
      for (int i = *start; i < WF_FORMATS_NUM; ++i)
        {
          wiegand_format_t const * p = &wf_formats_[i];
          if (!format_empty_(p) && p->code_len == len)
            {
              *start = i;
              return p;
            }
        }
    }

  return NULL;
}

int wf_save_at_index(uint8_t * wf, int const idx)
{
  if (idx >= 0 && idx < WF_FORMATS_NUM)
    {
      wiegand_format_t * dest = &wf_formats_[idx];
      unpack_(dest, wf);
      return 0;
    }

  return -1;
}

int wf_lookup_and_copy_by_index(uint8_t * dest, int idx)
{
  if (idx >= 0 && idx < WF_FORMATS_NUM)
    {
      wiegand_format_t const * p = &wf_formats_[idx];
      if (!format_empty_(p))
        {
          pack_(dest, p);
          return 0;
        }
    }

  return -1;
}

int wf_clear_at_index(int const idx)
{
  if (idx >= 0 && idx < WF_FORMATS_NUM)
    {
      memcpy(&wf_formats_[idx], &wf_none_, sizeof(wiegand_format_t));
      return 0;
    }

  return -1;
}

int wf_count_formats(void)
{
  int count = 0;

  for (int i = 0; i < WF_FORMATS_NUM; ++i)
    {
      wiegand_format_t const * p = &wf_formats_[i];
      if (!format_empty_(p))
        {
          count += 1;
        }
    }

  return count;
}

int wf_persist_formats(void)
{
  uint32_t crc = 0xffffffffU;
  uint8_t  out_buf[WF_PACKED_SIZE * WF_FORMATS_NUM];
  uint8_t * dest = out_buf;

  for (int i = 0; i < WF_FORMATS_NUM; ++i)
    {
      pack_(dest, &wf_formats_[i]);
      crc = crc32(out_buf, sizeof out_buf, crc);
      dest += WF_PACKED_SIZE;
    }


  int error = fs_backup_previous_wiegand_formats();

  if (error && error != LFS_ERR_NOENT)
    {
      goto exit_point_;
    }

  error = fs_replace_wiegand_formats(out_buf, sizeof out_buf, crc);

exit_point_:
  return error;
}

#define IO_BUF_SIZE_ (WF_PACKED_SIZE * WF_FORMATS_NUM + sizeof(uint32_t))

int wf_restore_table(void)
{
  uint8_t io_buf[IO_BUF_SIZE_];

  int result = fs_read_wiegand_formats(io_buf, IO_BUF_SIZE_);
  if (result < 0)
    {
      goto exit_point_;
    }

  uint32_t read_crc = 0;
  memcpy(&read_crc, io_buf + WF_PACKED_SIZE * WF_FORMATS_NUM, sizeof(uint32_t));
  uint32_t const calc_crc = crc32(io_buf, WF_PACKED_SIZE * WF_FORMATS_NUM, 0xffffffffu);
  if (read_crc != calc_crc)
    {
      result = CRC_ERROR;
      goto exit_point_;
    }

  uint8_t * src = io_buf;
  for (int i = 0; i < WF_FORMATS_NUM; ++i)
    {
      unpack_(&wf_formats_[i], src);
      src += WF_PACKED_SIZE;
    }

  result = 0;

exit_point_:
  return result;
}
