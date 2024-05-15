#include "bsdata.h"
#include <stdlib.h>

int main(int argc, char** argv) {
  int numberOfRandomNumbers = 10000;
  int *listOfRandomNumbers; 

  // seed RNG
  initializeGenerator();

  listOfRandomNumbers = generateUnboundedNumberOfIntegers(numberOfRandomNumbers);
  if (!listOfRandomNumbers) return 1;

  printIntegerList(listOfRandomNumbers, numberOfRandomNumbers);

  free(listOfRandomNumbers);

  return 0;
}
