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
#line 1 "tests/test_seek.toml.test.tc"

//////////////// AUTOGENERATED TEST ////////////////
#include "lfs.h"
#include "bd/lfs_testbd.h"
#include <stdio.h>
extern const char *lfs_testbd_path;
extern uint32_t lfs_testbd_cycles;

void test_case1(
        __attribute__((unused)) intmax_t COUNT,
        __attribute__((unused)) intmax_t SKIP) {
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
    #line 12 "tests/test_seek.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "kitty",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_APPEND), 0);
    size = strlen("kittycatcat");
    memcpy(buffer, "kittycatcat", size);
    for (int j = 0; j < COUNT; j++) {
        lfs_file_write(&lfs, &file, buffer, size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "kitty", LFS_O_RDONLY), 0);

    lfs_soff_t pos = -1;
    size = strlen("kittycatcat");
    for (int i = 0; i < SKIP; i++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", size), 0);
        pos = lfs_file_tell(&lfs, &file);
    }
    __LFS_ASSERT_INT_GE(__FILE__, __LINE__, pos, 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, pos, LFS_SEEK_SET), pos);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_rewind(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, 0, LFS_SEEK_CUR), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, size, LFS_SEEK_CUR), 3*size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, pos, LFS_SEEK_SET), pos);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, -size, LFS_SEEK_CUR), pos);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, -size, LFS_SEEK_END) >= 0, 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", size), 0);

    size = lfs_file_size(&lfs, &file);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, 0, LFS_SEEK_CUR), size);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case2(
        __attribute__((unused)) intmax_t COUNT,
        __attribute__((unused)) intmax_t SKIP) {
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
    #line 81 "tests/test_seek.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "kitty",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_APPEND), 0);
    size = strlen("kittycatcat");
    memcpy(buffer, "kittycatcat", size);
    for (int j = 0; j < COUNT; j++) {
        lfs_file_write(&lfs, &file, buffer, size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "kitty", LFS_O_RDWR), 0);

    lfs_soff_t pos = -1;
    size = strlen("kittycatcat");
    for (int i = 0; i < SKIP; i++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", size), 0);
        pos = lfs_file_tell(&lfs, &file);
    }
    __LFS_ASSERT_INT_GE(__FILE__, __LINE__, pos, 0);

    memcpy(buffer, "doggodogdog", size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, pos, LFS_SEEK_SET), pos);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, pos, LFS_SEEK_SET), pos);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "doggodogdog", size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_rewind(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, pos, LFS_SEEK_SET), pos);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "doggodogdog", size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, -size, LFS_SEEK_END) >= 0, 1);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", size), 0);

    size = lfs_file_size(&lfs, &file);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, 0, LFS_SEEK_CUR), size);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

#define COUNT 132
#define OFFSETS {512, 1020, 513, 1021, 511, 1019, 1441}
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
    #line 136 "tests/test_seek.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "kitty",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_APPEND), 0);
    size = strlen("kittycatcat");
    memcpy(buffer, "kittycatcat", size);
    for (int j = 0; j < COUNT; j++) {
        lfs_file_write(&lfs, &file, buffer, size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "kitty", LFS_O_RDWR), 0);

    size = strlen("hedgehoghog");
    const lfs_soff_t offsets[] = OFFSETS;

    for (unsigned i = 0; i < sizeof(offsets) / sizeof(offsets[0]); i++) {
        lfs_soff_t off = offsets[i];
        memcpy(buffer, "hedgehoghog", size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, off, LFS_SEEK_SET), off);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, off, LFS_SEEK_SET), off);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hedgehoghog", size), 0);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, 0, LFS_SEEK_SET), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", size), 0);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, off, LFS_SEEK_SET), off);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hedgehoghog", size), 0);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, 0, LFS_SEEK_SET), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", size), 0);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, off, LFS_SEEK_SET), off);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hedgehoghog", size), 0);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef COUNT
#undef OFFSETS

void test_case4(
        __attribute__((unused)) intmax_t COUNT,
        __attribute__((unused)) intmax_t SKIP) {
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
    #line 196 "tests/test_seek.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "kitty",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_APPEND), 0);
    size = strlen("kittycatcat");
    memcpy(buffer, "kittycatcat", size);
    for (int j = 0; j < COUNT; j++) {
        lfs_file_write(&lfs, &file, buffer, size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "kitty", LFS_O_RDWR), 0);

    size = strlen("kittycatcat");
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), COUNT*size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, (COUNT+SKIP)*size,
            LFS_SEEK_SET), (COUNT+SKIP)*size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), 0);

    memcpy(buffer, "porcupineee", size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, (COUNT+SKIP)*size,
            LFS_SEEK_SET), (COUNT+SKIP)*size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "porcupineee", size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, COUNT*size,
            LFS_SEEK_SET), COUNT*size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "\0\0\0\0\0\0\0\0\0\0\0", size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, -((COUNT+SKIP)*size),
            LFS_SEEK_CUR), LFS_ERR_INVAL);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), (COUNT+1)*size);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, -((COUNT+2*SKIP)*size),
            LFS_SEEK_END), LFS_ERR_INVAL);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), (COUNT+1)*size);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case5(
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

    // test case 5
    #line 244 "tests/test_seek.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "tinykitty",
            LFS_O_RDWR | LFS_O_CREAT), 0);
    int j = 0;
    int k = 0;

    memcpy(buffer, "abcdefghijklmnopqrstuvwxyz", 26);
    for (unsigned i = 0; i < SIZE; i++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, &buffer[j++ % 26], 1), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), i+1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), i+1);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, 0, LFS_SEEK_SET), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE);
    for (unsigned i = 0; i < SIZE; i++) {
        uint8_t c;
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, &c, 1), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, c, buffer[k++ % 26]);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), SIZE);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, 0, LFS_SEEK_SET), 0);
    for (unsigned i = 0; i < SIZE; i++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, &buffer[j++ % 26], 1), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), i+1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), i+1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE);
        if (i < SIZE-2) {
            uint8_t c[3];
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, -1, LFS_SEEK_CUR), i);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, &c, 3), 3);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), i+3);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, i+1, LFS_SEEK_SET), i+1);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), i+1);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE);
        }
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, 0, LFS_SEEK_SET), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE);
    for (unsigned i = 0; i < SIZE; i++) {
        uint8_t c;
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, &c, 1), 1);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, c, buffer[k++ % 26]);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), SIZE);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SIZE);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

void test_case6(
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

    // test case 6
    #line 313 "tests/test_seek.toml"
    err = lfs_mount(&lfs, &cfg);
    if (err) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    }
    err = lfs_file_open(&lfs, &file, "kitty", LFS_O_RDONLY);
    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, !err || err == LFS_ERR_NOENT, true);
    if (!err) {
        if (lfs_file_size(&lfs, &file) != 0) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), 11*COUNT);
            for (int j = 0; j < COUNT; j++) {
                memset(buffer, 0, 11+1);
                __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 11), 11);
                __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", 11) == 0 ||
                       memcmp(buffer, "doggodogdog", 11) == 0, true);
            }
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "kitty", LFS_O_WRONLY | LFS_O_CREAT), 0);
    if (lfs_file_size(&lfs, &file) == 0) {
        for (int j = 0; j < COUNT; j++) {
            strcpy((char*)buffer, "kittycatcat");
            size = strlen((char*)buffer);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
        }
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    strcpy((char*)buffer, "doggodogdog");
    size = strlen((char*)buffer);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "kitty", LFS_O_RDWR), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), COUNT*size);
    // seek and write using quadratic probing to touch all
    // 11-byte words in the file
    lfs_off_t off = 0;
    for (int j = 0; j < COUNT; j++) {
        off = (5*off + 1) % COUNT;
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, off*size, LFS_SEEK_SET), off*size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, memcmp(buffer, "kittycatcat", size) == 0 ||
               memcmp(buffer, "doggodogdog", size) == 0, true);
        if (memcmp(buffer, "doggodogdog", size) != 0) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, off*size, LFS_SEEK_SET), off*size);
            strcpy((char*)buffer, "doggodogdog");
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, off*size, LFS_SEEK_SET), off*size);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
            __LFS_ASSERT_MEM_EQ(__FILE__, __LINE__, buffer, "doggodogdog", size);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_sync(&lfs, &file), 0);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, off*size, LFS_SEEK_SET), off*size);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
            __LFS_ASSERT_MEM_EQ(__FILE__, __LINE__, buffer, "doggodogdog", size);
        }
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "kitty", LFS_O_RDWR), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), COUNT*size);
    for (int j = 0; j < COUNT; j++) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_MEM_EQ(__FILE__, __LINE__, buffer, "doggodogdog", size);
    }
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
    extern void test_case1(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 1 && perm == 1)) { test_case1(132, 4); }
    extern void test_case1(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 1 && perm == 2)) { test_case1(132, 128); }
    extern void test_case1(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 1 && perm == 3)) { test_case1(200, 10); }
    extern void test_case1(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 1 && perm == 4)) { test_case1(200, 100); }
    extern void test_case1(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 1 && perm == 5)) { test_case1(4, 1); }
    extern void test_case1(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 1 && perm == 6)) { test_case1(4, 2); }
    extern void test_case2(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 2 && perm == 1)) { test_case2(132, 4); }
    extern void test_case2(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 2 && perm == 2)) { test_case2(132, 128); }
    extern void test_case2(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 2 && perm == 3)) { test_case2(200, 10); }
    extern void test_case2(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 2 && perm == 4)) { test_case2(200, 100); }
    extern void test_case2(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 2 && perm == 5)) { test_case2(4, 1); }
    extern void test_case2(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 2 && perm == 6)) { test_case2(4, 2); }
    extern void test_case3();
    if (argc < 3 || (case_ == 3 && perm == 1)) { test_case3(); }
    extern void test_case4(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 4 && perm == 1)) { test_case4(132, 4); }
    extern void test_case4(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 4 && perm == 2)) { test_case4(132, 128); }
    extern void test_case4(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 4 && perm == 3)) { test_case4(200, 10); }
    extern void test_case4(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 4 && perm == 4)) { test_case4(200, 100); }
    extern void test_case4(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 4 && perm == 5)) { test_case4(4, 2); }
    extern void test_case4(intmax_t COUNT, intmax_t SKIP);
    if (argc < 3 || (case_ == 4 && perm == 6)) { test_case4(4, 3); }
    extern void test_case5(intmax_t SIZE);
    if (argc < 3 || (case_ == 5 && perm == 1)) { test_case5(2); }
    extern void test_case5(intmax_t SIZE);
    if (argc < 3 || (case_ == 5 && perm == 2)) { test_case5(4); }
    extern void test_case5(intmax_t SIZE);
    if (argc < 3 || (case_ == 5 && perm == 3)) { test_case5(128); }
    extern void test_case5(intmax_t SIZE);
    if (argc < 3 || (case_ == 5 && perm == 4)) { test_case5(132); }
    extern void test_case6(intmax_t COUNT);
    if (argc < 3 || (case_ == 6 && perm == 1)) { test_case6(4); }
    extern void test_case6(intmax_t COUNT);
    if (argc < 3 || (case_ == 6 && perm == 2)) { test_case6(64); }
    extern void test_case6(intmax_t COUNT);
    if (argc < 3 || (case_ == 6 && perm == 3)) { test_case6(128); }
}
