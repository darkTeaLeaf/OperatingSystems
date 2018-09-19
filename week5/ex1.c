#include <pthread.h>
#include <stdio.h>

void *thread_funct(void* num){
   printf("Some text from thread: %d\n", (int) num);
   
   return NULL;
}

int main(void){
   int n = 5;
   pthread_t thread;

   for(int i = 0; i < n; i++){
      pthread_create(&thread, NULL, thread_funct, (void*)i);
      pthread_join(thread, NULL);  //Sequential

   }
//   pthread_join(thread, NULL);  //Parallel
   return 0;
}
