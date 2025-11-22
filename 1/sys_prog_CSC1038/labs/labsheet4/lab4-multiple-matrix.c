#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  // make first matrix
  int m1 = atoi(argv[1]);
  int n1 = atoi(argv[2]);
  int A[m1][n1];
  // populate first matrix
  for (int i = 0; i < m1; i++) {
    for (int j = 0; j < n1; j++) {
      A[i][j] = atoi(argv[j + 3 + (i * n1)]);
    }
  }

  // make second matrix
  int skip = 3 + (m1 * n1);
  int m2 = atoi(argv[skip++]);
  int n2 = atoi(argv[skip++]);
  int B[m2][n2];
  // populate second matrix
  for (int i = 0; i < m2; i++) {
    for (int j = 0; j < n2; j++) {
      B[i][j] = atoi(argv[j + skip + (i * n2)]);
    }
  }

  // calculate AB
  int m3 = m2;
  int n3 = n2;
  int AB[m3][n3];
  for (int k = 0; k < n3; k++) {
    for (int i = 0; i < m3; i++) {
      int cell = 0;
      int j = 0;
      while (j < m3) {
        // A row * B col
        cell += A[i][j] * B[j][k];
        j++;
      }
      AB[i][k] = cell;
    }
  }

  // print AB
  for (int i = 0; i < m3; i++) {
    for (int j = 0; j < n3 - 1; j++) {
      printf("%d ", AB[i][j]);
    }
    printf("%d\n", AB[i][n3 - 1]);
  }

  // exit with no error
  return 0;
}
