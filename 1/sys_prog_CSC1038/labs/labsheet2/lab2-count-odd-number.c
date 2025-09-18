#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[10]){
  int count = 0;
  int nums[10];
  for (int i = 0; i < argc; i++){
    nums[i] = atoi(argv[i]);
    if (nums[i] % 2 != 0){
      count++;
    }
  }
  printf("%d\n", count);
  return 0;
}
