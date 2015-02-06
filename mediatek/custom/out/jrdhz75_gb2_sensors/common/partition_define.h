
#ifndef __PARTITION_DEFINE_H__
#define __PARTITION_DEFINE_H__




#define KB  (1024)
#define MB  (1024 * KB)
#define GB  (1024 * MB)

#define PART_SIZE_PRELOADER			(512*KB)
#define PART_SIZE_DSP_BL			(1536*KB)
#define PART_SIZE_PRO_INFO			(1024*KB)
#define PART_SIZE_NVRAM			(3072*KB)
#define PART_SIZE_SECCFG			(256*KB)
#define PART_SIZE_UBOOT			(512*KB)
#define PART_SIZE_BOOTIMG			(10240*KB)
#define PART_SIZE_RECOVERY			(6144*KB)
#define PART_SIZE_SEC_RO			(2304*KB)
#define PART_SIZE_MISC			(512*KB)
#define PART_SIZE_LOGO			(3072*KB)
#define PART_SIZE_EXPDB			(768*KB)
#define PART_SIZE_ANDROID			(138240*KB)
#define PART_SIZE_CUSTPACK			(117760*KB)
#define PART_SIZE_MOBILE_INFO			(2304*KB)
#define PART_SIZE_CACHE			(61440*KB)
#define PART_SIZE_USRDATA			(0*KB)
#define PART_SIZE_BMTPOOL			(0x50)
#define PART_NUM			18
#define MBR_START_ADDRESS_BYTE			(*1024)



#endif