ifneq ($(TARGET_SIMULATOR),true)

ifeq ($(TARGET_ARCH),arm)
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := applypatch.c bspatch.c freecache.c imgpatch.c utils.c
LOCAL_MODULE := libapplypatch
LOCAL_MODULE_TAGS := eng user
LOCAL_C_INCLUDES += external/bzip2 external/zlib bootable/recovery
LOCAL_STATIC_LIBRARIES += libmtdutils libmincrypt libbz libz

ifeq ($(MTK_EMMC_SUPPORT),yes)
LOCAL_CFLAGS += -DMTK_EMMC_PLATFORM
endif

include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := main.c
LOCAL_MODULE := applypatch
LOCAL_C_INCLUDES += bootable/recovery
LOCAL_STATIC_LIBRARIES += libapplypatch libmtdutils libmincrypt libbz
LOCAL_SHARED_LIBRARIES += libz libcutils libstdc++ libc

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := main.c
LOCAL_MODULE := applypatch_static
LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_MODULE_TAGS := eng user
LOCAL_C_INCLUDES += bootable/recovery
LOCAL_STATIC_LIBRARIES += libapplypatch libmtdutils libmincrypt libbz
LOCAL_STATIC_LIBRARIES += libz libcutils libstdc++ libc

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := imgdiff.c utils.c bsdiff.c
LOCAL_MODULE := imgdiff
LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_MODULE_TAGS := eng user
LOCAL_C_INCLUDES += external/zlib external/bzip2
LOCAL_STATIC_LIBRARIES += libz libbz

include $(BUILD_HOST_EXECUTABLE)

endif   # TARGET_ARCH == arm
endif  # !TARGET_SIMULATOR
