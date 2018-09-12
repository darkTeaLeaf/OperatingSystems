
#include <stdio.h>

int main(){
   for(int i = 0; i < 5; i++){
   fork();
   sleep(5);
   }
   return 0;
}
/*In the first column we have our initial processe, when we create copy of this process, during 
the second termination we create copy of initial process and copy of first copy (child of
initial process), the same in the third termination. So, we have 8 processes.
*/
