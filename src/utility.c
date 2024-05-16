#include "utility.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* STRING VALIDATION */
int validateStringIsInt(char *str) {
  int iterator;

  for (iterator = 0; iterator < strlen(str); iterator++) {
    if (!isdigit(str[iterator])) return 0;
  }

  return 1;
}

int validateStringIsFloat(char *str) {
  byte decimalSeen = 0;
  int iterator;

  for (iterator = 0; iterator < strlen(str); iterator++) {
    if (str[iterator] == '.' && !decimalSeen) {
      decimalSeen = 0;
      continue;
    }
    else if (str[iterator] == '.' && decimalSeen) return 0;

    if (!isdigit(str[iterator])) return 0;
  }

  return 1;
}

/* ERROR HANDLING */
/* accepts either no arguments or 1 argument. */
void throw(void (*printerFunction)(void*), ...){
  va_list ap;

  va_start(ap, printerFunction);
  printerFunction(va_arg(ap, void*));
  va_end(ap);

  exit(1);
}

void notImplementedError() {
  printf("Not yet implemented.\n");
}

void missingArgumentError(char *arg) {
  printf("Error: missing argument to %s\n", arg);
}

void invalidArgumentInputError(char *arg) {
  printf("Error: argument %s received invalid input\n", arg);
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
