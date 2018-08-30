#include<stdio.h>
#include<string.h>

void main(){

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    swap(&n, &m);

    printf("%d%d", n, m);
}

void swap(int *n, int *m){
    int z = *n;
    *n = *m;
    *m = z;
}
