/*
Author: Adam Tait
Date: 13/11/25
Description: Read data from a binary file and display the data in a readable
format
*/

// include relevent libraries
#include <stdio.h>
#include <stdlib.h>

// student struct
typedef struct {
  int nameLen;
  char name[50];
  int collegeLen;
  char college[50];
  int age;
  float gpa;
} Student;

// function headers
Student *getStudent(char *filename);
void printStudent(Student *student);

// main function
int main(int argc, char *argvp[]) {
  // get student data from binary file
  Student *student = getStudent("studentBinary.bin");
  // print student data
  printStudent(student);
  // free all used memory
  free(student);
  // exit with no error
  return 0;
}

// function to get student struct from binary file
Student *getStudent(char *filename) {
  // create new student
  Student *student = malloc(sizeof(Student));
  // open the binary file
  FILE *pfile = fopen(filename, "rb");
  if (!pfile) {
    printf("Failed to open %s.\n", filename);
  }

  // read the binary file
  int wcount1 = fread(&student->nameLen, sizeof(int), 1, pfile);
  int wcount2 = fread(student->name, sizeof(char), student->nameLen, pfile);
  int wcount3 = fread(&student->collegeLen, sizeof(int), 1, pfile);
  int wcount4 =
      fread(student->college, sizeof(char), student->collegeLen, pfile);
  int wcount5 = fread(&student->age, sizeof(int), 1, pfile);
  int wcount6 = fread(&student->gpa, sizeof(float), 1, pfile);
  // close the file
  fclose(pfile);
  // return the student struct
  return student;
}

// function to print formatted student data
void printStudent(Student *student) {
  printf("Name: %s\n", student->name);
  printf("College: %s\n", student->college);
  printf("Age: %d\n", student->age);
  printf("Grade: %.2f\n", student->gpa);
}
