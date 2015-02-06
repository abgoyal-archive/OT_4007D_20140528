

#include <stdio.h>

#include "utils.h"

/** Write a 4-byte value to f in little-endian order. */
void Write4(int value, FILE* f) {
  fputc(value & 0xff, f);
  fputc((value >> 8) & 0xff, f);
  fputc((value >> 16) & 0xff, f);
  fputc((value >> 24) & 0xff, f);
}

/** Write an 8-byte value to f in little-endian order. */
void Write8(long long value, FILE* f) {
  fputc(value & 0xff, f);
  fputc((value >> 8) & 0xff, f);
  fputc((value >> 16) & 0xff, f);
  fputc((value >> 24) & 0xff, f);
  fputc((value >> 32) & 0xff, f);
  fputc((value >> 40) & 0xff, f);
  fputc((value >> 48) & 0xff, f);
  fputc((value >> 56) & 0xff, f);
}

int Read2(void* pv) {
    unsigned char* p = pv;
    return (int)(((unsigned int)p[1] << 8) |
                 (unsigned int)p[0]);
}

int Read4(void* pv) {
    unsigned char* p = pv;
    return (int)(((unsigned int)p[3] << 24) |
                 ((unsigned int)p[2] << 16) |
                 ((unsigned int)p[1] << 8) |
                 (unsigned int)p[0]);
}

long long Read8(void* pv) {
    unsigned char* p = pv;
    return (long long)(((unsigned long long)p[7] << 56) |
                       ((unsigned long long)p[6] << 48) |
                       ((unsigned long long)p[5] << 40) |
                       ((unsigned long long)p[4] << 32) |
                       ((unsigned long long)p[3] << 24) |
                       ((unsigned long long)p[2] << 16) |
                       ((unsigned long long)p[1] << 8) |
                       (unsigned long long)p[0]);
}
