

#include <stdio.h>

#ifndef __ENCRYPTEDFS_PROVISIONING_H__
#define __ENCRYPTEDFS_PROVISIONING_H__

#define MODE_ENCRYPTED_FS_DISABLED    0
#define MODE_ENCRYPTED_FS_ENABLED     1

#define ENCRYPTED_FS_OK               0
#define ENCRYPTED_FS_ERROR          (-1)

#define ENCRYPTED_FS_KEY_SIZE        16
#define ENCRYPTED_FS_SALT_SIZE       16
#define ENCRYPTED_FS_MAX_HASH_SIZE  128
#define ENTROPY_MAX_SIZE        4096

struct encrypted_fs_info {
    int mode;
    char key[ENCRYPTED_FS_KEY_SIZE];
    char salt[ENCRYPTED_FS_SALT_SIZE];
    int salt_length;
    char hash[ENCRYPTED_FS_MAX_HASH_SIZE];
    int hash_length;
    char entropy[ENTROPY_MAX_SIZE];
    int entropy_length;
};

typedef struct encrypted_fs_info encrypted_fs_info;

int read_encrypted_fs_info(encrypted_fs_info *secure_fs_data);

int restore_encrypted_fs_info(encrypted_fs_info *secure_data);

#endif /* __ENCRYPTEDFS_PROVISIONING_H__ */

