/*
Author: Adam Tait
Date: 10/10/2025
Description: format arguments into country info
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// format function header
// takes arr of strings and returns formatted string with newlines
const char *format(char *info[]);

// main function
int main(int argc, char *argv[]) {
  // initialise function pointer to format
  const char *(*pFormat)(char *[]) = &format;
  // print the result of the pointer functions operation on the arguments
  printf("%s", pFormat(argv));
  return 0;
}

// takes arr of strings and returns formatted string with newlines
const char *format(char *info[]) {
  // initialise formatted string
  char *formatted = malloc(100 * sizeof(char));
  // country
  strcat(formatted, info[1]);
  strcat(formatted, "\n");
  // city
  strcat(formatted, info[2]);
  strcat(formatted, "\n");
  // population
  strcat(formatted, info[3]);
  strcat(formatted, " million people\n");
  // size
  strcat(formatted, info[4]);
  strcat(formatted, " km2\n");
  // return the new string
  return formatted;
}
