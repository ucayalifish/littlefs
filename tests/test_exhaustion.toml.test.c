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
#line 1 "tests/test_exhaustion.toml.test.tc"

//////////////// AUTOGENERATED TEST ////////////////
#include "lfs.h"
#include "bd/lfs_testbd.h"
#include <stdio.h>
extern const char *lfs_testbd_path;
extern uint32_t lfs_testbd_cycles;

#define LFS_BLOCK_CYCLES LFS_ERASE_CYCLES / 2
#define LFS_ERASE_CYCLES 10
void test_case1(
        __attribute__((unused)) intmax_t LFS_BADBLOCK_BEHAVIOR) {
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
    #line 14 "tests/test_exhaustion.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "roadrunner"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    uint32_t cycle = 0;
    while (true) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        for (uint32_t i = 0; i < FILES; i++) {
            // chose name, roughly random seed, and random 2^n size
            sprintf(path, "roadrunner/test%d", i);
            srand(cycle * i);
            size = 1 << ((rand() % 10)+2);

            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
                    LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);

            for (lfs_size_t j = 0; j < size; j++) {
                char c = 'a' + (rand() % 26);
                lfs_ssize_t res = lfs_file_write(&lfs, &file, &c, 1);
                __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, res == 1 || res == LFS_ERR_NOSPC, true);
                if (res == LFS_ERR_NOSPC) {
                    err = lfs_file_close(&lfs, &file);
                    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == 0 || err == LFS_ERR_NOSPC, true);
                    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
                    goto exhausted;
                }
            }

            err = lfs_file_close(&lfs, &file);
            __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == 0 || err == LFS_ERR_NOSPC, true);
            if (err == LFS_ERR_NOSPC) {
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
                goto exhausted;
            }
        }

        for (uint32_t i = 0; i < FILES; i++) {
            // check for errors
            sprintf(path, "roadrunner/test%d", i);
            srand(cycle * i);
            size = 1 << ((rand() % 10)+2);

            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
            for (lfs_size_t j = 0; j < size; j++) {
                char c = 'a' + (rand() % 26);
                char r;
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, &r, 1), 1);
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, r, c);
            }

            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

        cycle += 1;
    }

exhausted:
    // should still be readable
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (uint32_t i = 0; i < FILES; i++) {
        // check for errors
        sprintf(path, "roadrunner/test%d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, path, &info), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    LFS_WARN("completed %d cycles", cycle);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_BLOCK_CYCLES
#undef LFS_ERASE_CYCLES

#define LFS_BLOCK_CYCLES LFS_ERASE_CYCLES / 2
#define LFS_ERASE_CYCLES 10
void test_case2(
        __attribute__((unused)) intmax_t LFS_BADBLOCK_BEHAVIOR) {
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
    #line 99 "tests/test_exhaustion.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    uint32_t cycle = 0;
    while (true) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        for (uint32_t i = 0; i < FILES; i++) {
            // chose name, roughly random seed, and random 2^n size
            sprintf(path, "test%d", i);
            srand(cycle * i);
            size = 1 << ((rand() % 10)+2);

            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
                    LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);

            for (lfs_size_t j = 0; j < size; j++) {
                char c = 'a' + (rand() % 26);
                lfs_ssize_t res = lfs_file_write(&lfs, &file, &c, 1);
                __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, res == 1 || res == LFS_ERR_NOSPC, true);
                if (res == LFS_ERR_NOSPC) {
                    err = lfs_file_close(&lfs, &file);
                    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == 0 || err == LFS_ERR_NOSPC, true);
                    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
                    goto exhausted;
                }
            }

            err = lfs_file_close(&lfs, &file);
            __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == 0 || err == LFS_ERR_NOSPC, true);
            if (err == LFS_ERR_NOSPC) {
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
                goto exhausted;
            }
        }

        for (uint32_t i = 0; i < FILES; i++) {
            // check for errors
            sprintf(path, "test%d", i);
            srand(cycle * i);
            size = 1 << ((rand() % 10)+2);

            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
            for (lfs_size_t j = 0; j < size; j++) {
                char c = 'a' + (rand() % 26);
                char r;
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, &r, 1), 1);
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, r, c);
            }

            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

        cycle += 1;
    }

exhausted:
    // should still be readable
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (uint32_t i = 0; i < FILES; i++) {
        // check for errors
        sprintf(path, "test%d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, path, &info), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    LFS_WARN("completed %d cycles", cycle);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_BLOCK_CYCLES
#undef LFS_ERASE_CYCLES

#define LFS_BADBLOCK_BEHAVIOR LFS_TESTBD_BADBLOCK_PROGERROR
#define LFS_BLOCK_CYCLES LFS_ERASE_CYCLES / 2
#define LFS_ERASE_CYCLES 20
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
    #line 178 "tests/test_exhaustion.toml"
    uint32_t run_cycles[2];
    const uint32_t run_block_count[2] = {LFS_BLOCK_COUNT/2, LFS_BLOCK_COUNT};

    for (int run = 0; run < 2; run++) {
        for (lfs_block_t b = 0; b < LFS_BLOCK_COUNT; b++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_setwear(&cfg, b,
                    (b < run_block_count[run]) ? 0 : LFS_ERASE_CYCLES), 0);
        }

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "roadrunner"), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

        uint32_t cycle = 0;
        while (true) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
            for (uint32_t i = 0; i < FILES; i++) {
                // chose name, roughly random seed, and random 2^n size
                sprintf(path, "roadrunner/test%d", i);
                srand(cycle * i);
                size = 1 << ((rand() % 10)+2);

                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
                        LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);

                for (lfs_size_t j = 0; j < size; j++) {
                    char c = 'a' + (rand() % 26);
                    lfs_ssize_t res = lfs_file_write(&lfs, &file, &c, 1);
                    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, res == 1 || res == LFS_ERR_NOSPC, true);
                    if (res == LFS_ERR_NOSPC) {
                        err = lfs_file_close(&lfs, &file);
                        __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == 0 || err == LFS_ERR_NOSPC, true);
                        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
                        goto exhausted;
                    }
                }

                err = lfs_file_close(&lfs, &file);
                __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == 0 || err == LFS_ERR_NOSPC, true);
                if (err == LFS_ERR_NOSPC) {
                    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
                    goto exhausted;
                }
            }

            for (uint32_t i = 0; i < FILES; i++) {
                // check for errors
                sprintf(path, "roadrunner/test%d", i);
                srand(cycle * i);
                size = 1 << ((rand() % 10)+2);

                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
                for (lfs_size_t j = 0; j < size; j++) {
                    char c = 'a' + (rand() % 26);
                    char r;
                    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, &r, 1), 1);
                    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, r, c);
                }

                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
            }
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

            cycle += 1;
        }

exhausted:
        // should still be readable
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        for (uint32_t i = 0; i < FILES; i++) {
            // check for errors
            sprintf(path, "roadrunner/test%d", i);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, path, &info), 0);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

        run_cycles[run] = cycle;
        LFS_WARN("completed %d blocks %d cycles",
                run_block_count[run], run_cycles[run]);
    }

    // check we increased the lifetime by 2x with ~10% error
    __LFS_ASSERT_INT_GT(__FILE__, __LINE__, run_cycles[1]*110/100, 2*run_cycles[0]);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_BADBLOCK_BEHAVIOR
#undef LFS_BLOCK_CYCLES
#undef LFS_ERASE_CYCLES

#define LFS_BADBLOCK_BEHAVIOR LFS_TESTBD_BADBLOCK_PROGERROR
#define LFS_BLOCK_CYCLES LFS_ERASE_CYCLES / 2
#define LFS_ERASE_CYCLES 20
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
    #line 270 "tests/test_exhaustion.toml"
    uint32_t run_cycles[2];
    const uint32_t run_block_count[2] = {LFS_BLOCK_COUNT/2, LFS_BLOCK_COUNT};

    for (int run = 0; run < 2; run++) {
        for (lfs_block_t b = 0; b < LFS_BLOCK_COUNT; b++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_setwear(&cfg, b,
                    (b < run_block_count[run]) ? 0 : LFS_ERASE_CYCLES), 0);
        }

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

        uint32_t cycle = 0;
        while (true) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
            for (uint32_t i = 0; i < FILES; i++) {
                // chose name, roughly random seed, and random 2^n size
                sprintf(path, "test%d", i);
                srand(cycle * i);
                size = 1 << ((rand() % 10)+2);

                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
                        LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);

                for (lfs_size_t j = 0; j < size; j++) {
                    char c = 'a' + (rand() % 26);
                    lfs_ssize_t res = lfs_file_write(&lfs, &file, &c, 1);
                    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, res == 1 || res == LFS_ERR_NOSPC, true);
                    if (res == LFS_ERR_NOSPC) {
                        err = lfs_file_close(&lfs, &file);
                        __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == 0 || err == LFS_ERR_NOSPC, true);
                        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
                        goto exhausted;
                    }
                }

                err = lfs_file_close(&lfs, &file);
                __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == 0 || err == LFS_ERR_NOSPC, true);
                if (err == LFS_ERR_NOSPC) {
                    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
                    goto exhausted;
                }
            }

            for (uint32_t i = 0; i < FILES; i++) {
                // check for errors
                sprintf(path, "test%d", i);
                srand(cycle * i);
                size = 1 << ((rand() % 10)+2);

                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
                for (lfs_size_t j = 0; j < size; j++) {
                    char c = 'a' + (rand() % 26);
                    char r;
                    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, &r, 1), 1);
                    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, r, c);
                }

                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
            }
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

            cycle += 1;
        }

exhausted:
        // should still be readable
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        for (uint32_t i = 0; i < FILES; i++) {
            // check for errors
            sprintf(path, "test%d", i);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, path, &info), 0);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

        run_cycles[run] = cycle;
        LFS_WARN("completed %d blocks %d cycles",
                run_block_count[run], run_cycles[run]);
    }

    // check we increased the lifetime by 2x with ~10% error
    __LFS_ASSERT_INT_GT(__FILE__, __LINE__, run_cycles[1]*110/100, 2*run_cycles[0]);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LFS_BADBLOCK_BEHAVIOR
#undef LFS_BLOCK_CYCLES
#undef LFS_ERASE_CYCLES

#define CYCLES 100
#define LFS_BADBLOCK_BEHAVIOR LFS_TESTBD_BADBLOCK_PROGERROR
#define LFS_ERASE_CYCLES 4294967295
void test_case5(
        __attribute__((unused)) intmax_t LFS_BLOCK_CYCLES) {
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
    #line 361 "tests/test_exhaustion.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mkdir(&lfs, "roadrunner"), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    uint32_t cycle = 0;
    while (cycle < CYCLES) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        for (uint32_t i = 0; i < FILES; i++) {
            // chose name, roughly random seed, and random 2^n size
            sprintf(path, "roadrunner/test%d", i);
            srand(cycle * i);
            size = 1 << 4; //((rand() % 10)+2);

            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
                    LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);

            for (lfs_size_t j = 0; j < size; j++) {
                char c = 'a' + (rand() % 26);
                lfs_ssize_t res = lfs_file_write(&lfs, &file, &c, 1);
                __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, res == 1 || res == LFS_ERR_NOSPC, true);
                if (res == LFS_ERR_NOSPC) {
                    err = lfs_file_close(&lfs, &file);
                    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == 0 || err == LFS_ERR_NOSPC, true);
                    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
                    goto exhausted;
                }
            }

            err = lfs_file_close(&lfs, &file);
            __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == 0 || err == LFS_ERR_NOSPC, true);
            if (err == LFS_ERR_NOSPC) {
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
                goto exhausted;
            }
        }

        for (uint32_t i = 0; i < FILES; i++) {
            // check for errors
            sprintf(path, "roadrunner/test%d", i);
            srand(cycle * i);
            size = 1 << 4; //((rand() % 10)+2);

            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
            for (lfs_size_t j = 0; j < size; j++) {
                char c = 'a' + (rand() % 26);
                char r;
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, &r, 1), 1);
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, r, c);
            }

            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

        cycle += 1;
    }

exhausted:
    // should still be readable
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (uint32_t i = 0; i < FILES; i++) {
        // check for errors
        sprintf(path, "roadrunner/test%d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_stat(&lfs, path, &info), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    LFS_WARN("completed %d cycles", cycle);

    // check the wear on our block device
    lfs_testbd_wear_t minwear = -1;
    lfs_testbd_wear_t totalwear = 0;
    lfs_testbd_wear_t maxwear = 0;
    // skip 0 and 1 as superblock movement is intentionally avoided
    for (lfs_block_t b = 2; b < LFS_BLOCK_COUNT; b++) {
        lfs_testbd_wear_t wear = lfs_testbd_getwear(&cfg, b);
        printf("%08x: wear %d\n", b, wear);
        __LFS_ASSERT_INT_GE(__FILE__, __LINE__, wear, 0);
        if (wear < minwear) {
            minwear = wear;
        }
        if (wear > maxwear) {
            maxwear = wear;
        }
        totalwear += wear;
    }
    lfs_testbd_wear_t avgwear = totalwear / LFS_BLOCK_COUNT;
    LFS_WARN("max wear: %d cycles", maxwear);
    LFS_WARN("avg wear: %d cycles", totalwear / LFS_BLOCK_COUNT);
    LFS_WARN("min wear: %d cycles", minwear);

    // find standard deviation^2
    lfs_testbd_wear_t dev2 = 0;
    for (lfs_block_t b = 2; b < LFS_BLOCK_COUNT; b++) {
        lfs_testbd_wear_t wear = lfs_testbd_getwear(&cfg, b);
        __LFS_ASSERT_INT_GE(__FILE__, __LINE__, wear, 0);
        lfs_testbd_swear_t diff = wear - avgwear;
        dev2 += diff*diff;
    }
    dev2 /= totalwear;
    LFS_WARN("std dev^2: %d", dev2);
    __LFS_ASSERT_INT_LT(__FILE__, __LINE__, dev2, 8);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef CYCLES
#undef LFS_BADBLOCK_BEHAVIOR
#undef LFS_ERASE_CYCLES

const char *lfs_testbd_path;
uint32_t lfs_testbd_cycles;
int main(int argc, char **argv) {
    int case_         = (argc > 1) ? atoi(argv[1]) : 0;
    int perm          = (argc > 2) ? atoi(argv[2]) : 0;
    lfs_testbd_path   = (argc > 3) ? argv[3] : NULL;
    lfs_testbd_cycles = (argc > 4) ? atoi(argv[4]) : 0;
    extern void test_case1(intmax_t LFS_BADBLOCK_BEHAVIOR);
    if (argc < 3 || (case_ == 1 && perm == 1)) { test_case1(LFS_TESTBD_BADBLOCK_PROGERROR); }
    extern void test_case1(intmax_t LFS_BADBLOCK_BEHAVIOR);
    if (argc < 3 || (case_ == 1 && perm == 2)) { test_case1(LFS_TESTBD_BADBLOCK_ERASEERROR); }
    extern void test_case1(intmax_t LFS_BADBLOCK_BEHAVIOR);
    if (argc < 3 || (case_ == 1 && perm == 3)) { test_case1(LFS_TESTBD_BADBLOCK_READERROR); }
    extern void test_case1(intmax_t LFS_BADBLOCK_BEHAVIOR);
    if (argc < 3 || (case_ == 1 && perm == 4)) { test_case1(LFS_TESTBD_BADBLOCK_PROGNOOP); }
    extern void test_case1(intmax_t LFS_BADBLOCK_BEHAVIOR);
    if (argc < 3 || (case_ == 1 && perm == 5)) { test_case1(LFS_TESTBD_BADBLOCK_ERASENOOP); }
    extern void test_case2(intmax_t LFS_BADBLOCK_BEHAVIOR);
    if (argc < 3 || (case_ == 2 && perm == 1)) { test_case2(LFS_TESTBD_BADBLOCK_PROGERROR); }
    extern void test_case2(intmax_t LFS_BADBLOCK_BEHAVIOR);
    if (argc < 3 || (case_ == 2 && perm == 2)) { test_case2(LFS_TESTBD_BADBLOCK_ERASEERROR); }
    extern void test_case2(intmax_t LFS_BADBLOCK_BEHAVIOR);
    if (argc < 3 || (case_ == 2 && perm == 3)) { test_case2(LFS_TESTBD_BADBLOCK_READERROR); }
    extern void test_case2(intmax_t LFS_BADBLOCK_BEHAVIOR);
    if (argc < 3 || (case_ == 2 && perm == 4)) { test_case2(LFS_TESTBD_BADBLOCK_PROGNOOP); }
    extern void test_case2(intmax_t LFS_BADBLOCK_BEHAVIOR);
    if (argc < 3 || (case_ == 2 && perm == 5)) { test_case2(LFS_TESTBD_BADBLOCK_ERASENOOP); }
    extern void test_case3();
    if (argc < 3 || (case_ == 3 && perm == 1)) { test_case3(); }
    extern void test_case4();
    if (argc < 3 || (case_ == 4 && perm == 1)) { test_case4(); }
    extern void test_case5(intmax_t LFS_BLOCK_CYCLES);
    if (argc < 3 || (case_ == 5 && perm == 1)) { test_case5(5); }
    extern void test_case5(intmax_t LFS_BLOCK_CYCLES);
    if (argc < 3 || (case_ == 5 && perm == 2)) { test_case5(4); }
    extern void test_case5(intmax_t LFS_BLOCK_CYCLES);
    if (argc < 3 || (case_ == 5 && perm == 3)) { test_case5(3); }
    extern void test_case5(intmax_t LFS_BLOCK_CYCLES);
    if (argc < 3 || (case_ == 5 && perm == 4)) { test_case5(2); }
    extern void test_case5(intmax_t LFS_BLOCK_CYCLES);
    if (argc < 3 || (case_ == 5 && perm == 5)) { test_case5(1); }
}
