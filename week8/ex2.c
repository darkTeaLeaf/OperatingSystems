#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

int main(){

  int m = 1 << 20;

  for(int i = 0; i < 10; i++){
    void *p = malloc(10*m);
    memset(p, 0, 10*m);
    sleep(1);
  }

}
