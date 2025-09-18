#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415

int main(int argc, char *argv[]){
  if (argc < 2) {
    printf("No input given!\n");
    return 1;
  }
  if (argc < 3) {
    printf("Two arguments needed!\n");
    return 1;
  }

  float radius = atof(argv[1]);
  float height = atof(argv[2]);
  if (radius < 0 || height < 0){
    printf("The radious or height cannot be negative!\n");
  }
  double area = (height * radius * PI * 2) + (radius * radius * PI * 2);
  printf("%.2f\n", area);
  return 0;
}
