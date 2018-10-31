#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){

  int fd;
  struct stat buf;
  void* file_memory;

  fd = open("ex1.txt", O_RDWR);
  if(fd == -1){
    printf("File error\n");
    exit(1);
  }

  fstat(fd, &buf);

  file_memory = mmap(0, buf.st_size, PROT_WRITE, MAP_SHARED, fd, 0);
  close(fd);

  sprintf((char*) file_memory, "%s\n", "This is a nice day");
  munmap(file_memory, buf.st_size);

  return 0;
}
