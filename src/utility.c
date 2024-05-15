#include "utility.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void throw(void (*printer)(void*), ...) {
  va_list ap;

  va_start(ap, printer);
  // only use one argument
  printer(va_arg(ap, void*));
  va_end(ap);

  exit(1);
   
  return;
}

void notImplementedError() {
  printf("Not yet implemented.\n");
}

void missingArgumentError(char *arg) {
  printf("Error: missing argument to %s\n", arg);
}

void invalidDataTypeFlagError(byte dataTypeSelected) {
  printf("Internal error: invalid data type flag is selected.\n");
  printf("Value of data type flag: 0x%x\n", dataTypeSelected);
}
