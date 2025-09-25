/*
Author: Adam Tait
Date: 25/09/25
This program reverses the string passed as the first argument
*/
#include <stdio.h>
#include <string.h>

void reverse(char *s);

int main(int argc, char *argv[]){
  if (argc != 2){
    printf("Enter exactly one argument\n");
    return 0;
  }
  reverse(argv[1]);
  return 0;
}

void reverse(char *s){
  char reversed[50];
  reversed[49] = '\0';
  int i = 0;
  while (s[i] != '\0'){
    reversed[50-i-2] = s[i];
    i++;
  }

  i = 50 - i - 1;
  while (reversed[i] != '\0'){
    printf("%c",reversed[i]);
    i++;
  }
  printf("\n");
}
