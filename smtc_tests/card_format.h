#ifndef SMARTECCONSOLE_CARD_FORMAT_H
#define SMARTECCONSOLE_CARD_FORMAT_H

#include <stddef.h>
#include <stdint.h>

typedef enum wiegand_parity_type_e
{
  WPT_NONE = 0, WPT_ODD = 1, WPT_EVEN = 2, WPT_ABS = -1,
} W_PARITY_TYPE_E;

typedef enum wiegand_code_type_e
{
  WCT_PIN = 0, WCT_CARD = 1, WCT_NONE = -1,
} W_CODE_TYPE_E;

#define WF_NO_PARITY_POS -1

#define WF_NOT_BIT_MASK -1ULL

#define WF_NOT_BIT_POS -1

#define WF_NOT_CODE_LEN -1

#define WF_FORMATS_NUM 16

typedef struct parity_group_s
{
  uint64_t mask;
  int8_t   pos;
  int8_t   type;
} parity_group_t;

typedef struct wiegand_format_s
{
  uint64_t parity_bit_mask;      // маска выделения битов контроля четности, невалидное значение - -1
  parity_group_t groups[3];
/*
  uint64_t parity_group_mask[3]; // неиспользуемая группа должна быть 0, невалидное значение - -1
  int8_t   parity_bit_pos[3];    // индекс соответствующего бита четности начиная с 0, отсутствует - -1
  int8_t
           parity_type[3];       // вид контроля четности, в заполненной таблице 0 - отсутствует, 1 - нечетность, 2 - четность, в пустой записи - все -1 (значение из W_PARITY_TYPE_E)
*/
  int8_t   code_len;             // длина кода в битах, по умолчанию -- -1, валидное значение [1-64]
  int8_t   code_type;            // 0 - пин, 1 - карта, -1 - дефолтное значение для пустой записи: значение из W_CODE_TYPE_E
} wiegand_format_t;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

typedef struct packed_wgf_s
{
  uint64_t parity_bit_mask;
  uint64_t group_mask[3];
  int8_t group_pos[3];
  int8_t group_type[3];
  int8_t code_len;
  int8_t code_type;
} __attribute__((packed)) packed_wgf_t;

#pragma clang diagnostic pop

#define WF_PACKED_SIZE sizeof(packed_wgf_t)

_Static_assert(sizeof(wiegand_format_t) == 64, "sizeof(wiegand_format_t)");

_Static_assert(offsetof(wiegand_format_t, code_type) == 57, "wiegand_format_t trailing slope");

_Static_assert(WF_PACKED_SIZE == (4 * sizeof(uint64_t) + 8), "wrong wiegand_format_t packed size");

_Static_assert(sizeof(packed_wgf_t) == 40, "wrong wiegand_format_t (packed_wgf_t) packed size");

_Static_assert(sizeof(packed_wgf_t) - offsetof(packed_wgf_t, code_type) == 1, "unexpected trailing slope int packed_wgf_t");

void wf_purge_table(void);

wiegand_format_t const * wf_lookup_by_code_length(int len, int * start);

int wf_save_at_index(uint8_t * wf, int idx);

int wf_lookup_and_copy_by_index(uint8_t * dest, int idx);

int wf_clear_at_index(int idx);

int wf_count_formats(void);

int wf_persist_formats(void);

int wf_restore_table(void);

#endif //SMARTECCONSOLE_CARD_FORMAT_H
