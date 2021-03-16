#ifndef STORAGE_MGR_H_
#define STORAGE_MGR_H_

#include <lfs.h>
#include <limits.h>

int create_ram_flash(void);

int destroy_ram_flash(void);

/**
 * Монтирует файловую систему
 * @return  enum lfs_error.
 */
int mount_file_system(void);

// Ошибка, означающая, что ошибки littlefs нет,
// но функция не смогла выполнить свой контракт.
#define LOGIC_FS_ERR (-123)

#define CRC_ERROR (-125)

/**
 * Если существует файл с сохраненной картой разделов охраны,
 * то переименовывает его в backup-файл.
 * @return Отрицательное значение при ошибке.
 */
int fs_backup_previous_region_map(void);

/**
 * Пытается записать карту разделов охраны и контрольную сумму в основной файл таблицы разделов.
 * @param data данные для записи
 * @param size размер данных для записи
 * @param crc контрольная сумма
 * @return Положительное значение (4 байта CRC32) в случае успеха
 *  или отрицательное значение при ошибке.
 */
int fs_replace_region_map(uint8_t const * data, size_t size, uint32_t crc);

/**
 * Пытается прочитать данные таблицы разделов охраны из основного или backup-файла.
 * @param buffer буфер назначения
 * @param exact_size ожидаемый размер
 * @return возвращает число прочитанных байт или отрицательное значение в случае ошибки.
 */
int fs_read_region_map(uint8_t * buffer, int exact_size);

/**
 * Если существует файл с сохраненной таблицей карт,
 * то пытается сохранить его в backup-файл.
 * @return Отрицательное значение при ошибке.
 */
int fs_backup_previous_acl_table(void);

/**
 * Пытается сохранить таблицу карт и контрольную сумму в файл таблицы карт.
 * @param data данные для записи
 * @param record_size размер данных
 * @param crc контрольная сумма
 * @return Положительное значение (4 байта CRC32) в случае успеха
 *  или отрицательное значение при ошибке.
 */
int fs_replace_acl_table(uint8_t const * data, size_t record_size, int record_num, uint32_t crc);

int fs_open_acl_file(bool main_file);

void fs_close_acl_file(void);

int fs_read_acl_bytes(uint8_t * buffer, int how_many);

int fs_backup_previous_wiegand_formats(void);

int fs_replace_wiegand_formats(uint8_t const * data, size_t size, uint32_t crc);

int fs_read_wiegand_formats(uint8_t * buffer, int exact_size);

/**
 * Пытается очистить конфигурацию сохранённую в файловой системе.
 * @return флаги очистки файлов
 * бит 0 == 1 -- не удалось очистить region_map_data,
 * бит 1 == 1 -- не удалось очистить region_map_backup,
 * бит 2 == 1 -- не удалось очистить card_table_data,
 * бит 3 == 1 -- не удалось очистить card_table_backup,
 * бит 4 == 1 -- не удалось очистить wiegand_format_data,
 * бит 5 == 1 -- не удалось очистить wiegand_format_backup,
 */
unsigned fs_clear_configuration_files(void);

#endif /* STORAGE_MGR_H_ */
