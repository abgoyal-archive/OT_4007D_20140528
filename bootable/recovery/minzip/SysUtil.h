
#ifndef _MINZIP_SYSUTIL
#define _MINZIP_SYSUTIL

#include "inline_magic.h"

#include <sys/types.h>

typedef struct MemMapping {
    void*   addr;           /* start of data */
    size_t  length;         /* length of data */

    void*   baseAddr;       /* page-aligned base address */
    size_t  baseLength;     /* length of mapping */
} MemMapping;

/* copy a map */
INLINE void sysCopyMap(MemMapping* dst, const MemMapping* src) {
    *dst = *src;
}

int sysLoadFileInShmem(int fd, MemMapping* pMap);

int sysMapFileInShmem(int fd, MemMapping* pMap);

int sysMapFileSegmentInShmem(int fd, off_t start, long length,
    MemMapping* pMap);

void sysReleaseShmem(MemMapping* pMap);

#endif /*_MINZIP_SYSUTIL*/
