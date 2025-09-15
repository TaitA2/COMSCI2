// include standard io and standard library headers
#include <stdio.h>
#include <stdlib.h>

// main function takes argument count and array of arguments
int main(int argc, char *argv[]){
  // initialise array of integers
  // each index holds the value of points for each score type
  int values[] = {5,2,3,3};
  // initialise total to 0 to track score
  int total = 0;
  // iterate 4 times to get a score for each type

  for (int i = 0; i < 4; i++){
    // initialise score 
    int score;
    // set score to entered int
    scanf("%d", &score);
    // exit the program if a negative number is found
    if (score < 0) {return 1;}
    // increase the total by the number of points * the poin value
    total += values[i]*score;
  }
  // print total
  printf("%d\n", total);
  // exit program 
  return 0;
}
