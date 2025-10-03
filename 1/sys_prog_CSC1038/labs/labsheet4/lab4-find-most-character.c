#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int counts[50];
  int max = 0;
  char maxchar;
  for (int i = 0; i < strlen(argv[1]); i++) {
    char c1 = argv[1][i];
    for (int j = i + 1; j < strlen(argv[1]); j++) {
      char c2 = argv[1][j];
      if (c1 == c2 && !isblank(c1)) {
        counts[i]++;
      }
      if (counts[i] > max) {
        max = counts[i];
        maxchar = argv[1][i];
      }
    }
  }
  printf("%c\n", maxchar);
  return 0;
}
