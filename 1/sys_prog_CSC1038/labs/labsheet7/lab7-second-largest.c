/*
Author: Adam Tait
Date: 26/10/25
Description: Find and print the second largest number in given arguments
*/

#include <stdio.h>
#include <stdlib.h>

// function header to convert strings to floats
void getNums(int size, char *argv[], float *nums);
// function header to find second largest number in an array of floats
float secondLargest(int size, float *nums);

// main function
int main(int argc, char *argv[]) {
  // set size int to number of floats entered
  int size = argc - 1;
  // initialise nums array of floats
  float *nums = malloc(size * sizeof(float));
  // convert string arguments to floats
  getNums(size, argv, nums);
  // find the second largest number
  float ans = secondLargest(size, nums);
  // print the result
  printf("%.1f\n", ans);
  // free all used memory
  free(nums);
  // exit with no error
  return 0;
}

// function to convert strings to floats
void getNums(int size, char *argv[], float *nums) {
  for (int i = 0; i < size; i++) {
    nums[i] = atof(argv[i + 1]);
  }
}

// function to find second largest number in an array of floats
float secondLargest(int size, float *nums) {
  // initialise largest and second largest floats to 0
  float largest = 0;
  float secondLargest = 0;
  // iterate over all the numbers
  for (int i = 0; i < size; i++) {
    // demote the largest to second largest and replace largest with current
    // number if its bigger
    if (nums[i] > largest) {
      secondLargest = largest;
      largest = nums[i];
      // otherwise replace second largest if its bigger and not the largest
    } else if (nums[i] > secondLargest && nums[i] != largest) {
      secondLargest = nums[i];
    }
  }
  // return the result
  return secondLargest;
}
