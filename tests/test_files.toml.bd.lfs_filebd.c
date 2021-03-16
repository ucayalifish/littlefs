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
#line 1 "bd/lfs_filebd.c"
/*
 * Block device emulated in a file
 *
 * Copyright (c) 2017, Arm Limited. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "bd/lfs_filebd.h"

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int lfs_filebd_createcfg(const struct lfs_config *cfg, const char *path,
        const struct lfs_filebd_config *bdcfg) {
    LFS_FILEBD_TRACE("lfs_filebd_createcfg(%p {.context=%p, "
                ".read=%p, .prog=%p, .erase=%p, .sync=%p, "
                ".read_size=%"PRIu32", .prog_size=%"PRIu32", "
                ".block_size=%"PRIu32", .block_count=%"PRIu32"}, "
                "\"%s\", "
                "%p {.erase_value=%"PRId32"})",
            (void*)cfg, cfg->context,
            (void*)(uintptr_t)cfg->read, (void*)(uintptr_t)cfg->prog,
            (void*)(uintptr_t)cfg->erase, (void*)(uintptr_t)cfg->sync,
            cfg->read_size, cfg->prog_size, cfg->block_size, cfg->block_count,
            path, (void*)bdcfg, bdcfg->erase_value);
    lfs_filebd_t *bd = cfg->context;
    bd->cfg = bdcfg;

    // open file
    bd->fd = open(path, O_RDWR | O_CREAT, 0666);
    if (bd->fd < 0) {
        int err = -errno;
        LFS_FILEBD_TRACE("lfs_filebd_createcfg -> %d", err);
        return err;
    }

    LFS_FILEBD_TRACE("lfs_filebd_createcfg -> %d", 0);
    return 0;
}

int lfs_filebd_create(const struct lfs_config *cfg, const char *path) {
    LFS_FILEBD_TRACE("lfs_filebd_create(%p {.context=%p, "
                ".read=%p, .prog=%p, .erase=%p, .sync=%p, "
                ".read_size=%"PRIu32", .prog_size=%"PRIu32", "
                ".block_size=%"PRIu32", .block_count=%"PRIu32"}, "
                "\"%s\")",
            (void*)cfg, cfg->context,
            (void*)(uintptr_t)cfg->read, (void*)(uintptr_t)cfg->prog,
            (void*)(uintptr_t)cfg->erase, (void*)(uintptr_t)cfg->sync,
            cfg->read_size, cfg->prog_size, cfg->block_size, cfg->block_count,
            path);
    static const struct lfs_filebd_config defaults = {.erase_value=-1};
    int err = lfs_filebd_createcfg(cfg, path, &defaults);
    LFS_FILEBD_TRACE("lfs_filebd_create -> %d", err);
    return err;
}

int lfs_filebd_destroy(const struct lfs_config *cfg) {
    LFS_FILEBD_TRACE("lfs_filebd_destroy(%p)", (void*)cfg);
    lfs_filebd_t *bd = cfg->context;
    int err = close(bd->fd);
    if (err < 0) {
        err = -errno;
        LFS_FILEBD_TRACE("lfs_filebd_destroy -> %d", err);
        return err;
    }
    LFS_FILEBD_TRACE("lfs_filebd_destroy -> %d", 0);
    return 0;
}

int lfs_filebd_read(const struct lfs_config *cfg, lfs_block_t block,
        lfs_off_t off, void *buffer, lfs_size_t size) {
    LFS_FILEBD_TRACE("lfs_filebd_read(%p, "
                "0x%"PRIx32", %"PRIu32", %p, %"PRIu32")",
            (void*)cfg, block, off, buffer, size);
    lfs_filebd_t *bd = cfg->context;

    // check if read is valid
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, off  % cfg->read_size, 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, size % cfg->read_size, 0);
    __LFS_ASSERT_INT_LT(__FILE__, __LINE__, block, cfg->block_count);

    // zero for reproducability (in case file is truncated)
    if (bd->cfg->erase_value != -1) {
        memset(buffer, bd->cfg->erase_value, size);
    }

    // read
    off_t res1 = lseek(bd->fd,
            (off_t)block*cfg->block_size + (off_t)off, SEEK_SET);
    if (res1 < 0) {
        int err = -errno;
        LFS_FILEBD_TRACE("lfs_filebd_read -> %d", err);
        return err;
    }

    ssize_t res2 = read(bd->fd, buffer, size);
    if (res2 < 0) {
        int err = -errno;
        LFS_FILEBD_TRACE("lfs_filebd_read -> %d", err);
        return err;
    }

    LFS_FILEBD_TRACE("lfs_filebd_read -> %d", 0);
    return 0;
}

int lfs_filebd_prog(const struct lfs_config *cfg, lfs_block_t block,
        lfs_off_t off, const void *buffer, lfs_size_t size) {
    LFS_FILEBD_TRACE("lfs_filebd_prog(%p, 0x%"PRIx32", %"PRIu32", %p, %"PRIu32")",
            (void*)cfg, block, off, buffer, size);
    lfs_filebd_t *bd = cfg->context;

    // check if write is valid
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, off  % cfg->prog_size, 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, size % cfg->prog_size, 0);
    __LFS_ASSERT_INT_LT(__FILE__, __LINE__, block, cfg->block_count);

    // check that data was erased? only needed for testing
    if (bd->cfg->erase_value != -1) {
        off_t res1 = lseek(bd->fd,
                (off_t)block*cfg->block_size + (off_t)off, SEEK_SET);
        if (res1 < 0) {
            int err = -errno;
            LFS_FILEBD_TRACE("lfs_filebd_prog -> %d", err);
            return err;
        }

        for (lfs_off_t i = 0; i < size; i++) {
            uint8_t c;
            ssize_t res2 = read(bd->fd, &c, 1);
            if (res2 < 0) {
                int err = -errno;
                LFS_FILEBD_TRACE("lfs_filebd_prog -> %d", err);
                return err;
            }

            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, c, bd->cfg->erase_value);
        }
    }

    // program data
    off_t res1 = lseek(bd->fd,
            (off_t)block*cfg->block_size + (off_t)off, SEEK_SET);
    if (res1 < 0) {
        int err = -errno;
        LFS_FILEBD_TRACE("lfs_filebd_prog -> %d", err);
        return err;
    }

    ssize_t res2 = write(bd->fd, buffer, size);
    if (res2 < 0) {
        int err = -errno;
        LFS_FILEBD_TRACE("lfs_filebd_prog -> %d", err);
        return err;
    }

    LFS_FILEBD_TRACE("lfs_filebd_prog -> %d", 0);
    return 0;
}

int lfs_filebd_erase(const struct lfs_config *cfg, lfs_block_t block) {
    LFS_FILEBD_TRACE("lfs_filebd_erase(%p, 0x%"PRIx32")", (void*)cfg, block);
    lfs_filebd_t *bd = cfg->context;

    // check if erase is valid
    __LFS_ASSERT_INT_LT(__FILE__, __LINE__, block, cfg->block_count);

    // erase, only needed for testing
    if (bd->cfg->erase_value != -1) {
        off_t res1 = lseek(bd->fd, (off_t)block*cfg->block_size, SEEK_SET);
        if (res1 < 0) {
            int err = -errno;
            LFS_FILEBD_TRACE("lfs_filebd_erase -> %d", err);
            return err;
        }

        for (lfs_off_t i = 0; i < cfg->block_size; i++) {
            ssize_t res2 = write(bd->fd, &(uint8_t){bd->cfg->erase_value}, 1);
            if (res2 < 0) {
                int err = -errno;
                LFS_FILEBD_TRACE("lfs_filebd_erase -> %d", err);
                return err;
            }
        }
    }

    LFS_FILEBD_TRACE("lfs_filebd_erase -> %d", 0);
    return 0;
}

int lfs_filebd_sync(const struct lfs_config *cfg) {
    LFS_FILEBD_TRACE("lfs_filebd_sync(%p)", (void*)cfg);
    // file sync
    lfs_filebd_t *bd = cfg->context;
    int err = fsync(bd->fd);
    if (err) {
        err = -errno;
        LFS_FILEBD_TRACE("lfs_filebd_sync -> %d", 0);
        return err;
    }

    LFS_FILEBD_TRACE("lfs_filebd_sync -> %d", 0);
    return 0;
}
