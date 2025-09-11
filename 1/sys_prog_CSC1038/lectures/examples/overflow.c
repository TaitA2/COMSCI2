#include <stdio.h>

int main() {
  int a, b, c;
  a = 15000;
  b = 15000;
  c = a + b;
  printf("%d\n", c);
  /*  integer overflow at around 2147483648
      because 32 bit int uses 1 bit as sign
      2^31 == 2147483648
      when int value exceeds 2^31, sign bit gets flipped
      resulting int is -2^31 */
  while (c > 1) {
    a += 2000;
    b += 2000;
    c = a + b;
    printf("%d\n", c);
  }
  return 0;
}
