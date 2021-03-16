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
#line 1 "tests/test_truncate.toml.test.tc"

//////////////// AUTOGENERATED TEST ////////////////
#include "lfs.h"
#include "bd/lfs_testbd.h"
#include <stdio.h>
extern const char *lfs_testbd_path;
extern uint32_t lfs_testbd_cycles;

#define LARGESIZE 8192
void test_case1(
        __attribute__((unused)) intmax_t MEDIUMSIZE) {
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
    #line 5 "tests/test_truncate.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "baldynoop",
            LFS_O_WRONLY | LFS_O_CREAT), 0);

    strcpy((char*)buffer, "hair");
    size = strlen((char*)buffer);
    for (lfs_off_t j = 0; j < LARGESIZE; j += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), LARGESIZE);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);
    
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "baldynoop", LFS_O_RDWR), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), LARGESIZE);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_truncate(&lfs, &file, MEDIUMSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), MEDIUMSIZE);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "baldynoop", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), MEDIUMSIZE);

    size = strlen("hair");
    for (lfs_off_t j = 0; j < MEDIUMSIZE; j += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hair", size), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LARGESIZE

#define LARGESIZE 8192
void test_case2(
        __attribute__((unused)) intmax_t MEDIUMSIZE) {
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
    #line 49 "tests/test_truncate.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "baldyread",
            LFS_O_WRONLY | LFS_O_CREAT), 0);

    strcpy((char*)buffer, "hair");
    size = strlen((char*)buffer);
    for (lfs_off_t j = 0; j < LARGESIZE; j += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), LARGESIZE);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "baldyread", LFS_O_RDWR), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), LARGESIZE);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_truncate(&lfs, &file, MEDIUMSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), MEDIUMSIZE);

    size = strlen("hair");
    for (lfs_off_t j = 0; j < MEDIUMSIZE; j += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hair", size), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "baldyread", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), MEDIUMSIZE);

    size = strlen("hair");
    for (lfs_off_t j = 0; j < MEDIUMSIZE; j += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hair", size), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LARGESIZE

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
    #line 98 "tests/test_truncate.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "sequence",
            LFS_O_RDWR | LFS_O_CREAT | LFS_O_TRUNC), 0);

    size = lfs_min(lfs.cfg->cache_size, sizeof(buffer)/2);
    lfs_size_t qsize = size / 4;
    uint8_t *wb = buffer;
    uint8_t *rb = buffer + size;
    for (lfs_off_t j = 0; j < size; ++j) {
        wb[j] = j;
    }

    /* Spread sequence over size */
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, wb, size), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), size);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), size);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, 0, LFS_SEEK_SET), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), 0);

    /* Chop off the last quarter */
    lfs_size_t trunc = size - qsize;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_truncate(&lfs, &file, trunc), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), trunc);

    /* Read should produce first 3/4 */
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rb, size), trunc);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rb, wb, trunc), 0);

    /* Move to 1/4 */
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), trunc);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, qsize, LFS_SEEK_SET), qsize);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), qsize);

    /* Chop to 1/2 */
    trunc -= qsize;
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_truncate(&lfs, &file, trunc), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_tell(&lfs, &file), qsize);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), trunc);
    
    /* Read should produce second quarter */
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, rb, size), trunc - qsize);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(rb, wb + qsize, trunc - qsize), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}

#define LARGESIZE 8192
void test_case4(
        __attribute__((unused)) intmax_t MEDIUMSIZE) {
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
    #line 152 "tests/test_truncate.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "baldywrite",
            LFS_O_WRONLY | LFS_O_CREAT), 0);

    strcpy((char*)buffer, "hair");
    size = strlen((char*)buffer);
    for (lfs_off_t j = 0; j < LARGESIZE; j += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), LARGESIZE);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "baldywrite", LFS_O_RDWR), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), LARGESIZE);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_truncate(&lfs, &file, MEDIUMSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), MEDIUMSIZE);

    strcpy((char*)buffer, "bald");
    size = strlen((char*)buffer);
    for (lfs_off_t j = 0; j < MEDIUMSIZE; j += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), MEDIUMSIZE);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "baldywrite", LFS_O_RDONLY), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), MEDIUMSIZE);

    size = strlen("bald");
    for (lfs_off_t j = 0; j < MEDIUMSIZE; j += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "bald", size), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LARGESIZE

#define LARGESIZE 2048
void test_case5(
        __attribute__((unused)) intmax_t MEDIUMSIZE,
        __attribute__((unused)) intmax_t SMALLSIZE) {
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
    #line 205 "tests/test_truncate.toml"
    err = lfs_mount(&lfs, &cfg);
    if (err) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    }
    err = lfs_file_open(&lfs, &file, "baldy", LFS_O_RDONLY);
    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, !err || err == LFS_ERR_NOENT, true);
    if (!err) {
        size = lfs_file_size(&lfs, &file);
        __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, size == 0 ||
                size == LARGESIZE ||
                size == MEDIUMSIZE ||
                size == SMALLSIZE, true);
        for (lfs_off_t j = 0; j < size; j += 4) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, 4), 4);
            __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, memcmp(buffer, "hair", 4) == 0 ||
                   memcmp(buffer, "bald", 4) == 0 ||
                   memcmp(buffer, "comb", 4) == 0, true);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "baldy",
            LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), 0);
    strcpy((char*)buffer, "hair");
    size = strlen((char*)buffer);
    for (lfs_off_t j = 0; j < LARGESIZE; j += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), LARGESIZE);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "baldy", LFS_O_RDWR), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), LARGESIZE);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_truncate(&lfs, &file, MEDIUMSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), MEDIUMSIZE);
    strcpy((char*)buffer, "bald");
    size = strlen((char*)buffer);
    for (lfs_off_t j = 0; j < MEDIUMSIZE; j += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), MEDIUMSIZE);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "baldy", LFS_O_RDWR), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), MEDIUMSIZE);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_truncate(&lfs, &file, SMALLSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SMALLSIZE);
    strcpy((char*)buffer, "comb");
    size = strlen((char*)buffer);
    for (lfs_off_t j = 0; j < SMALLSIZE; j += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), SMALLSIZE);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LARGESIZE

#define LARGESIZE 8192
#define MEDIUMSIZE 2048
#define SMALLSIZE 32
void test_case6(
        __attribute__((unused)) intmax_t CONFIG) {
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
    #line 271 "tests/test_truncate.toml"
    #define COUNT 5
    const struct {
        lfs_off_t startsizes[COUNT];
        lfs_off_t startseeks[COUNT];
        lfs_off_t hotsizes[COUNT];
        lfs_off_t coldsizes[COUNT];
    } configs[] = {
        // cold shrinking
        {{2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE},
         {2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE},
         {2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE},
         {          0,   SMALLSIZE,  MEDIUMSIZE,   LARGESIZE, 2*LARGESIZE}},
        // cold expanding
        {{2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE},
         {2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE},
         {2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE},
         {          0,   SMALLSIZE,  MEDIUMSIZE,   LARGESIZE, 2*LARGESIZE}},
        // warm shrinking truncate
        {{2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE},
         {2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE},
         {          0,   SMALLSIZE,  MEDIUMSIZE,   LARGESIZE, 2*LARGESIZE},
         {          0,           0,           0,           0,           0}},
        // warm expanding truncate
        {{          0,   SMALLSIZE,  MEDIUMSIZE,   LARGESIZE, 2*LARGESIZE},
         {          0,   SMALLSIZE,  MEDIUMSIZE,   LARGESIZE, 2*LARGESIZE},
         {2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE},
         {2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE}},
        // mid-file shrinking truncate
        {{2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE},
         {  LARGESIZE,   LARGESIZE,   LARGESIZE,   LARGESIZE,   LARGESIZE},
         {          0,   SMALLSIZE,  MEDIUMSIZE,   LARGESIZE, 2*LARGESIZE},
         {          0,           0,           0,           0,           0}},
        // mid-file expanding truncate
        {{          0,   SMALLSIZE,   MEDIUMSIZE,  LARGESIZE, 2*LARGESIZE},
         {          0,           0,   SMALLSIZE,  MEDIUMSIZE,   LARGESIZE},
         {2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE},
         {2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE, 2*LARGESIZE}},
    };

    const lfs_off_t *startsizes = configs[CONFIG].startsizes;
    const lfs_off_t *startseeks = configs[CONFIG].startseeks;
    const lfs_off_t *hotsizes   = configs[CONFIG].hotsizes;
    const lfs_off_t *coldsizes  = configs[CONFIG].coldsizes;

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    for (unsigned i = 0; i < COUNT; i++) {
        sprintf(path, "hairyhead%d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path,
                LFS_O_WRONLY | LFS_O_CREAT | LFS_O_TRUNC), 0);

        strcpy((char*)buffer, "hair");
        size = strlen((char*)buffer);
        for (lfs_off_t j = 0; j < startsizes[i]; j += size) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);
        }
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), startsizes[i]);

        if (startseeks[i] != startsizes[i]) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file,
                    startseeks[i], LFS_SEEK_SET), startseeks[i]);
        }

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_truncate(&lfs, &file, hotsizes[i]), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), hotsizes[i]);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    for (unsigned i = 0; i < COUNT; i++) {
        sprintf(path, "hairyhead%d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDWR), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), hotsizes[i]);

        size = strlen("hair");
        lfs_off_t j = 0;
        for (; j < startsizes[i] && j < hotsizes[i]; j += size) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hair", size), 0);
        }

        for (; j < hotsizes[i]; j += size) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "\0\0\0\0", size), 0);
        }

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_truncate(&lfs, &file, coldsizes[i]), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), coldsizes[i]);

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);

    for (unsigned i = 0; i < COUNT; i++) {
        sprintf(path, "hairyhead%d", i);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, path, LFS_O_RDONLY), 0);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), coldsizes[i]);

        size = strlen("hair");
        lfs_off_t j = 0;
        for (; j < startsizes[i] && j < hotsizes[i] && j < coldsizes[i];
                j += size) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hair", size), 0);
        }

        for (; j < coldsizes[i]; j += size) {
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "\0\0\0\0", size), 0);
        }

        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    }

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // epilogue
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_destroy(&cfg), 0);
}
#undef LARGESIZE
#undef MEDIUMSIZE
#undef SMALLSIZE

void test_case7(
        __attribute__((unused)) intmax_t MEDIUMSIZE) {
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
    #line 399 "tests/test_truncate.toml"
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_format(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "baldynoop",
            LFS_O_RDWR | LFS_O_CREAT), 0);

    strcpy((char*)buffer, "hair");
    size = strlen((char*)buffer);
    for (lfs_off_t j = 0; j < MEDIUMSIZE; j += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_write(&lfs, &file, buffer, size), size);

        // this truncate should do nothing
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_truncate(&lfs, &file, j+size), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), MEDIUMSIZE);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_seek(&lfs, &file, 0, LFS_SEEK_SET), 0);
    // should do nothing again
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_truncate(&lfs, &file, MEDIUMSIZE), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), MEDIUMSIZE);

    for (lfs_off_t j = 0; j < MEDIUMSIZE; j += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hair", size), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), 0);

    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_close(&lfs, &file), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_unmount(&lfs), 0);

    // still there after reboot?
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_mount(&lfs, &cfg), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_open(&lfs, &file, "baldynoop", LFS_O_RDWR), 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_size(&lfs, &file), MEDIUMSIZE);
    for (lfs_off_t j = 0; j < MEDIUMSIZE; j += size) {
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), size);
        __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, memcmp(buffer, "hair", size), 0);
    }
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_file_read(&lfs, &file, buffer, size), 0);
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
    extern void test_case1(intmax_t MEDIUMSIZE);
    if (argc < 3 || (case_ == 1 && perm == 1)) { test_case1(32); }
    extern void test_case1(intmax_t MEDIUMSIZE);
    if (argc < 3 || (case_ == 1 && perm == 2)) { test_case1(2048); }
    extern void test_case2(intmax_t MEDIUMSIZE);
    if (argc < 3 || (case_ == 2 && perm == 1)) { test_case2(32); }
    extern void test_case2(intmax_t MEDIUMSIZE);
    if (argc < 3 || (case_ == 2 && perm == 2)) { test_case2(2048); }
    extern void test_case3();
    if (argc < 3 || (case_ == 3 && perm == 1)) { test_case3(); }
    extern void test_case4(intmax_t MEDIUMSIZE);
    if (argc < 3 || (case_ == 4 && perm == 1)) { test_case4(32); }
    extern void test_case4(intmax_t MEDIUMSIZE);
    if (argc < 3 || (case_ == 4 && perm == 2)) { test_case4(2048); }
    extern void test_case5(intmax_t MEDIUMSIZE, intmax_t SMALLSIZE);
    if (argc < 3 || (case_ == 5 && perm == 1)) { test_case5(32, 4); }
    extern void test_case5(intmax_t MEDIUMSIZE, intmax_t SMALLSIZE);
    if (argc < 3 || (case_ == 5 && perm == 2)) { test_case5(32, 512); }
    extern void test_case5(intmax_t MEDIUMSIZE, intmax_t SMALLSIZE);
    if (argc < 3 || (case_ == 5 && perm == 3)) { test_case5(1024, 4); }
    extern void test_case5(intmax_t MEDIUMSIZE, intmax_t SMALLSIZE);
    if (argc < 3 || (case_ == 5 && perm == 4)) { test_case5(1024, 512); }
    extern void test_case6(intmax_t CONFIG);
    if (argc < 3 || (case_ == 6 && perm == 1)) { test_case6(0); }
    extern void test_case6(intmax_t CONFIG);
    if (argc < 3 || (case_ == 6 && perm == 2)) { test_case6(1); }
    extern void test_case6(intmax_t CONFIG);
    if (argc < 3 || (case_ == 6 && perm == 3)) { test_case6(2); }
    extern void test_case6(intmax_t CONFIG);
    if (argc < 3 || (case_ == 6 && perm == 4)) { test_case6(3); }
    extern void test_case6(intmax_t CONFIG);
    if (argc < 3 || (case_ == 6 && perm == 5)) { test_case6(4); }
    extern void test_case6(intmax_t CONFIG);
    if (argc < 3 || (case_ == 6 && perm == 6)) { test_case6(5); }
    extern void test_case7(intmax_t MEDIUMSIZE);
    if (argc < 3 || (case_ == 7 && perm == 1)) { test_case7(32); }
    extern void test_case7(intmax_t MEDIUMSIZE);
    if (argc < 3 || (case_ == 7 && perm == 2)) { test_case7(2048); }
}
