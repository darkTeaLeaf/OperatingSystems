#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry {
    int number;
    char aging;
    int referenced;
} ENTRY;

int check_presence(int, ENTRY *, int);

int remove_least_important(ENTRY *, int, int);

void update_aging(ENTRY *, int);

int main() {
    int numb, size, hit = 0, miss = 0;

    printf("Enter number of page frames: ");
    scanf("%d", &size);

    ENTRY *table = malloc(sizeof(ENTRY) * size);

    for (int i = 0; i < size; ++i) {
        ENTRY e = {-1, 0, 0};
        table[i] = e;
    }

    FILE *input;
    input = fopen("/Desktop/week9/input.txt", "r");

    if (input == NULL) {
        printf("\nError of reading the input file!");
        exit(1);
    }
    while (fscanf(input, "%d", &numb) != EOF) {

        int presence = check_presence(size, table, numb);

        if (presence == -1) {
            remove_least_important(table, size, numb);
            miss++;
        } else if (presence >= 0) {
            table[presence].referenced = 1;
            hit++;
        }

        update_aging(table, size);
    }

    printf("\nHITS/MISSES %d/%d", hit, miss);
    fclose(input);

    return 0;
}

int check_presence(int size, ENTRY *table, int numb) {
    for (int i = 0; i < size; ++i) {
        if (table[i].number == numb) {
            return i;
        }
    }
    return -1;
}

int remove_least_important(ENTRY *table, int size, int numb) {
    int least_index = 0;
    int least_age = 0;
    for (int i = 1; i < size; ++i) {
        int num = table[i].number;
        int age = table[i].number;
        if (num == -1) {
            table[i].number = numb;
            table[i].aging = 0;
            table[i].referenced = 1;
            return 0;
        }

        if (age > least_age) {
            least_index = i;
        }
    }
    table[least_index].number = numb;
    table[least_index].aging = 0;
    table[least_index].referenced = 1;

    return 0;
}

void update_aging(ENTRY *table, int size) {
    unsigned char one = 128;

    for (int i = 0; i < size; ++i) {
        if (table[i].number != -1) {
            table[i].aging = table[i].aging >> 1;
            if (table[i].referenced == 1) {
                table[i].aging = table[i].aging | one;
            }
            table[i].referenced = 0;
        }
    }
}