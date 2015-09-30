#ifndef __IP_ADDR_H__
#define __IP_ADDR_H__

#include "c_types.h"

struct ip_addr {
    uint32 addr;
};

typedef struct ip_addr ip_addr_t;

struct ip_info {
    struct ip_addr ip;
    struct ip_addr netmask;
    struct ip_addr gw;
};

#define IP4_ADDR(ipaddr, a,b,c,d) \
        (ipaddr)->addr = ((uint32)((d) & 0xff) << 24) | \
                         ((uint32)((c) & 0xff) << 16) | \
                         ((uint32)((b) & 0xff) << 8)  | \
                          (uint32)((a) & 0xff)

/**
 * Determine if two address are on the same network.
 *
 * @arg addr1 IP address 1
 * @arg addr2 IP address 2
 * @arg mask network identifier mask
 * @return !0 if the network identifiers of both address match
 */
#define ip_addr_netcmp(addr1, addr2, mask) (((addr1)->addr & \
        (mask)->addr) == \
        ((addr2)->addr & \
         (mask)->addr))

/** Set an IP address given by the four byte-parts.
    Little-endian version that prevents the use of htonl. */
#define IP4_ADDR(ipaddr, a,b,c,d) \
        (ipaddr)->addr = ((uint32)((d) & 0xff) << 24) | \
                         ((uint32)((c) & 0xff) << 16) | \
                         ((uint32)((b) & 0xff) << 8)  | \
                          (uint32)((a) & 0xff)

#define ip4_addr1(ipaddr) (((uint8*)(ipaddr))[0])
#define ip4_addr2(ipaddr) (((uint8*)(ipaddr))[1])
#define ip4_addr3(ipaddr) (((uint8*)(ipaddr))[2])
#define ip4_addr4(ipaddr) (((uint8*)(ipaddr))[3])

#define ip4_addr1_16(ipaddr) ((uint16)ip4_addr1(ipaddr))
#define ip4_addr2_16(ipaddr) ((uint16)ip4_addr2(ipaddr))
#define ip4_addr3_16(ipaddr) ((uint16)ip4_addr3(ipaddr))
#define ip4_addr4_16(ipaddr) ((uint16)ip4_addr4(ipaddr))


/** 255.255.255.255 */
#define IPADDR_NONE         ((uint32)0xffffffffUL)
/** 0.0.0.0 */
#define IPADDR_ANY          ((uint32)0x00000000UL)
#define ip_addr_isany(addr1) ((addr1) == NULL || (addr1)->addr == IPADDR_ANY)
uint32 ipaddr_addr(const char *cp);

/** IPv4 only: set the IP address given as an u32_t */
#define ip4_addr_set_u32(dest_ipaddr, src_u32) ((dest_ipaddr)->addr = (src_u32))
/** IPv4 only: get the IP address as an u32_t */
#define ip4_addr_get_u32(src_ipaddr) ((src_ipaddr)->addr)

#define IP2STR(ipaddr) ip4_addr1_16(ipaddr), \
    ip4_addr2_16(ipaddr), \
    ip4_addr3_16(ipaddr), \
    ip4_addr4_16(ipaddr)

#define IPSTR "%d.%d.%d.%d"

#endif /* __IP_ADDR_H__ */
