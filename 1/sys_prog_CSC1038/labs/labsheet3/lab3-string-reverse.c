/*
Author: Adam Tait
Date: 25/09/25
This program reverses the string passed as the first argument
*/
#include <stdio.h>
#include <string.h>

void reverse(char *s);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Enter exactly one argument\n");
    return 0;
  }
  reverse(argv[1]);
  return 0;
}

void reverse(char *s) {
  int i = strlen(s) - 1;
  while (i >= 0) {
    printf("%c", s[i]);
    i--;
  }

  printf("\n");
}
