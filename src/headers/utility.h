#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include "shared.h"

void throw(void (*printerFunction)(void*), ...);

void notImplementedError();
void missingArgumentError(char*);
void invalidDataTypeFlagError(byte);

void help();

#endif
