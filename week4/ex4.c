#include <stdio.h>

void promt();
void print_command(char *command);

int main(){
   char command[10];
   while(1){
   promt();
   print_command(command);
   system(command);}
}

void promt(){
   printf("> ");
}

void print_command(char *command){
   fgets(command, 10, stdin);
}


