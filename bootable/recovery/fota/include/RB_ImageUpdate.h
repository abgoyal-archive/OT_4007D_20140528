
#ifndef	__RB_IMAGEUPDATE_H__
#define	__RB_IMAGEUPDATE_H__

#include "RbErrors.h"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */


	   /*********************************************************
	  **					C O N F I D E N T I A L             **
	 **						  Copyright 2002-2010                **
	  **                         Red Bend Ltd.                  **
	   **********************************************************/



/* RB_UpdateParams - Defines advanced parameters for Image Update */
typedef struct RB_UpdateParams {
	unsigned long isBackgroundUpdate;
	unsigned long maxReaders;
	unsigned long written_sectors;
} RB_UpdateParams;

/* RB_SectionData - define section boundaries for old and new sections using offset and size */
typedef struct tag__RbSectionData {
	unsigned long old_offset;
	unsigned long old_size;
	unsigned long new_offset;
	unsigned long new_size;
	unsigned long ram_size;
	unsigned long bg_ram_size;
} RB_SectionData;

RB_RETCODE RB_ImageUpdate(
    void *pbUserData,					/* User data passed to all porting routines */
    unsigned long dwStartAddress,		/* start address of app to update */
    unsigned long dwEndAddress,			/* end address of app to update */
    unsigned char *pbyRAM,				/* pointer for the ram to use */
    unsigned long dwRAMSize,			/* size of the ram */
    unsigned char *pbyInternalRAM,
    unsigned long dwInternalRAMSize,
    unsigned long *dwBufferBlocks,		/* array of backup buffer block (sector) addresses */
    unsigned long dwNumOfBuffers,		/* number of backup buffer blocks */     
    unsigned long dwOperation,
    unsigned long dwUpdateParamsSize,	/* must be initialized to sizeof(RB_UpdateParams) */
    RB_UpdateParams *updateParams);		/* additional update parameters */

RB_RETCODE RB_ReadSourceBytes(
	void *pbUserData,				/* User data passed to all porting routines. Could be NULL */
    unsigned long address,			/* address of page in flash to retrieve */
    unsigned long size,				/* size of page in flash to retrieve */
    unsigned char *buff,			/* buffer large enough to contain size bytes */
	long section_id);

RB_RETCODE RB_ReadTargetBytes(
	void *pbUserData,				/* User data passed to all porting routines. Could be NULL */
    unsigned long address,			/* address of page in flash to retrieve */
    unsigned long size,				/* size of page in flash to retrieve */
    unsigned char *buff,			/* buffer large enough to contain size bytes */
	long section_id);			


long RB_OpenDelta(void* pbUserData,void* pRAM, long ram_sz);


long RB_GetSectionsData(
	void *pbUserData,					/* User data passed to all porting routines */
	long maxEntries,					/* Maximum number of entries in sectionsArray */
	RB_SectionData *sectionsArray,		/* Array to fill with section information */
	void *pRam,
	long ram_sz);

/* RB_GetDelta() - Get the Delta either as a whole or in block pieces */
long RB_GetDelta(
	void *pbUserData,				    /* User data passed to all porting routines */
	unsigned char *pbBuffer,			/* pointer to user buffer */
    unsigned long dwStartAddressOffset, /* offset from start of delta file */
    unsigned long dwSize);              /* buffer size in bytes */

long RB_ReadBackupBlock(
	void *pbUserData,					/* User data passed to all porting routines */
	unsigned char *pbBuffer,			/* pointer to user buffer in RAM where the data will be copied */
	unsigned long dwBlockAddress,		/* address of data to read into RAM. Must be inside one of the backup buffer blocks */
	unsigned long dwSize);				/* buffer size in bytes */

long RB_EraseBackupBlock(
	void *pbUserData,					/* User data passed to all porting routines */
	unsigned long dwStartAddress);		/* block start address in flash to erase */

long RB_WriteBackupBlock(
	void *pbUserData,					/* User data passed to all porting routines */
	unsigned long dwBlockStartAddress,	/* address of the block to be updated */
	unsigned char *pbBuffer);  	        /* RAM to copy data from */

long RB_WriteBackupPartOfBlock(
	void *pbUserData,					/* User data passed to all porting routines */
	unsigned long dwStartAddress,		/* Start address in flash to write to */
	unsigned long dwSize,				/* Size of data to write */
	unsigned char* pbBuffer);			/* Buffer in RAM to write from */

long RB_WriteBlock(
	void *pbUserData,					/* User data passed to all porting routines */
	unsigned long dwBlockAddress,		/* address of the block to be updated */
	unsigned char *pbBuffer);			/* pointer to data to be written */


long RB_WriteMetadataOfBlock(
	void *pbUserData,					/* User data passed to all porting routines */
	unsigned long dwBlockAddress,		/* address of the block of that the metadata describe */
	unsigned long dwMdSize,				/* Size of the data that the metadata describe*/
	unsigned char *pbMDBuffer);			/* pointer to metadata to be written */
							 

long RB_ReadImage(
	void *pbUserData,					/* User data passed to all porting routines */
	unsigned char *pbBuffer,			/* pointer to user buffer */
    unsigned long dwStartAddress,		/* memory address to read from */
    unsigned long dwSize);				/* number of bytes to copy */

long RB_ReadImageNewKey(
	void *pbUserData,					/* User data passed to all porting routines */
	unsigned char *pbBuffer,
	unsigned long dwStartAddress,
	unsigned long dwSize);

long RB_GetBlockSize(void);/* returns the size of a memory-block */

/* RB_GetUPIVersion() - get the UPI version string */
long RB_GetUPIVersion(unsigned char *pbVersion);			/* Buffer to return the version string in */

//Protocol versions
//get the UPI version string
unsigned long RB_GetUPIProtocolVersion(void);
//get the UPI scout version string
unsigned long RB_GetUPIScoutProtocolVersion(void);
//get the delta UPI version
unsigned long RB_GetDeltaProtocolVersion(void* pbUserData, void* pbyRAM, unsigned long dwRAMSize);		/* User data passed to all porting routines, pointer for the ram to use, size of the ram */
//get the delta scout version
unsigned long RB_GetDeltaScoutProtocolVersion(void* pbUserData, void* pbyRAM, unsigned long dwRAMSize); /* User data passed to all porting routines, pointer for the ram to use, size of the ram */
//get the minimal RAM use for delta expand
unsigned long RB_GetDeltaMinRamUse(void* pbUserData, void* pbyRAM, unsigned long dwRAMSize);			/* User data passed to all porting routines, pointer for the ram to use, size of the ram */

long RB_ResetTimerA(void);

long RB_ResetTimerB(void);

void RB_Progress(
	void *pbUserData,					/* User data passed to all porting routines */
	unsigned long uPercent);			/* progress info in percents */

unsigned long RB_Trace(
	void *pbUserData,					/* User data passed to all porting routines */
	const char *aFormat,...);			/* format string to printf */


typedef enum {
RB_SEMAPHORE_READER = 0,   /* Lock a reader semaphore before reading flash content */
RB_SEMAPHORE_LAST = 50                  /* Last and unused enum value, for sizing arrays, etc. */
} RB_SEMAPHORE;

/*Add the following porting routines (replace the critical section routines):*/

/* RB_SemaphoreInit() - Initialize the specified semaphore to number of available shared resources */
long RB_SemaphoreInit(void *pbUserData, RB_SEMAPHORE semaphore, long num_resources);

/* RB_SemaphoreDestroy() - Destroy the specified semaphore */
long RB_SemaphoreDestroy(void *pbUserData, RB_SEMAPHORE semaphore);

/* RB_SemaphoreDown() - Request to use the resource protected by specified semaphore */
long RB_SemaphoreDown(void *pbUserData, RB_SEMAPHORE semaphore,long num);

/* RB_SemaphoreUp() - Free the resource protected by specified semaphore */
long RB_SemaphoreUp(void *pbUserData, RB_SEMAPHORE semaphore,long num);

void *RB_Malloc(unsigned long size);				/* size in bytes of memory block to allocate */

void RB_Free(void *pMemBlock);					/* pointer to memory block allocated by RB_Malloc() */

#ifdef __cplusplus
	}
#endif  /* __cplusplus */

#endif	/*	__RB_UPDATE_IMAGE_H__	*/
