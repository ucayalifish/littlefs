#ifndef SECURITY_REGIONS_MGR_H_
#define SECURITY_REGIONS_MGR_H_

#include <stdint.h>
#include <stdbool.h>
#include "emulation.h"

#define TOTAL_REGIONS 64

typedef enum region_state_e
{
  REGION_ABSENT = 0x0fu,
  REGION_DISARMED = 1u,
  REGION_ARMED,
  REGION_ALARMED,
  REGION_DISARMED_DISTURBED
} REGION_STATE_E;

typedef enum region_subaction_e
{
  ARM_REGION           = 0xC1u,
  DISARM_REGION        = 0xC2u,
  ARM_REGION_BYPASSING = 0xC6u,
  RESET_REGION_ALARM   = 0xC7u,
} REGION_SUBACTION_E;

typedef struct sas_region_map_entry_s
{
  ip4_addr_t ip_addr;   // ip адрес контроллера
  uint8_t  btn_led_id;  // id кнопки и индикатора на табло, к которой привязан регион
  uint8_t  region_id;   // id региона на контроллере
  uint8_t  unused[2];
} region_t;

void set_region_state(region_t const * region, REGION_STATE_E state);

REGION_STATE_E get_region_state(uint8_t btn_id);

void region_state_actual_period_tick(void);

void region_state_actual_period_expired(void);

void region_check_alarm_n_play(void);

bool add_region_entry(unsigned int idx, ip4_addr_t ip, uint8_t region_id, uint8_t linked_btn_id);

bool delete_region_entry(unsigned idx);

region_t * get_region_entry(unsigned idx);

void clear_region_map(void);

/**
 * Специальная функция для обнуления таблицы регионов перед ее заполнением из флэша.
 * Сделана для предупреждения assert'ов в отладочных сборках.
 */
void purge_region_map(void);

int region_map_count(void);

region_t * lookup_region_entry_by_button_id(uint8_t btn_id);

region_t * lookup_matched_region(ip4_addr_t const * ip, uint8_t region_id);

int persist_region_map(void);

int restore_region_map(void);

#endif /* SECURITY_REGIONS_MGR_H_ */
