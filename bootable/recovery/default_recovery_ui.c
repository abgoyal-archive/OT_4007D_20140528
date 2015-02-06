

#include <linux/input.h>

#include "recovery_ui.h"
#include "common.h"
#include "cust_keys.h"

char* MENU_HEADERS[] = { "Android system recovery utility",
                         "",
                         NULL };

char* MENU_ITEMS[] = { "reboot system now",
                       "apply update from sdcard",
                       "wipe data/factory reset",
                       "wipe cache partition",
#ifdef SUPPORT_DATA_BACKUP_RESTORE //wschen 2011-03-09 
                       "backup user data",
                       "restore user data",
#endif
                       NULL };

char* MENU_FORCE_ITEMS[] = { "reboot system now",
                             "apply sdcard:update.zip",
                             NULL };

int device_recovery_start() {
    return 0;
}

int device_toggle_display(volatile char* key_pressed, int key_code) {
    return key_code == KEY_HOME;
}

int device_reboot_now(volatile char* key_pressed, int key_code) {
    return 0;
}

int device_handle_key(int key_code, int visible) {
    if (visible) {
        switch (key_code) {
            //case RECOVERY_KEY_DOWN:
            case RECOVERY_KEY_VOLDOWN:
                return HIGHLIGHT_DOWN;

            //case RECOVERY_KEY_UP:
            case RECOVERY_KEY_VOLUP:
                return HIGHLIGHT_UP;

            case RECOVERY_KEY_CENTER:
                return SELECT_ITEM;
        }
    }

    return NO_ACTION;
}

int device_perform_action(int which) {
    return which;
}

int device_wipe_data() {
    return 0;
}
