/*
Author: Adam Tait
Date: 10/10/2025
Description: This program is intended to take two non-zero integers
and return the result of each mathemematical operation between them.
*/
// import the math library
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// Function  declarations
// addition function
float sum(float a, float b) { return a + b; }
// subtraction function
float dif(float a, float b) { return a - b; }
// multiplication function
float prod(float a, float b) { return a * b; }
// division function
float divide(float a, float b) { return a / b; }
// power function
float power(float a, float b) { return pow(a, b); }
// natural log function
float nlog(float a, float b) { return log(a) + log(b); }
// main function
int main(int argc, char *argv[]) {
  // declare arguments a and b as floats
  float a = atof(argv[1]);
  float b = atof(argv[2]);

  // create pointers to each function
  float (*pSum)(float, float) = &sum;
  float (*pDif)(float, float) = &dif;
  float (*pProd)(float, float) = &prod;
  float (*pDivide)(float, float) = &divide;
  float (*pPower)(float, float) = &power;
  float (*pNlog)(float, float) = &nlog;

  // print the results of passing a and b to the pointers of each function
  printf("%.2f\n", pSum(a, b));
  printf("%.2f\n", pDif(a, b));
  printf("%.2f\n", pProd(a, b));
  printf("%.2f\n", pDivide(a, b));
  printf("%.2f\n", pPower(a, b));
  printf("%.2f\n", pNlog(a, b));

  // return with no error
  return 0;
}
