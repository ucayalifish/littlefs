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
#line 1 "bd/lfs_testbd.c"
/*
 * Testing block device, wraps filebd and rambd while providing a bunch
 * of hooks for testing littlefs in various conditions.
 *
 * Copyright (c) 2017, Arm Limited. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "bd/lfs_testbd.h"

#include <stdlib.h>


int lfs_testbd_createcfg(const struct lfs_config *cfg, const char *path,
        const struct lfs_testbd_config *bdcfg) {
    LFS_TESTBD_TRACE("lfs_testbd_createcfg(%p {.context=%p, "
                ".read=%p, .prog=%p, .erase=%p, .sync=%p, "
                ".read_size=%"PRIu32", .prog_size=%"PRIu32", "
                ".block_size=%"PRIu32", .block_count=%"PRIu32"}, "
                "\"%s\", "
                "%p {.erase_value=%"PRId32", .erase_cycles=%"PRIu32", "
                ".badblock_behavior=%"PRIu8", .power_cycles=%"PRIu32", "
                ".buffer=%p, .wear_buffer=%p})",
            (void*)cfg, cfg->context,
            (void*)(uintptr_t)cfg->read, (void*)(uintptr_t)cfg->prog,
            (void*)(uintptr_t)cfg->erase, (void*)(uintptr_t)cfg->sync,
            cfg->read_size, cfg->prog_size, cfg->block_size, cfg->block_count,
            path, (void*)bdcfg, bdcfg->erase_value, bdcfg->erase_cycles,
            bdcfg->badblock_behavior, bdcfg->power_cycles,
            bdcfg->buffer, bdcfg->wear_buffer);
    lfs_testbd_t *bd = cfg->context;
    bd->cfg = bdcfg;

    // setup testing things
    bd->persist = path;
    bd->power_cycles = bd->cfg->power_cycles;

    if (bd->cfg->erase_cycles) {
        if (bd->cfg->wear_buffer) {
            bd->wear = bd->cfg->wear_buffer;
        } else {
            bd->wear = lfs_malloc(sizeof(lfs_testbd_wear_t)*cfg->block_count);
            if (!bd->wear) {
                LFS_TESTBD_TRACE("lfs_testbd_createcfg -> %d", LFS_ERR_NOMEM);
                return LFS_ERR_NOMEM;
            }
        }

        memset(bd->wear, 0, sizeof(lfs_testbd_wear_t) * cfg->block_count);
    }

    // create underlying block device
    if (bd->persist) {
        bd->u.file.cfg = (struct lfs_filebd_config){
            .erase_value = bd->cfg->erase_value,
        };
        int err = lfs_filebd_createcfg(cfg, path, &bd->u.file.cfg);
        LFS_TESTBD_TRACE("lfs_testbd_createcfg -> %d", err);
        return err;
    } else {
        bd->u.ram.cfg = (struct lfs_rambd_config){
            .erase_value = bd->cfg->erase_value,
            .buffer = bd->cfg->buffer,
        };
        int err = lfs_rambd_createcfg(cfg, &bd->u.ram.cfg);
        LFS_TESTBD_TRACE("lfs_testbd_createcfg -> %d", err);
        return err;
    }
}

int lfs_testbd_create(const struct lfs_config *cfg, const char *path) {
    LFS_TESTBD_TRACE("lfs_testbd_create(%p {.context=%p, "
                ".read=%p, .prog=%p, .erase=%p, .sync=%p, "
                ".read_size=%"PRIu32", .prog_size=%"PRIu32", "
                ".block_size=%"PRIu32", .block_count=%"PRIu32"}, "
                "\"%s\")",
            (void*)cfg, cfg->context,
            (void*)(uintptr_t)cfg->read, (void*)(uintptr_t)cfg->prog,
            (void*)(uintptr_t)cfg->erase, (void*)(uintptr_t)cfg->sync,
            cfg->read_size, cfg->prog_size, cfg->block_size, cfg->block_count,
            path);
    static const struct lfs_testbd_config defaults = {.erase_value=-1};
    int err = lfs_testbd_createcfg(cfg, path, &defaults);
    LFS_TESTBD_TRACE("lfs_testbd_create -> %d", err);
    return err;
}

int lfs_testbd_destroy(const struct lfs_config *cfg) {
    LFS_TESTBD_TRACE("lfs_testbd_destroy(%p)", (void*)cfg);
    lfs_testbd_t *bd = cfg->context;
    if (bd->cfg->erase_cycles && !bd->cfg->wear_buffer) {
        lfs_free(bd->wear);
    }

    if (bd->persist) {
        int err = lfs_filebd_destroy(cfg);
        LFS_TESTBD_TRACE("lfs_testbd_destroy -> %d", err);
        return err;
    } else {
        int err = lfs_rambd_destroy(cfg);
        LFS_TESTBD_TRACE("lfs_testbd_destroy -> %d", err);
        return err;
    }
}

/// Internal mapping to block devices ///
static int lfs_testbd_rawread(const struct lfs_config *cfg, lfs_block_t block,
        lfs_off_t off, void *buffer, lfs_size_t size) {
    lfs_testbd_t *bd = cfg->context;
    if (bd->persist) {
        return lfs_filebd_read(cfg, block, off, buffer, size);
    } else {
        return lfs_rambd_read(cfg, block, off, buffer, size);
    }
}

static int lfs_testbd_rawprog(const struct lfs_config *cfg, lfs_block_t block,
        lfs_off_t off, const void *buffer, lfs_size_t size) {
    lfs_testbd_t *bd = cfg->context;
    if (bd->persist) {
        return lfs_filebd_prog(cfg, block, off, buffer, size);
    } else {
        return lfs_rambd_prog(cfg, block, off, buffer, size);
    }
}

static int lfs_testbd_rawerase(const struct lfs_config *cfg,
        lfs_block_t block) {
    lfs_testbd_t *bd = cfg->context;
    if (bd->persist) {
        return lfs_filebd_erase(cfg, block);
    } else {
        return lfs_rambd_erase(cfg, block);
    }
}

static int lfs_testbd_rawsync(const struct lfs_config *cfg) {
    lfs_testbd_t *bd = cfg->context;
    if (bd->persist) {
        return lfs_filebd_sync(cfg);
    } else {
        return lfs_rambd_sync(cfg);
    }
}

/// block device API ///
int lfs_testbd_read(const struct lfs_config *cfg, lfs_block_t block,
        lfs_off_t off, void *buffer, lfs_size_t size) {
    LFS_TESTBD_TRACE("lfs_testbd_read(%p, "
                "0x%"PRIx32", %"PRIu32", %p, %"PRIu32")",
            (void*)cfg, block, off, buffer, size);
    lfs_testbd_t *bd = cfg->context;

    // check if read is valid
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, off  % cfg->read_size, 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, size % cfg->read_size, 0);
    __LFS_ASSERT_INT_LT(__FILE__, __LINE__, block, cfg->block_count);

    // block bad?
    if (bd->cfg->erase_cycles && bd->wear[block] >= bd->cfg->erase_cycles &&
            bd->cfg->badblock_behavior == LFS_TESTBD_BADBLOCK_READERROR) {
        LFS_TESTBD_TRACE("lfs_testbd_read -> %d", LFS_ERR_CORRUPT);
        return LFS_ERR_CORRUPT;
    }

    // read
    int err = lfs_testbd_rawread(cfg, block, off, buffer, size);
    LFS_TESTBD_TRACE("lfs_testbd_read -> %d", err);
    return err;
}

int lfs_testbd_prog(const struct lfs_config *cfg, lfs_block_t block,
        lfs_off_t off, const void *buffer, lfs_size_t size) {
    LFS_TESTBD_TRACE("lfs_testbd_prog(%p, "
                "0x%"PRIx32", %"PRIu32", %p, %"PRIu32")",
            (void*)cfg, block, off, buffer, size);
    lfs_testbd_t *bd = cfg->context;

    // check if write is valid
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, off  % cfg->prog_size, 0);
    __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, size % cfg->prog_size, 0);
    __LFS_ASSERT_INT_LT(__FILE__, __LINE__, block, cfg->block_count);

    // block bad?
    if (bd->cfg->erase_cycles && bd->wear[block] >= bd->cfg->erase_cycles) {
        if (bd->cfg->badblock_behavior ==
                LFS_TESTBD_BADBLOCK_PROGERROR) {
            LFS_TESTBD_TRACE("lfs_testbd_prog -> %d", LFS_ERR_CORRUPT);
            return LFS_ERR_CORRUPT;
        } else if (bd->cfg->badblock_behavior ==
                LFS_TESTBD_BADBLOCK_PROGNOOP ||
                bd->cfg->badblock_behavior ==
                LFS_TESTBD_BADBLOCK_ERASENOOP) {
            LFS_TESTBD_TRACE("lfs_testbd_prog -> %d", 0);
            return 0;
        }
    }

    // prog
    int err = lfs_testbd_rawprog(cfg, block, off, buffer, size);
    if (err) {
        LFS_TESTBD_TRACE("lfs_testbd_prog -> %d", err);
        return err;
    }

    // lose power?
    if (bd->power_cycles > 0) {
        bd->power_cycles -= 1;
        if (bd->power_cycles == 0) {
            // sync to make sure we persist the last changes
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_rawsync(cfg), 0);
            // simulate power loss
            exit(33);
        }
    }

    LFS_TESTBD_TRACE("lfs_testbd_prog -> %d", 0);
    return 0;
}

int lfs_testbd_erase(const struct lfs_config *cfg, lfs_block_t block) {
    LFS_TESTBD_TRACE("lfs_testbd_erase(%p, 0x%"PRIx32")", (void*)cfg, block);
    lfs_testbd_t *bd = cfg->context;

    // check if erase is valid
    __LFS_ASSERT_INT_LT(__FILE__, __LINE__, block, cfg->block_count);

    // block bad?
    if (bd->cfg->erase_cycles) {
        if (bd->wear[block] >= bd->cfg->erase_cycles) {
            if (bd->cfg->badblock_behavior ==
                    LFS_TESTBD_BADBLOCK_ERASEERROR) {
                LFS_TESTBD_TRACE("lfs_testbd_erase -> %d", LFS_ERR_CORRUPT);
                return LFS_ERR_CORRUPT;
            } else if (bd->cfg->badblock_behavior ==
                    LFS_TESTBD_BADBLOCK_ERASENOOP) {
                LFS_TESTBD_TRACE("lfs_testbd_erase -> %d", 0);
                return 0;
            }
        } else {
            // mark wear
            bd->wear[block] += 1;
        }
    }

    // erase
    int err = lfs_testbd_rawerase(cfg, block);
    if (err) {
        LFS_TESTBD_TRACE("lfs_testbd_erase -> %d", err);
        return err;
    }

    // lose power?
    if (bd->power_cycles > 0) {
        bd->power_cycles -= 1;
        if (bd->power_cycles == 0) {
            // sync to make sure we persist the last changes
            __LFS_ASSERT_INT_EQ(__FILE__, __LINE__, lfs_testbd_rawsync(cfg), 0);
            // simulate power loss
            exit(33);
        }
    }

    LFS_TESTBD_TRACE("lfs_testbd_prog -> %d", 0);
    return 0;
}

int lfs_testbd_sync(const struct lfs_config *cfg) {
    LFS_TESTBD_TRACE("lfs_testbd_sync(%p)", (void*)cfg);
    int err = lfs_testbd_rawsync(cfg);
    LFS_TESTBD_TRACE("lfs_testbd_sync -> %d", err);
    return err;
}


/// simulated wear operations ///
lfs_testbd_swear_t lfs_testbd_getwear(const struct lfs_config *cfg,
        lfs_block_t block) {
    LFS_TESTBD_TRACE("lfs_testbd_getwear(%p, %"PRIu32")", (void*)cfg, block);
    lfs_testbd_t *bd = cfg->context;

    // check if block is valid
    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, bd->cfg->erase_cycles, true);
    __LFS_ASSERT_INT_LT(__FILE__, __LINE__, block, cfg->block_count);

    LFS_TESTBD_TRACE("lfs_testbd_getwear -> %"PRIu32, bd->wear[block]);
    return bd->wear[block];
}

int lfs_testbd_setwear(const struct lfs_config *cfg,
        lfs_block_t block, lfs_testbd_wear_t wear) {
    LFS_TESTBD_TRACE("lfs_testbd_setwear(%p, %"PRIu32")", (void*)cfg, block);
    lfs_testbd_t *bd = cfg->context;

    // check if block is valid
    __LFS_ASSERT_BOOL_EQ(__FILE__, __LINE__, bd->cfg->erase_cycles, true);
    __LFS_ASSERT_INT_LT(__FILE__, __LINE__, block, cfg->block_count);

    bd->wear[block] = wear;

    LFS_TESTBD_TRACE("lfs_testbd_setwear -> %d", 0);
    return 0;
}
