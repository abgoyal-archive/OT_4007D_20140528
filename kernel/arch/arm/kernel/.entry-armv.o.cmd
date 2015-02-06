cmd_arch/arm/kernel/entry-armv.o := arm-eabi-gcc -Wp,-MD,arch/arm/kernel/.entry-armv.o.d  -nostdinc -isystem /local/build/sourcecode/vL3V/prebuilt/linux-x86/toolchain/arm-eabi-4.4.3/bin/../lib/gcc/arm-eabi/4.4.3/include -I/local/build/sourcecode/vL3V/kernel/arch/arm/include -Iinclude  -include include/generated/autoconf.h -I..//mediatek/custom/jrdhz75_gb2_sensors/common -I../mediatek/platform/mt6575/kernel/core/include/ -I../mediatek/source/kernel/include/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/alsps/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/leds/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/battery/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/accelerometer/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/kpd/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/rtc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/headset/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/core/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/dct/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/camera/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/touchpanel/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/usb/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/alsps/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/leds/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/magnetometer/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/accelerometer/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/lcm/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/lcm/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/barometer/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/lens/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/lens/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/./ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/jogball/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/sound/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/sound/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/imgsensor/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/imgsensor/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/eeprom/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/eeprom/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/hdmi/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/gyroscope/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/flashlight/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/kernel/flashlight/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/sensors/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/audioflinger/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/camera/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/bluetooth/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/inc/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/fmradio/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/lens/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/imgsensor/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/eeprom/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/ant/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/combo/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/flashlight/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/vt/ -I../mediatek/custom/out/jrdhz75_gb2_sensors/hal/matv/ -D__KERNEL__   -mlittle-endian -DMODEM_3G -I../mediatek/platform/mt6575/kernel/core/include -D__ASSEMBLY__   -mabi=aapcs-linux -mno-thumb-interwork  -D__LINUX_ARM_ARCH__=7 -march=armv7-a  -include asm/unified.h -msoft-float -gdwarf-2       -c -o arch/arm/kernel/entry-armv.o arch/arm/kernel/entry-armv.S

deps_arch/arm/kernel/entry-armv.o := \
  arch/arm/kernel/entry-armv.S \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/local/timers.h) \
    $(wildcard include/config/kprobes.h) \
    $(wildcard include/config/aeabi.h) \
    $(wildcard include/config/thumb2/kernel.h) \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/needs/syscall/for/cmpxchg.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/cpu/endian/be8.h) \
    $(wildcard include/config/neon.h) \
    $(wildcard include/config/cpu/arm610.h) \
    $(wildcard include/config/cpu/arm710.h) \
    $(wildcard include/config/iwmmxt.h) \
    $(wildcard include/config/crunch.h) \
    $(wildcard include/config/vfp.h) \
    $(wildcard include/config/arm/thumb.h) \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/memory.h \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/dram/base.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/discontigmem.h) \
  include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/const.h \
  ../mediatek/platform/mt6575/kernel/core/include/mach/memory.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/sizes.h \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/glue.h \
    $(wildcard include/config/cpu/abrt/lv4t.h) \
    $(wildcard include/config/cpu/abrt/ev4.h) \
    $(wildcard include/config/cpu/abrt/ev4t.h) \
    $(wildcard include/config/cpu/abrt/ev5tj.h) \
    $(wildcard include/config/cpu/abrt/ev5t.h) \
    $(wildcard include/config/cpu/abrt/ev6.h) \
    $(wildcard include/config/cpu/abrt/ev7.h) \
    $(wildcard include/config/cpu/pabrt/legacy.h) \
    $(wildcard include/config/cpu/pabrt/v6.h) \
    $(wildcard include/config/cpu/pabrt/v7.h) \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/vfpmacros.h \
    $(wildcard include/config/vfpv3.h) \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/vfp.h \
  ../mediatek/platform/mt6575/kernel/core/include/mach/entry-macro.S \
  ../mediatek/platform/mt6575/kernel/core/include/mach/hardware.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/hardware/gic.h \
  ../mediatek/platform/mt6575/kernel/core/include/mach/mt6575_reg_base.h \
    $(wildcard include/config/base.h) \
  ../mediatek/platform/mt6575/kernel/core/include/mach/irqs.h \
  ../mediatek/platform/mt6575/kernel/core/include/mach/mt6575_irq.h \
    $(wildcard include/config/mt6575/fpga.h) \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/thread_notify.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/unwind.h \
    $(wildcard include/config/arm/unwind.h) \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/unistd.h \
    $(wildcard include/config/oabi/compat.h) \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/tls.h \
    $(wildcard include/config/tls/reg/emul.h) \
    $(wildcard include/config/cpu/32v6k.h) \
  arch/arm/kernel/entry-header.S \
    $(wildcard include/config/frame/pointer.h) \
    $(wildcard include/config/alignment/trap.h) \
    $(wildcard include/config/cpu/v6.h) \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
  include/linux/linkage.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/linkage.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/assembler.h \
    $(wildcard include/config/cpu/feroceon.h) \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/ptrace.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/hwcap.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/asm-offsets.h \
  include/generated/asm-offsets.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/thread_info.h \
    $(wildcard include/config/arm/thumbee.h) \
  /local/build/sourcecode/vL3V/kernel/arch/arm/include/asm/fpstate.h \

arch/arm/kernel/entry-armv.o: $(deps_arch/arm/kernel/entry-armv.o)

$(deps_arch/arm/kernel/entry-armv.o):
