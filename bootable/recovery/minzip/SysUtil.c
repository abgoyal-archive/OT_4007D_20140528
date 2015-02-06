
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <limits.h>
#include <errno.h>
#include <assert.h>

#define LOG_TAG "minzip"
#include "Log.h"
#include "SysUtil.h"

#define DEFAULT_PAGE_SIZE   4096


static void* sysCreateAnonShmem(size_t length)
{
    void* ptr;

    ptr = mmap(NULL, length, PROT_READ | PROT_WRITE,
            MAP_SHARED | MAP_ANON, -1, 0);
    if (ptr == MAP_FAILED) {
        LOGW("mmap(%d, RW, SHARED|ANON) failed: %s\n", (int) length,
            strerror(errno));
        return NULL;
    }

    return ptr;
}

static int getFileStartAndLength(int fd, off_t *start_, size_t *length_)
{
    off_t start, end;
    size_t length;

    assert(start_ != NULL);
    assert(length_ != NULL);

    start = lseek(fd, 0L, SEEK_CUR);
    end = lseek(fd, 0L, SEEK_END);
    (void) lseek(fd, start, SEEK_SET);

    if (start == (off_t) -1 || end == (off_t) -1) {
        LOGE("could not determine length of file\n");
        return -1;
    }

    length = end - start;
    if (length == 0) {
        LOGE("file is empty\n");
        return -1;
    }

    *start_ = start;
    *length_ = length;

    return 0;
}

int sysLoadFileInShmem(int fd, MemMapping* pMap)
{
    off_t start;
    size_t length, actual;
    void* memPtr;

    assert(pMap != NULL);

    if (getFileStartAndLength(fd, &start, &length) < 0)
        return -1;

    memPtr = sysCreateAnonShmem(length);
    if (memPtr == NULL)
        return -1;

    actual = read(fd, memPtr, length);
    if (actual != length) {
        LOGE("only read %d of %d bytes\n", (int) actual, (int) length);
        sysReleaseShmem(pMap);
        return -1;
    }

    pMap->baseAddr = pMap->addr = memPtr;
    pMap->baseLength = pMap->length = length;

    return 0;
}

int sysMapFileInShmem(int fd, MemMapping* pMap)
{
    off_t start;
    size_t length;
    void* memPtr;

    assert(pMap != NULL);

    if (getFileStartAndLength(fd, &start, &length) < 0)
        return -1;

    memPtr = mmap(NULL, length, PROT_READ, MAP_FILE | MAP_SHARED, fd, start);
    if (memPtr == MAP_FAILED) {
        LOGW("mmap(%d, R, FILE|SHARED, %d, %d) failed: %s\n", (int) length,
            fd, (int) start, strerror(errno));
        return -1;
    }

    pMap->baseAddr = pMap->addr = memPtr;
    pMap->baseLength = pMap->length = length;

    return 0;
}

int sysMapFileSegmentInShmem(int fd, off_t start, long length,
    MemMapping* pMap)
{
    off_t dummy;
    size_t fileLength, actualLength;
    off_t actualStart;
    int adjust;
    void* memPtr;

    assert(pMap != NULL);

    if (getFileStartAndLength(fd, &dummy, &fileLength) < 0)
        return -1;

    if (start + length > (long)fileLength) {
        LOGW("bad segment: st=%d len=%ld flen=%d\n",
            (int) start, length, (int) fileLength);
        return -1;
    }

    /* adjust to be page-aligned */
    adjust = start % DEFAULT_PAGE_SIZE;
    actualStart = start - adjust;
    actualLength = length + adjust;

    memPtr = mmap(NULL, actualLength, PROT_READ, MAP_FILE | MAP_SHARED,
                fd, actualStart);
    if (memPtr == MAP_FAILED) {
        LOGW("mmap(%d, R, FILE|SHARED, %d, %d) failed: %s\n",
            (int) actualLength, fd, (int) actualStart, strerror(errno));
        return -1;
    }

    pMap->baseAddr = memPtr;
    pMap->baseLength = actualLength;
    pMap->addr = (char*)memPtr + adjust;
    pMap->length = length;

    LOGVV("mmap seg (st=%d ln=%d): bp=%p bl=%d ad=%p ln=%d\n",
        (int) start, (int) length,
        pMap->baseAddr, (int) pMap->baseLength,
        pMap->addr, (int) pMap->length);

    return 0;
}

void sysReleaseShmem(MemMapping* pMap)
{
    if (pMap->baseAddr == NULL && pMap->baseLength == 0)
        return;

    if (munmap(pMap->baseAddr, pMap->baseLength) < 0) {
        LOGW("munmap(%p, %d) failed: %s\n",
            pMap->baseAddr, (int)pMap->baseLength, strerror(errno));
    } else {
        LOGV("munmap(%p, %d) succeeded\n", pMap->baseAddr, pMap->baseLength);
        pMap->baseAddr = NULL;
        pMap->baseLength = 0;
    }
}

