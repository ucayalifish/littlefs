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
#line 1 "tests/test_dirs.toml.test.tc"

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
    #line 3 "tests/test_dirs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case2(
        __attribute__((unused)) intmax_t N) {
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
    #line 20 "tests/test_dirs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int i = 0; i < N; i++) {
        sprintf(path, "dir%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, path), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    for (int i = 0; i < N; i++) {
        sprintf(path, "dir%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case3(
        __attribute__((unused)) intmax_t N) {
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
    #line 51 "tests/test_dirs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int i = 0; i < N; i++) {
        sprintf(path, "removeme%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, path), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    for (int i = 0; i < N; i++) {
        sprintf(path, "removeme%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    lfs_unmount(&lfs);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int i = 0; i < N; i++) {
        sprintf(path, "removeme%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, path), 0);
    }
    lfs_unmount(&lfs);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case4(
        __attribute__((unused)) intmax_t N) {
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
    #line 101 "tests/test_dirs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int i = 0; i < N; i++) {
        sprintf(path, "test%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, path), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    for (int i = 0; i < N; i++) {
        sprintf(path, "test%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    lfs_unmount(&lfs);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int i = 0; i < N; i++) {
        char oldpath[128];
        char newpath[128];
        sprintf(oldpath, "test%03d", i);
        sprintf(newpath, "tedd%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, oldpath, newpath), 0);
    }
    lfs_unmount(&lfs);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    for (int i = 0; i < N; i++) {
        sprintf(path, "tedd%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    lfs_unmount(&lfs);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case5(
        __attribute__((unused)) intmax_t N) {
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
    #line 161 "tests/test_dirs.toml"
    err = lfs_mount(&lfs, &cfg);
    if (err) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    }

    for (int i = 0; i < N; i++) {
        sprintf(path, "hi%03d", i);
        err = lfs_mkdir(&lfs, path);
        __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == 0 || err == LFS_ERR_EXIST, true);
    }

    for (int i = 0; i < N; i++) {
        sprintf(path, "hello%03d", i);
        err = lfs_remove(&lfs, path);
        __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == 0 || err == LFS_ERR_NOENT, true);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    for (int i = 0; i < N; i++) {
        sprintf(path, "hi%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    for (int i = 0; i < N; i++) {
        char oldpath[128];
        char newpath[128];
        sprintf(oldpath, "hi%03d", i);
        sprintf(newpath, "hello%03d", i);
        // YES this can overwrite an existing newpath
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, oldpath, newpath), 0);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    for (int i = 0; i < N; i++) {
        sprintf(path, "hello%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    for (int i = 0; i < N; i++) {
        sprintf(path, "hello%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, path), 0);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case6(
        __attribute__((unused)) intmax_t N) {
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
    #line 240 "tests/test_dirs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int i = 0; i < N; i++) {
        sprintf(path, "file%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
                LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    for (int i = 0; i < N; i++) {
        sprintf(path, "file%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    lfs_unmount(&lfs);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case7(
        __attribute__((unused)) intmax_t N) {
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
    #line 273 "tests/test_dirs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int i = 0; i < N; i++) {
        sprintf(path, "removeme%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
                LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    for (int i = 0; i < N; i++) {
        sprintf(path, "removeme%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    lfs_unmount(&lfs);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int i = 0; i < N; i++) {
        sprintf(path, "removeme%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, path), 0);
    }
    lfs_unmount(&lfs);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case8(
        __attribute__((unused)) intmax_t N) {
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
    #line 325 "tests/test_dirs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int i = 0; i < N; i++) {
        sprintf(path, "test%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
                LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    for (int i = 0; i < N; i++) {
        sprintf(path, "test%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    lfs_unmount(&lfs);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int i = 0; i < N; i++) {
        char oldpath[128];
        char newpath[128];
        sprintf(oldpath, "test%03d", i);
        sprintf(newpath, "tedd%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, oldpath, newpath), 0);
    }
    lfs_unmount(&lfs);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    for (int i = 0; i < N; i++) {
        sprintf(path, "tedd%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    lfs_unmount(&lfs);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case9(
        __attribute__((unused)) intmax_t N) {
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

    // test case 9
    #line 387 "tests/test_dirs.toml"
    err = lfs_mount(&lfs, &cfg);
    if (err) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    }

    for (int i = 0; i < N; i++) {
        sprintf(path, "hi%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_CREAT | LFS_O_WRONLY), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }

    for (int i = 0; i < N; i++) {
        sprintf(path, "hello%03d", i);
        err = lfs_remove(&lfs, path);
        __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == 0 || err == LFS_ERR_NOENT, true);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    for (int i = 0; i < N; i++) {
        sprintf(path, "hi%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    for (int i = 0; i < N; i++) {
        char oldpath[128];
        char newpath[128];
        sprintf(oldpath, "hi%03d", i);
        sprintf(newpath, "hello%03d", i);
        // YES this can overwrite an existing newpath
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, oldpath, newpath), 0);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    for (int i = 0; i < N; i++) {
        sprintf(path, "hello%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    for (int i = 0; i < N; i++) {
        sprintf(path, "hello%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, path), 0);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case10() {
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

    // test case 10
    #line 465 "tests/test_dirs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "potato"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "burito",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "potato/baked"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "potato/sweet"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "potato/fried"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "potato"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "baked");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "fried");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "sweet");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // try removing?
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "potato"), LFS_ERR_NOTEMPTY);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // try renaming?
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "potato", "coldpotato"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "coldpotato", "warmpotato"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "warmpotato", "hotpotato"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "potato"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "coldpotato"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "warmpotato"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hotpotato"), LFS_ERR_NOTEMPTY);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // try cross-directory renaming
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coldpotato"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "hotpotato/baked", "coldpotato/baked"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "coldpotato", "hotpotato"), LFS_ERR_NOTEMPTY);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "coldpotato"), LFS_ERR_NOTEMPTY);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hotpotato"), LFS_ERR_NOTEMPTY);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "hotpotato/fried", "coldpotato/fried"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "coldpotato", "hotpotato"), LFS_ERR_NOTEMPTY);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "coldpotato"), LFS_ERR_NOTEMPTY);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hotpotato"), LFS_ERR_NOTEMPTY);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "hotpotato/sweet", "coldpotato/sweet"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_rename(&lfs, "coldpotato", "hotpotato"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "coldpotato"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hotpotato"), LFS_ERR_NOTEMPTY);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "hotpotato"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "baked");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "fried");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "sweet");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    
    // final remove
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hotpotato"), LFS_ERR_NOTEMPTY);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hotpotato/baked"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hotpotato"), LFS_ERR_NOTEMPTY);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hotpotato/fried"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hotpotato"), LFS_ERR_NOTEMPTY);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hotpotato/sweet"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "hotpotato"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "burito");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case11(
        __attribute__((unused)) intmax_t N) {
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
    #line 590 "tests/test_dirs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "prickly-pear"), 0);
    for (int i = 0; i < N; i++) {
        sprintf(path, "prickly-pear/cactus%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, path), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "prickly-pear"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    for (int i = 0; i < N; i++) {
        sprintf(path, "cactus%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    lfs_unmount(&lfs);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "prickly-pear"), LFS_ERR_NOTEMPTY);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "prickly-pear"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    for (int i = 0; i < N; i++) {
        sprintf(path, "cactus%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
        sprintf(path, "prickly-pear/%s", info.name);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, path), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "prickly-pear"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "prickly-pear"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "prickly-pear"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

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
    #line 646 "tests/test_dirs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "potato"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "burito",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "potato"), LFS_ERR_EXIST);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "burito"), LFS_ERR_EXIST);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "burito",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), LFS_ERR_EXIST);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "potato",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), LFS_ERR_EXIST);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "tomato"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "burito"), LFS_ERR_NOTDIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "tomato", LFS_O_RDONLY), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "potato", LFS_O_RDONLY), LFS_ERR_ISDIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "tomato", LFS_O_WRONLY), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "potato", LFS_O_WRONLY), LFS_ERR_ISDIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "potato",
            LFS_O_WRONLY | LFS_O_CREAT), LFS_ERR_ISDIR);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "/"), LFS_ERR_EXIST);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), LFS_ERR_EXIST);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/", LFS_O_RDONLY), LFS_ERR_ISDIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/", LFS_O_WRONLY), LFS_ERR_ISDIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/",
            LFS_O_WRONLY | LFS_O_CREAT), LFS_ERR_ISDIR);

    // check that errors did not corrupt directory
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "burito");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "potato");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // or on disk
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "burito");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "potato");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case13(
        __attribute__((unused)) intmax_t COUNT) {
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
    #line 721 "tests/test_dirs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "hello"), 0);
    for (int i = 0; i < COUNT; i++) {
        sprintf(path, "hello/kitty%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, path), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    for (int j = 2; j < COUNT; j++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "hello"), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);

        lfs_soff_t pos;
        for (int i = 0; i < j; i++) {
            sprintf(path, "kitty%03d", i);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
            __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
            pos = lfs_dir_tell(&lfs, &dir);
            __LFS_ASSERT_INT_GE(__FILE__, __LINE__, pos, 0);
        }

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_seek(&lfs, &dir, pos), 0);
        sprintf(path, "kitty%03d", j);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_rewind(&lfs, &dir), 0);
        sprintf(path, "kitty%03d", 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_seek(&lfs, &dir, pos), 0);
        sprintf(path, "kitty%03d", j);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    }

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case14(
        __attribute__((unused)) intmax_t COUNT) {
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
    #line 782 "tests/test_dirs.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int i = 0; i < COUNT; i++) {
        sprintf(path, "hi%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, path), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    for (int j = 2; j < COUNT; j++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);

        lfs_soff_t pos;
        for (int i = 0; i < j; i++) {
            sprintf(path, "hi%03d", i);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
            __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
            pos = lfs_dir_tell(&lfs, &dir);
            __LFS_ASSERT_INT_GE(__FILE__, __LINE__, pos, 0);
        }

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_seek(&lfs, &dir, pos), 0);
        sprintf(path, "hi%03d", j);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_rewind(&lfs, &dir), 0);
        sprintf(path, "hi%03d", 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_seek(&lfs, &dir, pos), 0);
        sprintf(path, "hi%03d", j);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    }

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
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 1)) { test_case2(0); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 2)) { test_case2(3); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 3)) { test_case2(6); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 4)) { test_case2(9); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 5)) { test_case2(12); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 6)) { test_case2(15); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 7)) { test_case2(18); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 8)) { test_case2(21); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 9)) { test_case2(24); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 10)) { test_case2(27); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 11)) { test_case2(30); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 12)) { test_case2(33); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 13)) { test_case2(36); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 14)) { test_case2(39); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 15)) { test_case2(42); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 16)) { test_case2(45); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 17)) { test_case2(48); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 18)) { test_case2(51); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 19)) { test_case2(54); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 20)) { test_case2(57); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 21)) { test_case2(60); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 22)) { test_case2(63); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 23)) { test_case2(66); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 24)) { test_case2(69); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 25)) { test_case2(72); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 26)) { test_case2(75); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 27)) { test_case2(78); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 28)) { test_case2(81); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 29)) { test_case2(84); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 30)) { test_case2(87); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 31)) { test_case2(90); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 32)) { test_case2(93); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 33)) { test_case2(96); }
    extern void test_case2(intmax_t N);
    if (argc < 3 || (case_ == 2 && perm == 34)) { test_case2(99); }
    extern void test_case3(intmax_t N);
    if (argc < 3 || (case_ == 3 && perm == 1)) { test_case3(3); }
    extern void test_case3(intmax_t N);
    if (argc < 3 || (case_ == 3 && perm == 2)) { test_case3(14); }
    extern void test_case3(intmax_t N);
    if (argc < 3 || (case_ == 3 && perm == 3)) { test_case3(25); }
    extern void test_case3(intmax_t N);
    if (argc < 3 || (case_ == 3 && perm == 4)) { test_case3(36); }
    extern void test_case3(intmax_t N);
    if (argc < 3 || (case_ == 3 && perm == 5)) { test_case3(47); }
    extern void test_case3(intmax_t N);
    if (argc < 3 || (case_ == 3 && perm == 6)) { test_case3(58); }
    extern void test_case3(intmax_t N);
    if (argc < 3 || (case_ == 3 && perm == 7)) { test_case3(69); }
    extern void test_case3(intmax_t N);
    if (argc < 3 || (case_ == 3 && perm == 8)) { test_case3(80); }
    extern void test_case3(intmax_t N);
    if (argc < 3 || (case_ == 3 && perm == 9)) { test_case3(91); }
    extern void test_case4(intmax_t N);
    if (argc < 3 || (case_ == 4 && perm == 1)) { test_case4(3); }
    extern void test_case4(intmax_t N);
    if (argc < 3 || (case_ == 4 && perm == 2)) { test_case4(14); }
    extern void test_case4(intmax_t N);
    if (argc < 3 || (case_ == 4 && perm == 3)) { test_case4(25); }
    extern void test_case4(intmax_t N);
    if (argc < 3 || (case_ == 4 && perm == 4)) { test_case4(36); }
    extern void test_case4(intmax_t N);
    if (argc < 3 || (case_ == 4 && perm == 5)) { test_case4(47); }
    extern void test_case4(intmax_t N);
    if (argc < 3 || (case_ == 4 && perm == 6)) { test_case4(58); }
    extern void test_case4(intmax_t N);
    if (argc < 3 || (case_ == 4 && perm == 7)) { test_case4(69); }
    extern void test_case4(intmax_t N);
    if (argc < 3 || (case_ == 4 && perm == 8)) { test_case4(80); }
    extern void test_case4(intmax_t N);
    if (argc < 3 || (case_ == 4 && perm == 9)) { test_case4(91); }
    extern void test_case5(intmax_t N);
    if (argc < 3 || (case_ == 5 && perm == 1)) { test_case5(5); }
    extern void test_case5(intmax_t N);
    if (argc < 3 || (case_ == 5 && perm == 2)) { test_case5(11); }
    extern void test_case6(intmax_t N);
    if (argc < 3 || (case_ == 6 && perm == 1)) { test_case6(3); }
    extern void test_case6(intmax_t N);
    if (argc < 3 || (case_ == 6 && perm == 2)) { test_case6(14); }
    extern void test_case6(intmax_t N);
    if (argc < 3 || (case_ == 6 && perm == 3)) { test_case6(25); }
    extern void test_case6(intmax_t N);
    if (argc < 3 || (case_ == 6 && perm == 4)) { test_case6(36); }
    extern void test_case6(intmax_t N);
    if (argc < 3 || (case_ == 6 && perm == 5)) { test_case6(47); }
    extern void test_case6(intmax_t N);
    if (argc < 3 || (case_ == 6 && perm == 6)) { test_case6(58); }
    extern void test_case6(intmax_t N);
    if (argc < 3 || (case_ == 6 && perm == 7)) { test_case6(69); }
    extern void test_case6(intmax_t N);
    if (argc < 3 || (case_ == 6 && perm == 8)) { test_case6(80); }
    extern void test_case6(intmax_t N);
    if (argc < 3 || (case_ == 6 && perm == 9)) { test_case6(91); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 1)) { test_case7(0); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 2)) { test_case7(3); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 3)) { test_case7(6); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 4)) { test_case7(9); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 5)) { test_case7(12); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 6)) { test_case7(15); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 7)) { test_case7(18); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 8)) { test_case7(21); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 9)) { test_case7(24); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 10)) { test_case7(27); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 11)) { test_case7(30); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 12)) { test_case7(33); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 13)) { test_case7(36); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 14)) { test_case7(39); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 15)) { test_case7(42); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 16)) { test_case7(45); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 17)) { test_case7(48); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 18)) { test_case7(51); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 19)) { test_case7(54); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 20)) { test_case7(57); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 21)) { test_case7(60); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 22)) { test_case7(63); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 23)) { test_case7(66); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 24)) { test_case7(69); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 25)) { test_case7(72); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 26)) { test_case7(75); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 27)) { test_case7(78); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 28)) { test_case7(81); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 29)) { test_case7(84); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 30)) { test_case7(87); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 31)) { test_case7(90); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 32)) { test_case7(93); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 33)) { test_case7(96); }
    extern void test_case7(intmax_t N);
    if (argc < 3 || (case_ == 7 && perm == 34)) { test_case7(99); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 1)) { test_case8(0); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 2)) { test_case8(3); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 3)) { test_case8(6); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 4)) { test_case8(9); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 5)) { test_case8(12); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 6)) { test_case8(15); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 7)) { test_case8(18); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 8)) { test_case8(21); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 9)) { test_case8(24); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 10)) { test_case8(27); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 11)) { test_case8(30); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 12)) { test_case8(33); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 13)) { test_case8(36); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 14)) { test_case8(39); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 15)) { test_case8(42); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 16)) { test_case8(45); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 17)) { test_case8(48); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 18)) { test_case8(51); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 19)) { test_case8(54); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 20)) { test_case8(57); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 21)) { test_case8(60); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 22)) { test_case8(63); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 23)) { test_case8(66); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 24)) { test_case8(69); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 25)) { test_case8(72); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 26)) { test_case8(75); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 27)) { test_case8(78); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 28)) { test_case8(81); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 29)) { test_case8(84); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 30)) { test_case8(87); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 31)) { test_case8(90); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 32)) { test_case8(93); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 33)) { test_case8(96); }
    extern void test_case8(intmax_t N);
    if (argc < 3 || (case_ == 8 && perm == 34)) { test_case8(99); }
    extern void test_case9(intmax_t N);
    if (argc < 3 || (case_ == 9 && perm == 1)) { test_case9(5); }
    extern void test_case9(intmax_t N);
    if (argc < 3 || (case_ == 9 && perm == 2)) { test_case9(25); }
    extern void test_case10();
    if (argc < 3 || (case_ == 10 && perm == 1)) { test_case10(); }
    extern void test_case11(intmax_t N);
    if (argc < 3 || (case_ == 11 && perm == 1)) { test_case11(10); }
    extern void test_case11(intmax_t N);
    if (argc < 3 || (case_ == 11 && perm == 2)) { test_case11(100); }
    extern void test_case12();
    if (argc < 3 || (case_ == 12 && perm == 1)) { test_case12(); }
    extern void test_case13(intmax_t COUNT);
    if (argc < 3 || (case_ == 13 && perm == 1)) { test_case13(4); }
    extern void test_case13(intmax_t COUNT);
    if (argc < 3 || (case_ == 13 && perm == 2)) { test_case13(128); }
    extern void test_case13(intmax_t COUNT);
    if (argc < 3 || (case_ == 13 && perm == 3)) { test_case13(132); }
    extern void test_case14(intmax_t COUNT);
    if (argc < 3 || (case_ == 14 && perm == 1)) { test_case14(4); }
    extern void test_case14(intmax_t COUNT);
    if (argc < 3 || (case_ == 14 && perm == 2)) { test_case14(128); }
    extern void test_case14(intmax_t COUNT);
    if (argc < 3 || (case_ == 14 && perm == 3)) { test_case14(132); }
}
