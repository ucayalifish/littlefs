#ifndef CARDS_MGR_H_
#define CARDS_MGR_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_ACL_ENTRIES_NUM 1000

typedef enum access_right_flag_s
{
  CAN_NOTHING_E          = 0,
  CAN_ARM_E              = 1 << 0,
  CAN_RESET_AND_DISARM_E = 1 << 1,
}                                                     ACL_FLAGS_E;

typedef struct acl_entry_s
{
  uint64_t card_id;
  int32_t  pin_code;
  uint32_t acl[2];
} __attribute__((packed)) __attribute__((aligned(4))) acl_entry_t;

_Static_assert(_Alignof(acl_entry_t) == 4, "unexpected acl alignment");

_Static_assert(sizeof(acl_entry_t) == 20, "unexpected acl record size");

_Static_assert(offsetof(acl_entry_t, acl) == sizeof(acl_entry_t) - 2 * sizeof(uint32_t), "unexpected trailing slop in acl struct");

_Static_assert(sizeof(acl_entry_t) * MAX_ACL_ENTRIES_NUM == 20000, "unexpected total size of acl table");

// номер-индекс в таблице + данные
#define ACL_WIRE_SIZE (sizeof(acl_entry_t) + sizeof(int32_t))

#define ACL_MAP_SIZE (MAX_ACL_ENTRIES_NUM / CHAR_BIT)

int replace_acl_entry(uint8_t const * new_acl, int32_t idx);

int read_acl_entry(uint8_t * dest, int32_t acl_to_read);

int delete_acl_entry(int32_t acl_to_delete);

void clear_acl_table(void);

void fill_in_acl_entry_map(uint8_t * dest);

uint32_t const * card_is_on_list(uint64_t const * raw, int raw_len, uint64_t const * card);

uint32_t const * pin_is_on_list(uint64_t const * pin);

int persist_card_table(void);

int restore_acl_table(void);

#endif /* CARDS_MGR_H_ */
