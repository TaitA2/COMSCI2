/*
Author: Adam Tait
Date: 26/10/25
Description: Find and print the largest number which is at leas twice as large
as another
*/

#include <stdio.h>
#include <stdlib.h>

// function header to convert strings to ints
void getNums(int size, char *argv[], int *nums);
// function header to find largest number in an array of ints
int getLargest(int size, int *nums);
// function header to find smallest number in an array of ints
int getSmallest(int size, int *nums);

// main function
int main(int argc, char *argv[]) {
  // set size int to number of ints entered
  int size = argc - 1;
  // initialise nums array of ints
  int *nums = malloc(size * sizeof(int));
  // convert string arguments to ints
  getNums(size, argv, nums);
  // find the smallest number
  int smallest = getSmallest(size, nums);
  // find the largest number
  int ans = getLargest(size, nums);
  // print the result if its at least twice as big as
  printf("%d\n", ans >= smallest * 2 ? ans : 0);
  // free all used memory
  free(nums);
  // exit with no error
  return 0;
}

// function to convert strings to ints
void getNums(int size, char *argv[], int *nums) {
  for (int i = 0; i < size; i++) {
    nums[i] = atof(argv[i + 1]);
  }
}

// function to find largest number in an array of ints
int getLargest(int size, int *nums) {
  // initialise largest to 0
  int largest = 0;

  // iterate over all the numbers
  for (int i = 0; i < size; i++) {
    // replace largest if current num is bigger
    if (nums[i] > largest) {
      largest = nums[i];
    }
  }
  // return the result
  return largest;
}

// function to find the smallest number in an array of ints
int getSmallest(int size, int *nums) {
  // initialise smallest to first num
  int smallest = nums[0];

  // iterate over all the numbers
  for (int i = 0; i < size; i++) {
    // replace smallest if current num is bigger
    if (nums[i] < smallest) {
      smallest = nums[i];
    }
  }
  // return the result
  return smallest;
}
