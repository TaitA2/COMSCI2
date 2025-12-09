#include <stdlib.h>

/*RETURNS ARRAY*/
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

/*IN PLACE*/
// function to cast arguments to array of ints
void arrToi(char *argv[], int *nums, int arrLen) {
  for (int i = 0; i < arrLen; i++) {
    nums[i] = atoi(argv[i + 1]);
  }
}
