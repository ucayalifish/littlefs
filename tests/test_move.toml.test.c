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
#line 1 "tests/test_move.toml.test.tc"

//////////////// AUTOGENERATED TEST ////////////////
#include "lfs.h"
#include "bd/lfs_testbd.h"
#include <stdio.h>
extern const char *lfs_testbd_path;
extern uint32_t lfs_testbd_cycles;

#define LFS_ERASE_CYCLES 0
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
    #line 3 "tests/test_move.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "a"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "b"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "c"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "d"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "a/hello", LFS_O_CREAT | LFS_O_WRONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "hola\n", 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "bonjour\n", 8), 8);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "ohayo\n", 6), 6);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "a/hello", "c/hello"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "a"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "c"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hello");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 5+8+6);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "a/hello", LFS_O_RDONLY), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "b/hello", LFS_O_RDONLY), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "c/hello", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hola\n", 5), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 8), 8);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "bonjour\n", 8), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 6), 6);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "ohayo\n", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "d/hello", LFS_O_RDONLY), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_ERASE_CYCLES

#define LFS_ERASE_CYCLES 0
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
    #line 60 "tests/test_move.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "hi"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "hi", "hi"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "hi/hi"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "hi/hi", "hi/hi"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "hi/hi/hi"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "hi/hi/hi", "hi/hi/hi"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "hi/hi/hi", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hi");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_ERASE_CYCLES

#define LFS_ERASE_CYCLES 0
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
    #line 341 "tests/test_move.toml"
    err = lfs_mount(&lfs, &cfg);
    if (err) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    }
    err = lfs_mkdir(&lfs, "a");
    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, !err || err == LFS_ERR_EXIST, true);
    err = lfs_mkdir(&lfs, "b");
    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, !err || err == LFS_ERR_EXIST, true);
    err = lfs_mkdir(&lfs, "c");
    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, !err || err == LFS_ERR_EXIST, true);
    err = lfs_mkdir(&lfs, "d");
    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, !err || err == LFS_ERR_EXIST, true);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    while (true) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        // there should never exist _2_ hello files
        int count = 0;
        if (lfs_stat(&lfs, "a/hello", &info) == 0) {
            __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hello");
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
            __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, info.size == 5+8+6 || info.size == 0, true);
            count += 1;
        }
        if (lfs_stat(&lfs, "b/hello", &info) == 0) {
            __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hello");
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 5+8+6);
            count += 1;
        }
        if (lfs_stat(&lfs, "c/hello", &info) == 0) {
            __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hello");
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 5+8+6);
            count += 1;
        }
        if (lfs_stat(&lfs, "d/hello", &info) == 0) {
            __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hello");
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 5+8+6);
            count += 1;
        }
        __LFS_ASSERT_INT_LE(__FILE__, __LINE__, count, 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        if (lfs_stat(&lfs, "a/hello", &info) == 0 && info.size > 0) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "a/hello", "b/hello"), 0);
        } else if (lfs_stat(&lfs, "b/hello", &info) == 0) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "b/hello", "c/hello"), 0);
        } else if (lfs_stat(&lfs, "c/hello", &info) == 0) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "c/hello", "d/hello"), 0);
        } else if (lfs_stat(&lfs, "d/hello", &info) == 0) {
            // success
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
            break;
        } else {
            // create file
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "a/hello",
                    LFS_O_WRONLY | LFS_O_CREAT), 0);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "hola\n", 5), 5);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "bonjour\n", 8), 8);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "ohayo\n", 6), 6);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "a"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "d"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hello");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 5+8+6);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "a/hello", LFS_O_RDONLY), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "b/hello", LFS_O_RDONLY), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "c/hello", LFS_O_RDONLY), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "d/hello", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hola\n", 5), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 8), 8);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "bonjour\n", 8), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 6), 6);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "ohayo\n", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_ERASE_CYCLES

#define LFS_ERASE_CYCLES 0
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
    #line 450 "tests/test_move.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "a"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "b"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "c"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "d"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "a/hi"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "a/hi/hola"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "a/hi/bonjour"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "a/hi/ohayo"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "a/hi", "c/hi"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "a"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "c"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hi");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "a/hi"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "b/hi"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "c/hi"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "bonjour");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hola");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "ohayo");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "d/hi"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_ERASE_CYCLES

#define LFS_ERASE_CYCLES 0
void test_case11() {
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

    // test case 11
    #line 804 "tests/test_move.toml"
    err = lfs_mount(&lfs, &cfg);
    if (err) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    }
    err = lfs_mkdir(&lfs, "a");
    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, !err || err == LFS_ERR_EXIST, true);
    err = lfs_mkdir(&lfs, "b");
    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, !err || err == LFS_ERR_EXIST, true);
    err = lfs_mkdir(&lfs, "c");
    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, !err || err == LFS_ERR_EXIST, true);
    err = lfs_mkdir(&lfs, "d");
    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, !err || err == LFS_ERR_EXIST, true);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    while (true) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        // there should never exist _2_ hi directories
        int count = 0;
        if (lfs_stat(&lfs, "a/hi", &info) == 0) {
            __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hi");
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
            count += 1;
        }
        if (lfs_stat(&lfs, "b/hi", &info) == 0) {
            __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hi");
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
            count += 1;
        }
        if (lfs_stat(&lfs, "c/hi", &info) == 0) {
            __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hi");
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
            count += 1;
        }
        if (lfs_stat(&lfs, "d/hi", &info) == 0) {
            __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hi");
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
            count += 1;
        }
        __LFS_ASSERT_INT_LE(__FILE__, __LINE__, count, 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        if (lfs_stat(&lfs, "a/hi", &info) == 0) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "a/hi", "b/hi"), 0);
        } else if (lfs_stat(&lfs, "b/hi", &info) == 0) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "b/hi", "c/hi"), 0);
        } else if (lfs_stat(&lfs, "c/hi", &info) == 0) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "c/hi", "d/hi"), 0);
        } else if (lfs_stat(&lfs, "d/hi", &info) == 0) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
            break; // success
        } else {
            // create dir and rename for atomicity
            err = lfs_mkdir(&lfs, "temp");
            __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, !err || err == LFS_ERR_EXIST, true);
            err = lfs_mkdir(&lfs, "temp/hola");
            __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, !err || err == LFS_ERR_EXIST, true);
            err = lfs_mkdir(&lfs, "temp/bonjour");
            __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, !err || err == LFS_ERR_EXIST, true);
            err = lfs_mkdir(&lfs, "temp/ohayo");
            __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, !err || err == LFS_ERR_EXIST, true);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "temp", "a/hi"), 0);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "a"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "d"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hi");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "a/hi"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "b/hi"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "c/hi"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "d/hi"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "bonjour");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hola");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "ohayo");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_ERASE_CYCLES

#define LFS_ERASE_CYCLES 0
void test_case12() {
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

    // test case 12
    #line 920 "tests/test_move.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "a"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "b"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "c"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "d"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "a/hello", LFS_O_CREAT | LFS_O_WRONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "hola\n", 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "bonjour\n", 8), 8);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "ohayo\n", 6), 6);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "a/hello", "b/hello"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "b/hello", "c/hello"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "c/hello", "d/hello"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "a/hello", LFS_O_RDONLY), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "b/hello", LFS_O_RDONLY), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "c/hello", LFS_O_RDONLY), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "d/hello", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hola\n", 5), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 8), 8);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "bonjour\n", 8), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 6), 6);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "ohayo\n", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "b"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "c"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "a", &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "b", &info), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "c", &info), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "d", &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "a/hello", LFS_O_RDONLY), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "b/hello", LFS_O_RDONLY), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "c/hello", LFS_O_RDONLY), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "d/hello", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 5), 5);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hola\n", 5), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 8), 8);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "bonjour\n", 8), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 6), 6);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "ohayo\n", 6), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_ERASE_CYCLES

#define LFS_ERASE_CYCLES 0
void test_case13() {
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

    // test case 13
    #line 984 "tests/test_move.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // littlefs keeps files sorted, so we know the order these will be in
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/1.move_me",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/0.before",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "test.1", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/2.in_between",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "test.2", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/4.after",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "test.3", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    lfs_file_t files[3];
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[0], "0.before",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[1], "2.in_between",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[2], "4.after",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[0], "test.4", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[1], "test.5", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[2], "test.6", 7), 7);

    // rename file while everything is open, this triggers both
    // a create and delete simultaneously
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "/1.move_me", "/3.move_me"), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[0]), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[1]), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[2]), 0);

    // check that nothing was corrupted
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "0.before");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "2.in_between");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "3.move_me");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "4.after");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/0.before", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.4");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/2.in_between", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.5");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/4.after", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.6");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // now move back
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[0], "0.before",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[1], "2.in_between",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[2], "4.after",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[0], "test.7", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[1], "test.8", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[2], "test.9", 7), 7);

    // rename file while everything is open, this triggers both
    // a create and delete simultaneously
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "/3.move_me", "/1.move_me"), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[0]), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[1]), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[2]), 0);

    // and check that nothing was corrupted again
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "0.before");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "1.move_me");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "2.in_between");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "4.after");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/0.before", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.7");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/2.in_between", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.8");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/4.after", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.9");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_ERASE_CYCLES

#define LFS_ERASE_CYCLES 0
void test_case14() {
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

    // test case 14
    #line 1130 "tests/test_move.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // littlefs keeps files sorted, so we know the order these will be in
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/1.move_me",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/3.move_me",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "remove me",
            sizeof("remove me")), sizeof("remove me"));
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/0.before",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "test.1", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/2.in_between",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "test.2", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/4.after",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "test.3", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    lfs_file_t files[3];
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[0], "0.before",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[1], "2.in_between",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[2], "4.after",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[0], "test.4", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[1], "test.5", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[2], "test.6", 7), 7);

    // rename file while everything is open, this triggers both
    // a create and delete simultaneously
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "/1.move_me", "/3.move_me"), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[0]), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[1]), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[2]), 0);

    // check that nothing was corrupted
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "0.before");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "2.in_between");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "3.move_me");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "4.after");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/0.before", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.4");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/2.in_between", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.5");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/4.after", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.6");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // now move back
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/1.move_me",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "remove me",
            sizeof("remove me")), sizeof("remove me"));
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[0], "0.before",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[1], "2.in_between",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[2], "4.after",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[0], "test.7", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[1], "test.8", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[2], "test.9", 7), 7);

    // rename file while everything is open, this triggers both
    // a create and delete simultaneously
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "/3.move_me", "/1.move_me"), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[0]), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[1]), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[2]), 0);

    // and check that nothing was corrupted again
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "0.before");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "1.move_me");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "2.in_between");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "4.after");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/0.before", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.7");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/2.in_between", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.8");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/4.after", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.9");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_ERASE_CYCLES

#define LFS_ERASE_CYCLES 0
void test_case15() {
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

    // test case 15
    #line 1286 "tests/test_move.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // littlefs keeps files sorted, so we know the order these will be in
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "/dir.1"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "/dir.2"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.1/1.move_me",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.2/1.move_me",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "remove me",
            sizeof("remove me")), sizeof("remove me"));
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.1/0.before",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "test.1", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.1/2.after",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "test.2", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.2/0.before",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "test.3", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.2/2.after",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "test.4", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    lfs_file_t files[4];
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[0], "/dir.1/0.before",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[1], "/dir.1/2.after",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[2], "/dir.2/0.before",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[3], "/dir.2/2.after",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[0], "test.5", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[1], "test.6", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[2], "test.7", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[3], "test.8", 7), 7);

    // rename file while everything is open, this triggers both
    // a create and delete as it overwrites the destination file
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "/dir.1/1.move_me", "/dir.2/1.move_me"), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[0]), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[1]), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[2]), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[3]), 0);

    // check that nothing was corrupted
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "dir.1");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "dir.2");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/dir.1"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "0.before");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "2.after");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/dir.2"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "0.before");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "1.move_me");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "2.after");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.1/0.before", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.5");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.1/2.after", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.6");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.2/0.before", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.7");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.2/2.after", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.8");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // now move back
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.1/1.move_me",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "remove me",
            sizeof("remove me")), sizeof("remove me"));
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[0], "/dir.1/0.before",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[1], "/dir.1/2.after",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[2], "/dir.2/0.before",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[3], "/dir.2/2.after",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[0], "test.9", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[1], "test.a", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[2], "test.b", 7), 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[3], "test.c", 7), 7);

    // rename file while everything is open, this triggers both
    // a create and delete simultaneously
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "/dir.2/1.move_me", "/dir.1/1.move_me"), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[0]), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[1]), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[2]), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[3]), 0);

    // and check that nothing was corrupted again
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "dir.1");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "dir.2");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/dir.1"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "0.before");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "1.move_me");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "2.after");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/dir.2"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "0.before");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "2.after");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, 7);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.1/0.before", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.9");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.1/2.after", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.a");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.2/0.before", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.b");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/dir.2/2.after", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 7), 7);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "test.c");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_ERASE_CYCLES

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
    extern void test_case9();
    if (argc < 3 || (case_ == 9 && perm == 1)) { test_case9(); }
    extern void test_case10();
    if (argc < 3 || (case_ == 10 && perm == 1)) { test_case10(); }
    extern void test_case11();
    if (argc < 3 || (case_ == 11 && perm == 1)) { test_case11(); }
    extern void test_case12();
    if (argc < 3 || (case_ == 12 && perm == 1)) { test_case12(); }
    extern void test_case13();
    if (argc < 3 || (case_ == 13 && perm == 1)) { test_case13(); }
    extern void test_case14();
    if (argc < 3 || (case_ == 14 && perm == 1)) { test_case14(); }
    extern void test_case15();
    if (argc < 3 || (case_ == 15 && perm == 1)) { test_case15(); }
    extern void test_case16(intmax_t RELOCATIONS);
    if (argc < 3 || (case_ == 16 && perm == 1)) { test_case16(0); }
    extern void test_case16(intmax_t RELOCATIONS);
    if (argc < 3 || (case_ == 16 && perm == 2)) { test_case16(1); }
    extern void test_case16(intmax_t RELOCATIONS);
    if (argc < 3 || (case_ == 16 && perm == 3)) { test_case16(2); }
    extern void test_case16(intmax_t RELOCATIONS);
    if (argc < 3 || (case_ == 16 && perm == 4)) { test_case16(3); }
    extern void test_case17(intmax_t RELOCATIONS);
    if (argc < 3 || (case_ == 17 && perm == 1)) { test_case17(0); }
    extern void test_case17(intmax_t RELOCATIONS);
    if (argc < 3 || (case_ == 17 && perm == 2)) { test_case17(1); }
    extern void test_case17(intmax_t RELOCATIONS);
    if (argc < 3 || (case_ == 17 && perm == 3)) { test_case17(2); }
    extern void test_case17(intmax_t RELOCATIONS);
    if (argc < 3 || (case_ == 17 && perm == 4)) { test_case17(3); }
    extern void test_case17(intmax_t RELOCATIONS);
    if (argc < 3 || (case_ == 17 && perm == 5)) { test_case17(4); }
    extern void test_case17(intmax_t RELOCATIONS);
    if (argc < 3 || (case_ == 17 && perm == 6)) { test_case17(5); }
    extern void test_case17(intmax_t RELOCATIONS);
    if (argc < 3 || (case_ == 17 && perm == 7)) { test_case17(6); }
    extern void test_case17(intmax_t RELOCATIONS);
    if (argc < 3 || (case_ == 17 && perm == 8)) { test_case17(7); }
}
