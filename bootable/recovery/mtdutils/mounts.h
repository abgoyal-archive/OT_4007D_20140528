

#ifndef MTDUTILS_MOUNTS_H_
#define MTDUTILS_MOUNTS_H_

typedef struct MountedVolume MountedVolume;

int scan_mounted_volumes(void);

const MountedVolume *find_mounted_volume_by_device(const char *device);

const MountedVolume *
find_mounted_volume_by_mount_point(const char *mount_point);

int unmount_mounted_volume(const MountedVolume *volume);

int remount_read_only(const MountedVolume* volume);

#endif  // MTDUTILS_MOUNTS_H_
