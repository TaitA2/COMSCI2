/*
Author: Adam Tait
Date: 10/12/2025
Description: This program accepts a list of integers as command line arguments and prints the largest possible sum of two adjacent elements.
Approach:
- Cast arguments as integers and store in an array
- iterate through the int array
- check if the current element is less than the next element and their sum is greater than the current known maximum,
- if so, replace the maximum
- after iterating, return the maximum sum
- print the result
- free all dynamically allocated memory
*/

// import relevant libraries
#include <stdio.h>
#include <stdlib.h>

// function header to convert arguments to array of ints
int *arrtoi(int arrLen, char *nums[]);
// function header to find largest sum of increasing adjacent pair of elements in an array of ints
int maxSum(int arrLen, int *nums);

// main function
int main(int argc, char *argv[]){
  // convert arguments to array of ints
  int *nums = arrtoi(argc-1, argv);
  // find the largest possible sum of increasing adjacent pairs
  int max = maxSum(argc-1, nums);
  // print the result
  printf("%d\n", max);
  // free used memory
  free(nums);
  // exit without error
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

// function to find largest sum of increasing adjacent pair of elements in an array of ints
int maxSum(int arrLen, int *nums){
  int max = 0;
  for (int i = 0; i < arrLen-1; i++){
    if (nums[i] < nums[i+1] && nums[i]+nums[i+1] > max){
      max = nums[i]+nums[i+1];
    }
  }
  return max;
}
