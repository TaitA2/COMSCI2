/*
Author: Adam Tait
Date: 22/11/25
Description: convert up to 8 binary digits to decimal
*/

// include relevent libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum bits as 8
const int maxBits = 8;

// function header for converting bit chars to a decimal number
void binToDec(char *bits[], int bitCount, int *decimal);

// main function
int main(int argc, char *argv[]) {
  // return early if too many bits entered
  int bitCount = argc - 1;
  if (bitCount > maxBits) {
    printf("Too many binary digits entered.\n");
    return 0;
  }

  // calculate and print decimal value
  int decimal = 0;
  binToDec(argv, bitCount, &decimal);
  printf("%d\n", decimal);

  // exit with no error
  return 0;
}

// function for converting bit chars to a decimal number
void binToDec(char *bits[], int bitCount, int *decimal) {
  // iterate through bits
  for (int i = 0; i < bitCount; i++) {
    // exit early if invalid input
    if (strcmp(bits[i + 1], "1") != 0 && strcmp(bits[i + 1], "0") != 0) {
      printf("Only digits 1 and 0 are permitted.\n");
      exit(0);
    }
    int bit = atoi(bits[i + 1]);
    // shift the bit by its power and add to decimal
    *decimal += bit << (bitCount - i - 1);
  }
}
