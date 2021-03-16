#include <stdalign.h>
#include <string.h>
#include "security_regions_mgr.h"
#include "crc.h"
#include "storage_mgr.h"
#include "emulation.h"

// специальное "неслучайное" значение, означающее отсутствие значения
#define NOT_A_BYTE 0b10100101U

#define ACTUAL_STATE_PERIOD 400UL    // 4s

struct region_state_s
{
  REGION_STATE_E state;
  bool           actual;
  uint16_t       actual_cnt;
};

static const region_t blank_region_ = {{IPADDR_NONE}, NOT_A_BYTE, NOT_A_BYTE, {0, 0}};

static region_t regions_[TOTAL_BUTTONS] __attribute__((section(".ccmram")));

static volatile struct region_state_s region_state_[TOTAL_BUTTONS] __attribute__((section(".ccmram")));

_Static_assert(sizeof regions_ == sizeof(region_t) * TOTAL_BUTTONS, "Unexpected size of region maps");

_Static_assert((sizeof regions_ % alignof(uint32_t)) == 0, "Region map size does not suit for CRC32");

#define REGION_IS_BLANK_(r) (((r).ip_addr.addr == IPADDR_NONE) && ((r).btn_led_id == NOT_A_BYTE) && ((r).region_id == NOT_A_BYTE))

static void clear_region_(region_t * reg)
{
  set_region_state(reg, REGION_ABSENT);
  *reg = blank_region_;
}

void set_region_state(region_t const * region, REGION_STATE_E const state)
{
  uint8_t const        btn_idx        = region->btn_led_id;
  REGION_STATE_E const previous_state = region_state_[btn_idx].state;

  if (previous_state != state)
    {
      switch (state)
        {
          case REGION_ABSENT:
            {
              region_state_[btn_idx].state = state;
            }
          break;

          case REGION_DISARMED:
            {
              region_state_[btn_idx].state = state;
            }
          break;

          case REGION_ARMED:
            {
              region_state_[btn_idx].state = state;
            }
          break;

          case REGION_ALARMED:
            {
              region_state_[btn_idx].state = state;
            }
          break;

          case REGION_DISARMED_DISTURBED:
            {
              region_state_[btn_idx].state = state;
            }
          break;

          default:
            return;
        }

    }

  if (!region_state_[btn_idx].actual)
    {
      region_state_[btn_idx].actual = true;
      region_state_[btn_idx].actual_cnt = 0ul;
    }
  else
    {
      region_state_[btn_idx].actual_cnt = 0ul;
    }
}

void region_state_actual_period_tick(void)
{
  for (unsigned idx = 0; idx < TOTAL_BUTTONS; ++idx)
    {
      // рассчитано на таймер с периодом в 10 мс, в результате сбрасываем флаг через 4 с
      if (++region_state_[idx].actual_cnt % ACTUAL_STATE_PERIOD == 0ul && region_state_[idx].actual && region_state_[idx].state != REGION_ABSENT)
        {
          region_state_[idx].actual = false;
        }
    }
}

void region_state_actual_period_expired(void)
{
  for (unsigned idx = 0; idx < TOTAL_BUTTONS; ++idx)
    {
      if (!region_state_[idx].actual && region_state_[idx].state != REGION_ABSENT)
        {
          region_t * region = lookup_region_entry_by_button_id(idx);
          if (region)
            {
              /*
               * Для пользователя будет отображаться последнее актуальное состояние, при этом, попытки послать команды
               * разделу, связи с которым нет, будут игнорироваться до восстановления соединения
               */
              region_state_[idx].state = REGION_ABSENT;
            }
        }
    }
}

REGION_STATE_E get_region_state(uint8_t btn_id)
{
  if (btn_id < TOTAL_BUTTONS)
    {
      return region_state_[btn_id].state;
    }

  return REGION_ABSENT;
}

void region_check_alarm_n_play(void)
{
  for (unsigned idx = 0; idx < TOTAL_BUTTONS; ++idx)
    {
      if (get_region_state(idx) == REGION_ALARMED)
        {
          return;
        }
    }
}

bool add_region_entry(unsigned int idx, ip4_addr_t ip, uint8_t region_id, uint8_t linked_btn_id)
{
  if (idx < TOTAL_BUTTONS && region_id < TOTAL_REGIONS && linked_btn_id < TOTAL_BUTTONS)
    {
      regions_[idx].ip_addr    = ip;
      regions_[idx].region_id  = region_id;
      regions_[idx].btn_led_id = linked_btn_id;

      return false;
    }

  return true;
}

bool delete_region_entry(unsigned const idx)
{
  if (idx < TOTAL_BUTTONS)
    {
      if (!REGION_IS_BLANK_(regions_[idx]))
        {
          region_t * reg = &regions_[idx];
          clear_region_(reg);
          return false;
        }
    }

  return true;
}

region_t * get_region_entry(unsigned idx)
{
  if (!REGION_IS_BLANK_(regions_[idx]))
    {
      return &regions_[idx];
    }

  return NULL;
}

void clear_region_map(void)
{
  for (unsigned idx = 0; idx < TOTAL_BUTTONS; ++idx)
    {
      region_t * reg = &regions_[idx];
      if (!REGION_IS_BLANK_(*reg) && reg->ip_addr.addr != IPADDR_ANY)
        {
          clear_region_(reg);
        }
    }
}

void purge_region_map(void)
{
  for (unsigned idx = 0; idx < TOTAL_BUTTONS; ++idx)
    {
      regions_[idx] = blank_region_;
      region_state_[idx].state = REGION_ABSENT;
      region_state_[idx].actual = true;
      region_state_[idx].actual_cnt = 0u;
    }
}

int region_map_count(void)
{
  int ret = 0;

  for (unsigned i = 0; i < TOTAL_BUTTONS; ++i)
    {
      region_t const * const r = &regions_[i];
      if (r->ip_addr.addr != IPADDR_NONE
          && (r->region_id != NOT_A_BYTE && r->region_id < TOTAL_REGIONS)
          && (r->btn_led_id != NOT_A_BYTE && r->btn_led_id < TOTAL_BUTTONS))
        {
          ret += 1;
        }
    }

  return ret;
}

region_t * lookup_region_entry_by_button_id(uint8_t btn_id)
{
  for (unsigned i = 0; i < TOTAL_BUTTONS; ++i)
    {
      if (!REGION_IS_BLANK_(regions_[i]) && regions_[i].btn_led_id == btn_id)
        {
          return &regions_[i];
        }
    }

  return NULL;
}

region_t * lookup_matched_region(ip4_addr_t const * ip, uint8_t const region_id)
{
  for (unsigned i = 0; i < TOTAL_BUTTONS; ++i)
    {
      if (!REGION_IS_BLANK_(regions_[i]) && regions_[i].ip_addr.addr == ip->addr && regions_[i].region_id == region_id)
        {
          return &regions_[i];
        }
    }

  return NULL;
}

// размер буфера должен быть достаточен для сохранения всех регионов и контрольной суммы
#define IO_BUF_SIZE_ (sizeof regions_ + sizeof(uint32_t))

int persist_region_map(void)
{
  uint32_t const crc = crc32(regions_, sizeof regions_, 0xffffffffu);

  int error = fs_backup_previous_region_map();
  if (error && error != LFS_ERR_NOENT)
    {
      goto exit_point_;
    }

  error = fs_replace_region_map((uint8_t const *) regions_, sizeof regions_, crc);

exit_point_:
  return error;
}

int restore_region_map(void)
{
  uint8_t io_buf[IO_BUF_SIZE_] = {0};

  int result = fs_read_region_map(io_buf, IO_BUF_SIZE_);
  if (result < 0)
    {
      goto exit_point_;
    }

  uint32_t read_crc = 0;
  memcpy(&read_crc, io_buf + sizeof regions_, sizeof(uint32_t));
  uint32_t const calc_crc = crc32(io_buf, sizeof regions_, 0xffffffffu);
  if (read_crc != calc_crc)
    {
      result = CRC_ERROR;
      goto exit_point_;
    }

  memcpy(regions_, io_buf, sizeof regions_);
  result = 0;

exit_point_:
  return result;
}

