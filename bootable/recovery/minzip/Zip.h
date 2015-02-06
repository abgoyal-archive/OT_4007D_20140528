
#ifndef _MINZIP_ZIP
#define _MINZIP_ZIP

#include "inline_magic.h"

#include <stdlib.h>
#include <utime.h>

#include "Hash.h"
#include "SysUtil.h"

typedef struct ZipEntry {
    unsigned int fileNameLen;
    const char*  fileName;       // not null-terminated
    long         offset;
    long         compLen;
    long         uncompLen;
    int          compression;
    long         modTime;
    long         crc32;
    int          versionMadeBy;
    long         externalFileAttributes;
} ZipEntry;

typedef struct ZipArchive {
    int         fd;
    unsigned int numEntries;
    ZipEntry*   pEntries;
    HashTable*  pHash;          // maps file name to ZipEntry
    MemMapping  map;
} ZipArchive;

typedef struct {
    const char *str;
    size_t len;
} UnterminatedString;

int mzOpenZipArchive(const char* fileName, ZipArchive* pArchive);

void mzCloseZipArchive(ZipArchive* pArchive);


const ZipEntry* mzFindZipEntry(const ZipArchive* pArchive,
        const char* entryName);

INLINE unsigned int mzZipEntryCount(const ZipArchive* pArchive) {
    return pArchive->numEntries;
}

INLINE const ZipEntry*
mzGetZipEntryAt(const ZipArchive* pArchive, unsigned int index)
{
    if (index < pArchive->numEntries) {
        return pArchive->pEntries + index;
    }
    return NULL;
}

INLINE unsigned int
mzGetZipEntryIndex(const ZipArchive *pArchive, const ZipEntry *pEntry) {
    return pEntry - pArchive->pEntries;
}

INLINE UnterminatedString mzGetZipEntryFileName(const ZipEntry* pEntry) {
    UnterminatedString ret;
    ret.str = pEntry->fileName;
    ret.len = pEntry->fileNameLen;
    return ret;
}
INLINE long mzGetZipEntryOffset(const ZipEntry* pEntry) {
    return pEntry->offset;
}
INLINE long mzGetZipEntryUncompLen(const ZipEntry* pEntry) {
    return pEntry->uncompLen;
}
INLINE long mzGetZipEntryModTime(const ZipEntry* pEntry) {
    return pEntry->modTime;
}
INLINE long mzGetZipEntryCrc32(const ZipEntry* pEntry) {
    return pEntry->crc32;
}
bool mzIsZipEntrySymlink(const ZipEntry* pEntry);


typedef bool (*ProcessZipEntryContentsFunction)(const unsigned char *data,
    int dataLen, void *cookie);

bool mzProcessZipEntryContents(const ZipArchive *pArchive,
    const ZipEntry *pEntry, ProcessZipEntryContentsFunction processFunction,
    void *cookie);

bool mzReadZipEntry(const ZipArchive* pArchive, const ZipEntry* pEntry,
        char* buf, int bufLen);

bool mzIsZipEntryIntact(const ZipArchive *pArchive, const ZipEntry *pEntry);

bool mzExtractZipEntryToFile(const ZipArchive *pArchive,
    const ZipEntry *pEntry, int fd);

bool mzExtractZipEntryToBuffer(const ZipArchive *pArchive,
    const ZipEntry *pEntry, unsigned char* buffer);

enum { MZ_EXTRACT_FILES_ONLY = 1, MZ_EXTRACT_DRY_RUN = 2 };
bool mzExtractRecursive(const ZipArchive *pArchive,
        const char *zipDir, const char *targetDir,
        int flags, const struct utimbuf *timestamp,
        void (*callback)(const char *fn, void*), void *cookie);

#endif /*_MINZIP_ZIP*/
