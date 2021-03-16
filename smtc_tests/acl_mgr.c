#include <string.h>
#include "acl_mgr.h"
#include "crc.h"
#include "storage_mgr.h"
#include "card_format.h"

static acl_entry_t acls_[MAX_ACL_ENTRIES_NUM]__attribute__((section(".ccmram"))) = {0};

static inline bool acl_empty_(unsigned idx)
{
  return acls_[idx].card_id == 0 && acls_[idx].pin_code == 0;
}

int replace_acl_entry(uint8_t const * new_acl, int32_t const idx)
{
  if (idx >= 0 && idx < MAX_ACL_ENTRIES_NUM)
    {
      void * dest = &acls_[idx];
      memcpy(dest, new_acl, sizeof(acl_entry_t));
      return 0;
    }

  return -1;
}

int read_acl_entry(uint8_t * dest, int32_t const acl_to_read)
{

  if (acl_to_read >= 0 && acl_to_read < MAX_ACL_ENTRIES_NUM)
    {
      if (acl_empty_((unsigned ) acl_to_read))
        {
          return -1;
        }

      memcpy(dest, &acl_to_read, sizeof acl_to_read);
      dest += sizeof acl_to_read;
      memcpy(dest, &acls_[acl_to_read], sizeof(acl_entry_t));
      return 0;
    }

  return -1;
}

int delete_acl_entry(int32_t acl_to_delete)
{
  if (acl_to_delete >= 0 && acl_to_delete < MAX_ACL_ENTRIES_NUM)
    {
      void * to_delete = &acls_[acl_to_delete];
      memset(to_delete, 0, sizeof(acl_entry_t));
      return 0;
    }

  return -1;
}

void clear_acl_table(void)
{
  memset(acls_, 0, sizeof acls_);
}

void fill_in_acl_entry_map(uint8_t * dest)
{
  for (unsigned i = 0; i < MAX_ACL_ENTRIES_NUM; ++i)
    {
      if (acl_empty_(i))
        {
          continue;
        }

      unsigned const byte = i / CHAR_BIT;
      unsigned const bit  = i % CHAR_BIT;
      dest[byte] |= (1 << bit);
    }
}

uint32_t const * card_is_on_list(uint64_t const * raw, int const raw_len, uint64_t const * card)
{
  if (*card == 0)
    {
      return NULL;
    }

  for (int idx = 0; idx < MAX_ACL_ENTRIES_NUM; ++idx)
    {
      if (acls_[idx].card_id == 0)
        {
          continue;
        }

      if (acls_[idx].card_id == *card)
        {
          return acls_[idx].acl;
        }
    }

  return NULL;
}

uint32_t const * pin_is_on_list(uint64_t const * pin)
{
  if (*pin == 0)
    {
      return NULL;
    }

  for (int idx = 0; idx < MAX_ACL_ENTRIES_NUM; ++idx)
    {
      if (acls_[idx].pin_code == 0)
        {
          continue;
        }

      if (acls_[idx].pin_code == (int32_t) *pin)
        {
          return acls_[idx].acl;
        }
    }

  return NULL;
}

int persist_card_table(void)
{
  uint32_t const crc = crc32(acls_, sizeof acls_, 0xffffffffu);

  int error = fs_backup_previous_acl_table();
  if (error && error != LFS_ERR_NOENT)
    {
      goto exit_point_;
    }

  error = fs_replace_acl_table((uint8_t const *) acls_, sizeof(acl_entry_t), MAX_ACL_ENTRIES_NUM, crc);

exit_point_:
  return error;
}

// размер буфера должен быть достаточен для сохранения всех записей и контрольной суммы
#define IO_BUF_SIZE_ (sizeof acls_ + sizeof(uint32_t))

static uint8_t io_buf_[sizeof(acl_entry_t)] __attribute__((section(".ccmram"))) = {0};

static int try_restore_acl_table_(bool const from_main)
{
  int result = fs_open_acl_file(from_main);
  if (result < 0)
    {
      goto exit_point_;
    }

  uint32_t crc = 0xffffffffU;

  for (int rec = 0; rec < MAX_ACL_ENTRIES_NUM; ++rec)
    {
      result = fs_read_acl_bytes(io_buf_, sizeof(acl_entry_t));
      if (result < 0 || (result > 0 && result < (int) sizeof(acl_entry_t)))
        {
          goto clean_up_;
        }
      crc = crc32(io_buf_, sizeof io_buf_, crc);
      acl_entry_t * dest = &acls_[rec];
      memcpy(dest, io_buf_, sizeof(acl_entry_t));
    }

  uint32_t crc_read;
  result = fs_read_acl_bytes((uint8_t *) &crc_read, sizeof crc_read);
  if (result < 0 || (result > 0 && result < (int) sizeof(acl_entry_t)))
    {
      goto clean_up_;
    }

  if (crc_read != crc)
    {
      result = CRC_ERROR;
      goto clean_up_;
    }

  result = 0;

clean_up_:
  fs_close_acl_file();

exit_point_:
  return result;
}

int restore_acl_table(void)
{
  int result = try_restore_acl_table_(true);

  if (result < 0)
    {
      result = try_restore_acl_table_(false);
    }

  if (result < 0)
    {
      clear_acl_table();
    }

  return result;
}
