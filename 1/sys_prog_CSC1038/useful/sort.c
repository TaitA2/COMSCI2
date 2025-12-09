#include <stdio.h>
#include <stdlib.h>

// function header for quick sort
void sort(int nums[], int low, int high);

int main(int argc, char *argv[]) {
  int nums[argc - 1];
  for (int i = 0; i < argc - 1; i++) {
    nums[i] = atoi(argv[i + 1]);
  }

  // quick sort usage
  int low = 0; // set low to 0 (first index of arr)
  int high = sizeof(nums) / sizeof(nums[0]); // set high to length of arr
  // sort arr nums in place
  sort(nums, low, high - 1);

  for (int i = 0; i < high; i++) {
    printf("%d\n", nums[i]);
  }
  return 0;
}
// function for sorting an array of ints in place using quick sort algorithm
void sort(int nums[], int low, int high) {
  if (low < high) {
    int pivot = nums[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
      if (nums[j] < pivot) {
        i++;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }
    i++;
    int temp = nums[i];
    nums[i] = nums[high];
    nums[high] = temp;

    sort(nums, low, i - 1);
    sort(nums, i + 1, high);
  }
}
