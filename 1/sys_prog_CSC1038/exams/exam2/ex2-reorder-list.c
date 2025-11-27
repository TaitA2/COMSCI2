#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
  int nums[100];
  int i = 0;
  for (int j = 1; j < argc;j++){
    int n = atoi(argv[j]);
    if (n % 2 == 0){
      printf("%d\n", n);
    } else{
      nums[i] = n;
      i++;
    }
  }
  for (int j = 0; j < i;j++){
    printf("%d\n", nums[j]);
    
  }
}
