#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  if (argc != 5){return 1;}
  int values[3] = {5,2,3,3};
  int total = 0;
  for (int i = 0; i < 4; i++){
    int score = atoi(argv[i+1]);
    if (score < 0) {return 1;}
    total += values[i]*score;
    
  }
  printf("%d\n", total);
  return 0;
}
