//include standard io and standard library headers
#include <stdio.h>
#include <stdlib.h>

// main function takes argument count and array of arguments
int main(int argc, char *argv[]){
  // exit program if no centimetre argument provided
  if (argc < 2) {return 1;}
  // initialise centimetres int as first argument
  int centimetres = atoi(argv[1]);
  // calculate inches float
  float inches = centimetres/2.54;
  // print inches to 2 decimal point accuray
  printf("%.2f\n",inches);
  // exit the program
  return 0;
}
