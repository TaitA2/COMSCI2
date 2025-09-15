//include standard io and standard library headers
#include <stdio.h>
#include <stdlib.h>

// main function takes argument count and array of arguments
int main(int argc, char *argv[]){
  // set lower and upper limits 
  int lower = 30;
  int upper = 50;
  // set centimetre to lower bound
  int centimetre = lower;
  // continue loop until centimetre value reaches upper limit
  while (centimetre < upper){
    // calculate inches 
    float inches = centimetre/2.54;
    // print current centimetre value
    printf("%dcm: ", centimetre);
    /* 
       increment centimetre 
       if new value is multiple of five, print new line, otherwise add tab char
    */
    ++centimetre % 5 == 0 ? printf("%.2f in.\n",inches) : printf("%.2f in.\t",inches);
  }
  // exit program
  return 0;
}
