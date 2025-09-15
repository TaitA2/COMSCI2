// include standard io headers
#include <stdio.h>

// main function takes argument count int and array of arguments
int main(int argc, char *argv[]){
  // initialise name variable as char * 
  char *name;
  // set name to first argument if provided. otherwise default to "Name"
  name = (argc > 1) ? argv[1] : "Name";
  // print the name with a newline character at the end
  printf("First %s\n", name);
  // print the second name 2 tab spaces away from the start of the line. do not end with newline
  printf("\t\tSecond %s", name);
  // move the cursor back to the start of the line then print third name ending with a new line
  printf("\rThird %s\n", name);

  // exit the program
  return 0;
}
