#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isLeap(int year);
int main(int argc, char *argv[]){
  int start = atoi(argv[1]);
  int end = atoi(argv[2])+1;
  for (int i = start; i < end; i++){
    if (isLeap(i)){
      printf("%d\n", i);
    }
  }
  return 0;
}
bool isLeap(int year){
  if (year % 400 == 0){
    return true;
  }
  if (year % 100 == 0){
    return false;
  }
  if (year % 4 == 0){
    return true;
  }
  return false;
}
