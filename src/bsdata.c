#include "bsdata.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int* generateUnboundedNumberOfIntegers(int numberOfIntegers) { 
  int *list = malloc(sizeof(int) * numberOfIntegers);
  int iterator;

  for (iterator = 0; iterator < numberOfIntegers; iterator++)
    list[iterator] = rand();

  return list;
}

int main(int argc, char** argv) {
  int numberOfRandomNumbers = 10000;
  int *randomNumbers; 
  int iterator;

  randomNumbers = generateUnboundedNumberOfIntegers(numberOfRandomNumbers);

  // seed RNG
  srand(time(NULL));

  for (iterator = 0; iterator < numberOfRandomNumbers; iterator++)
    printf("%d\n", randomNumbers[iterator]);

  free(randomNumbers);

  return 0;
}
