/*
A pthread program illustrating how to create a thread and some of the pthread
API
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int sum; // data shared by thread(s)

void *runner(void *param); // the thread

int main(int argc, char **argv) {
  pthread_t tid;       // the thread identifier
  pthread_attr_t attr; // set of attributes for the thread

  if (argc != 2) {
    fprintf(stderr, "usage: a.out <integer value>\n");
    return -1;
  }

  if (atoi(argv[1]) < 0) {
    fprintf(stderr, "Argument %d must be non-negative\n", atoi(argv[1]));
    return -1;
  }

  // get default attributes
  pthread_attr_init(&attr);

  // create thread
  pthread_create(&tid, &attr, runner, argv[1]);

  // wait for thread to exit
  pthread_join(tid, NULL);

  printf("sum = %d\n", sum);
}

// the thread will begin control in this function
void *runner(void *param) {
  long long int i, upper = atoll(param);
  sum = 0;

  if (upper > 0) {
    for (i = 1; i <= upper; i++) {
      sum += i;
    }
  }
  pthread_exit(0);
}
