#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <signal.h>
__attribute__((unused)) static void __lfs_assert_print_bool(bool v, size_t size) { (void)size; printf("%s", v ? "true" : "false"); }
__attribute__((unused)) static void __lfs_assert_fail_bool( const char *file, int line, const char *comp, bool lh, size_t lsize, bool rh, size_t rsize) { printf("%s:%d:assert: assert failed with ", file, line); __lfs_assert_print_bool(lh, lsize); printf(", expected %s ", comp); __lfs_assert_print_bool(rh, rsize); printf("\n"); fflush(NULL); raise(SIGABRT); }
#define __LFS_ASSERT_BOOL_NE(file, line, lh, rh) do { bool _lh = !!(lh); bool _rh = !!(rh); if (!(_lh != _rh)) { __lfs_assert_fail_bool(file, line, "ne", _lh, 0, _rh, 0); } } while (0)
#define __LFS_ASSERT_BOOL_LT(file, line, lh, rh) do { bool _lh = !!(lh); bool _rh = !!(rh); if (!(_lh < _rh)) { __lfs_assert_fail_bool(file, line, "lt", _lh, 0, _rh, 0); } } while (0)
#define __LFS_ASSERT_BOOL_LE(file, line, lh, rh) do { bool _lh = !!(lh); bool _rh = !!(rh); if (!(_lh <= _rh)) { __lfs_assert_fail_bool(file, line, "le", _lh, 0, _rh, 0); } } while (0)
#define __LFS_ASSERT_BOOL_EQ(file, line, lh, rh) do { bool _lh = !!(lh); bool _rh = !!(rh); if (!(_lh == _rh)) { __lfs_assert_fail_bool(file, line, "eq", _lh, 0, _rh, 0); } } while (0)
#define __LFS_ASSERT_BOOL_GT(file, line, lh, rh) do { bool _lh = !!(lh); bool _rh = !!(rh); if (!(_lh > _rh)) { __lfs_assert_fail_bool(file, line, "gt", _lh, 0, _rh, 0); } } while (0)
#define __LFS_ASSERT_BOOL_GE(file, line, lh, rh) do { bool _lh = !!(lh); bool _rh = !!(rh); if (!(_lh >= _rh)) { __lfs_assert_fail_bool(file, line, "ge", _lh, 0, _rh, 0); } } while (0)
__attribute__((unused)) static void __lfs_assert_print_int(intmax_t v, size_t size) { (void)size; printf("%"PRIiMAX, v); }
__attribute__((unused)) static void __lfs_assert_fail_int( const char *file, int line, const char *comp, intmax_t lh, size_t lsize, intmax_t rh, size_t rsize) { printf("%s:%d:assert: assert failed with ", file, line); __lfs_assert_print_int(lh, lsize); printf(", expected %s ", comp); __lfs_assert_print_int(rh, rsize); printf("\n"); fflush(NULL); raise(SIGABRT); }
#define __LFS_ASSERT_INT_NE(file, line, lh, rh) do { __typeof__(lh) _lh = lh; __typeof__(lh) _rh = (__typeof__(lh))rh; if (!(_lh != _rh)) { __lfs_assert_fail_int(file, line, "ne", (intmax_t)_lh, 0, (intmax_t)_rh, 0); } } while (0)
#define __LFS_ASSERT_INT_LT(file, line, lh, rh) do { __typeof__(lh) _lh = lh; __typeof__(lh) _rh = (__typeof__(lh))rh; if (!(_lh < _rh)) { __lfs_assert_fail_int(file, line, "lt", (intmax_t)_lh, 0, (intmax_t)_rh, 0); } } while (0)
#define __LFS_ASSERT_INT_LE(file, line, lh, rh) do { __typeof__(lh) _lh = lh; __typeof__(lh) _rh = (__typeof__(lh))rh; if (!(_lh <= _rh)) { __lfs_assert_fail_int(file, line, "le", (intmax_t)_lh, 0, (intmax_t)_rh, 0); } } while (0)
#define __LFS_ASSERT_INT_EQ(file, line, lh, rh) do { __typeof__(lh) _lh = lh; __typeof__(lh) _rh = (__typeof__(lh))rh; if (!(_lh == _rh)) { __lfs_assert_fail_int(file, line, "eq", (intmax_t)_lh, 0, (intmax_t)_rh, 0); } } while (0)
#define __LFS_ASSERT_INT_GT(file, line, lh, rh) do { __typeof__(lh) _lh = lh; __typeof__(lh) _rh = (__typeof__(lh))rh; if (!(_lh > _rh)) { __lfs_assert_fail_int(file, line, "gt", (intmax_t)_lh, 0, (intmax_t)_rh, 0); } } while (0)
#define __LFS_ASSERT_INT_GE(file, line, lh, rh) do { __typeof__(lh) _lh = lh; __typeof__(lh) _rh = (__typeof__(lh))rh; if (!(_lh >= _rh)) { __lfs_assert_fail_int(file, line, "ge", (intmax_t)_lh, 0, (intmax_t)_rh, 0); } } while (0)
__attribute__((unused)) static void __lfs_assert_print_mem(const void * v, size_t size) { const uint8_t *s = v; printf("\""); for (size_t i = 0; i < size && i < 16; i++) { if (s[i] >= ' ' && s[i] <= '~') { printf("%c", s[i]); } else { printf("\\x%02x", s[i]); } } if (size > 16) { printf("..."); } printf("\""); }
__attribute__((unused)) static void __lfs_assert_fail_mem( const char *file, int line, const char *comp, const void * lh, size_t lsize, const void * rh, size_t rsize) { printf("%s:%d:assert: assert failed with ", file, line); __lfs_assert_print_mem(lh, lsize); printf(", expected %s ", comp); __lfs_assert_print_mem(rh, rsize); printf("\n"); fflush(NULL); raise(SIGABRT); }
#define __LFS_ASSERT_MEM_NE(file, line, lh, rh, size) do { const void *_lh = lh; const void *_rh = rh; if (!(memcmp(_lh, _rh, size) != 0)) { __lfs_assert_fail_mem(file, line, "ne", _lh, size, _rh, size); } } while (0)
#define __LFS_ASSERT_MEM_LT(file, line, lh, rh, size) do { const void *_lh = lh; const void *_rh = rh; if (!(memcmp(_lh, _rh, size) < 0)) { __lfs_assert_fail_mem(file, line, "lt", _lh, size, _rh, size); } } while (0)
#define __LFS_ASSERT_MEM_LE(file, line, lh, rh, size) do { const void *_lh = lh; const void *_rh = rh; if (!(memcmp(_lh, _rh, size) <= 0)) { __lfs_assert_fail_mem(file, line, "le", _lh, size, _rh, size); } } while (0)
#define __LFS_ASSERT_MEM_EQ(file, line, lh, rh, size) do { const void *_lh = lh; const void *_rh = rh; if (!(memcmp(_lh, _rh, size) == 0)) { __lfs_assert_fail_mem(file, line, "eq", _lh, size, _rh, size); } } while (0)
#define __LFS_ASSERT_MEM_GT(file, line, lh, rh, size) do { const void *_lh = lh; const void *_rh = rh; if (!(memcmp(_lh, _rh, size) > 0)) { __lfs_assert_fail_mem(file, line, "gt", _lh, size, _rh, size); } } while (0)
#define __LFS_ASSERT_MEM_GE(file, line, lh, rh, size) do { const void *_lh = lh; const void *_rh = rh; if (!(memcmp(_lh, _rh, size) >= 0)) { __lfs_assert_fail_mem(file, line, "ge", _lh, size, _rh, size); } } while (0)
__attribute__((unused)) static void __lfs_assert_print_str(const char * v, size_t size) { __lfs_assert_print_mem(v, size); }
__attribute__((unused)) static void __lfs_assert_fail_str( const char *file, int line, const char *comp, const char * lh, size_t lsize, const char * rh, size_t rsize) { printf("%s:%d:assert: assert failed with ", file, line); __lfs_assert_print_str(lh, lsize); printf(", expected %s ", comp); __lfs_assert_print_str(rh, rsize); printf("\n"); fflush(NULL); raise(SIGABRT); }
#define __LFS_ASSERT_STR_NE(file, line, lh, rh) do { const char *_lh = lh; const char *_rh = rh; if (!(strcmp(_lh, _rh) != 0)) { __lfs_assert_fail_str(file, line, "ne", _lh, strlen(_lh), _rh, strlen(_rh)); } } while (0)
#define __LFS_ASSERT_STR_LT(file, line, lh, rh) do { const char *_lh = lh; const char *_rh = rh; if (!(strcmp(_lh, _rh) < 0)) { __lfs_assert_fail_str(file, line, "lt", _lh, strlen(_lh), _rh, strlen(_rh)); } } while (0)
#define __LFS_ASSERT_STR_LE(file, line, lh, rh) do { const char *_lh = lh; const char *_rh = rh; if (!(strcmp(_lh, _rh) <= 0)) { __lfs_assert_fail_str(file, line, "le", _lh, strlen(_lh), _rh, strlen(_rh)); } } while (0)
#define __LFS_ASSERT_STR_EQ(file, line, lh, rh) do { const char *_lh = lh; const char *_rh = rh; if (!(strcmp(_lh, _rh) == 0)) { __lfs_assert_fail_str(file, line, "eq", _lh, strlen(_lh), _rh, strlen(_rh)); } } while (0)
#define __LFS_ASSERT_STR_GT(file, line, lh, rh) do { const char *_lh = lh; const char *_rh = rh; if (!(strcmp(_lh, _rh) > 0)) { __lfs_assert_fail_str(file, line, "gt", _lh, strlen(_lh), _rh, strlen(_rh)); } } while (0)
#define __LFS_ASSERT_STR_GE(file, line, lh, rh) do { const char *_lh = lh; const char *_rh = rh; if (!(strcmp(_lh, _rh) >= 0)) { __lfs_assert_fail_str(file, line, "ge", _lh, strlen(_lh), _rh, strlen(_rh)); } } while (0)
#line 1 "tests/test_entries.toml.test.tc"

//////////////// AUTOGENERATED TEST ////////////////
#include "lfs.h"
#include "bd/lfs_testbd.h"
#include <stdio.h>
extern const char *lfs_testbd_path;
extern uint32_t lfs_testbd_cycles;

void test_case1() {
    // prologue
    __attribute__((unused)) lfs_t lfs;
    __attribute__((unused)) lfs_testbd_t bd;
    __attribute__((unused)) lfs_file_t file;
    __attribute__((unused)) lfs_dir_t dir;
    __attribute__((unused)) struct lfs_info info;
    __attribute__((unused)) char path[1024];
    __attribute__((unused)) uint8_t buffer[1024];
    __attribute__((unused)) lfs_size_t size;
    __attribute__((unused)) int err;
    
    __attribute__((unused)) const struct lfs_config cfg = {
        .context        = &bd,
        .read           = lfs_testbd_read,
        .prog           = lfs_testbd_prog,
        .erase          = lfs_testbd_erase,
        .sync           = lfs_testbd_sync,
        .read_size      = LFS_READ_SIZE,
        .prog_size      = LFS_PROG_SIZE,
        .block_size     = LFS_BLOCK_SIZE,
        .block_count    = LFS_BLOCK_COUNT,
        .block_cycles   = LFS_BLOCK_CYCLES,
        .cache_size     = LFS_CACHE_SIZE,
        .lookahead_size = LFS_LOOKAHEAD_SIZE,
    };

    __attribute__((unused)) const struct lfs_testbd_config bdcfg = {
        .erase_value        = LFS_ERASE_VALUE,
        .erase_cycles       = LFS_ERASE_CYCLES,
        .badblock_behavior  = LFS_BADBLOCK_BEHAVIOR,
        .power_cycles       = lfs_testbd_cycles,
    };

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_createcfg(&cfg, lfs_testbd_path, &bdcfg), 0);

    // test case 1
    #line 10 "tests/test_entries.toml"
    uint8_t wbuffer[1024];
    uint8_t rbuffer[1024];

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // write hi0 20
    sprintf(path, "hi0"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi1 20
    sprintf(path, "hi1"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi2 20
    sprintf(path, "hi2"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi3 20
    sprintf(path, "hi3"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // read hi1 20
    sprintf(path, "hi1"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi1 200
    sprintf(path, "hi1"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // read hi0 20
    sprintf(path, "hi0"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi1 200
    sprintf(path, "hi1"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi2 20
    sprintf(path, "hi2"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi3 20
    sprintf(path, "hi3"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case2() {
    // prologue
    __attribute__((unused)) lfs_t lfs;
    __attribute__((unused)) lfs_testbd_t bd;
    __attribute__((unused)) lfs_file_t file;
    __attribute__((unused)) lfs_dir_t dir;
    __attribute__((unused)) struct lfs_info info;
    __attribute__((unused)) char path[1024];
    __attribute__((unused)) uint8_t buffer[1024];
    __attribute__((unused)) lfs_size_t size;
    __attribute__((unused)) int err;
    
    __attribute__((unused)) const struct lfs_config cfg = {
        .context        = &bd,
        .read           = lfs_testbd_read,
        .prog           = lfs_testbd_prog,
        .erase          = lfs_testbd_erase,
        .sync           = lfs_testbd_sync,
        .read_size      = LFS_READ_SIZE,
        .prog_size      = LFS_PROG_SIZE,
        .block_size     = LFS_BLOCK_SIZE,
        .block_count    = LFS_BLOCK_COUNT,
        .block_cycles   = LFS_BLOCK_CYCLES,
        .cache_size     = LFS_CACHE_SIZE,
        .lookahead_size = LFS_LOOKAHEAD_SIZE,
    };

    __attribute__((unused)) const struct lfs_testbd_config bdcfg = {
        .erase_value        = LFS_ERASE_VALUE,
        .erase_cycles       = LFS_ERASE_CYCLES,
        .badblock_behavior  = LFS_BADBLOCK_BEHAVIOR,
        .power_cycles       = lfs_testbd_cycles,
    };

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_createcfg(&cfg, lfs_testbd_path, &bdcfg), 0);

    // test case 2
    #line 99 "tests/test_entries.toml"
    uint8_t wbuffer[1024];
    uint8_t rbuffer[1024];

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // write hi0 20
    sprintf(path, "hi0"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi1 200
    sprintf(path, "hi1"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi2 20
    sprintf(path, "hi2"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi3 20
    sprintf(path, "hi3"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // read hi1 200
    sprintf(path, "hi1"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi1 20
    sprintf(path, "hi1"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // read hi0 20
    sprintf(path, "hi0"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi1 20
    sprintf(path, "hi1"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi2 20
    sprintf(path, "hi2"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi3 20
    sprintf(path, "hi3"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case3() {
    // prologue
    __attribute__((unused)) lfs_t lfs;
    __attribute__((unused)) lfs_testbd_t bd;
    __attribute__((unused)) lfs_file_t file;
    __attribute__((unused)) lfs_dir_t dir;
    __attribute__((unused)) struct lfs_info info;
    __attribute__((unused)) char path[1024];
    __attribute__((unused)) uint8_t buffer[1024];
    __attribute__((unused)) lfs_size_t size;
    __attribute__((unused)) int err;
    
    __attribute__((unused)) const struct lfs_config cfg = {
        .context        = &bd,
        .read           = lfs_testbd_read,
        .prog           = lfs_testbd_prog,
        .erase          = lfs_testbd_erase,
        .sync           = lfs_testbd_sync,
        .read_size      = LFS_READ_SIZE,
        .prog_size      = LFS_PROG_SIZE,
        .block_size     = LFS_BLOCK_SIZE,
        .block_count    = LFS_BLOCK_COUNT,
        .block_cycles   = LFS_BLOCK_CYCLES,
        .cache_size     = LFS_CACHE_SIZE,
        .lookahead_size = LFS_LOOKAHEAD_SIZE,
    };

    __attribute__((unused)) const struct lfs_testbd_config bdcfg = {
        .erase_value        = LFS_ERASE_VALUE,
        .erase_cycles       = LFS_ERASE_CYCLES,
        .badblock_behavior  = LFS_BADBLOCK_BEHAVIOR,
        .power_cycles       = lfs_testbd_cycles,
    };

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_createcfg(&cfg, lfs_testbd_path, &bdcfg), 0);

    // test case 3
    #line 188 "tests/test_entries.toml"
    uint8_t wbuffer[1024];
    uint8_t rbuffer[1024];

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // write hi0 200
    sprintf(path, "hi0"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi1 200
    sprintf(path, "hi1"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi2 200
    sprintf(path, "hi2"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi3 200
    sprintf(path, "hi3"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // read hi0 200
    sprintf(path, "hi0"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi1 200
    sprintf(path, "hi1"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi2 200
    sprintf(path, "hi2"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi3 200
    sprintf(path, "hi3"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case4() {
    // prologue
    __attribute__((unused)) lfs_t lfs;
    __attribute__((unused)) lfs_testbd_t bd;
    __attribute__((unused)) lfs_file_t file;
    __attribute__((unused)) lfs_dir_t dir;
    __attribute__((unused)) struct lfs_info info;
    __attribute__((unused)) char path[1024];
    __attribute__((unused)) uint8_t buffer[1024];
    __attribute__((unused)) lfs_size_t size;
    __attribute__((unused)) int err;
    
    __attribute__((unused)) const struct lfs_config cfg = {
        .context        = &bd,
        .read           = lfs_testbd_read,
        .prog           = lfs_testbd_prog,
        .erase          = lfs_testbd_erase,
        .sync           = lfs_testbd_sync,
        .read_size      = LFS_READ_SIZE,
        .prog_size      = LFS_PROG_SIZE,
        .block_size     = LFS_BLOCK_SIZE,
        .block_count    = LFS_BLOCK_COUNT,
        .block_cycles   = LFS_BLOCK_CYCLES,
        .cache_size     = LFS_CACHE_SIZE,
        .lookahead_size = LFS_LOOKAHEAD_SIZE,
    };

    __attribute__((unused)) const struct lfs_testbd_config bdcfg = {
        .erase_value        = LFS_ERASE_VALUE,
        .erase_cycles       = LFS_ERASE_CYCLES,
        .badblock_behavior  = LFS_BADBLOCK_BEHAVIOR,
        .power_cycles       = lfs_testbd_cycles,
    };

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_createcfg(&cfg, lfs_testbd_path, &bdcfg), 0);

    // test case 4
    #line 261 "tests/test_entries.toml"
    uint8_t wbuffer[1024];
    uint8_t rbuffer[1024];

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // write hi0 200
    sprintf(path, "hi0"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi1 20
    sprintf(path, "hi1"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi2 200
    sprintf(path, "hi2"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi3 200
    sprintf(path, "hi3"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // read hi1 20
    sprintf(path, "hi1"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi1 200
    sprintf(path, "hi1"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // read hi0 200
    sprintf(path, "hi0"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi1 200
    sprintf(path, "hi1"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi2 200
    sprintf(path, "hi2"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi3 200
    sprintf(path, "hi3"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case5() {
    // prologue
    __attribute__((unused)) lfs_t lfs;
    __attribute__((unused)) lfs_testbd_t bd;
    __attribute__((unused)) lfs_file_t file;
    __attribute__((unused)) lfs_dir_t dir;
    __attribute__((unused)) struct lfs_info info;
    __attribute__((unused)) char path[1024];
    __attribute__((unused)) uint8_t buffer[1024];
    __attribute__((unused)) lfs_size_t size;
    __attribute__((unused)) int err;
    
    __attribute__((unused)) const struct lfs_config cfg = {
        .context        = &bd,
        .read           = lfs_testbd_read,
        .prog           = lfs_testbd_prog,
        .erase          = lfs_testbd_erase,
        .sync           = lfs_testbd_sync,
        .read_size      = LFS_READ_SIZE,
        .prog_size      = LFS_PROG_SIZE,
        .block_size     = LFS_BLOCK_SIZE,
        .block_count    = LFS_BLOCK_COUNT,
        .block_cycles   = LFS_BLOCK_CYCLES,
        .cache_size     = LFS_CACHE_SIZE,
        .lookahead_size = LFS_LOOKAHEAD_SIZE,
    };

    __attribute__((unused)) const struct lfs_testbd_config bdcfg = {
        .erase_value        = LFS_ERASE_VALUE,
        .erase_cycles       = LFS_ERASE_CYCLES,
        .badblock_behavior  = LFS_BADBLOCK_BEHAVIOR,
        .power_cycles       = lfs_testbd_cycles,
    };

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_createcfg(&cfg, lfs_testbd_path, &bdcfg), 0);

    // test case 5
    #line 350 "tests/test_entries.toml"
    uint8_t wbuffer[1024];
    uint8_t rbuffer[1024];

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // write hi0 200
    sprintf(path, "hi0"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi1 20
    sprintf(path, "hi1"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi2 200
    sprintf(path, "hi2"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi3 200
    sprintf(path, "hi3"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi4 200
    sprintf(path, "hi4"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // read hi1 20
    sprintf(path, "hi1"); size = 20;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi1 200
    sprintf(path, "hi1"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // read hi0 200
    sprintf(path, "hi0"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi1 200
    sprintf(path, "hi1"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi2 200
    sprintf(path, "hi2"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi3 200
    sprintf(path, "hi3"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi4 200
    sprintf(path, "hi4"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case6() {
    // prologue
    __attribute__((unused)) lfs_t lfs;
    __attribute__((unused)) lfs_testbd_t bd;
    __attribute__((unused)) lfs_file_t file;
    __attribute__((unused)) lfs_dir_t dir;
    __attribute__((unused)) struct lfs_info info;
    __attribute__((unused)) char path[1024];
    __attribute__((unused)) uint8_t buffer[1024];
    __attribute__((unused)) lfs_size_t size;
    __attribute__((unused)) int err;
    
    __attribute__((unused)) const struct lfs_config cfg = {
        .context        = &bd,
        .read           = lfs_testbd_read,
        .prog           = lfs_testbd_prog,
        .erase          = lfs_testbd_erase,
        .sync           = lfs_testbd_sync,
        .read_size      = LFS_READ_SIZE,
        .prog_size      = LFS_PROG_SIZE,
        .block_size     = LFS_BLOCK_SIZE,
        .block_count    = LFS_BLOCK_COUNT,
        .block_cycles   = LFS_BLOCK_CYCLES,
        .cache_size     = LFS_CACHE_SIZE,
        .lookahead_size = LFS_LOOKAHEAD_SIZE,
    };

    __attribute__((unused)) const struct lfs_testbd_config bdcfg = {
        .erase_value        = LFS_ERASE_VALUE,
        .erase_cycles       = LFS_ERASE_CYCLES,
        .badblock_behavior  = LFS_BADBLOCK_BEHAVIOR,
        .power_cycles       = lfs_testbd_cycles,
    };

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_createcfg(&cfg, lfs_testbd_path, &bdcfg), 0);

    // test case 6
    #line 454 "tests/test_entries.toml"
    uint8_t wbuffer[1024];
    uint8_t rbuffer[1024];

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // write hi0 200
    sprintf(path, "hi0"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi1 200
    sprintf(path, "hi1"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi2 200
    sprintf(path, "hi2"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // write hi3 200
    sprintf(path, "hi3"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hi1"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "hi1", &info), LFS_ERR_NOENT);
    // read hi0 200
    sprintf(path, "hi0"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi2 200
    sprintf(path, "hi2"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi3 200
    sprintf(path, "hi3"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hi2"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "hi2", &info), LFS_ERR_NOENT);
    // read hi0 200
    sprintf(path, "hi0"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    // read hi3 200
    sprintf(path, "hi3"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hi3"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "hi3", &info), LFS_ERR_NOENT);
    // read hi0 200
    sprintf(path, "hi0"); size = 200;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hi0"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "hi0", &info), LFS_ERR_NOENT);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case7() {
    // prologue
    __attribute__((unused)) lfs_t lfs;
    __attribute__((unused)) lfs_testbd_t bd;
    __attribute__((unused)) lfs_file_t file;
    __attribute__((unused)) lfs_dir_t dir;
    __attribute__((unused)) struct lfs_info info;
    __attribute__((unused)) char path[1024];
    __attribute__((unused)) uint8_t buffer[1024];
    __attribute__((unused)) lfs_size_t size;
    __attribute__((unused)) int err;
    
    __attribute__((unused)) const struct lfs_config cfg = {
        .context        = &bd,
        .read           = lfs_testbd_read,
        .prog           = lfs_testbd_prog,
        .erase          = lfs_testbd_erase,
        .sync           = lfs_testbd_sync,
        .read_size      = LFS_READ_SIZE,
        .prog_size      = LFS_PROG_SIZE,
        .block_size     = LFS_BLOCK_SIZE,
        .block_count    = LFS_BLOCK_COUNT,
        .block_cycles   = LFS_BLOCK_CYCLES,
        .cache_size     = LFS_CACHE_SIZE,
        .lookahead_size = LFS_LOOKAHEAD_SIZE,
    };

    __attribute__((unused)) const struct lfs_testbd_config bdcfg = {
        .erase_value        = LFS_ERASE_VALUE,
        .erase_cycles       = LFS_ERASE_CYCLES,
        .badblock_behavior  = LFS_BADBLOCK_BEHAVIOR,
        .power_cycles       = lfs_testbd_cycles,
    };

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_createcfg(&cfg, lfs_testbd_path, &bdcfg), 0);

    // test case 7
    #line 552 "tests/test_entries.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    memset(path, 'm', 200);
    path[200] = '\0';

    size = 400;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    uint8_t wbuffer[1024];
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    size = 400;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    uint8_t rbuffer[1024];
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case8() {
    // prologue
    __attribute__((unused)) lfs_t lfs;
    __attribute__((unused)) lfs_testbd_t bd;
    __attribute__((unused)) lfs_file_t file;
    __attribute__((unused)) lfs_dir_t dir;
    __attribute__((unused)) struct lfs_info info;
    __attribute__((unused)) char path[1024];
    __attribute__((unused)) uint8_t buffer[1024];
    __attribute__((unused)) lfs_size_t size;
    __attribute__((unused)) int err;
    
    __attribute__((unused)) const struct lfs_config cfg = {
        .context        = &bd,
        .read           = lfs_testbd_read,
        .prog           = lfs_testbd_prog,
        .erase          = lfs_testbd_erase,
        .sync           = lfs_testbd_sync,
        .read_size      = LFS_READ_SIZE,
        .prog_size      = LFS_PROG_SIZE,
        .block_size     = LFS_BLOCK_SIZE,
        .block_count    = LFS_BLOCK_COUNT,
        .block_cycles   = LFS_BLOCK_CYCLES,
        .cache_size     = LFS_CACHE_SIZE,
        .lookahead_size = LFS_LOOKAHEAD_SIZE,
    };

    __attribute__((unused)) const struct lfs_testbd_config bdcfg = {
        .erase_value        = LFS_ERASE_VALUE,
        .erase_cycles       = LFS_ERASE_CYCLES,
        .badblock_behavior  = LFS_BADBLOCK_BEHAVIOR,
        .power_cycles       = lfs_testbd_cycles,
    };

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_createcfg(&cfg, lfs_testbd_path, &bdcfg), 0);

    // test case 8
    #line 577 "tests/test_entries.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    memset(path, 'm', 200);
    path[200] = '\0';

    size = 40;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    uint8_t wbuffer[1024];
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    size = 40;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    uint8_t rbuffer[1024];
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    size = 400;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    memset(wbuffer, 'c', size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    size = 400;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rbuffer, wbuffer, size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

const char *lfs_testbd_path;
uint32_t lfs_testbd_cycles;
int main(int argc, char **argv) {
    int case_         = (argc > 1) ? atoi(argv[1]) : 0;
    int perm          = (argc > 2) ? atoi(argv[2]) : 0;
    lfs_testbd_path   = (argc > 3) ? argv[3] : NULL;
    lfs_testbd_cycles = (argc > 4) ? atoi(argv[4]) : 0;
    extern void test_case1();
    if (argc < 3 || (case_ == 1 && perm == 1)) { test_case1(); }
    extern void test_case2();
    if (argc < 3 || (case_ == 2 && perm == 1)) { test_case2(); }
    extern void test_case3();
    if (argc < 3 || (case_ == 3 && perm == 1)) { test_case3(); }
    extern void test_case4();
    if (argc < 3 || (case_ == 4 && perm == 1)) { test_case4(); }
    extern void test_case5();
    if (argc < 3 || (case_ == 5 && perm == 1)) { test_case5(); }
    extern void test_case6();
    if (argc < 3 || (case_ == 6 && perm == 1)) { test_case6(); }
    extern void test_case7();
    if (argc < 3 || (case_ == 7 && perm == 1)) { test_case7(); }
    extern void test_case8();
    if (argc < 3 || (case_ == 8 && perm == 1)) { test_case8(); }
}
