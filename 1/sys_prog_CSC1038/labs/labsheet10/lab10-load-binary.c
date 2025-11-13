/*
Author: Adam Tait
Date: 13/11/25
Description: Read data from a binary file and display the data in a readable
format using a linked list
*/

// include relevent libraries
#include <stdio.h>
#include <stdlib.h>

// node struct
typedef struct Node {
  char info[50];
  struct Node *next;
} Node;

// function headers
Node *getStudent(char *filename);
void printStudent(Node *student);

// main function
int main(int argc, char *argvp[]) {
  // get student data from binary file
  Node *studentHead = getStudent("studentBinary.bin");
  // print student data
  printStudent(studentHead);
  // free all used memory
  free(studentHead);
  // exit with no error
  return 0;
}

// function to get student struct from binary file
Node *getStudent(char *filename) {
  // create new student
  Node *studentHead = malloc(sizeof(Node));
  // open the binary file
  FILE *pfile = fopen(filename, "rb");
  if (!pfile) {
    printf("Failed to open %s.\n", filename);
  }

  // read the binary file
  int nameLen = 0;
  int wcount1 = fread(&nameLen, sizeof(int), 1, pfile);
  Node *cur = studentHead;
  int wcount2 = fread(cur->info, sizeof(char), nameLen, pfile);

  Node *next = malloc(sizeof(Node));
  cur->next = next;
  cur = cur->next;

  int collegeLen = 0;
  int wcount3 = fread(&collegeLen, sizeof(int), 1, pfile);
  int wcount4 = fread(cur->info, sizeof(char), collegeLen, pfile);

  Node *next2 = malloc(sizeof(Node));
  cur->next = next2;
  cur = cur->next;

  int age = 0;
  int wcount5 = fread(&age, sizeof(int), 1, pfile);

  sprintf(cur->info, "%d", age);

  Node *next3 = malloc(sizeof(Node));
  cur->next = next3;
  cur = cur->next;

  cur->next = NULL;

  float gpa = 0.0;
  int wcount6 = fread(&gpa, sizeof(float), 1, pfile);

  sprintf(cur->info, "%.2f", gpa);
  // close the file
  fclose(pfile);
  // return the student struct
  return studentHead;
}

// function to print formatted student data
void printStudent(Node *studentHead) {
  Node *cur = studentHead;
  printf("Name: %s\n", cur->info);
  cur = cur->next;
  printf("College: %s\n", cur->info);
  cur = cur->next;
  printf("Age: %s\n", cur->info);
  cur = cur->next;
  printf("Grade: %s\n", cur->info);
}
