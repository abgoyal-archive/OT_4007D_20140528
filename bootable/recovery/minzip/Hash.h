
#ifndef _MINZIP_HASH
#define _MINZIP_HASH

#include "inline_magic.h"

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/* compute the hash of an item with a specific type */
typedef unsigned int (*HashCompute)(const void* item);

typedef int (*HashCompareFunc)(const void* tableItem, const void* looseItem);

typedef void (*HashFreeFunc)(void* ptr);

typedef int (*HashForeachFunc)(void* data, void* arg);

typedef struct HashEntry {
    unsigned int hashValue;
    void* data;
} HashEntry;

#define HASH_TOMBSTONE ((void*) 0xcbcacccd)     // invalid ptr value

typedef struct HashTable {
    int         tableSize;          /* must be power of 2 */
    int         numEntries;         /* current #of "live" entries */
    int         numDeadEntries;     /* current #of tombstone entries */
    HashEntry*  pEntries;           /* array on heap */
    HashFreeFunc freeFunc;
} HashTable;

HashTable* mzHashTableCreate(size_t initialSize, HashFreeFunc freeFunc);

size_t mzHashSize(size_t size);

void mzHashTableClear(HashTable* pHashTable);

void mzHashTableFree(HashTable* pHashTable);

INLINE int mzHashTableNumEntries(HashTable* pHashTable) {
    return pHashTable->numEntries;
}

INLINE int mzHashTableMemUsage(HashTable* pHashTable) {
    return sizeof(HashTable) + pHashTable->tableSize * sizeof(HashEntry);
}

void* mzHashTableLookup(HashTable* pHashTable, unsigned int itemHash, void* item,
    HashCompareFunc cmpFunc, bool doAdd);

bool mzHashTableRemove(HashTable* pHashTable, unsigned int hash, void* item);

int mzHashForeach(HashTable* pHashTable, HashForeachFunc func, void* arg);

typedef struct HashIter {
    void*       data;
    HashTable*  pHashTable;
    int         idx;
} HashIter;
INLINE void mzHashIterNext(HashIter* pIter) {
    int i = pIter->idx +1;
    int lim = pIter->pHashTable->tableSize;
    for ( ; i < lim; i++) {
        void* data = pIter->pHashTable->pEntries[i].data;
        if (data != NULL && data != HASH_TOMBSTONE)
            break;
    }
    pIter->idx = i;
}
INLINE void mzHashIterBegin(HashTable* pHashTable, HashIter* pIter) {
    pIter->pHashTable = pHashTable;
    pIter->idx = -1;
    mzHashIterNext(pIter);
}
INLINE bool mzHashIterDone(HashIter* pIter) {
    return (pIter->idx >= pIter->pHashTable->tableSize);
}
INLINE void* mzHashIterData(HashIter* pIter) {
    assert(pIter->idx >= 0 && pIter->idx < pIter->pHashTable->tableSize);
    return pIter->pHashTable->pEntries[pIter->idx].data;
}


typedef unsigned int (*HashCalcFunc)(const void* item);
void mzHashTableProbeCount(HashTable* pHashTable, HashCalcFunc calcFunc,
    HashCompareFunc cmpFunc);

#endif /*_MINZIP_HASH*/
