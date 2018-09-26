#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main(){
  pid_t p1, p2= -256;
  p1 = fork();
  int fd[2];

  if(p1 > 0){
    p2 = fork();
  }

  if(p1 == 0){
    printf("Hello from the first child process number %d\n", p1);

    read(fd[0], &p2, sizeof(pid_t));
    close(fd[0]);

    printf("Read number of the second prosecc number %d\n", p2);

    if(p2 != getpid()){
      printf("The first child process number %d is sleeping\n", p1);
      sleep(5);
      printf("The first child process number %d is sending a signal\n", p1);
      kill(p2, SIGSTOP);
    }

  }
  else if (p1 > 0 & p2 > 0){
    printf("The main process works\n");
    printf("the main process has child processes number %d and number %d\n", p1, p2);

    close(fd[0]);
    write(fd[1], &p2, sizeof(pid_t));
    close(fd[1]);

    wait(&p2);
    printf("Exit\n");
    exit(1);
  }
  else if(p2 == 0){
    printf("Hello from the second child process number %d\n", p2);

    while(1){
      printf("The second child process is alive\n");
      sleep(1);
    }
  }

  return (0);
}

