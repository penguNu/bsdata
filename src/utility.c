#include "utility.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* ERROR HANDLING */
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

/* HELP SCREEN */

void _printEmptyLine() {
  printf("\n");
}

void _printStrln(char *text) {
  printf("%s\n", text);
}

void _printSection(char *name) {
  printf("  %s\n", name);
}

void _printOption(char *option, char *description) {
  printf("    %-30s \t%s\n", option, description);
}

void help() {
  printf("Usage: bsdata [OPTIONS...]\n\n");

  _printOption("-h, --help,", "prints this help screen");
  _printEmptyLine();

  /* general options */
  _printSection("General options");
  _printOption("-l, --length NUMBER,", "generate a data set with size of NUMBER");
}
