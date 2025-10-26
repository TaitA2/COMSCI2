/*
Author: Adam Tait
Date: 26/10/25
Description: Find and print the longest string
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function header to find largest number in an array of ints
void getLongest(int size, char *argv[], char **words);

// main function
int main(int argc, char *argv[]) {
  // set size int to number of ints entered
  int size = argc;
  char **words = malloc(1000);
  words[0] = "";
  words[1] = "";
  // find the longest string
  getLongest(size, argv, words);
  // print the results
  int i = 0;
  while (words[i] != NULL) {
    printf("%s\n", words[i]);
    i++;
  }
  // free all used memory
  free(words);
  // exit with no error
  return 0;
}

// function to find largest number in an array of ints
void getLongest(int size, char *argv[], char **words) {
  int j = 0;
  // iterate over all the numbers
  for (int i = 1; i < size; i++) {
    // replace largest if current num is bigger
    if (strlen(argv[i]) == strlen(words[0])) {
      words[j++] = argv[i];
    } else if (strlen(argv[i]) > strlen(words[0])) {
      j = 0;
      words[j++] = argv[i];
    }
  }
}
