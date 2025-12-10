/*
Author: Adam Tait
Date: 10/12/2025
Description: This program accepts n strings of digits and prints the RLE compressed version of each string on seperate lines.
Approach: 
- Iterate through all arguments
- Iterate through all characters of each argument
- Iterate ahead in characters to find how many concurrent of the same character exist
- Print the character followed by the amount of that character
- Repeat

*/

// include relevant libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function header to perform RLE compression on all strings in an array
void rleAll(int count, char *readings[]);
// function header to perform RLE compression on a single string
char *rle(char *reading);

// main function
int main(int argc, char *argv[]){
  // print rle compressed versions of all given strings
  rleAll(argc, argv);
  // exit without error
  return 0;
}

// function to perform RLE compression on all strings in an array
void rleAll(int count, char *readings[]){
  // iterate through all strings 
  for (int i = 1; i < count; i++){
    // set the current reading to the argument
    char *reading = readings[i];
    // convert the reading to RLE compressed version
    char *rleReading = rle(reading);
    // print the RLE compressed string
    printf("%s\n",rleReading);
  }
 
}

// function to perform RLE compression on a single string
char *rle(char *reading){
  // declare rleReading string
  char *rleReading = malloc(sizeof(char)*100);
  // iterate through chars of string
  for (int j = 0; j < strlen(reading); j++){
    // print whitespace between char results
    if (j != 0){
      strcat(rleReading, " ");
    }
    int k = j+1;
    while (k < strlen(reading) && reading[j] == reading[k]){
      k++;
    }

    // declare rle of current character
    char *rleChar = malloc(sizeof(char)*100);

    // store the character and count in the rleChar string
    sprintf(rleChar, "%c %d", reading[j], k-j); 
    // concatonate the current RLE to the RLE string for the entire line
    strcat(rleReading, rleChar);


    // set j to skip all values parsed by k
    j = k-1;
  }
  // return the RLE compressed string 
  return rleReading;
}

