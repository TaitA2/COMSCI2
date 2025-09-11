/* Include standard input and output */
#include <stdio.h>
#include <stdlib.h>
/*
Function: Main
Parameters: int a country calling code
returns: int
description: Prints out the country of a given calling code
*/

int main(int argc, char *argv[]) { /* Begin Function */
  int countryCode;
  countryCode = atoi(argv[1]);

  switch (countryCode) {
  case 353:
    printf("Ireland\n");
    break;
  case 44:
    printf("United Kingdom\n");
    break;
  case 33:
    printf("France\n");
    break;
  case 34:
    printf("Spain\n");
    break;
  default:
    printf("Undefined!");
    break;
  }

  return 0;
} /* End function and program*/
