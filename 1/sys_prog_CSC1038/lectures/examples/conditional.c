#include <stdio.h>

int main() {
  /* if (conditional) {expr 1} else {expr 2}
   =========================================
   conditional ? expr 1 : expr 2 */
  int a, b;
  a = 5;
  b = 20;

  a > b ? printf("a") : printf("b");
  return 0;
}
