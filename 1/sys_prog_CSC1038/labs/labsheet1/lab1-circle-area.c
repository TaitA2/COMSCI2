// include standard io and standard library
#include <stdio.h>
#include <stdlib.h>

// define global constant PI as 3.14 to test reduced accuracy
#define PI 3.1415

// main function takes argument count and array of arguments
int main(int argc, char *argv[]){
  //initialise radius ^ 2
  int r2;
  // initialise radius to 0
  int radius = 0;
  // override radius with argument if provided
  if (argc > 1){radius = atoi(argv[1]);}

  // initialise the area as 0.0 float
  float area = 0.0f;
  // calculate r^2 as r*r
  r2 = radius * radius;
  // calculate area as pi*r^2
  area = r2*PI;
  // print area to 2 decimal point accuracy
  printf("%.2f\n", area);
  // printf("%9.2f\n", area); - remove bug for einstein
  // exit program
  return 0;
}
