cmd_lib/reciprocal_div.o := arm-eabi-gcc -Wp,-MD,lib/.reciprocal_div.o.d  -nostdinc -isystem /local/build/sourcecode/vL3V/prebuilt/linux-x86/toolchain/arm-eabi-4.4.3/bin/../lib/gcc/arm-eabi/4.4.3/include -I/local/build/sourcecode/vL3V/kernel/arch/arm/include -Iinclude  -include include/generated/autoconf.h -I..//mediatek/custom/jrdhz75_gb2_sensors/common -I../mediatek/platform/mt6575/kernel/core/include/ -I../mediatek/source/kernel/include/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/alsps/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/leds/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/battery/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/accelerometer/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/kpd/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/rtc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/headset/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/core/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/dct/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/camera/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/touchpanel/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/usb/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/alsps/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/leds/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/magnetometer/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/accelerometer/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/lcm/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/lcm/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/barometer/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/lens/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/lens/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/./ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/jogball/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/sound/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/sound/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/imgsensor/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/imgsensor/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/eeprom/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/eeprom/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/hdmi/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/gyroscope/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/flashlight/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/flashlight/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/sensors/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/audioflinger/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/camera/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/bluetooth/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/fmradio/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/lens/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/imgsensor/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/eeprom/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/ant/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/combo/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/flashlight/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/vt/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/matv/ -D__KERNEL__ -mlittle-endian -DMODEM_3G -I../mediatek/platform/mt6575/kernel/core/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -marm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -mabi=aapcs-linux -mno-thumb-interwork -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -DMTK_WAPI_SUPPORT -DMTK_SENSOR_SUPPORT -DCUSTOM_KERNEL_ALSPS -DCUSTOM_KERNEL_ACCELEROMETER -DMTK_BT_SUPPORT -DMTK_FM_SUPPORT -DMTK_CAMERA_APP_3DHW_SUPPORT -DMTK_M4U_SUPPORT -DMTK_WLAN_SUPPORT -DMTK_BT_21_SUPPORT -DMTK_BT_30_SUPPORT -DMTK_BT_40_SUPPORT -DMTK_BT_PROFILE_OPP -DMTK_BT_PROFILE_SIMAP -DMTK_BT_PROFILE_PRXM -DMTK_BT_PROFILE_PRXR -DMTK_BT_PROFILE_HIDH -DMTK_BT_PROFILE_FTP -DMTK_BT_PROFILE_PBAP -DMTK_BT_PROFILE_MANAGER -DMTK_BT_PROFILE_BPP -DMTK_BT_PROFILE_BIP -DMTK_BT_PROFILE_DUN -DMTK_BT_PROFILE_PAN -DMTK_BT_PROFILE_HFP -DMTK_BT_PROFILE_A2DP -DMTK_BT_PROFILE_AVRCP -DMTK_BT_PROFILE_AVRCP14 -DMTK_BT_PROFILE_MAPS -DMTK_BT_PROFILE_MAPC -DMTK_BT_PROFILE_SPP -DMTK_WIFI_HOTSPOT_SUPPORT -DMTK_FM_SUPPORT -DHAVE_XLOG_FEATURE -DMTK_AUTO_DETECT_ACCELEROMETER -DMTK_MAV_SUPPORT -DMTK_HDR_SUPPORT -DMTK_CAMERA_BSP_SUPPORT -DMTK_AUTORAMA_SUPPORT -DMTK_IPV6_SUPPORT -DMTK_FM_RECORDING_SUPPORT -DMTK_USES_HD_VIDEO -DMTK_COMBO_QUICK_SLEEP_SUPPORT -DMTK_COMBO_CORE_DUMP_SUPPORT -DMTK_PRODUCT_INFO_SUPPORT -DMT6575 -DMT6628_FM -DMTK_MT6628 -DHI253_YUV -DGC0328_YUV -DSP0718_YUV -DDUMMY -DDUMMY_LENS -DFM_ANALOG_INPUT -DMTK_GPS_MT6628 -DMT6628 -DMODEM_3G -DNT35510_6575_DSI -DILI9488_6575_DSI -DDUMMY_FLASHLIGHT -DMT6628 -DLCM_WIDTH=\"320\" -DLCM_HEIGHT=\"480\" -DMTK_LCM_PHYSICAL_ROTATION=\"0\" -DMTK_SHARE_MODEM_SUPPORT=\"2\" -DMTK_SHARE_MODEM_CURRENT=\"2\" -DUSER_BUILD_KERNEL -Wframe-larger-than=1024 -fno-stack-protector -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack   -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(reciprocal_div)"  -D"KBUILD_MODNAME=KBUILD_STR(reciprocal_div)"  -c -o lib/reciprocal_div.o lib/reciprocal_div.c

deps_lib/reciprocal_div.o := \
  lib/reciprocal_div.c \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/div64.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/system.h \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/fa526.h) \
    $(wildcard include/config/arch/has/barriers.h) \
    $(wildcard include/config/arm/dma/mem/bufferable.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/cpu/sa1100.h) \
    $(wildcard include/config/cpu/sa110.h) \
    $(wildcard include/config/cpu/32v6k.h) \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/linkage.h \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/preempt/monitor.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  include/linux/typecheck.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/irqflags.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
    $(wildcard include/config/arm/thumb.h) \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/hwcap.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/outercache.h \
    $(wildcard include/config/outer/cache/sync.h) \
    $(wildcard include/config/outer/cache.h) \
  include/asm-generic/cmpxchg-local.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/linux/posix_types.h \
  include/linux/stddef.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/posix_types.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  include/linux/reciprocal_div.h \

lib/reciprocal_div.o: $(deps_lib/reciprocal_div.o)

$(deps_lib/reciprocal_div.o):
