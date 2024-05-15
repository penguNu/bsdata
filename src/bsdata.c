#include "bsdata.h"
#include <stdlib.h>
#include <string.h>

void parseArgs(int argc, char **argv) {
  int iterator;

  /* state tracking */
  byte dataTypeSelectedFlag = 0;

  int *list;
  int listLength = DEFAULT_LIST_LENGTH; // unless specified in args, generate list of default length

  for (iterator = 1; iterator < argc; iterator++) {
    /* print help */
    if (strcmp(argv[iterator], "-h") == 0 || strcmp(argv[iterator], "--help") == 0) {
      help();
      return;
    }

    /* specify length of generated list */
    if (strcmp(argv[iterator], "-l") == 0 || strcmp(argv[iterator], "--length") == 0) {
      // if there are no more arguments then the user screwed up
      if (iterator + 1 == argc) missingArgumentError(argv[iterator]);

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
    throw(notImplementedError);
  }
  else if (dataTypeSelectedFlag == TYPE_CHAR) {
    throw(notImplementedError);
  }
  else if (dataTypeSelectedFlag == TYPE_STRING) {
    throw(notImplementedError);
  }
  else {
    throw((void*)invalidDataTypeFlagError, dataTypeSelectedFlag);
  }

  return; 
}

int main(int argc, char** argv) {
  // seed RNG
  initializeGenerator();

  parseArgs(argc, argv);

  return 0;
}
