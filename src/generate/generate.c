#include "generate.h"
#include <stdlib.h>
#include <time.h>         // for seeding (srand)

unsigned int seedNumber;

void _srand(unsigned int seed) {
  seedNumber = seed;
  return;
}

void initializeGenerator() {
#ifndef GENERATOR_INITIALIZED
#define GENERATOR_INITIALIZED
  _srand(time(NULL));
#endif
}

int *createEmptyList(int numberOfIntegers) {
  return malloc(sizeof(int) * numberOfIntegers);
}

