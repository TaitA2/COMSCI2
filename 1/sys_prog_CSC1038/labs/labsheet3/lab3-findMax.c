#include <stdio.h>
#include <stdlib.h>

int maximum(int size, char *arr[]);
int main(int argc, char *argv[]){
  printf("%d\n", maximum(argc, argv));
}

int maximum(int size, char *arr[]){
  int max = 0;
  for (int i = 0; i < size; i++){
    int n = atoi(arr[i]);
    if (n > max){
      max = n;
    }
  }
  return max;
}
