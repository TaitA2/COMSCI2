/*
Author: Adam Tait
Date: 26/10/25
Description: take 2 vectors and print their dot product
*/

#include <stdio.h>
#include <stdlib.h>
// take size of each vector and vectors array
void getElements(int size, char *args[], int *elements);
// take size of each vector and vectors array and replace vector array with
void getVectors(int size, int *elements, int **vectors);
// take 2 arrays of ints and return dot product int
int getDotProduct(int size, int *v1, int *v2);

// main function
int main(int argc, char *argv[]) {
  // int for size of each vector
  int size = atoi(argv[1]);
  // array of ints to contain vector elements
  int *elements = malloc(2 * size * sizeof(int));
  // array of vectors - 2D array of ints
  int **vectors = malloc(2 * size * sizeof(int));
  // populate the ellements array of ints
  getElements(size, argv, elements);
  // populate the vectors 2D array of ints
  getVectors(size, elements, vectors);
  // calculate the dot product of the 2 vectors
  int ans = getDotProduct(size, vectors[0], vectors[1]);
  // print the result
  printf("%d\n", ans);
  // free all used memory
  free(elements);
  free(vectors);
  return 0;
}

// function to convert arguments into array of ints
void getElements(int size, char *args[], int *elements) {
  // iterate over args
  for (int i = 0; i < size * 2; i++) {
    // cast arg to int and store in elements array
    elements[i] = atoi(args[i + 2]);
  }
}

// function to convert 1D array of ints to 2D array of ints (vectors)
void getVectors(int size, int *elements, int **vectors) {
  // iterate twice since 2 vectors expected
  for (int i = 0; i < 2; i++) {
    // initialise 1D array of ints for each vector
    int *vector = malloc(size * sizeof(int));
    // populate vector with elements
    for (int j = 0; j < size; j++) {
      vector[j] = elements[j + (i * size)];
    }
    // store new vector in vectors array
    vectors[i] = vector;
  }
}

// function to calculate the dot product of 2 vectors
int getDotProduct(int size, int *v1, int *v2) {
  // initialise total as 0
  int total = 0;
  // iterate over both vectors
  for (int i = 0; i < size; i++) {
    // increase the total by the product of the two elements
    total += (v1[i] * v2[i]);
  }

  // return the total dot product
  return total;
}
