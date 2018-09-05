#include<stdio.h>
#include<string.h>

void bubble_sort(int *array, int size);

void main(){

    int size = 10;
    int array[size];
    scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }

    bubble_sort(array, size);

    for (int j = 0; j < size; ++j) {
        printf("%d ", array[j]);
    }

}

void bubble_sort(int *array, int size){
    int a;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i ; ++j) {
            if(array[j]> array[j+1]){
                a = array[j];
                array[j] = array[j+1];
                array[j+1] = a;
            }
        }
    }
}
