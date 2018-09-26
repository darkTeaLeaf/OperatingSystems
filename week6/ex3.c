#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int);

int main(){
  signal(SIGINT, handler);

  while(1){
    printf("Sleeping...\n");
    sleep(1);
  }

  return (0);
}

void handler(int signalnum){
  printf("Caught signal %d, come out\n", signalnum);
  exit(1);
}
