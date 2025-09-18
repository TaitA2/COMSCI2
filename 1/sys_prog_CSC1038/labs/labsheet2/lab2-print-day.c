#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[1]){
  char *weeks[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  int index = atoi(argv[1])-1;
  char *day = weeks[index];
  printf("%s\n", day);
  return 0;
}
