#include "bsdata.h"
#include <stdlib.h>

int main(int argc, char** argv) {
  int numberOfRandomNumbers = 10000;
  int *listOfRandomNumbers; 

  // seed RNG
  initializeGenerator();

  listOfRandomNumbers = generateUnboundedNumberOfIntegers(numberOfRandomNumbers);

  printIntegerList(listOfRandomNumbers, numberOfRandomNumbers);

  free(listOfRandomNumbers);

  return 0;
}
