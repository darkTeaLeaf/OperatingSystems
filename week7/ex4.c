#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realloc2(void *ptr, size_t size);

int main(){
  int *a1 = malloc(10*sizeof(int));

  printf("Initial array:\n");
  for(int i = 0; i < 10; i++){
    a1[i] = i;
    printf("%d ", a1[i]);
  }
  printf("\n");

  a1 = realloc2(a1, 15);

  printf("Reallocated array:\n");
  for(int i = 10; i < 15; i++){
    printf("%d ", a1[i]);
    a1[i] = i;
  }
  printf("\n");

  printf("Reallocated array with new values:\n");
  for(int i = 0; i < 15; i++){
    printf("%d ", a1[i]);
  }

  return 0;
}

void *realloc2(void *ptr, size_t size){
  if(ptr == NULL){
    int *a1 = malloc(size*sizeof(int));
    return a1;
  }
  else{

    if(size == 0){
      free(ptr);
      return NULL;
    }
    else{
      int *a1 = malloc(size*sizeof(int));
      memcpy(a1, ptr, size*sizeof(int));
      return a1;
    }
  }
  
}
