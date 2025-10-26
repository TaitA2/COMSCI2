/*
Author: Adam Tait
Date: 26/10/25
Description: format input into students as name, programme, grade of all
students with above average CSCE grades
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// type definition of a student struct
typedef struct {
  char *name;
  char *programme;
  float grade;
} Student;

// function header to convert array of strings to array of students
void getStudents(Student *students, char *argv[], int size);
// function header to format and print each student with sufficient grades
void printStudents(Student *students, int size, float avg);
// function header to find average grade
float getAverage(Student *students, int size);

// main function
int main(int argc, char *argv[]) {
  // declare size int of how many students
  int size = (argc - 1) / 3;
  // declare array of students with sufficient memory
  Student *students = malloc(sizeof(Student) * size);
  // populate student array
  getStudents(students, argv, size);
  // find average grade
  float avg = getAverage(students, size);
  // print formatted output of each student
  printStudents(students, size, avg);
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
void printStudents(Student *students, int size, float avg) {
  // iterate over each student
  for (int i = 0; i < size; i++) {
    // print name and grade of above average CSCE students
    if (students[i].grade >= avg &&
        (strcmp(students[i].programme, "CSCE") == 0)) {
      printf("%s, %.2f\n", students[i].name, students[i].grade);
    }
  }
  // print average grade
  printf("Average grade: %.2f\n", avg);
}

// function to get the average grade of all students
float getAverage(Student *students, int size) {
  // initialise total and count to 0
  float total = 0;
  int count = 0;
  // iterate over students
  for (int i = 0; i < size; i++) {
    // increment count and increase total by grade
    total += students[i].grade;
    count++;
  }

  // return the average grade
  return total / count;
}
