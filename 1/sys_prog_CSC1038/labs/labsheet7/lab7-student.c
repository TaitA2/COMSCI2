/*
Author: Adam Tait
Date: 26/10/25
Description: format input into students as name, programme, grade
*/

#include <stdio.h>
#include <stdlib.h>
// type definition of a student struct
typedef struct {
  char *name;
  char *programme;
  float grade;
} Student;

// function header to convert array of strings to array of students
void getStudents(Student *students, char *argv[], int size);
// function header to format and print each student in an array
void printStudents(Student *students, int size);

// main function
int main(int argc, char *argv[]) {
  // declare size int of how many students
  int size = (argc - 1) / 3;
  // declare array of students with sufficient memory
  Student *students = malloc(sizeof(Student) * size);
  // populate student array
  getStudents(students, argv, size);
  // print formatted output of each student
  printStudents(students, size);
  // free all used memory
  free(students);
  // exit with no errors
  return 0;
}

// function to convert array of strings to array of student structs
void getStudents(Student *students, char *argv[], int size) {
  // initialise i for iterating over args
  int i = 1;
  // initialise j for iterating students array
  int j = 0;
  while (i < size * 3) {
    // declare a new student
    Student student;
    // set each attribute of the student to the corresponding arg
    student.name = argv[i++];
    student.programme = argv[i++];
    student.grade = atof(argv[i++]);
    // add the new student to the array
    students[j++] = student;
  }
}

// function to format and print each student in an array
void printStudents(Student *students, int size) {
  for (int i = 0; i < size; i++) {
    printf("%s, %s, %.2f\n", students[i].name, students[i].programme,
           students[i].grade);
  }
}
