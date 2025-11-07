/*
Author: Adam Tait
Date: 7/11/25
Description: This program prints the index of the element in an array of
integers where the sum of integers before and after it are equal

Approach:
- convert arguments to array of integers
- iterate through the array
- each iteration keeps track of the total value of the integers already parsed
- a second iteration calculates the total value of all later integers
- compare the two totals and print the index where they are the same

*/
// include the libraries for input / output
#include <stdio.h>
// include the libraries for type conversions
#include <stdlib.h>

// function header to convert string arguments to an array of ints
int *getNums(int arrLen, char *argv[]);
// function header to find the index of the balance point in an array of ints
int getBal(int arrLen, int *nums);

// main function
int main(int argc, char *argv[]) {
  // set the array length to 1 less than the arg count to exclude program name
  int arrLen = argc - 1;
  // convert arguments to integer array
  int *nums = getNums(arrLen, argv);
  // find the balance point
  int balancePoint = getBal(arrLen, nums);
  // print the result
  printf("%d\n", balancePoint);
  // exit without error
  return 0;
}

// function to convert string arguments to an array of ints
int *getNums(int arrLen, char *argv[]) {
  // create an integer array and allocate sufficient memory
  int *nums = malloc(arrLen * sizeof(int));
  for (int i = 0; i < arrLen; i++) {
    nums[i] = atoi(argv[i + 1]);
  }
  return nums;
}
// function to find the index of the balance point in an array of ints
int getBal(int arrLen, int *nums) {
  // initaliase the total value of all integers before i as 0
  int leftTotal = 0;
  for (int i = 0; i < arrLen; i++) {
    // initaliase the total value of all integers after i as 0
    int rightTotal = 0;
    // iterate through all upcomming values
    for (int j = i + 1; j < arrLen; j++) {
      // increase the upcoming total by the value
      rightTotal += nums[j];
    }
    // return the index if its a balance point
    if (leftTotal == rightTotal) {
      return i + 1; // +1 since the balance point position is 1-based
    }
    // increase the total value of the integers already seen by the current
    // value
    leftTotal += nums[i];
  }
  // return -1 if there is no balance point
  return -1;
}
