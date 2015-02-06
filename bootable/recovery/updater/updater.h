

#ifndef _UPDATER_UPDATER_H_
#define _UPDATER_UPDATER_H_

#include <stdio.h>
#include "minzip/Zip.h"

typedef struct {
    FILE* cmd_pipe;
    ZipArchive* package_zip;
    int version;
} UpdaterInfo;

#endif
