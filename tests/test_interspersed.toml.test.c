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
#line 1 "tests/test_interspersed.toml.test.tc"

//////////////// AUTOGENERATED TEST ////////////////
#include "lfs.h"
#include "bd/lfs_testbd.h"
#include <stdio.h>
extern const char *lfs_testbd_path;
extern uint32_t lfs_testbd_cycles;

void test_case1(
        __attribute__((unused)) intmax_t FILES,
        __attribute__((unused)) intmax_t SIZE) {
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
    #line 6 "tests/test_interspersed.toml"
    lfs_file_t files[FILES];
    const char alphas[] = "abcdefghijklmnopqrstuvwxyz";
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int j = 0; j < FILES; j++) {
        sprintf(path, "%c", alphas[j]);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[j], path,
                LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), 0);
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < FILES; j++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[j], &alphas[j], 1), 1);
        }
    }

    for (int j = 0; j < FILES; j++) {
        lfs_file_close(&lfs, &files[j]);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    for (int j = 0; j < FILES; j++) {
        sprintf(path, "%c", alphas[j]);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, SIZE);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    for (int j = 0; j < FILES; j++) {
        sprintf(path, "%c", alphas[j]);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[j], path, LFS_O_RDONLY), 0);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < FILES; j++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &files[j], buffer, 1), 1);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[0], alphas[j]);
        }
    }

    for (int j = 0; j < FILES; j++) {
        lfs_file_close(&lfs, &files[j]);
    }
    
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case2(
        __attribute__((unused)) intmax_t FILES,
        __attribute__((unused)) intmax_t SIZE) {
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
    #line 66 "tests/test_interspersed.toml"
    const char alphas[] = "abcdefghijklmnopqrstuvwxyz";
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int j = 0; j < FILES; j++) {
        sprintf(path, "%c", alphas[j]);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
                LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), 0);
        for (int i = 0; i < SIZE; i++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, &alphas[j], 1), 1);
        }
        lfs_file_close(&lfs, &file);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "zzz", LFS_O_WRONLY | LFS_O_CREAT), 0);
    for (int j = 0; j < FILES; j++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, (const void*)"~", 1), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);

        sprintf(path, "%c", alphas[j]);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, path), 0);
    }
    lfs_file_close(&lfs, &file);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "zzz");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, FILES);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "zzz", LFS_O_RDONLY), 0);
    for (int i = 0; i < FILES; i++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 1), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[0], '~');
    }
    lfs_file_close(&lfs, &file);
    
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case3(
        __attribute__((unused)) intmax_t SIZE) {
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
    #line 118 "tests/test_interspersed.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    lfs_file_t files[3];
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[0], "e", LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[1], "f", LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[2], "g", LFS_O_WRONLY | LFS_O_CREAT), 0);

    for (int i = 0; i < SIZE/2; i++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[0], (const void*)"e", 1), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[1], (const void*)"f", 1), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[2], (const void*)"g", 1), 1);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "f"), 0);

    for (int i = 0; i < SIZE/2; i++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[0], (const void*)"e", 1), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[1], (const void*)"f", 1), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[2], (const void*)"g", 1), 1);
    }

    lfs_file_close(&lfs, &files[0]);
    lfs_file_close(&lfs, &files[1]);
    lfs_file_close(&lfs, &files[2]);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "e");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, SIZE);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "g");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, SIZE);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[0], "e", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[1], "g", LFS_O_RDONLY), 0);
    for (int i = 0; i < SIZE; i++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &files[0], buffer, 1), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[0], 'e');
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &files[1], buffer, 1), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[0], 'g');
    }
    lfs_file_close(&lfs, &files[0]);
    lfs_file_close(&lfs, &files[1]);
    
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case4(
        __attribute__((unused)) intmax_t FILES,
        __attribute__((unused)) intmax_t SIZE) {
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
    #line 180 "tests/test_interspersed.toml"
    lfs_file_t files[FILES];
    const char alphas[] = "abcdefghijklmnopqrstuvwxyz";

    err = lfs_mount(&lfs, &cfg);
    if (err) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    }

    for (int j = 0; j < FILES; j++) {
        sprintf(path, "%c", alphas[j]);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[j], path,
                LFS_O_WRONLY | LFS_O_CREAT | LFS_O_APPEND), 0);
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < FILES; j++) {
            size = lfs_file_size(&lfs, &files[j]);
            __LFS_ASSERT_INT_GE(__FILE__, __LINE__, (int)size, 0);
            if ((int)size <= i) {
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[j], &alphas[j], 1), 1);
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &files[j]), 0);
            }
        }
    }

    for (int j = 0; j < FILES; j++) {
        lfs_file_close(&lfs, &files[j]);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_open(&lfs, &dir, "/"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, ".");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, "..");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_DIR);
    for (int j = 0; j < FILES; j++) {
        sprintf(path, "%c", alphas[j]);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 1);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, info.name, path);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.type, LFS_TYPE_REG);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, info.size, SIZE);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_read(&lfs, &dir, &info), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_dir_close(&lfs, &dir), 0);

    for (int j = 0; j < FILES; j++) {
        sprintf(path, "%c", alphas[j]);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[j], path, LFS_O_RDONLY), 0);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < FILES; j++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &files[j], buffer, 1), 1);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[0], alphas[j]);
        }
    }

    for (int j = 0; j < FILES; j++) {
        lfs_file_close(&lfs, &files[j]);
    }
    
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
    extern void test_case1(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 1 && perm == 1)) { test_case1(4, 10); }
    extern void test_case1(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 1 && perm == 2)) { test_case1(4, 100); }
    extern void test_case1(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 1 && perm == 3)) { test_case1(10, 10); }
    extern void test_case1(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 1 && perm == 4)) { test_case1(10, 100); }
    extern void test_case1(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 1 && perm == 5)) { test_case1(26, 10); }
    extern void test_case1(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 1 && perm == 6)) { test_case1(26, 100); }
    extern void test_case2(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 1)) { test_case2(4, 10); }
    extern void test_case2(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 2)) { test_case2(4, 100); }
    extern void test_case2(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 3)) { test_case2(10, 10); }
    extern void test_case2(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 4)) { test_case2(10, 100); }
    extern void test_case2(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 5)) { test_case2(26, 10); }
    extern void test_case2(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 6)) { test_case2(26, 100); }
    extern void test_case3(intmax_t SIZE);
    if (argc < 3 || (case_ == 3 && perm == 1)) { test_case3(10); }
    extern void test_case3(intmax_t SIZE);
    if (argc < 3 || (case_ == 3 && perm == 2)) { test_case3(100); }
    extern void test_case4(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 4 && perm == 1)) { test_case4(4, 10); }
    extern void test_case4(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 4 && perm == 2)) { test_case4(4, 100); }
    extern void test_case4(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 4 && perm == 3)) { test_case4(10, 10); }
    extern void test_case4(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 4 && perm == 4)) { test_case4(10, 100); }
    extern void test_case4(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 4 && perm == 5)) { test_case4(26, 10); }
    extern void test_case4(intmax_t FILES, intmax_t SIZE);
    if (argc < 3 || (case_ == 4 && perm == 6)) { test_case4(26, 100); }
}
