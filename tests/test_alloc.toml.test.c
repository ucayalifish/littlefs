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
#line 1 "tests/test_alloc.toml.test.tc"

//////////////// AUTOGENERATED TEST ////////////////
#include "lfs.h"
#include "bd/lfs_testbd.h"
#include <stdio.h>
extern const char *lfs_testbd_path;
extern uint32_t lfs_testbd_cycles;

#define FILES 3
#define LFS_BADBLOCK_BEHAVIOR LFS_TESTBD_BADBLOCK_PROGERROR
#define LFS_ERASE_CYCLES 0
#define SIZE (((LFS_BLOCK_SIZE-8)*(LFS_BLOCK_COUNT-6)) / FILES)
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
    #line 9 "tests/test_alloc.toml"
    const char *names[FILES] = {"bacon", "eggs", "pancakes"};
    lfs_file_t files[FILES];

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "breakfast"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int n = 0; n < FILES; n++) {
        sprintf(path, "breakfast/%s", names[n]);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[n], path,
                LFS_O_WRONLY | LFS_O_CREAT | LFS_O_APPEND), 0);
    }
    for (int n = 0; n < FILES; n++) {
        size = strlen(names[n]);
        for (lfs_size_t i = 0; i < SIZE; i += size) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[n], names[n], size), size);
        }
    }
    for (int n = 0; n < FILES; n++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[n]), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int n = 0; n < FILES; n++) {
        sprintf(path, "breakfast/%s", names[n]);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
        size = strlen(names[n]);
        for (lfs_size_t i = 0; i < SIZE; i += size) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
            __LFS_ASSERT_MEM_EQ(__FILE__, __LINE__, buffer, names[n], size);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef FILES
#undef LFS_BADBLOCK_BEHAVIOR
#undef LFS_ERASE_CYCLES
#undef SIZE

#define FILES 3
#define LFS_BADBLOCK_BEHAVIOR LFS_TESTBD_BADBLOCK_PROGERROR
#define LFS_ERASE_CYCLES 0
#define SIZE (((LFS_BLOCK_SIZE-8)*(LFS_BLOCK_COUNT-6)) / FILES)
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
    #line 52 "tests/test_alloc.toml"
    const char *names[FILES] = {"bacon", "eggs", "pancakes"};

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "breakfast"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    for (int n = 0; n < FILES; n++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        sprintf(path, "breakfast/%s", names[n]);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
                LFS_O_WRONLY | LFS_O_CREAT | LFS_O_APPEND), 0);
        size = strlen(names[n]);
        memcpy(buffer, names[n], size);
        for (int i = 0; i < SIZE; i += size) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int n = 0; n < FILES; n++) {
        sprintf(path, "breakfast/%s", names[n]);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
        size = strlen(names[n]);
        for (int i = 0; i < SIZE; i += size) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
            __LFS_ASSERT_MEM_EQ(__FILE__, __LINE__, buffer, names[n], size);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef FILES
#undef LFS_BADBLOCK_BEHAVIOR
#undef LFS_ERASE_CYCLES
#undef SIZE

#define FILES 3
#define LFS_BADBLOCK_BEHAVIOR LFS_TESTBD_BADBLOCK_PROGERROR
#define LFS_ERASE_CYCLES 0
#define SIZE (((LFS_BLOCK_SIZE-8)*(LFS_BLOCK_COUNT-6)) / FILES)
void test_case3(
        __attribute__((unused)) intmax_t CYCLES) {
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
    #line 92 "tests/test_alloc.toml"
    const char *names[FILES] = {"bacon", "eggs", "pancakes"};
    lfs_file_t files[FILES];

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    for (int c = 0; c < CYCLES; c++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "breakfast"), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        for (int n = 0; n < FILES; n++) {
            sprintf(path, "breakfast/%s", names[n]);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &files[n], path,
                    LFS_O_WRONLY | LFS_O_CREAT | LFS_O_APPEND), 0);
        }
        for (int n = 0; n < FILES; n++) {
            size = strlen(names[n]);
            for (int i = 0; i < SIZE; i += size) {
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &files[n], names[n], size), size);
            }
        }
        for (int n = 0; n < FILES; n++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &files[n]), 0);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        for (int n = 0; n < FILES; n++) {
            sprintf(path, "breakfast/%s", names[n]);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
            size = strlen(names[n]);
            for (int i = 0; i < SIZE; i += size) {
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
                __LFS_ASSERT_MEM_EQ(__FILE__, __LINE__, buffer, names[n], size);
            }
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        for (int n = 0; n < FILES; n++) {
            sprintf(path, "breakfast/%s", names[n]);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, path), 0);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "breakfast"), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    }

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef FILES
#undef LFS_BADBLOCK_BEHAVIOR
#undef LFS_ERASE_CYCLES
#undef SIZE

#define FILES 3
#define LFS_BADBLOCK_BEHAVIOR LFS_TESTBD_BADBLOCK_PROGERROR
#define LFS_ERASE_CYCLES 0
#define SIZE (((LFS_BLOCK_SIZE-8)*(LFS_BLOCK_COUNT-6)) / FILES)
void test_case4(
        __attribute__((unused)) intmax_t CYCLES) {
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
    #line 147 "tests/test_alloc.toml"
    const char *names[FILES] = {"bacon", "eggs", "pancakes"};

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    for (int c = 0; c < CYCLES; c++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "breakfast"), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

        for (int n = 0; n < FILES; n++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
            sprintf(path, "breakfast/%s", names[n]);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
                    LFS_O_WRONLY | LFS_O_CREAT | LFS_O_APPEND), 0);
            size = strlen(names[n]);
            memcpy(buffer, names[n], size);
            for (int i = 0; i < SIZE; i += size) {
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
            }
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
        }

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        for (int n = 0; n < FILES; n++) {
            sprintf(path, "breakfast/%s", names[n]);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
            size = strlen(names[n]);
            for (int i = 0; i < SIZE; i += size) {
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
                __LFS_ASSERT_MEM_EQ(__FILE__, __LINE__, buffer, names[n], size);
            }
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        for (int n = 0; n < FILES; n++) {
            sprintf(path, "breakfast/%s", names[n]);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, path), 0);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "breakfast"), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    }

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef FILES
#undef LFS_BADBLOCK_BEHAVIOR
#undef LFS_ERASE_CYCLES
#undef SIZE

#define LFS_BADBLOCK_BEHAVIOR LFS_TESTBD_BADBLOCK_PROGERROR
#define LFS_ERASE_CYCLES 0
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
    #line 195 "tests/test_alloc.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    lfs_file_open(&lfs, &file, "exhaustion", LFS_O_WRONLY | LFS_O_CREAT);
    size = strlen("exhaustion");
    memcpy(buffer, "exhaustion", size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);

    size = strlen("blahblahblahblah");
    memcpy(buffer, "blahblahblahblah", size);
    lfs_ssize_t res;
    while (true) {
        res = lfs_file_write(&lfs, &file, buffer, size);
        if (res < 0) {
            break;
        }

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, res, size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, res, LFS_ERR_NOSPC);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    lfs_file_open(&lfs, &file, "exhaustion", LFS_O_RDONLY);
    size = strlen("exhaustion");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "exhaustion", size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_BADBLOCK_BEHAVIOR
#undef LFS_ERASE_CYCLES

#define LFS_BADBLOCK_BEHAVIOR LFS_TESTBD_BADBLOCK_PROGERROR
#define LFS_ERASE_CYCLES 0
#define SIZE (((LFS_BLOCK_SIZE-8)*(LFS_BLOCK_COUNT-4)) / 3)
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
    #line 232 "tests/test_alloc.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    lfs_file_open(&lfs, &file, "padding", LFS_O_WRONLY | LFS_O_CREAT);
    size = strlen("buffering");
    memcpy(buffer, "buffering", size);
    for (int i = 0; i < SIZE; i += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "padding"), 0);

    lfs_file_open(&lfs, &file, "exhaustion", LFS_O_WRONLY | LFS_O_CREAT);
    size = strlen("exhaustion");
    memcpy(buffer, "exhaustion", size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);

    size = strlen("blahblahblahblah");
    memcpy(buffer, "blahblahblahblah", size);
    lfs_ssize_t res;
    while (true) {
        res = lfs_file_write(&lfs, &file, buffer, size);
        if (res < 0) {
            break;
        }

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, res, size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, res, LFS_ERR_NOSPC);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    lfs_file_open(&lfs, &file, "exhaustion", LFS_O_RDONLY);
    size = strlen("exhaustion");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "exhaustion", size), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "exhaustion"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_BADBLOCK_BEHAVIOR
#undef LFS_ERASE_CYCLES
#undef SIZE

#define LFS_BADBLOCK_BEHAVIOR LFS_TESTBD_BADBLOCK_PROGERROR
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
    #line 279 "tests/test_alloc.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // find out max file size
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "exhaustiondir"), 0);
    size = strlen("blahblahblahblah");
    memcpy(buffer, "blahblahblahblah", size);
    lfs_file_open(&lfs, &file, "exhaustion", LFS_O_WRONLY | LFS_O_CREAT);
    int count = 0;
    while (true) {
        err = lfs_file_write(&lfs, &file, buffer, size);
        if (err < 0) {
            break;
        }

        count += 1;
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, err, LFS_ERR_NOSPC);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "exhaustion"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "exhaustiondir"), 0);

    // see if dir fits with max file size
    lfs_file_open(&lfs, &file, "exhaustion", LFS_O_WRONLY | LFS_O_CREAT);
    for (int i = 0; i < count; i++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "exhaustiondir"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "exhaustiondir"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "exhaustion"), 0);

    // see if dir fits with > max file size
    lfs_file_open(&lfs, &file, "exhaustion", LFS_O_WRONLY | LFS_O_CREAT);
    for (int i = 0; i < count+1; i++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "exhaustiondir"), LFS_ERR_NOSPC);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "exhaustion"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_BADBLOCK_BEHAVIOR
#undef LFS_ERASE_CYCLES

#define LFS_BADBLOCK_BEHAVIOR LFS_TESTBD_BADBLOCK_PROGERROR
#define LFS_ERASE_CYCLES 0
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
    #line 419 "tests/test_alloc.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // find out max file size
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "exhaustiondir"), 0);
    for (int i = 0; i < 10; i++) {
        sprintf(path, "dirwithanexhaustivelylongnameforpadding%d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, path), 0);
    }
    size = strlen("blahblahblahblah");
    memcpy(buffer, "blahblahblahblah", size);
    lfs_file_open(&lfs, &file, "exhaustion", LFS_O_WRONLY | LFS_O_CREAT);
    int count = 0;
    while (true) {
        err = lfs_file_write(&lfs, &file, buffer, size);
        if (err < 0) {
            break;
        }

        count += 1;
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, err, LFS_ERR_NOSPC);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "exhaustion"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "exhaustiondir"), 0);
    for (int i = 0; i < 10; i++) {
        sprintf(path, "dirwithanexhaustivelylongnameforpadding%d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, path), 0);
    }

    // see that chained dir fails
    lfs_file_open(&lfs, &file, "exhaustion", LFS_O_WRONLY | LFS_O_CREAT);
    for (int i = 0; i < count+1; i++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);

    for (int i = 0; i < 10; i++) {
        sprintf(path, "dirwithanexhaustivelylongnameforpadding%d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, path), 0);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "exhaustiondir"), LFS_ERR_NOSPC);

    // shorten file to try a second chained dir
    while (true) {
        err = lfs_mkdir(&lfs, "exhaustiondir");
        if (err != LFS_ERR_NOSPC) {
            break;
        }

        lfs_ssize_t filesize = lfs_file_size(&lfs, &file);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, filesize > 0, true);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_truncate(&lfs, &file, filesize - size), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, err, 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "exhaustiondir2"), LFS_ERR_NOSPC);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_BADBLOCK_BEHAVIOR
#undef LFS_ERASE_CYCLES

#define LFS_BADBLOCK_BEHAVIOR LFS_TESTBD_BADBLOCK_PROGERROR
#define LFS_ERASE_CYCLES 0
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
    #line 490 "tests/test_alloc.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // create one block hole for half a directory
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "bump", LFS_O_WRONLY | LFS_O_CREAT), 0);
    for (lfs_size_t i = 0; i < cfg.block_size; i += 2) {
        memcpy(&buffer[i], "hi", 2);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, cfg.block_size), cfg.block_size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    lfs_file_open(&lfs, &file, "exhaustion", LFS_O_WRONLY | LFS_O_CREAT);
    size = strlen("blahblahblahblah");
    memcpy(buffer, "blahblahblahblah", size);
    for (lfs_size_t i = 0;
            i < (cfg.block_count-4)*(cfg.block_size-8);
            i += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // remount to force reset of lookahead
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // open hole
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_remove(&lfs, "bump"), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "splitdir"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "splitdir/bump",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    for (lfs_size_t i = 0; i < cfg.block_size; i += 2) {
        memcpy(&buffer[i], "hi", 2);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, 2*cfg.block_size), LFS_ERR_NOSPC);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_BADBLOCK_BEHAVIOR
#undef LFS_ERASE_CYCLES

#define LFS_BADBLOCK_BEHAVIOR LFS_TESTBD_BADBLOCK_PROGERROR
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
    #line 535 "tests/test_alloc.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // fill completely with two files
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "exhaustion1",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    size = strlen("blahblahblahblah");
    memcpy(buffer, "blahblahblahblah", size);
    for (lfs_size_t i = 0;
            i < ((cfg.block_count-2)/2)*(cfg.block_size-8);
            i += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "exhaustion2",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    size = strlen("blahblahblahblah");
    memcpy(buffer, "blahblahblahblah", size);
    for (lfs_size_t i = 0;
            i < ((cfg.block_count-2+1)/2)*(cfg.block_size-8);
            i += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // remount to force reset of lookahead
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // rewrite one file
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "exhaustion1",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);
    size = strlen("blahblahblahblah");
    memcpy(buffer, "blahblahblahblah", size);
    for (lfs_size_t i = 0;
            i < ((cfg.block_count-2)/2)*(cfg.block_size-8);
            i += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // rewrite second file, this requires lookahead does not
    // use old population
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "exhaustion2",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);
    size = strlen("blahblahblahblah");
    memcpy(buffer, "blahblahblahblah", size);
    for (lfs_size_t i = 0;
            i < ((cfg.block_count-2+1)/2)*(cfg.block_size-8);
            i += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_BADBLOCK_BEHAVIOR
#undef LFS_ERASE_CYCLES

#define LFS_BADBLOCK_BEHAVIOR LFS_TESTBD_BADBLOCK_PROGERROR
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
    #line 600 "tests/test_alloc.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // fill completely with two files
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "exhaustion1",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    size = strlen("blahblahblahblah");
    memcpy(buffer, "blahblahblahblah", size);
    for (lfs_size_t i = 0;
            i < ((cfg.block_count-2)/2)*(cfg.block_size-8);
            i += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "exhaustion2",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    size = strlen("blahblahblahblah");
    memcpy(buffer, "blahblahblahblah", size);
    for (lfs_size_t i = 0;
            i < ((cfg.block_count-2+1)/2)*(cfg.block_size-8);
            i += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // remount to force reset of lookahead
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    // rewrite one file with a hole of one block
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "exhaustion1",
            LFS_O_WRONLY | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);
    size = strlen("blahblahblahblah");
    memcpy(buffer, "blahblahblahblah", size);
    for (lfs_size_t i = 0;
            i < ((cfg.block_count-2)/2 - 1)*(cfg.block_size-8);
            i += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // try to allocate a directory, should fail!
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "split"), LFS_ERR_NOSPC);

    // file should not fail
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "notasplit",
            LFS_O_WRONLY | LFS_O_CREAT), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, "hi", 2), 2);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_BADBLOCK_BEHAVIOR
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
    extern void test_case3(intmax_t CYCLES);
    if (argc < 3 || (case_ == 3 && perm == 1)) { test_case3(1); }
    extern void test_case3(intmax_t CYCLES);
    if (argc < 3 || (case_ == 3 && perm == 2)) { test_case3(10); }
    extern void test_case4(intmax_t CYCLES);
    if (argc < 3 || (case_ == 4 && perm == 1)) { test_case4(1); }
    extern void test_case4(intmax_t CYCLES);
    if (argc < 3 || (case_ == 4 && perm == 2)) { test_case4(10); }
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
}
