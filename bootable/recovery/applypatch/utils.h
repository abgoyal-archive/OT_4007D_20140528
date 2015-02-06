

#ifndef _BUILD_TOOLS_APPLYPATCH_UTILS_H
#define _BUILD_TOOLS_APPLYPATCH_UTILS_H

#include <stdio.h>

// Read and write little-endian values of various sizes.

void Write4(int value, FILE* f);
void Write8(long long value, FILE* f);
int Read2(void* p);
int Read4(void* p);
long long Read8(void* p);

#endif //  _BUILD_TOOLS_APPLYPATCH_UTILS_H
