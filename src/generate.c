#include "generate.h"
#include <stdlib.h>
#include <time.h>         // for seeding (srand)

void initializeGenerator() {
  srand(time(NULL));
}

int* generateUnboundedNumberOfIntegers(int numberOfIntegers) { 
  int *list; 
  int iterator;

  list = malloc(sizeof(int) * numberOfIntegers);
  if (!list) return NULL;

  for (iterator = 0; iterator < numberOfIntegers; iterator++)
    list[iterator] = rand();

  return list;
}

/* nothing below here is implemented yet */

int *generateUpperBoundedNumberOfIntegers(int numberOfIntegers, int bound) {
  return NULL;
}

int *generateLowerBoundedNumberOfIntegers(int numberOfIntegers, int bound) {
  return NULL;
}

int *generateBoundedNumberOfIntegers(int numberOfIntegers, int lowerBound, int upperBound) {
  return NULL;
}
