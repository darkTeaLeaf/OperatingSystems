#include <stdio.h>
#include <stdlib.h>

int main(){
   int pid = fork(), n = 456;
   if(pid > 0){
   printf("Hello from parent [%d - %d]\n", pid, n);
   }else if(pid == 0){
   printf("Hello from child [%d - %d]\n", pid, n);
   }else{
   return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}
/*The first number from parent row is an id of thread which copy we created.
The first number from child row is an id of copy and it is always zero.
We have different first numbers from parent row because we take copy of different processes 
in different moments of time.
*/
