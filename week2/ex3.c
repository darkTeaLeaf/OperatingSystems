#include<stdio.h>
#include<string.h>

void main(){

    int n;
    scanf("%d", &n);

    int i  = 1;
    int f = 2*i - 1;

    while(n != 0){
        for (int j = 0; j < n-1; j++) {
            printf("%c", ' ');
        }

        for (int k = 0; k < f; k++) {
            printf("%c", '*');
        }

        printf("\n");
        i++;
        n--;
        f = 2*i - 1;
    }

}
