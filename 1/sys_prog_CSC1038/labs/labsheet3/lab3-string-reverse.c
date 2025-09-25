/*
Author: Adam Tait
Date: 25/09/25
This program reverses the string passed as the first argument
*/
#include <stdio.h>
#include <string.h>

char *reverse(char *s);
int main(int argc, char *argv[]){
  if (argc != 2){
    printf("Enter exactly one argument\n");
    return 0;
  }
  printf("%s\n", reverse(argv[1]));
  return 0;
}
char *reverse(char *s){
  char reversed[50];
  int i = 0;
  while (s[i] != '\0'){
    reversed[50-i-2] = s[i];
    // printf("%c\n",s[i]);
    i++;
  }

  i++
  while (i < 50){
    printf("%c",reversed[i]);
    i++;
  }
  printf("%s", reversed);
  return reversed;
}
