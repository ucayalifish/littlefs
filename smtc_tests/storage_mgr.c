#include "storage_mgr.h"
#include "flash.h"
#include <string.h>
#include <bd/lfs_rambd.h>

static uint8_t read_buf_[1024] = {0u};

static uint8_t prog_buf_[1024] = {0u};

static uint8_t lookahead_buf_[8] = {0u};

static uint8_t file_buf_[1024] = {0u};

static uint8_t ram_bd_buf_[STORAGE_BLOCK_SIZE * STORAGE_BLOCKS] = {0u};

static lfs_t lfs_;

static struct lfs_file_config file_cfg_ =
                                {
                                  .buffer = file_buf_,
                                  .attrs = NULL,
                                  .attr_count = 0
                                };

static struct lfs_rambd_config rambd_cfg_ =
                                 {
                                   .erase_value = -1,
                                   .buffer = ram_bd_buf_
                                 };

static lfs_rambd_t rambd_ =
                     {
                       .buffer = NULL,
                       .cfg = &rambd_cfg_
                     };

static const struct lfs_config lfs_cfg_ =
                                 {
                                   .read = lfs_rambd_read,
                                   .prog = lfs_rambd_prog,
                                   .erase = lfs_rambd_erase,
                                   .sync = lfs_rambd_sync,
                                   .read_size = 1024u,
                                   .prog_size = 4u,
                                   .block_size = STORAGE_BLOCK_SIZE,
                                   .block_count = STORAGE_BLOCKS,
                                   .block_cycles = 100,
                                   .cache_size = 1024u,
                                   .lookahead_size = 8u,
                                   .read_buffer = read_buf_,
                                   .prog_buffer = prog_buf_,
                                   .lookahead_buffer = lookahead_buf_,
                                   .file_max = 131072u,
                                   .context = &rambd_
                                 };

int create_ram_flash(void)
{
  return lfs_rambd_createcfg(&lfs_cfg_, &rambd_cfg_);
}

int destroy_ram_flash(void)
{
  return lfs_rambd_destroy(&lfs_cfg_);
}

int mount_file_system(void)
{
  int error = lfs_mount(&lfs_, &lfs_cfg_);

  if (error)
    {
      error = lfs_format(&lfs_, &lfs_cfg_);

      if (error == 0)
        {
          error = lfs_mount(&lfs_, &lfs_cfg_);
        }
    }

  if (error)
    {
      //HAL_FLASH_Lock();
    }

  return error;
}

static lfs_ssize_t fs_read_at_least_n_bytes_(char const * path, void * buffer, lfs_ssize_t const read_limit)
{
  lfs_file_t file;

  int error = lfs_file_opencfg(&lfs_, &file, path, LFS_O_RDONLY, &file_cfg_);
  if (error)
    {
      goto exit_point_;
    }

  lfs_ssize_t const bytes_read = lfs_file_read(&lfs_, &file, buffer, (lfs_size_t) read_limit);
  if (bytes_read < 0)
    {
      error = bytes_read;
      goto clean_up_;
    }

  if (bytes_read < read_limit)
    {
      error = LOGIC_FS_ERR;
      goto clean_up_;
    }

  error = bytes_read;

clean_up_:
  (void) lfs_file_close(&lfs_, &file);

exit_point_:
  return error;
}

/**
 * Заменить данные в файле целиком
 * @return  enum lfs_error в случае ошибки или количество записанных байт (4 т.к. последним записывается CRC32).
 */
static int fs_replace_file_(char const * path, uint8_t const * buffer, lfs_size_t size, uint32_t const crc)
{
  lfs_file_t file;

  int error = lfs_file_opencfg(&lfs_, &file, path, LFS_O_RDWR | LFS_O_CREAT | LFS_O_TRUNC, &file_cfg_);
  if (error)
    {
      goto exit_point_;
    }

  error = lfs_file_write(&lfs_, &file, buffer, size);
  if (error < 0)
    {
      goto clean_up_;
    }

  error = lfs_file_write(&lfs_, &file, &crc, sizeof crc);

clean_up_:
  (void) lfs_file_close(&lfs_, &file);

exit_point_:
  return error;
}

static char const region_map_main_file_[] __attribute__((section(".rodata.consts"))) = "region_map_data";

static char const region_map_backup_file_[] __attribute__((section(".rodata.consts"))) = "region_map_backup";

static char const acl_table_main_file_[] __attribute__((section(".rodata.consts"))) = "acl_table_data";

static char const acl_table_backup_file_[] __attribute__((section(".rodata.consts"))) = "acl_table_backup";

static char const wiegand_format_main_file_[] __attribute__((section(".rodata.consts"))) = "wiegand_format_data";

static char const wiegand_format_backup_file_[] __attribute__((section(".rodata.consts"))) = "wiegand_format_backup";

/**
 * Проверяет файл с данными.
 * Если файл не пуст - пытается сохранить его как бэкап.
 * @param data_file полное имя файла хранения
 * @param backup_file полное имя файла бэкапа
 * @return 0 -- успех, отрицательное значение
 */
static lfs_ssize_t check_and_rename_(char const * data_file, char const * backup_file)
{
  struct lfs_info info;
  lfs_ssize_t     result = lfs_stat(&lfs_, data_file, &info);
  if (result < 0)
    {
      goto exit_point_;
    }

  if (info.size > 0)
    {
      result = lfs_rename(&lfs_, data_file, backup_file);
    }

exit_point_:
  return result;
}

int fs_backup_previous_region_map()
{
  return check_and_rename_(region_map_main_file_, region_map_backup_file_);
}

int fs_replace_region_map(uint8_t const * data, size_t size, uint32_t const crc)
{
  return fs_replace_file_(region_map_main_file_, data, size, crc);
}

int fs_read_region_map(uint8_t * buffer, int const exact_size)
{
  int error = fs_read_at_least_n_bytes_(region_map_main_file_, buffer, exact_size);

  if (error < 0 || error != exact_size)
    {
      error = fs_read_at_least_n_bytes_(region_map_backup_file_, buffer, exact_size);
      if (error >= 0 && error != exact_size)
        {
          error = LOGIC_FS_ERR;
        }
    }

  return error;
}

int fs_backup_previous_acl_table(void)
{
  return check_and_rename_(acl_table_main_file_, acl_table_backup_file_);
}

int fs_replace_acl_table(uint8_t const * data, size_t const record_size, int const record_num, uint32_t const crc)
{
  lfs_file_t file;

  int error = lfs_file_opencfg(&lfs_, &file, acl_table_main_file_, LFS_O_RDWR | LFS_O_CREAT | LFS_O_TRUNC, &file_cfg_);
  if (error)
    {
      goto exit_point_;
    }
  else
    {
      uint8_t buffer[record_size];

      for (int i = 0; i < record_num; ++i)
        {
          uint8_t const * src = data + record_size * i;
          memcpy(buffer, src, record_size);
          error = lfs_file_write(&lfs_, &file, buffer, record_size);
          if (error < 0)
            {
              goto clean_up_;
            }
        }
    }

  error = lfs_file_write(&lfs_, &file, &crc, sizeof crc);

clean_up_:
  (void) lfs_file_close(&lfs_, &file);

exit_point_:
  return error;
}

static lfs_file_t acl_file_;

int fs_open_acl_file(bool const main_file)
{
  char const * path = main_file ? acl_table_main_file_ : acl_table_backup_file_;
  return lfs_file_opencfg(&lfs_, &acl_file_, path, LFS_O_RDONLY, &file_cfg_);
}

void fs_close_acl_file(void)
{
  (void) lfs_file_close(&lfs_, &acl_file_);
}

int fs_read_acl_bytes(uint8_t * buffer, int how_many)
{
  lfs_ssize_t const bytes_read = lfs_file_read(&lfs_, &acl_file_, buffer, how_many);
  if (bytes_read < 0)
    {
      return bytes_read;
    }

  if (bytes_read < how_many)
    {
      return LOGIC_FS_ERR;
    }

  return bytes_read;
}

int fs_backup_previous_wiegand_formats(void)
{
  return check_and_rename_(wiegand_format_main_file_, wiegand_format_backup_file_);
}

int fs_replace_wiegand_formats(uint8_t const * data, size_t const size, uint32_t const crc)
{
  return fs_replace_file_(wiegand_format_main_file_, data, size, crc);
}

int fs_read_wiegand_formats(uint8_t * buffer, int exact_size)
{
  int error = fs_read_at_least_n_bytes_(wiegand_format_main_file_, buffer, exact_size);

  if (error < 0 || error != exact_size)
    {
      error = fs_read_at_least_n_bytes_(wiegand_format_backup_file_, buffer, exact_size);
      if (error >= 0 && error != exact_size)
        {
          error = LOGIC_FS_ERR;
        }
    }

  return error;
}

unsigned fs_clear_configuration_files(void)
{
  unsigned extra = 0ull;
  int      error = lfs_remove(&lfs_, region_map_main_file_);
  if (error && error != LFS_ERR_NOENT)
    {
      extra |= (1ull << 0u);
    }

  error = lfs_remove(&lfs_, region_map_backup_file_);
  if (error && error != LFS_ERR_NOENT)
    {
      extra |= (1ull << 1u);
    }

  error = lfs_remove(&lfs_, acl_table_main_file_);
  if (error && error != LFS_ERR_NOENT)
    {
      extra |= (1ull << 2u);
    }

  error = lfs_remove(&lfs_, acl_table_backup_file_);
  if (error && error != LFS_ERR_NOENT)
    {
      extra |= (1ull << 3u);
    }

  error = lfs_remove(&lfs_, wiegand_format_main_file_);
  if (error && error != LFS_ERR_NOENT)
    {
      extra |= (1ull << 4u);
    }

  error = lfs_remove(&lfs_, wiegand_format_backup_file_);
  if (error && error != LFS_ERR_NOENT)
    {
      extra |= (1ull << 5u);
    }

  return extra;
}
