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
#line 1 "tests/test_files.toml.test.tc"

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
    #line 4 "tests/test_files.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "hello",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), 0);
    size = strlen("Hello World!")+1;
    strcpy((char*)buffer, "Hello World!");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "hello", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, (char*)buffer, "Hello World!");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case2(
        __attribute__((unused)) intmax_t CHUNKSIZE,
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
    #line 26 "tests/test_files.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    // write
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), 0);
    srand(1);
    for (lfs_size_t i = 0; i < SIZE; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE-i);
        for (lfs_size_t b = 0; b < chunk; b++) {
            buffer[b] = rand() & 0xff;
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, chunk), chunk);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // read
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE);
    srand(1);
    for (lfs_size_t i = 0; i < SIZE; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE-i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, chunk), chunk);
        for (lfs_size_t b = 0; b < chunk; b++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[b], (rand() & 0xff));
        }
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, CHUNKSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case3(
        __attribute__((unused)) intmax_t CHUNKSIZE,
        __attribute__((unused)) intmax_t SIZE1,
        __attribute__((unused)) intmax_t SIZE2) {
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
    #line 65 "tests/test_files.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    // write
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), 0);
    srand(1);
    for (lfs_size_t i = 0; i < SIZE1; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE1-i);
        for (lfs_size_t b = 0; b < chunk; b++) {
            buffer[b] = rand() & 0xff;
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, chunk), chunk);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // read
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE1);
    srand(1);
    for (lfs_size_t i = 0; i < SIZE1; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE1-i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, chunk), chunk);
        for (lfs_size_t b = 0; b < chunk; b++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[b], (rand() & 0xff));
        }
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, CHUNKSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // rewrite
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado", LFS_O_WRONLY), 0);
    srand(2);
    for (lfs_size_t i = 0; i < SIZE2; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE2-i);
        for (lfs_size_t b = 0; b < chunk; b++) {
            buffer[b] = rand() & 0xff;
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, chunk), chunk);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // read
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), lfs_max(SIZE1, SIZE2));
    srand(2);
    for (lfs_size_t i = 0; i < SIZE2; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE2-i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, chunk), chunk);
        for (lfs_size_t b = 0; b < chunk; b++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[b], (rand() & 0xff));
        }
    }
    if (SIZE1 > SIZE2) {
        srand(1);
        for (lfs_size_t b = 0; b < SIZE2; b++) {
            rand();
        }
        for (lfs_size_t i = SIZE2; i < SIZE1; i += CHUNKSIZE) {
            lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE1-i);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, chunk), chunk);
            for (lfs_size_t b = 0; b < chunk; b++) {
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[b], (rand() & 0xff));
            }
        }
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, CHUNKSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case4(
        __attribute__((unused)) intmax_t CHUNKSIZE,
        __attribute__((unused)) intmax_t SIZE1,
        __attribute__((unused)) intmax_t SIZE2) {
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
    #line 147 "tests/test_files.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    // write
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), 0);
    srand(1);
    for (lfs_size_t i = 0; i < SIZE1; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE1-i);
        for (lfs_size_t b = 0; b < chunk; b++) {
            buffer[b] = rand() & 0xff;
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, chunk), chunk);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // read
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE1);
    srand(1);
    for (lfs_size_t i = 0; i < SIZE1; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE1-i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, chunk), chunk);
        for (lfs_size_t b = 0; b < chunk; b++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[b], (rand() & 0xff));
        }
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, CHUNKSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // append
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado", LFS_O_WRONLY | LFS_O_APPEND), 0);
    srand(2);
    for (lfs_size_t i = 0; i < SIZE2; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE2-i);
        for (lfs_size_t b = 0; b < chunk; b++) {
            buffer[b] = rand() & 0xff;
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, chunk), chunk);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // read
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE1 + SIZE2);
    srand(1);
    for (lfs_size_t i = 0; i < SIZE1; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE1-i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, chunk), chunk);
        for (lfs_size_t b = 0; b < chunk; b++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[b], (rand() & 0xff));
        }
    }
    srand(2);
    for (lfs_size_t i = 0; i < SIZE2; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE2-i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, chunk), chunk);
        for (lfs_size_t b = 0; b < chunk; b++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[b], (rand() & 0xff));
        }
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, CHUNKSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case5(
        __attribute__((unused)) intmax_t CHUNKSIZE,
        __attribute__((unused)) intmax_t SIZE1,
        __attribute__((unused)) intmax_t SIZE2) {
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
    #line 224 "tests/test_files.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);

    // write
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), 0);
    srand(1);
    for (lfs_size_t i = 0; i < SIZE1; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE1-i);
        for (lfs_size_t b = 0; b < chunk; b++) {
            buffer[b] = rand() & 0xff;
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, chunk), chunk);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // read
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE1);
    srand(1);
    for (lfs_size_t i = 0; i < SIZE1; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE1-i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, chunk), chunk);
        for (lfs_size_t b = 0; b < chunk; b++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[b], (rand() & 0xff));
        }
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, CHUNKSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // truncate
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado", LFS_O_WRONLY | LFS_O_TRUNC), 0);
    srand(2);
    for (lfs_size_t i = 0; i < SIZE2; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE2-i);
        for (lfs_size_t b = 0; b < chunk; b++) {
            buffer[b] = rand() & 0xff;
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, chunk), chunk);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // read
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE2);
    srand(2);
    for (lfs_size_t i = 0; i < SIZE2; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE2-i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, chunk), chunk);
        for (lfs_size_t b = 0; b < chunk; b++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[b], (rand() & 0xff));
        }
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, CHUNKSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case6(
        __attribute__((unused)) intmax_t CHUNKSIZE,
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

    // test case 6
    #line 293 "tests/test_files.toml"
    err = lfs_mount(&lfs, &cfg);
    if (err) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    }

    err = lfs_file_open(&lfs, &file, "avacado", LFS_O_RDONLY);
    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == LFS_ERR_NOENT || err == 0, true);
    if (err == 0) {
        // can only be 0 (new file) or full size
        size = lfs_file_size(&lfs, &file);
        __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, size == 0 || size == SIZE, true);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }

    // write
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado", LFS_O_WRONLY | LFS_O_CREAT), 0);
    srand(1);
    for (lfs_size_t i = 0; i < SIZE; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE-i);
        for (lfs_size_t b = 0; b < chunk; b++) {
            buffer[b] = rand() & 0xff;
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, chunk), chunk);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // read
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE);
    srand(1);
    for (lfs_size_t i = 0; i < SIZE; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE-i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, chunk), chunk);
        for (lfs_size_t b = 0; b < chunk; b++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[b], (rand() & 0xff));
        }
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, CHUNKSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case7(
        __attribute__((unused)) intmax_t CHUNKSIZE,
        __attribute__((unused)) intmax_t MODE,
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

    // test case 7
    #line 347 "tests/test_files.toml"
    err = lfs_mount(&lfs, &cfg);
    if (err) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    }

    err = lfs_file_open(&lfs, &file, "avacado", LFS_O_RDONLY);
    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, err == LFS_ERR_NOENT || err == 0, true);
    if (err == 0) {
        // with syncs we could be any size, but it at least must be valid data
        size = lfs_file_size(&lfs, &file);
        __LFS_ASSERT_INT_LE(__FILE__, __LINE__, size, SIZE);
        srand(1);
        for (lfs_size_t i = 0; i < size; i += CHUNKSIZE) {
            lfs_size_t chunk = lfs_min(CHUNKSIZE, size-i);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, chunk), chunk);
            for (lfs_size_t b = 0; b < chunk; b++) {
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[b], (rand() & 0xff));
            }
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }

    // write
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado",
        LFS_O_WRONLY | LFS_O_CREAT | MODE), 0);
    size = lfs_file_size(&lfs, &file);
    __LFS_ASSERT_INT_LE(__FILE__, __LINE__, size, SIZE);
    srand(1);
    lfs_size_t skip = (MODE == LFS_O_APPEND) ? size : 0;
    for (lfs_size_t b = 0; b < skip; b++) {
        rand();
    }
    for (lfs_size_t i = skip; i < SIZE; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE-i);
        for (lfs_size_t b = 0; b < chunk; b++) {
            buffer[b] = rand() & 0xff;
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, chunk), chunk);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    // read
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "avacado", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE);
    srand(1);
    for (lfs_size_t i = 0; i < SIZE; i += CHUNKSIZE) {
        lfs_size_t chunk = lfs_min(CHUNKSIZE, SIZE-i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, chunk), chunk);
        for (lfs_size_t b = 0; b < chunk; b++) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, buffer[b], (rand() & 0xff));
        }
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, CHUNKSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

#define N 300
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
    #line 409 "tests/test_files.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    // create N files of 7 bytes
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int i = 0; i < N; i++) {
        sprintf(path, "file_%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
                LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), 0);
        char wbuffer[1024];
        size = 7;
        snprintf(wbuffer, size, "Hi %03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

        char rbuffer[1024];
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, rbuffer, wbuffer);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef N

#define N 300
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
    #line 434 "tests/test_files.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    // create N files of 7 bytes
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    for (int i = 0; i < N; i++) {
        sprintf(path, "file_%03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
                LFS_O_WRONLY | LFS_O_CREAT | LFS_O_EXCL), 0);
        char wbuffer[1024];
        size = 7;
        snprintf(wbuffer, size, "Hi %03d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

        char rbuffer[1024];
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, rbuffer, wbuffer);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef N

#define N 300
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
    #line 462 "tests/test_files.toml"
    err = lfs_mount(&lfs, &cfg);
    if (err) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    }
    // create N files of 7 bytes
    for (int i = 0; i < N; i++) {
        sprintf(path, "file_%03d", i);
        err = lfs_file_open(&lfs, &file, path, LFS_O_WRONLY | LFS_O_CREAT);
        char wbuffer[1024];
        size = 7;
        snprintf(wbuffer, size, "Hi %03d", i);
        if ((lfs_size_t)lfs_file_size(&lfs, &file) != size) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wbuffer, size), size);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

        char rbuffer[1024];
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rbuffer, size), size);
        __LFS_ASSERT_STR_EQ(__FILE__, __LINE__, rbuffer, wbuffer);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef N

const char *lfs_testbd_path;
uint32_t lfs_testbd_cycles;
int main(int argc, char **argv) {
    int case_         = (argc > 1) ? atoi(argv[1]) : 0;
    int perm          = (argc > 2) ? atoi(argv[2]) : 0;
    lfs_testbd_path   = (argc > 3) ? argv[3] : NULL;
    lfs_testbd_cycles = (argc > 4) ? atoi(argv[4]) : 0;
    extern void test_case1();
    if (argc < 3 || (case_ == 1 && perm == 1)) { test_case1(); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 1)) { test_case2(31, 32); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 2)) { test_case2(31, 8192); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 3)) { test_case2(31, 262144); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 4)) { test_case2(31, 0); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 5)) { test_case2(31, 7); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 6)) { test_case2(31, 8193); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 7)) { test_case2(16, 32); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 8)) { test_case2(16, 8192); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 9)) { test_case2(16, 262144); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 10)) { test_case2(16, 0); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 11)) { test_case2(16, 7); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 12)) { test_case2(16, 8193); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 13)) { test_case2(33, 32); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 14)) { test_case2(33, 8192); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 15)) { test_case2(33, 262144); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 16)) { test_case2(33, 0); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 17)) { test_case2(33, 7); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 18)) { test_case2(33, 8193); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 19)) { test_case2(1, 32); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 20)) { test_case2(1, 8192); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 21)) { test_case2(1, 262144); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 22)) { test_case2(1, 0); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 23)) { test_case2(1, 7); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 24)) { test_case2(1, 8193); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 25)) { test_case2(1023, 32); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 26)) { test_case2(1023, 8192); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 27)) { test_case2(1023, 262144); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 28)) { test_case2(1023, 0); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 29)) { test_case2(1023, 7); }
    extern void test_case2(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 2 && perm == 30)) { test_case2(1023, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 1)) { test_case3(31, 32, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 2)) { test_case3(31, 32, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 3)) { test_case3(31, 32, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 4)) { test_case3(31, 32, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 5)) { test_case3(31, 32, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 6)) { test_case3(31, 32, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 7)) { test_case3(31, 8192, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 8)) { test_case3(31, 8192, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 9)) { test_case3(31, 8192, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 10)) { test_case3(31, 8192, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 11)) { test_case3(31, 8192, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 12)) { test_case3(31, 8192, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 13)) { test_case3(31, 131072, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 14)) { test_case3(31, 131072, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 15)) { test_case3(31, 131072, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 16)) { test_case3(31, 131072, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 17)) { test_case3(31, 131072, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 18)) { test_case3(31, 131072, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 19)) { test_case3(31, 0, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 20)) { test_case3(31, 0, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 21)) { test_case3(31, 0, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 22)) { test_case3(31, 0, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 23)) { test_case3(31, 0, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 24)) { test_case3(31, 0, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 25)) { test_case3(31, 7, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 26)) { test_case3(31, 7, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 27)) { test_case3(31, 7, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 28)) { test_case3(31, 7, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 29)) { test_case3(31, 7, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 30)) { test_case3(31, 7, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 31)) { test_case3(31, 8193, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 32)) { test_case3(31, 8193, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 33)) { test_case3(31, 8193, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 34)) { test_case3(31, 8193, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 35)) { test_case3(31, 8193, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 36)) { test_case3(31, 8193, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 37)) { test_case3(16, 32, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 38)) { test_case3(16, 32, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 39)) { test_case3(16, 32, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 40)) { test_case3(16, 32, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 41)) { test_case3(16, 32, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 42)) { test_case3(16, 32, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 43)) { test_case3(16, 8192, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 44)) { test_case3(16, 8192, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 45)) { test_case3(16, 8192, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 46)) { test_case3(16, 8192, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 47)) { test_case3(16, 8192, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 48)) { test_case3(16, 8192, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 49)) { test_case3(16, 131072, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 50)) { test_case3(16, 131072, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 51)) { test_case3(16, 131072, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 52)) { test_case3(16, 131072, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 53)) { test_case3(16, 131072, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 54)) { test_case3(16, 131072, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 55)) { test_case3(16, 0, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 56)) { test_case3(16, 0, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 57)) { test_case3(16, 0, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 58)) { test_case3(16, 0, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 59)) { test_case3(16, 0, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 60)) { test_case3(16, 0, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 61)) { test_case3(16, 7, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 62)) { test_case3(16, 7, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 63)) { test_case3(16, 7, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 64)) { test_case3(16, 7, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 65)) { test_case3(16, 7, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 66)) { test_case3(16, 7, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 67)) { test_case3(16, 8193, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 68)) { test_case3(16, 8193, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 69)) { test_case3(16, 8193, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 70)) { test_case3(16, 8193, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 71)) { test_case3(16, 8193, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 72)) { test_case3(16, 8193, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 73)) { test_case3(1, 32, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 74)) { test_case3(1, 32, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 75)) { test_case3(1, 32, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 76)) { test_case3(1, 32, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 77)) { test_case3(1, 32, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 78)) { test_case3(1, 32, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 79)) { test_case3(1, 8192, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 80)) { test_case3(1, 8192, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 81)) { test_case3(1, 8192, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 82)) { test_case3(1, 8192, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 83)) { test_case3(1, 8192, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 84)) { test_case3(1, 8192, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 85)) { test_case3(1, 131072, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 86)) { test_case3(1, 131072, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 87)) { test_case3(1, 131072, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 88)) { test_case3(1, 131072, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 89)) { test_case3(1, 131072, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 90)) { test_case3(1, 131072, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 91)) { test_case3(1, 0, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 92)) { test_case3(1, 0, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 93)) { test_case3(1, 0, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 94)) { test_case3(1, 0, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 95)) { test_case3(1, 0, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 96)) { test_case3(1, 0, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 97)) { test_case3(1, 7, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 98)) { test_case3(1, 7, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 99)) { test_case3(1, 7, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 100)) { test_case3(1, 7, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 101)) { test_case3(1, 7, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 102)) { test_case3(1, 7, 8193); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 103)) { test_case3(1, 8193, 32); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 104)) { test_case3(1, 8193, 8192); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 105)) { test_case3(1, 8193, 131072); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 106)) { test_case3(1, 8193, 0); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 107)) { test_case3(1, 8193, 7); }
    extern void test_case3(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 3 && perm == 108)) { test_case3(1, 8193, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 1)) { test_case4(31, 32, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 2)) { test_case4(31, 32, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 3)) { test_case4(31, 32, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 4)) { test_case4(31, 32, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 5)) { test_case4(31, 32, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 6)) { test_case4(31, 32, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 7)) { test_case4(31, 8192, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 8)) { test_case4(31, 8192, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 9)) { test_case4(31, 8192, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 10)) { test_case4(31, 8192, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 11)) { test_case4(31, 8192, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 12)) { test_case4(31, 8192, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 13)) { test_case4(31, 131072, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 14)) { test_case4(31, 131072, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 15)) { test_case4(31, 131072, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 16)) { test_case4(31, 131072, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 17)) { test_case4(31, 131072, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 18)) { test_case4(31, 131072, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 19)) { test_case4(31, 0, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 20)) { test_case4(31, 0, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 21)) { test_case4(31, 0, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 22)) { test_case4(31, 0, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 23)) { test_case4(31, 0, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 24)) { test_case4(31, 0, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 25)) { test_case4(31, 7, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 26)) { test_case4(31, 7, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 27)) { test_case4(31, 7, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 28)) { test_case4(31, 7, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 29)) { test_case4(31, 7, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 30)) { test_case4(31, 7, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 31)) { test_case4(31, 8193, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 32)) { test_case4(31, 8193, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 33)) { test_case4(31, 8193, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 34)) { test_case4(31, 8193, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 35)) { test_case4(31, 8193, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 36)) { test_case4(31, 8193, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 37)) { test_case4(16, 32, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 38)) { test_case4(16, 32, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 39)) { test_case4(16, 32, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 40)) { test_case4(16, 32, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 41)) { test_case4(16, 32, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 42)) { test_case4(16, 32, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 43)) { test_case4(16, 8192, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 44)) { test_case4(16, 8192, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 45)) { test_case4(16, 8192, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 46)) { test_case4(16, 8192, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 47)) { test_case4(16, 8192, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 48)) { test_case4(16, 8192, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 49)) { test_case4(16, 131072, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 50)) { test_case4(16, 131072, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 51)) { test_case4(16, 131072, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 52)) { test_case4(16, 131072, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 53)) { test_case4(16, 131072, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 54)) { test_case4(16, 131072, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 55)) { test_case4(16, 0, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 56)) { test_case4(16, 0, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 57)) { test_case4(16, 0, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 58)) { test_case4(16, 0, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 59)) { test_case4(16, 0, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 60)) { test_case4(16, 0, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 61)) { test_case4(16, 7, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 62)) { test_case4(16, 7, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 63)) { test_case4(16, 7, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 64)) { test_case4(16, 7, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 65)) { test_case4(16, 7, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 66)) { test_case4(16, 7, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 67)) { test_case4(16, 8193, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 68)) { test_case4(16, 8193, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 69)) { test_case4(16, 8193, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 70)) { test_case4(16, 8193, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 71)) { test_case4(16, 8193, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 72)) { test_case4(16, 8193, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 73)) { test_case4(1, 32, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 74)) { test_case4(1, 32, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 75)) { test_case4(1, 32, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 76)) { test_case4(1, 32, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 77)) { test_case4(1, 32, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 78)) { test_case4(1, 32, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 79)) { test_case4(1, 8192, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 80)) { test_case4(1, 8192, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 81)) { test_case4(1, 8192, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 82)) { test_case4(1, 8192, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 83)) { test_case4(1, 8192, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 84)) { test_case4(1, 8192, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 85)) { test_case4(1, 131072, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 86)) { test_case4(1, 131072, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 87)) { test_case4(1, 131072, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 88)) { test_case4(1, 131072, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 89)) { test_case4(1, 131072, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 90)) { test_case4(1, 131072, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 91)) { test_case4(1, 0, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 92)) { test_case4(1, 0, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 93)) { test_case4(1, 0, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 94)) { test_case4(1, 0, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 95)) { test_case4(1, 0, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 96)) { test_case4(1, 0, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 97)) { test_case4(1, 7, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 98)) { test_case4(1, 7, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 99)) { test_case4(1, 7, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 100)) { test_case4(1, 7, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 101)) { test_case4(1, 7, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 102)) { test_case4(1, 7, 8193); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 103)) { test_case4(1, 8193, 32); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 104)) { test_case4(1, 8193, 8192); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 105)) { test_case4(1, 8193, 131072); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 106)) { test_case4(1, 8193, 0); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 107)) { test_case4(1, 8193, 7); }
    extern void test_case4(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 4 && perm == 108)) { test_case4(1, 8193, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 1)) { test_case5(31, 32, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 2)) { test_case5(31, 32, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 3)) { test_case5(31, 32, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 4)) { test_case5(31, 32, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 5)) { test_case5(31, 32, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 6)) { test_case5(31, 32, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 7)) { test_case5(31, 8192, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 8)) { test_case5(31, 8192, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 9)) { test_case5(31, 8192, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 10)) { test_case5(31, 8192, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 11)) { test_case5(31, 8192, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 12)) { test_case5(31, 8192, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 13)) { test_case5(31, 131072, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 14)) { test_case5(31, 131072, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 15)) { test_case5(31, 131072, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 16)) { test_case5(31, 131072, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 17)) { test_case5(31, 131072, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 18)) { test_case5(31, 131072, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 19)) { test_case5(31, 0, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 20)) { test_case5(31, 0, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 21)) { test_case5(31, 0, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 22)) { test_case5(31, 0, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 23)) { test_case5(31, 0, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 24)) { test_case5(31, 0, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 25)) { test_case5(31, 7, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 26)) { test_case5(31, 7, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 27)) { test_case5(31, 7, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 28)) { test_case5(31, 7, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 29)) { test_case5(31, 7, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 30)) { test_case5(31, 7, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 31)) { test_case5(31, 8193, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 32)) { test_case5(31, 8193, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 33)) { test_case5(31, 8193, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 34)) { test_case5(31, 8193, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 35)) { test_case5(31, 8193, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 36)) { test_case5(31, 8193, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 37)) { test_case5(16, 32, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 38)) { test_case5(16, 32, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 39)) { test_case5(16, 32, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 40)) { test_case5(16, 32, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 41)) { test_case5(16, 32, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 42)) { test_case5(16, 32, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 43)) { test_case5(16, 8192, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 44)) { test_case5(16, 8192, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 45)) { test_case5(16, 8192, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 46)) { test_case5(16, 8192, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 47)) { test_case5(16, 8192, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 48)) { test_case5(16, 8192, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 49)) { test_case5(16, 131072, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 50)) { test_case5(16, 131072, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 51)) { test_case5(16, 131072, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 52)) { test_case5(16, 131072, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 53)) { test_case5(16, 131072, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 54)) { test_case5(16, 131072, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 55)) { test_case5(16, 0, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 56)) { test_case5(16, 0, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 57)) { test_case5(16, 0, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 58)) { test_case5(16, 0, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 59)) { test_case5(16, 0, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 60)) { test_case5(16, 0, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 61)) { test_case5(16, 7, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 62)) { test_case5(16, 7, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 63)) { test_case5(16, 7, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 64)) { test_case5(16, 7, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 65)) { test_case5(16, 7, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 66)) { test_case5(16, 7, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 67)) { test_case5(16, 8193, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 68)) { test_case5(16, 8193, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 69)) { test_case5(16, 8193, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 70)) { test_case5(16, 8193, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 71)) { test_case5(16, 8193, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 72)) { test_case5(16, 8193, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 73)) { test_case5(1, 32, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 74)) { test_case5(1, 32, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 75)) { test_case5(1, 32, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 76)) { test_case5(1, 32, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 77)) { test_case5(1, 32, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 78)) { test_case5(1, 32, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 79)) { test_case5(1, 8192, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 80)) { test_case5(1, 8192, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 81)) { test_case5(1, 8192, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 82)) { test_case5(1, 8192, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 83)) { test_case5(1, 8192, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 84)) { test_case5(1, 8192, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 85)) { test_case5(1, 131072, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 86)) { test_case5(1, 131072, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 87)) { test_case5(1, 131072, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 88)) { test_case5(1, 131072, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 89)) { test_case5(1, 131072, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 90)) { test_case5(1, 131072, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 91)) { test_case5(1, 0, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 92)) { test_case5(1, 0, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 93)) { test_case5(1, 0, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 94)) { test_case5(1, 0, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 95)) { test_case5(1, 0, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 96)) { test_case5(1, 0, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 97)) { test_case5(1, 7, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 98)) { test_case5(1, 7, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 99)) { test_case5(1, 7, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 100)) { test_case5(1, 7, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 101)) { test_case5(1, 7, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 102)) { test_case5(1, 7, 8193); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 103)) { test_case5(1, 8193, 32); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 104)) { test_case5(1, 8193, 8192); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 105)) { test_case5(1, 8193, 131072); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 106)) { test_case5(1, 8193, 0); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 107)) { test_case5(1, 8193, 7); }
    extern void test_case5(intmax_t CHUNKSIZE, intmax_t SIZE1, intmax_t SIZE2);
    if (argc < 3 || (case_ == 5 && perm == 108)) { test_case5(1, 8193, 8193); }
    extern void test_case6(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 6 && perm == 1)) { test_case6(31, 32); }
    extern void test_case6(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 6 && perm == 2)) { test_case6(31, 0); }
    extern void test_case6(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 6 && perm == 3)) { test_case6(31, 7); }
    extern void test_case6(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 6 && perm == 4)) { test_case6(31, 2049); }
    extern void test_case6(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 6 && perm == 5)) { test_case6(16, 32); }
    extern void test_case6(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 6 && perm == 6)) { test_case6(16, 0); }
    extern void test_case6(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 6 && perm == 7)) { test_case6(16, 7); }
    extern void test_case6(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 6 && perm == 8)) { test_case6(16, 2049); }
    extern void test_case6(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 6 && perm == 9)) { test_case6(65, 32); }
    extern void test_case6(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 6 && perm == 10)) { test_case6(65, 0); }
    extern void test_case6(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 6 && perm == 11)) { test_case6(65, 7); }
    extern void test_case6(intmax_t CHUNKSIZE, intmax_t SIZE);
    if (argc < 3 || (case_ == 6 && perm == 12)) { test_case6(65, 2049); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 1)) { test_case7(31, LFS_O_APPEND, 32); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 2)) { test_case7(31, LFS_O_APPEND, 0); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 3)) { test_case7(31, LFS_O_APPEND, 7); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 4)) { test_case7(31, LFS_O_APPEND, 2049); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 5)) { test_case7(16, LFS_O_APPEND, 32); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 6)) { test_case7(16, LFS_O_APPEND, 0); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 7)) { test_case7(16, LFS_O_APPEND, 7); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 8)) { test_case7(16, LFS_O_APPEND, 2049); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 9)) { test_case7(65, LFS_O_APPEND, 32); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 10)) { test_case7(65, LFS_O_APPEND, 0); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 11)) { test_case7(65, LFS_O_APPEND, 7); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 12)) { test_case7(65, LFS_O_APPEND, 2049); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 13)) { test_case7(31, LFS_O_TRUNC, 32); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 14)) { test_case7(31, LFS_O_TRUNC, 0); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 15)) { test_case7(31, LFS_O_TRUNC, 7); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 16)) { test_case7(31, LFS_O_TRUNC, 200); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 17)) { test_case7(16, LFS_O_TRUNC, 32); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 18)) { test_case7(16, LFS_O_TRUNC, 0); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 19)) { test_case7(16, LFS_O_TRUNC, 7); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 20)) { test_case7(16, LFS_O_TRUNC, 200); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 21)) { test_case7(65, LFS_O_TRUNC, 32); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 22)) { test_case7(65, LFS_O_TRUNC, 0); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 23)) { test_case7(65, LFS_O_TRUNC, 7); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 24)) { test_case7(65, LFS_O_TRUNC, 200); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 25)) { test_case7(31, 0, 32); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 26)) { test_case7(31, 0, 0); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 27)) { test_case7(31, 0, 7); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 28)) { test_case7(31, 0, 200); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 29)) { test_case7(16, 0, 32); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 30)) { test_case7(16, 0, 0); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 31)) { test_case7(16, 0, 7); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 32)) { test_case7(16, 0, 200); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 33)) { test_case7(65, 0, 32); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 34)) { test_case7(65, 0, 0); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 35)) { test_case7(65, 0, 7); }
    extern void test_case7(intmax_t CHUNKSIZE, intmax_t MODE, intmax_t SIZE);
    if (argc < 3 || (case_ == 7 && perm == 36)) { test_case7(65, 0, 200); }
    extern void test_case8();
    if (argc < 3 || (case_ == 8 && perm == 1)) { test_case8(); }
    extern void test_case9();
    if (argc < 3 || (case_ == 9 && perm == 1)) { test_case9(); }
    extern void test_case10();
    if (argc < 3 || (case_ == 10 && perm == 1)) { test_case10(); }
}
