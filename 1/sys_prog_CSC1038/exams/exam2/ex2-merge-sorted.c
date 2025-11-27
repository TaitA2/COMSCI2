/*
Author: Adam Tait
Date: 27/11/25
Description: Merge two sorted arrays of ints into a single sorted array and print result.
*/

// import relevant libraries
#include <stdio.h>
#include <stdlib.h>

// function header for casting an array of strings to an array of integers
int *arrtoi(int arrLen, char *nums[], int arrLenA, int arrLenB);
 // function header to convert all arguments to single array of ints
int *mergeArrs(int argc, char *argv[]);
 // function header to print the final array of ints
void printSorted(int *arr, int arrLen);
void sort(int *nums, int left, int right);

// main function
int main(int argc, char *argv[]){
  // get pointer to merged array
  int *merged = mergeArrs(argc,argv);
  // print new array
  printSorted(merged, argc-3);
  // free used memory
  free(merged);
  // exit without error
  return 0;
}

int *mergeArrs(int argc, char *argv[]){
 // find first array length
 int arrLenA = atoi(argv[1]);
 // find second array length
 int arrLenB = atoi(argv[2+arrLenA]);

 // cast args as ints
 int *arr = arrtoi(argc-1, argv, arrLenA, arrLenB);
 sort(arr,0,arrLenA+arrLenB-1);

 return arr;

 
}

int *arrtoi(int arrLen, char *nums[], int arrLenA, int arrLenB) {
  // declare a pointer for the integer array and allocate sufficient memory
  int *iNums = malloc(sizeof(int) * arrLen);
  int k = 0;
  // iterate through the strings
  for (int i = 2; i <= arrLen; i++) {
   if (i != arrLenA+2){
    // cast the strings as ints and store in the int array
    iNums[i-2-k] = atoi(nums[i]);
  }else{k++;}}
  // return a pointer to the int array
  return iNums;
}


void printSorted(int *arr, int arrLen){
 for (int i = 0; i < arrLen;i++){
  printf("%d\n", arr[i]);
 }
 
}

void sort(int nums[], int left, int right) {
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
  sort(nums, i + 1, right);
  sort(nums, left, i - 1);
}
