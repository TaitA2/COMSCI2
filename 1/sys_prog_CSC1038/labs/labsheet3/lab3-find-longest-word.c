#include <stdio.h>
#include <string.h>

char *longest(int size, char *s);

int main(int argc, char *argv[]) {
  printf("%s\n", longest(argc, argv[1]));
  return 0;
}

char *longest(int size, char *s) {
  int max = 0;
  char *longest = "";

  char *word = strtok(s, " ");
  while (word != NULL) {
    int length = strlen(word);
    if (length > max) {
      max = length;
      longest = word;
    }
    word = strtok(NULL, " ");
  }
  return longest;
}
