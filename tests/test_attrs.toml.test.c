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
#line 1 "tests/test_attrs.toml.test.tc"

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
    #line 3 "tests/test_attrs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "hello"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "hello/hello", LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "hello", strlen("hello")), strlen("hello"));
    lfs_file_close(&lfs, &file);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    memset(buffer, 0, sizeof(buffer));
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "hello", 'A', "aaaa",   4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "hello", 'B', "bbbbbb", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "hello", 'C', "ccccc",  5), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'A', buffer,    4), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'B', buffer+4,  6), 6);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'C', buffer+10, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",   4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "bbbbbb", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+10, "ccccc",  5), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "hello", 'B', "", 0), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'A', buffer,    4), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'B', buffer+4,  6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'C', buffer+10, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",         4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "\0\0\0\0\0\0", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+10, "ccccc",        5), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_removeattr(&lfs, "hello", 'B'), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'A', buffer,    4), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'B', buffer+4,  6), LFS_ERR_NOATTR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'C', buffer+10, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",         4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "\0\0\0\0\0\0", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+10, "ccccc",        5), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "hello", 'B', "dddddd", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'A', buffer,    4), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'B', buffer+4,  6), 6);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'C', buffer+10, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",   4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "dddddd", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+10, "ccccc",  5), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "hello", 'B', "eee", 3), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'A', buffer,    4), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'B', buffer+4,  6), 3);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'C', buffer+10, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",      4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "eee\0\0\0", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+10, "ccccc",     5), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "hello", 'A', buffer, LFS_ATTR_MAX+1), LFS_ERR_NOSPC);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "hello", 'B', "fffffffff", 9), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'A', buffer,    4), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'B', buffer+4,  6), 9);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'C', buffer+10, 5), 5);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    memset(buffer, 0, sizeof(buffer));
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'A', buffer,    4), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'B', buffer+4,  9), 9);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello", 'C', buffer+13, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",      4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "fffffffff", 9), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+13, "ccccc",     5), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "hello/hello", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, sizeof(buffer)), strlen("hello"));
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hello", strlen("hello")), 0);
    lfs_file_close(&lfs, &file);
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
    #line 81 "tests/test_attrs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "hello"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "hello/hello", LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "hello", strlen("hello")), strlen("hello"));
    lfs_file_close(&lfs, &file);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    memset(buffer, 0, sizeof(buffer));
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "/", 'A', "aaaa",   4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "/", 'B', "bbbbbb", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "/", 'C', "ccccc",  5), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'A', buffer,    4), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'B', buffer+4,  6), 6);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'C', buffer+10, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",   4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "bbbbbb", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+10, "ccccc",  5), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "/", 'B', "", 0), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'A', buffer,    4), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'B', buffer+4,  6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'C', buffer+10, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",         4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "\0\0\0\0\0\0", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+10, "ccccc",        5), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_removeattr(&lfs, "/", 'B'), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'A', buffer,    4), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'B', buffer+4,  6), LFS_ERR_NOATTR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'C', buffer+10, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",         4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "\0\0\0\0\0\0", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+10, "ccccc",        5), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "/", 'B', "dddddd", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'A', buffer,    4), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'B', buffer+4,  6), 6);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'C', buffer+10, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",   4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "dddddd", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+10, "ccccc",  5), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "/", 'B', "eee", 3), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'A', buffer,    4), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'B', buffer+4,  6), 3);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'C', buffer+10, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",      4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "eee\0\0\0", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+10, "ccccc",     5), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "/", 'A', buffer, LFS_ATTR_MAX+1), LFS_ERR_NOSPC);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "/", 'B', "fffffffff", 9), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'A', buffer,    4), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'B', buffer+4,  6), 9);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'C', buffer+10, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    memset(buffer, 0, sizeof(buffer));
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'A', buffer,    4), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'B', buffer+4,  9), 9);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "/", 'C', buffer+13, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",      4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "fffffffff", 9), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+13, "ccccc",     5), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "hello/hello", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, sizeof(buffer)), strlen("hello"));
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hello", strlen("hello")), 0);
    lfs_file_close(&lfs, &file);
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
    #line 158 "tests/test_attrs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "hello"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "hello/hello", LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "hello", strlen("hello")), strlen("hello"));
    lfs_file_close(&lfs, &file);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    memset(buffer, 0, sizeof(buffer));
    struct lfs_attr attrs1[] = {
        {'A', buffer,    4},
        {'B', buffer+4,  6},
        {'C', buffer+10, 5},
    };
    struct lfs_file_config cfg1 = {.attrs=attrs1, .attr_count=3};

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_opencfg(&lfs, &file, "hello/hello", LFS_O_WRONLY, &cfg1), 0);
    memcpy(buffer,    "aaaa",   4);
    memcpy(buffer+4,  "bbbbbb", 6);
    memcpy(buffer+10, "ccccc",  5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    memset(buffer, 0, 15);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_opencfg(&lfs, &file, "hello/hello", LFS_O_RDONLY, &cfg1), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",   4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "bbbbbb", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+10, "ccccc",  5), 0);

    attrs1[1].size = 0;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_opencfg(&lfs, &file, "hello/hello", LFS_O_WRONLY, &cfg1), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    memset(buffer, 0, 15);
    attrs1[1].size = 6;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_opencfg(&lfs, &file, "hello/hello", LFS_O_RDONLY, &cfg1), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",         4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "\0\0\0\0\0\0", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+10, "ccccc",        5), 0);

    attrs1[1].size = 6;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_opencfg(&lfs, &file, "hello/hello", LFS_O_WRONLY, &cfg1), 0);
    memcpy(buffer+4,  "dddddd", 6);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    memset(buffer, 0, 15);
    attrs1[1].size = 6;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_opencfg(&lfs, &file, "hello/hello", LFS_O_RDONLY, &cfg1), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",   4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "dddddd", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+10, "ccccc",  5), 0);

    attrs1[1].size = 3;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_opencfg(&lfs, &file, "hello/hello", LFS_O_WRONLY, &cfg1), 0);
    memcpy(buffer+4,  "eee", 3);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    memset(buffer, 0, 15);
    attrs1[1].size = 6;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_opencfg(&lfs, &file, "hello/hello", LFS_O_RDONLY, &cfg1), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",      4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "eee\0\0\0", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+10, "ccccc",     5), 0);

    attrs1[0].size = LFS_ATTR_MAX+1;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_opencfg(&lfs, &file, "hello/hello", LFS_O_WRONLY, &cfg1)
, LFS_ERR_NOSPC);

    struct lfs_attr attrs2[] = {
        {'A', buffer,    4},
        {'B', buffer+4,  9},
        {'C', buffer+13, 5},
    };
    struct lfs_file_config cfg2 = {.attrs=attrs2, .attr_count=3};
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_opencfg(&lfs, &file, "hello/hello", LFS_O_RDWR, &cfg2), 0);
    memcpy(buffer+4,  "fffffffff", 9);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    attrs1[0].size = 4;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_opencfg(&lfs, &file, "hello/hello", LFS_O_RDONLY, &cfg1), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    memset(buffer, 0, sizeof(buffer));
    struct lfs_attr attrs3[] = {
        {'A', buffer,    4},
        {'B', buffer+4,  9},
        {'C', buffer+13, 5},
    };
    struct lfs_file_config cfg3 = {.attrs=attrs3, .attr_count=3};

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_opencfg(&lfs, &file, "hello/hello", LFS_O_RDONLY, &cfg3), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "aaaa",      4), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+4,  "fffffffff", 9), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+13, "ccccc",     5), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "hello/hello", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, sizeof(buffer)), strlen("hello"));
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hello", strlen("hello")), 0);
    lfs_file_close(&lfs, &file);
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
    #line 265 "tests/test_attrs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "hello"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "hello/hello", LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "hello", strlen("hello")), strlen("hello"));
    lfs_file_close(&lfs, &file);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "hello/hello", 'B', "fffffffff",  9), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_setattr(&lfs, "hello/hello", 'C', "ccccc",      5), 0);

    memset(buffer, 0, sizeof(buffer));
    struct lfs_attr attrs1[] = {
        {'B', "gggg", 4},
        {'C', "",     0},
        {'D', "hhhh", 4},
    };
    struct lfs_file_config cfg1 = {.attrs=attrs1, .attr_count=3};

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_opencfg(&lfs, &file, "hello/hello", LFS_O_WRONLY, &cfg1), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello/hello", 'B', buffer,    9), 9);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello/hello", 'C', buffer+9,  9), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello/hello", 'D', buffer+18, 9), LFS_ERR_NOATTR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "fffffffff",          9), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+9,  "ccccc\0\0\0\0",      9), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+18, "\0\0\0\0\0\0\0\0\0", 9), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello/hello", 'B', buffer,    9), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello/hello", 'C', buffer+9,  9), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_getattr(&lfs, "hello/hello", 'D', buffer+18, 9), 4);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer,    "gggg\0\0\0\0\0",     9), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+9,  "\0\0\0\0\0\0\0\0\0", 9), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer+18, "hhhh\0\0\0\0\0",     9), 0);

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
}
