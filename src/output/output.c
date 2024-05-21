#include "output.h"
#include <stdio.h>

void printIntegerList(int *list, int length) {
  int iterator;

  if (!list)
    return;

  for (iterator = 0; iterator < length; iterator++)
    printf("%d\n", list[iterator]);

  return;
}
