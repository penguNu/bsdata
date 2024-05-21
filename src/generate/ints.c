#include "generate.h"
#include <stdlib.h>

int *generateUnboundedNumberOfIntegers(int numberOfIntegers) {
  int *list;
  int iterator;

  list = createEmptyList(numberOfIntegers);

  if (!list)
    return NULL;

  for (iterator = 0; iterator < numberOfIntegers; iterator++)
    list[iterator] = rand();

  return list;
}

int *generateUpperBoundedNumberOfIntegers(int numberOfIntegers, int bound) {
  int *list;
  int iterator;
  int randomNumber;

  list = createEmptyList(numberOfIntegers);

  if (!list)
    return NULL;

  for (iterator = 0; iterator < numberOfIntegers; iterator++) {
    randomNumber = rand();

    if (randomNumber > bound)
      randomNumber = bound - (randomNumber - bound);

    list[iterator] = randomNumber;
  }

  return list;
}

int *generateLowerBoundedNumberOfIntegers(int numberOfIntegers, int bound) {
  int *list;
  int iterator;
  int randomNumber;

  list = createEmptyList(numberOfIntegers);

  if (!list)
    return NULL;

  for (iterator = 0; iterator < numberOfIntegers; iterator++) {
    randomNumber = rand();

    if (randomNumber < bound)
      randomNumber = bound + (bound - randomNumber);

    list[iterator] = randomNumber;
  }

  return list;
}

/* nothing below here is implemented yet */

int *generateBoundedNumberOfIntegers(int numberOfIntegers, int lowerBound, int upperBound) {
  return NULL;
}
