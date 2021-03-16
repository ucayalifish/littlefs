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
#line 1 "tests/test_paths.toml.test.tc"

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
    #line 4 "tests/test_paths.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/hottea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/warmtea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/coldtea"), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "tea/hottea", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "/tea/hottea", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "/milk"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "/milk", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "milk");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "milk", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "milk");
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
    #line 26 "tests/test_paths.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/hottea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/warmtea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/coldtea"), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "/tea/hottea", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "//tea//hottea", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "///tea///hottea", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "////milk"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "////milk", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "milk");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "milk", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "milk");
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
    #line 50 "tests/test_paths.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/hottea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/warmtea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/coldtea"), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "./tea/hottea", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "/./tea/hottea", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "/././tea/hottea", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "/./tea/./hottea", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "/./milk"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "/./milk", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "milk");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "milk", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "milk");
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
    #line 76 "tests/test_paths.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/hottea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/warmtea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/coldtea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee/hotcoffee"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee/warmcoffee"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee/coldcoffee"), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "coffee/../tea/hottea", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "tea/coldtea/../hottea", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "coffee/coldcoffee/../../tea/hottea", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "coffee/../coffee/../tea/hottea", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee/../milk"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "coffee/../milk", &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, strcmp(info.name, "milk"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "milk", &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, strcmp(info.name, "milk"), 0);
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
    #line 106 "tests/test_paths.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/hottea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/warmtea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/coldtea"), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "tea/hottea/", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "tea/hottea/.", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "tea/hottea/./.", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "hottea");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "tea/hottea/..", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "tea");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "tea/hottea/../.", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "tea");
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
    #line 128 "tests/test_paths.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, ".milk"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, ".milk", &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, strcmp(info.name, ".milk"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "tea/.././.milk", &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, strcmp(info.name, ".milk"), 0);
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
    #line 140 "tests/test_paths.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/hottea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/warmtea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "tea/coldtea"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee/hotcoffee"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee/warmcoffee"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee/coldcoffee"), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "coffee/../../../../../../tea/hottea", &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, strcmp(info.name, "hottea"), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee/../../../../../../milk"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "coffee/../../../../../../milk", &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, strcmp(info.name, "milk"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "milk", &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, strcmp(info.name, "milk"), 0);
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
    #line 164 "tests/test_paths.toml"
    lfs_format(&lfs, &cfg);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "dirt", &info), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "dirt/ground", &info), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "dirt/ground/earth", &info), LFS_ERR_NOENT);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "dirt"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "dirt/ground"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "dirt/ground/earth"), LFS_ERR_NOENT);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "dirt/ground"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "dirt/ground", LFS_O_WRONLY | LFS_O_CREAT)
, LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "dirt/ground/earth"), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "dirt/ground/earth", LFS_O_WRONLY | LFS_O_CREAT)
, LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case9() {
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
    #line 185 "tests/test_paths.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "/", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "/");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "/"), LFS_ERR_EXIST);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "/", LFS_O_WRONLY | LFS_O_CREAT)
, LFS_ERR_ISDIR);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "/"), LFS_ERR_INVAL);
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
    #line 201 "tests/test_paths.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "/", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "/");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "/");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, ".", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "/");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "..", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "/");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "//", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "/");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "./", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "/");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

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
    #line 226 "tests/test_paths.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "littlefs", &info), LFS_ERR_NOENT);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "littlefs"), LFS_ERR_NOENT);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "littlefs"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "littlefs", &info), 0);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "littlefs");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "littlefs"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, "littlefs", &info), LFS_ERR_NOENT);
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
    #line 242 "tests/test_paths.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee/hotcoffee"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee/warmcoffee"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee/coldcoffee"), 0);

    memset(path, 'w', LFS_NAME_MAX+1);
    path[LFS_NAME_MAX+1] = '\0';
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, path), LFS_ERR_NAMETOOLONG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_WRONLY | LFS_O_CREAT)
, LFS_ERR_NAMETOOLONG);

    memcpy(path, "coffee/", strlen("coffee/"));
    memset(path+strlen("coffee/"), 'w', LFS_NAME_MAX+1);
    path[strlen("coffee/")+LFS_NAME_MAX+1] = '\0';
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, path), LFS_ERR_NAMETOOLONG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_WRONLY | LFS_O_CREAT)
, LFS_ERR_NAMETOOLONG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

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
    #line 266 "tests/test_paths.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee/hotcoffee"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee/warmcoffee"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "coffee/coldcoffee"), 0);

    memset(path, 'w', LFS_NAME_MAX);
    path[LFS_NAME_MAX] = '\0';
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, path), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, path), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, path), 0);

    memcpy(path, "coffee/", strlen("coffee/"));
    memset(path+strlen("coffee/"), 'w', LFS_NAME_MAX);
    path[strlen("coffee/")+LFS_NAME_MAX] = '\0';
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, path), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, path), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, path), 0);
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
}
