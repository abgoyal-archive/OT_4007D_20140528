
#ifndef _FILE_SYSTEM_API_H_
#define _FILE_SYSTEM_API_H_



	   /*********************************************************
	  **					C O N F I D E N T I A L             **
	 **						  Copyright 2002-2008                **
	  **                         Red Bend Ltd.                  **
	   **********************************************************/







#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */







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
