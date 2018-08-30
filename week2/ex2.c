#include<stdio.h>
#include<string.h>

void main(){

    char f[256];

    int i;

    fgets(f, 256, stdin);

    for(i = strlen(f); i >=0; i--){
        printf("%c", f[i]);
    }

}
