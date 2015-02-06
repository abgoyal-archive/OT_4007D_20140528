
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/vfs.h>
#include <stdarg.h>
#include <libgen.h>
#include "minzip/SysUtil.h"
#include "minzip/DirUtil.h"
#include "minzip/Zip.h"
#include "backup_restore.h"

int main(int argc, char **argv)
{
    int ret = 0;
    if (argc == 2) {
        ret = check_ota(argv[1]);
        printf("%d", ret);
        return ret; 
    } else {
        ret = ERROR_INVALID_ARGS;
        printf("%d", ret);
        return ret;
    }
}

