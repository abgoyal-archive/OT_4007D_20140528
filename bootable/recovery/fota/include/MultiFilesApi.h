
#ifndef _REDBEND_MULTI_UPDATE_H_
#define _REDBEND_MULTI_UPDATE_H_
#ifdef M_LOADER_GEN
#include "stdio.h"
#endif



	   /*********************************************************
	  **					C O N F I D E N T I A L             **
	 **						  Copyright 2002-2010                **
	  **                         Red Bend Ltd.                  **
	   **********************************************************/







#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */


	
typedef enum tag_RW_TYPE{
	ONLY_R,
	ONLY_W,
	BOTH_RW
}E_RW_TYPE;
	




//get the version string
long RB_GetUPIVersion(unsigned char* pbVersion);




long RB_CopyFile(
	void* pbUserData,
	const unsigned short* strFromPath,
	const unsigned short* strToPath
);




long RB_DeleteFile( void* pbUserData, const unsigned short* strPath ); 




long RB_DeleteFolder( void* pbUserData, const unsigned short* strPath ); 




long RB_CreateFolder( void* pbUserData, const unsigned short* strPath ); 




long RB_OpenFile(
	void*					pbUserData,
	const unsigned short*	strPath, 
	E_RW_TYPE				wFlag,
	long*					pwHandle
);




long RB_ResizeFile( void* pbUserData, long wHandle, unsigned long dwSize );




long 
RB_CloseFile( void* pbUserData, long wHandle );


	

long RB_WriteFile( 
	void*			pbUserData,
	long			wHandle,
	unsigned long	dwPosition,
	unsigned char*	pbBuffer,
	unsigned long	dwSize
);




long RB_ReadFile( 
	void*			pbUserData,
	long			wHandle,
	unsigned long	dwPosition,
	unsigned char*	pbBuffer,
	unsigned long	dwSize
);


long RB_GetFileSize(
	void*	pbUserData,
	long	wHandle
);


long RB_SetFileReadOnlyAttr( 
	void*					pbUserData,
	const unsigned short*	strPath,
	unsigned long			wReadOnlyAttr
);



long RB_FSGetDelta( 
	unsigned char*	pbBuffer, 
	unsigned long	dwStartAddressOffset, 
	unsigned long	dwSize
);



void RB_FSProgress( void* pbUserData, unsigned long uPercent );

	



long RB_FSTrace(
	void*					pbUserData, 
	const unsigned short*	aFormat,
	...
);

/* Prints a string like the C printf() function */
unsigned long RB_Trace(void* pUser, const char * aFormat,...);	/* debug string to printf */



long RB_FSGetDelta(
	unsigned char* pbBuffer,
	unsigned long dwStartAddressOffset,
	unsigned long dwSize
);







long
RB_FileSystemUpdate(
	void*					pbUserData,
	const unsigned short*	strRootSourcePath,
	const unsigned short*	strRootTargetPath,
	const unsigned short*	strTempPath,
	const unsigned short*	strDeltaPath,
	unsigned char*			pbyRAM, 
	unsigned long			dwRAMSize,
	unsigned long			wOperation
);


#ifdef __cplusplus
	}
#endif	/* __cplusplus */

#endif
