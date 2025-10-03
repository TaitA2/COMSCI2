#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int count = 0;
  char c = argv[1][0];
  for (int i = 0; i < strlen(argv[2]); i++) {
    if (argv[2][i] == c) {
      count++;
    }
  }
  printf("%d\n", count);
  return 0;
}
