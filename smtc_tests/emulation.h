#ifndef LFS_EMULATION_H
#define LFS_EMULATION_H

#include <stdint.h>

struct ip4_addr {
  uint32_t addr;
};

typedef struct ip4_addr ip4_addr_t;

#define IPADDR_NONE         ((uint32_t)0xffffffffUL)
/** 127.0.0.1 */
#define IPADDR_LOOPBACK     ((uint32_t)0x7f000001UL)
/** 0.0.0.0 */
#define IPADDR_ANY          ((uint32_t)0x00000000UL)
/** 255.255.255.255 */
#define IPADDR_BROADCAST    ((uint32_t)0xffffffffUL)

#define TOTAL_BUTTONS   32

#endif //LFS_EMULATION_H
