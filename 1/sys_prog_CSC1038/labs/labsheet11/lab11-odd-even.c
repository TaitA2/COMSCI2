/*
Author: Adam Tait
Date: 22/11/25
Description: use bitwise operations to determine if input is odd or even
*/

// include relevent libraries
#include <stdio.h>
#include <stdlib.h>

// main function to print odd or even depending on least significant bit
int main(int argc, char *argv[]) {
  // cast input as integer
  int n = atoi(argv[1]);

  // print answer
  // odd & 1 == 1
  printf("%s\n", n & 1 ? "Odd" : "Even");

  // exit with no error
  return 0;
}
