#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int nums[argc];
  int count = 0;
  for (int i = 1; i < argc; i++){
    nums[i] = atoi(argv[i]);
    if (nums[i] % 2 == 0){
      printf("%d - %d\n", i-1, nums[i]);
      count++;
     }
  }
  if (count == 0){
    printf("Not found!\n");
  }
  return 0;
}
