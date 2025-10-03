#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
  char *main = argv[1];
  char *substring = argv[2];
  for (int i = 0; i < strlen(main); i++) {
    int j = 0;
    while (i + j < strlen(main) && main[i + j] == substring[j]) {
      j++;
    }
    if (j == strlen(substring)) {
      printf("%d %d\n", i, i + j - 1);
      return 0;
    }
  }
  return 0;
}
