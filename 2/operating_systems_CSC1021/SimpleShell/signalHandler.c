#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// function header to handle given signal
void sighandler(int signum);

// main function
int main() {

  // use signal() provided by signal.h to assign sighandler(int signum) as the
  // user-defined handler for the signal SIGINT
  signal(SIGINT, sighandler);
  // loop forever to allow handler testing
  while (1)
    ;
  return 0;
}

// function to handle given signal
void sighandler(int signum) {
  // print confirmation of signal
  printf("Received a signal %d\n", signum);
}
