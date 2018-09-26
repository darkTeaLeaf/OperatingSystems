#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main(){

  int fd1[2];
  char input[] = "some text";
  char output[100];

  if(pipe(fd1)==-1){
    fprintf(stderr, "Pipe failed");
    return 1;
  }

  write(fd1[1], input, strlen(input)+1);
  close(fd1[1]);
  read(fd1[0], output, 100);
  printf("%s", output);
}
