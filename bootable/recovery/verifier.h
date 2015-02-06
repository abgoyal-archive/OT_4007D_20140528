

#ifndef _RECOVERY_VERIFIER_H
#define _RECOVERY_VERIFIER_H

#include "mincrypt/rsa.h"

int verify_file(const char* path, const RSAPublicKey *pKeys, unsigned int numKeys);

#define VERIFY_SUCCESS        0
#define VERIFY_FAILURE        1

#endif  /* _RECOVERY_VERIFIER_H */
