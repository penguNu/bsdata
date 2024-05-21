#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include "shared.h"

int validateStringIsInt(char *);
int validateStringIsFloat(char *);

void throw (void (*)(void *), ...);

void notImplementedError();
void missingArgumentError(char *);
void invalidArgumentInputError(char *);
void invalidDataTypeFlagError(byte);

void help();

#endif
