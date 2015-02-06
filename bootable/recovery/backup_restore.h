
#ifndef BACKUP_RESTORE_H
#define BACKUP_RESTORE_H

int userdata_backup(void);
int userdata_restore(char *filename, int mode);
int check_part_size(ZipArchive *zip);
int check_ota(const char *filename);
extern char backup_path[PATH_MAX];
extern int part_size_changed;

enum {
    CHECK_OK = 0,
    ERROR_INVALID_ARGS,
    ERROR_OTA_FILE,
    ERROR_FILE_OPEN,
    ERROR_FILE_WRITE,
    ERROR_OUT_OF_MEMORY,
    ERROR_PARTITION_SETTING,
    ERROR_ONLY_FULL_CHANGE_SIZE,
    ERROR_ACCESS_SD,
    ERROR_ACCESS_USERDATA,
    ERROR_SD_FREE_SPACE,
    ERROR_SD_WRITE_PROTECTED,
    ERROR_USERDATA_FREE_SPACE,
    ERROR_MATCH_DEVICE,
    ERROR_DIFFERENTIAL_VERSION,
    ERROR_BUILD_PROP,
    NEED_TO_CHECK_FREE_SD,
};

int special_factory_reset(void);
#endif //BACKUP_RESTORE_H

