#include <stdio.h>

int main() {
  int numbers2D[3][4] = {
      /* A 2D array with 3 rows and 4 columns */
      {1, 2, 3, 4}, /* value for first row */
      {5, 6, 7, 8}, /* value for second row */
      {4, 5, 6, 7}  /* value for third row */
  };
  float averages[3];
  float sum;
  for (int i = 0; i < 3; i++) {
    sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += numbers2D[i][j];
    }
    averages[i] = sum / 4;
  }
  for (int i = 0; i < 3; i++) {
    printf("%f\n", averages[i]);
  }
}
