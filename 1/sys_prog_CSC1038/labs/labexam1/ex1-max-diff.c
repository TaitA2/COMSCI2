/*
Author: Adam Tait
Date: 7/11/25
Description: This program accepts an array of integers as input and displays the
maximum difference between any two elements. i.e the difference between the
smallest and largest elements in the input

Approach:
- iterate through the input
- find the largest and smallest values
- print the largest - the smallest

*/
// include the libraries for input / output
#include <stdio.h>
// include the libraries for type conversions
#include <stdlib.h>

// function header for casting an array of strings to an array of integers
int *arrtoi(int arrLen, char *nums[]);

// function header to take an array of integers and return the maximum
// difference between any two elements
int getMaxDif(int len, int *nums);

// main function
int main(int argc, char *argv[]) {
  // declare array length as 1 less than the number of arguments to exclude
  // command name
  int arrLen = argc - 1;
  // convert array of strings to ints
  int *nums = arrtoi(arrLen, argv);
  // find the maximum difference in the array
  int maxDif = getMaxDif(arrLen, nums);
  // print the result
  printf("%d\n", maxDif);
  // unallocate all used memory
  free(nums);
  // exit with no error
  return 0;
}

// function to convert array of strings to array of ints
int *arrtoi(int arrLen, char *nums[]) {
  // declare a pointer for the integer array and allocate sufficient memory
  int *iNums = malloc(sizeof(int) * arrLen);
  // iterate through the strings
  for (int i = 0; i < arrLen; i++) {
    // cast the strings as ints and store in the int array
    iNums[i] = atoi(nums[i + 1]);
  }
  // return a pointer to the int array
  return iNums;
}

// function to calculate the maximum difference in an array of ints
int getMaxDif(int arrLen, int *nums) {

  // declare the maximum and minimum values
  // uses bitshift operations to initialise as very large and very small values
  int max = -1 << 14;
  int min = 1 << 14;
  // iterate over the integer array
  for (int i = 0; i < arrLen; i++) {
    // replace the minimum if the current int is smaller
    if (nums[i] < min) {
      min = nums[i];
    }
    // replace the maximum if the current int is larger
    if (nums[i] > max) {
      max = nums[i];
    }
  }
  // return the difference between the largest and smallest elements
  return max - min;
}
