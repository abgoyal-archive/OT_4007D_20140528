

#ifndef _RECOVERY_BOOTLOADER_H
#define _RECOVERY_BOOTLOADER_H

struct bootloader_message {
    char command[32];
    char status[32];
    char recovery[1024];
};

int get_bootloader_message(struct bootloader_message *out);
int set_bootloader_message(const struct bootloader_message *in);

#endif
