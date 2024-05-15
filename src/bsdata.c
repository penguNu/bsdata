#include "bsdata.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void throwNotImplementedError() {
  printf("Not yet implemented.\n");

  exit(1);
}

void throwMissingArgumentError(char *arg) {
  printf("Error: missing argument to %s\n", arg);

  exit(1);
}

void throwInvalidDataTypeFlagError(byte dataTypeSelected) {
  printf("Internal error: invalid data type flag is selected.\n");
  printf("Value of data type flag: %x\n", dataTypeSelected);

  exit(1);
}

void parseArgs(int argc, char **argv) {
  int iterator;

  /* state tracking */
  byte dataTypeSelectedFlag = 0;

  int *list;
  int listLength = DEFAULT_LIST_LENGTH; // unless specified in args, generate list of default length

  for (iterator = 1; iterator < argc; iterator++) {
    /* help */
    if (strcmp(argv[iterator], "-h") == 0 || strcmp(argv[iterator], "--help") == 0) {
      throwNotImplementedError();
    }

    /* specify length of generated list */
    if (strcmp(argv[iterator], "-l") == 0 || strcmp(argv[iterator], "--length") == 0) {
      // if there are no more arguments then the user screwed up
      if (iterator + 1 == argc) throwMissingArgumentError(argv[iterator]);

      listLength = atoi(argv[iterator + 1]);
    }
  }

  // no data type selected, set the type to the default
  dataTypeSelectedFlag = DEFAULT_DATA_TYPE;
  
  if (dataTypeSelectedFlag == TYPE_INT) {
    list = generateUnboundedNumberOfIntegers(listLength);
    printIntegerList(list, listLength);
    free(list);
  }
  else if (dataTypeSelectedFlag == TYPE_FLOAT) {
    throwNotImplementedError();
  }
  else if (dataTypeSelectedFlag == TYPE_CHAR) {
    throwNotImplementedError();
  }
  else if (dataTypeSelectedFlag == TYPE_STRING) {
    throwNotImplementedError();
  }
  else {
    throwInvalidDataTypeFlagError(dataTypeSelectedFlag);
  }

  return; 
}

int main(int argc, char** argv) {
  // seed RNG
  initializeGenerator();

  parseArgs(argc, argv);

  return 0;
}
