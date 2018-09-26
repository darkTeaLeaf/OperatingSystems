#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int);

int main(){
  signal(SIGKILL, handler);
  signal(SIGSTOP, handler);
  signal(SIGUSR1, handler);

  while(1){
    sleep(1);
  }

  return (0);
}

void handler(int signalnum){
  printf("Caught signal %d, come out\n", signalnum);
  exit(1);
}

/*The program caught the signal 10, when user killed a process with signal
SIGUSR1, which number is 10.
*/

