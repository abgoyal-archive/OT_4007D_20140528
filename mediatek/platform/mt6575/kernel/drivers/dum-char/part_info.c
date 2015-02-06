#include "dumchar.h"
#include "part_info.h"
struct excel_info PartInfo[PART_NUM]={
			{"preloader",524288,0x0},
			{"dsp_bl",1572864,0x80000},
			{"pro_info",1048576,0x200000},
			{"nvram",3145728,0x300000},
			{"seccfg",262144,0x600000},
			{"uboot",524288,0x640000},
			{"bootimg",10485760,0x6c0000},
			{"recovery",6291456,0x10c0000},
			{"sec_ro",2359296,0x16c0000},
			{"misc",524288,0x1900000},
			{"logo",3145728,0x1980000},
			{"expdb",786432,0x1c80000},
			{"android",141557760,0x1d40000},
			{"custpack",120586240,0xa440000},
			{"mobile_info",2359296,0x11740000},
			{"cache",62914560,0x11980000},
			{"usrdata",0,0x15580000},
			{"bmtpool",51200,0xFFFF0050},
 };

EXPORT_SYMBOL(PartInfo);
