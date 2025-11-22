/*
Author: Adam Tait
Date: 22/11/25
Description: Calculate how many distinct ways exist to climb n steps
             moving 1 or 2 steps each time.
*/

// include relevent libraries
#include <stdio.h>
#include <stdlib.h>

// function header to calculate nth fibonacci number
int fibonacci(int n);

// main function
int main(int argc, char *argv[]) {
  // get n
  int n = atoi(argv[1]);

  // amount of steps increases according to the fibonacci sequence
  printf("%d\n", fibonacci(n));

  // exit with no error
  return 0;
}

// function to calculate nth fibonacci number
int fibonacci(int n) {
  int i = 0;
  int j = 1;
  for (int k = 0; k < n; k++) {

    // swap i and j
    j ^= i;
    i = j ^ i;
    j ^= i;

    // increase j by i
    j += i;
  }

  // return j (nth fibonacci number)
  return j;
}
