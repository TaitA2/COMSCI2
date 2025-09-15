#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int width = atoi(argv[1]);
  int height = atoi(argv[2]);

  for (int j = 0; j < width; j++) {
    printf("*");
  }
  printf("\n");

  for (int i = 0; i < height - 2; i++) {
    printf("*");
    for (int j = 0; j < width-2; j++) {
      printf(" ");
    }
    printf("*\n");
  }
  for (int j = 0; j < width; j++) {
    printf("*");
  }
  printf("\n");
}
