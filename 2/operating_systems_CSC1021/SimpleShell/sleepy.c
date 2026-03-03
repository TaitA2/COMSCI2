#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// main function
int main(int argc, char **argv) {
  // convert string arg to int time in seconds to sleep for
  int t = atoi(argv[1]);
  unsigned int slept; // declare uint to store time less than time intended

  // forever
  while (1) {
    slept = sleep(t); // sleep for given time in seconds

    // print the pid and difference between time actually slept and time
    // intended to sleep
    printf("process=%d ---- slept=%d\n", getpid(), slept);
  }
}
