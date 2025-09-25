/*
Author: Adam Tait
Date: 25/09/25
This program is to multiply or divide two numbers as specified by the user
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float multiply(float x, float y);
float divide(float x, float y);
int main(int argc, char *argv[]){
  if (argc != 4){
    printf("Must have 3 arguments!\n");
    return 1;
  }
  char *method = argv[1];
  float x = atof(argv[2]);
  float y = atof(argv[3]);
  if (strcmp(method,"multiply") == 0) {
    printf("%f\n", multiply(x,y));
    
  }else if (strcmp(method,"divide") == 0) {
    if (y == 0){
      printf("invalid\n");
      return 0;
    }
    printf("%f\n", divide(x,y));
    
  }else {
    printf("Invalid method: '%s'\n", method);
  }

  return 0;
}

float multiply(float x, float y){
  return x * y;
}

float divide(float x, float y){
  return x / y;
}
