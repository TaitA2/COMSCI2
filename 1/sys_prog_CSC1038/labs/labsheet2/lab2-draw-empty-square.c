#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int width = atoi(argv[1]);

  // print top edge
  for (int i = 0; i < width; i++) {
    printf("*");
  }
  printf("\n");

  // print body
  for (int i = 0; i < width - 2; i++) {
    printf("*");
    for (int j = 0; j < width-2; j++) {
      printf(" ");
    }
    printf("*\n");
  }

  // print bottom edge
  for (int i = 0; i < width; i++) {
    printf("*");
  }
  printf("\n");
}
