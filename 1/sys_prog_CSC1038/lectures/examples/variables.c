#include <stdio.h>

int main(int argc, char *argv[]) {
  int age = 23;
  long studentID = 17312594l;
  float height = 1.75f;
  char initial = 'A';
  char first_name[] = "Adam";
  char last_name[] = "Tait";
  printf("I have a first name %s.\n", first_name);
  printf("I have a last name %s.\n", last_name);
  printf("I have an initial %c.\n", initial);
  printf("My age is %d years old.\n", age);
  printf("My student id is %ld.\n", studentID);
  printf("I am %fm tall.\n", height);
}
