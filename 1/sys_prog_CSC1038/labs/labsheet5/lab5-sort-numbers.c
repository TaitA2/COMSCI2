/*
Author: Adam Tait
Date: 10/10/2025
Description: This program sorts an array of integers using different sorting
orders (asc / desc) selected through function pointers.
Arguments:
number of integers (int)
list of integers
sorting order (asc or desc) char*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// header for sort function
void sort(int nums[], int left, int right, char *order);
int main(int argc, char *argv[]) {
  // terminate early if too few arguments entered
  if (argc <= 2) {
    printf("Invalid number of arguments\n");
    return 0;
  }
  // set n to the number of integers to sort
  int n = atoi(argv[1]);
  // terminate early if wrong number of ints entered
  if (argc - 3 != n) {
    printf("Invalid number of arguments\n");
    return 0;
  }
  // set a char * as the order specified by the last argument
  char *order = argv[n + 2];
  // declare int array of size n - 1
  int nums[n - 1];

  // iterate over arguments and cast them as ints in the nums arr
  for (int i = 0; i < n; i++) {
    nums[i] = atoi(argv[i + 2]);
  }

  // return early if invalid order specified
  if (strcmp(order, "asc") != 0 && strcmp(order, "desc") != 0) {
    printf("Invalid order: %s\n", order);
    return 0;
  }

  // sort the array using quick sort
  int left = 0;
  int right = sizeof(nums) / sizeof(nums[0]);
  sort(nums, left, right, order);

  // print out the sorted array in order specified
  printf("Sorted numbers:");
  for (int i = 0; i < n; i++) {
    if (strcmp(order, "asc") == 0) {
      printf(" %d", nums[i]);
    } else {
      printf(" %d", nums[n - i - 1]);
    }
  }
  printf("\n");

  return 0;
}

// function to sort nums array in place in specified order
// quick sort
void sort(int nums[], int left, int right, char *order) {
  // edge case for when the sort is finished
  if (left >= right) {
    return;
  }
  // set pivot value to the right most item in arr
  int pivot = nums[right];
  // set i to below start index of target slice of the arr
  int i = left - 1;

  // iterate between left and right indices
  for (int j = left; j < right; j++) {
    // if the element is less than the pivot, swap i and j
    if (nums[j] < pivot) {
      // increment i before swap to target first element in arr portion
      i++;
      if (i == j) {
        continue;
      }
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    }
  }
  // increase i and swap the leftmost and rightmost unsorted elements
  i++;
  int temp = nums[i];
  nums[i] = nums[right];
  nums[right] = temp;
  // continue recursively on left and right portions of the array
  sort(nums, i + 1, right, order);
  sort(nums, left, i - 1, order);
}
