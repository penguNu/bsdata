#include "generate.h"
#include <stdlib.h>
#include <time.h>         // for seeding (srand)

void initializeGenerator() {
#ifndef GENERATOR_INITIALIZED
#define GENERATOR_INITIALIZED
  srand(time(NULL));
#endif
}

int *createEmptyList(int numberOfIntegers) {
  return malloc(sizeof(int) * numberOfIntegers);
}

