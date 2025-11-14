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

// function header for reading a binary file and returning a pointer to the head
// of a linked list
Node *getStudent(char *filename);

// funciton header for iterating through a linked list and printing the info at
// each node
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
  // initialise the length of the name to 0
  int nameLen = 0;
  // read the actual name length from the file
  int wcount1 = fread(&nameLen, sizeof(int), 1, pfile);

  // create a current node pointer set to the head node
  Node *cur = studentHead;
  // read nameLen chars from file into node
  int wcount2 = fread(cur->info, sizeof(char), nameLen, pfile);

  // create a new node pointer for the next block of info
  Node *next = malloc(sizeof(Node));
  cur->next = next; // set current node's next to new node
  cur = cur->next;  // set current node to new node

  // initialise the length of the college name to 0
  int collegeLen = 0;
  // read the actual college length from file
  int wcount3 = fread(&collegeLen, sizeof(int), 1, pfile);
  // read collegeLen chars from file into node
  int wcount4 = fread(cur->info, sizeof(char), collegeLen, pfile);

  // create a new node pointer for the next block of info
  Node *next2 = malloc(sizeof(Node));
  cur->next = next2; // set current node's next to new node
  cur = cur->next;   // set current node to new node

  // initialise age at 0
  int age = 0;
  // read actual age from file
  int wcount5 = fread(&age, sizeof(int), 1, pfile);

  // pass the age into the node's info as a string
  sprintf(cur->info, "%d", age);

  // create a new node pointer for the next block of info
  Node *next3 = malloc(sizeof(Node));
  cur->next = next3; // set current node's next to new node
  cur = cur->next;   // set current node to new node

  // initialise gpa at 0
  float gpa = 0.0;
  // read actual gpa from file
  int wcount6 = fread(&gpa, sizeof(float), 1, pfile);
  // pass the grade into the node's info as a string
  sprintf(cur->info, "%.2f", gpa);

  // set current node (tail) next to NULL
  cur->next = NULL;

  // close the file
  fclose(pfile);

  // return the student struct
  return studentHead;
}

// funciton for iterating through a linked list and printing the info at each
// node
void printStudent(Node *studentHead) {
  // set current node to the head
  Node *cur = studentHead;

  // print the info of current node, move to next node and repeat
  printf("Name: %s\n", cur->info);
  cur = cur->next;
  printf("College: %s\n", cur->info);
  cur = cur->next;
  printf("Age: %s\n", cur->info);
  cur = cur->next;
  printf("Grade: %s\n", cur->info);
}
