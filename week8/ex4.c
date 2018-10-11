#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/resource.h>

int main(){
  struct rusage usage;
  int m = 1 << 20;

  for(int i = 0; i < 10; i++){
    void *p = malloc(10*m);
    memset(p, 0, 10*m);
    int j = getrusage(RUSAGE_SELF, &usage);
    printf("Max resident set data:%ld\n", usage.ru_maxrss);
    printf("Integral shared memory size:%ld\n", usage.ru_ixrss);
    printf("Integral unshared data size:%ld", usage.ru_idrss);
    printf("Integral unshared stack size:%ld\n", usage.ru_isrss);
    sleep(1);
  }

}


