#include <stdio.h>
#include <stdlib.h>

char *longest(char *s);
int main(int argc, char *argv[]){
  longest(*argv);
}
char *longest(char *s){
  int start = 0;
  int end = 0;
  int i = 0;
  int j = 1;
  while (s[i] != '\0'){
    j = i+1;
    while (s[j] != '\0' && s[j] != ' '){
      j++;
    }
    if (j - i > end - start){
      start = i;
      end = j;
    }
    i = j;
  }
  printf("start is %d\n", start);
  printf("end is %d\n", end);
  for (int i = start; i <= end; i++){
    printf("%c",s[i]);
  }
  printf("\n");
  printf("done\n");
}
