

#ifndef MINZIP_DIRUTIL_H_
#define MINZIP_DIRUTIL_H_

#include <stdbool.h>
#include <utime.h>

int dirCreateHierarchy(const char *path, int mode,
        const struct utimbuf *timestamp, bool stripFileName);

int dirUnlinkHierarchy(const char *path);

int dirSetHierarchyPermissions(const char *path,
         int uid, int gid, int dirMode, int fileMode);

#endif  // MINZIP_DIRUTIL_H_
