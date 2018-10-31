#include <stdio.h>
#include <stdlib.h>

int main(){

   FILE *mf;
   char str [6];

   mf = fopen("ex2.txt", "w");

   setvbuf(mf, str, _IOLBF, 5);

   fputs("H", mf);
   sleep(1);
   fputs("e", mf);
   sleep(1);
   fputs("l", mf);
   sleep(1);
   fputs("l", mf);
   sleep(1);
   fputs("o", mf);
   sleep(1);

   printf("%s\n", str);

   fclose(mf);

  return 0;

}
