#include <stdio.h>
#include <stdlib.h>

int duplicate(int size, char *arr[]);
int main(int argc, char *argv[]){
  if (duplicate(argc, argv) == -1){
    printf("no duplicated number\n");
    return 0;
  }
  printf("%d\n", duplicate(argc, argv));
}

int duplicate(int size, char *arr[]){
  for (int i = 0; i < size; i++){
    int n = atoi(arr[i]);
    for (int j = i+1; j < size; j++){
      int m = atoi(arr[j]);
      if (n == m){
        return n;
      }
    }
  }
  return -1;
}
