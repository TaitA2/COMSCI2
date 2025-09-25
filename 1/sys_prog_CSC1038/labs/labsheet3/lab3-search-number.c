#include <stdio.h>
#include <stdlib.h>

int searchx(int size, char *arr[]);
int main(int argc, char *argv[]){
  if (searchx(argc, argv) == -1){
    printf("number not found\n");
    return 0;
  }
  printf("Found %d at %d\n", atoi(argv[1]), searchx(argc, argv));
}

int searchx(int size, char *arr[]){
  int target = atoi(arr[1]);
  for (int i = 2; i < size; i++){
    int n = atoi(arr[i]);
    if (n == target){
      return i-2;
    }
  }
  return -1;
}
