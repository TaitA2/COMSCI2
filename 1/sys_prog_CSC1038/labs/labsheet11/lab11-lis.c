/*
Author: Adam Tait
Date: 22/11/25
Description: Find the longest increasing subsequence in a sequence of numbers
*/

// include relevent libraries
#include <stdio.h>
#include <stdlib.h>

// function header to cast arguments to array of ints
void arrToi(char *argv[], int *nums, int arrLen);
// function header to get longest increasing sequence from array of ints
int getLis(int *nums, int arrLen);

// main function
int main(int argc, char *argv[]) {
  // cast args as ints
  int *nums = malloc(sizeof(int) * argc - 1);
  arrToi(argv, nums, argc - 1);

  // find longest increasing subsequence and print
  int lis = getLis(nums, argc - 1);
  printf("%d\n", lis);

  // exit with no error
  return 0;
}

// function to cast arguments to array of ints
void arrToi(char *argv[], int *nums, int arrLen) {
  for (int i = 0; i < arrLen; i++) {
    nums[i] = atoi(argv[i + 1]);
  }
}

// function to get longest increasing sequence from array of ints
int getLis(int *nums, int arrLen) {
  int lis = 1;
  for (int i = 0; i < arrLen; i++) {
    int highest = nums[i]; // set highest val in sequence to current val
    int is = 1;            // set increasing sequence length to 1
    for (int j = i + 1; j < arrLen; j++) {
      // increase 'is' and override highest val when new highest val found
      // (sequence is increasing)
      if (nums[j] >= highest) {
        is++;
        highest = nums[j];
      }
    }
    // override longest sequence if current is longer
    if (is > lis) {
      lis = is;
    }
  }

  // return the longest increasing sequence
  return lis;
}
