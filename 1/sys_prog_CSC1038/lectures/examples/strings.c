#include <stdio.h>
#include <string.h>

int copy() {
  char source[] = "the brown fox jumped over the lazy dog";
  char destination[50];
  strcpy(destination, source);
  source[0] = 'X';

  printf("The source string is %s\n", source);
  printf("The destination string is %s\n", destination);

  return 0;
}
#include <stdio.h>

int input() {
  char my_name[25];
  printf("Enter your name: ");
  fgets(my_name, sizeof(my_name), stdin);
  printf("Your name is %s\n", my_name);
  return 0;
}
#include <stdio.h>
#include <string.h>

int length() {
  char str[] = "this is a test string";
  int length = strlen(str);
  printf("Length: %d\n", length);

  return 0;
}

int cat() {
  char source[50] = "this is the start ";
  char dest[50] = "this is the end";
  strcat(source, dest);
  printf("Source: %s\n", source);
  printf("Destination: %s\n", dest);
  return 0;
}
int main() {
  copy();
  input();
  length();
  cat();
}
