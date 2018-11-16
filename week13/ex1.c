#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main() {
    char file[20] = "input.txt";
    long unsigned int read;
    char *input;
    input = (char*)malloc(8);
    int i = 0;
    int count = 8;
    HANDLE f_handle = CreateFileA(file, GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    while (ReadFile(f_handle, &input[i], 1, &read, NULL) && (!read==0)) {
        if (i+1 == count) {
            count *= 2;
            input = (char * )realloc(input, count);
        }
        i++;
    }
    input[i] = '\0';
    printf("%s", input);
    char temp[2];
    temp[1] = '\0';
    int available_n = 4;
    int *available;
    available = (int*)malloc(available_n*sizeof(int));
    int counter = 0;
    i = 0;
    for (i = 0; input[i] != '\n'; i++) {
        if (input[i] != ' ') {
            temp[0] = input[i];
            available[counter] = atoi(temp);
            counter++;
            if (counter == available_n) {
                available = (int*) realloc(available, available_n*sizeof(int)*2);
                available_n *= 2;
            }
        }
    }
    i+=3;
    int *existing = (int*)malloc((counter-1)*sizeof(int));
    counter = 0;
    for (i = i; input[i] != '\n'; i++) {
        if(input[i] != ' '){
            temp[0] = input[i];
            existing[counter] = atoi(temp);
            counter++;
        }
    }
    i += 3;
    int init_size = 8;
    int ** C = malloc( init_size * sizeof(int) );
    for ( int k = 0; k < init_size; k++ ) {
        C[k] = malloc( (counter-1) * sizeof(int) );
    }
    int f = counter;
    counter = 0;
    int column = 0;
    int check = 1;
    for (int k = 0; input[i] != '\r' ; k++) {
        for (i = i; input[i] != '\r'; i++) {
            if(input[i] != ' '){
                printf("%c\n", input[i]);
                temp[0] = input[i];
                C[k][counter] = atoi(temp);
                counter++;
            }
            if (counter == init_size) {
                init_size *= 2;
                C = realloc(C, init_size*sizeof(int));
                for ( int z = 0; z < init_size; z++ ) {
                    C[z] = realloc( C[z], f * sizeof(int) );
                }
            }
        }
        i+=2;
        column = counter;
        counter = 0;
        printf("%d",i);
    }
    i+=3;
    int ** R = malloc( init_size * sizeof(int) );
    for ( int k = 0; k < init_size; k++ ) {
        R[k] = malloc( (counter-1) * sizeof(int) );
    }
    for (int k = 0; input[i] != '\r' ; k++) {
        for (i = i; input[i] != '\r'; i++) {
            if(input[i] != ' '){
                printf("%c\n", input[i]);
                temp[0] = input[i];
                R[k][counter] = atoi(temp);
                counter++;
            }
        }
        i+=2;
        counter = 0;
    }
    for (int k =0; k < f+1; k++)
        for (int i =0; i < column; i++)
            printf("%d",R[k][i]);
    free(input);
//    the algorithm for deadlocks
    int row = f + 1;
    int *marked = (int *) malloc(sizeof(int) * row);
    for (int j = 0; j < row; ++j) {
        marked[j] = 0;
    }
    int num_of_marked = 0;
    int x = 0;
    while (num_of_marked < row) {
        int num_of_marked_this_iteration = 0;
        if (marked[x] == 0) {
            int less_equal = 1;
            for (int j = 0; j < column; ++j) {
                if (R[x][j] > available[j]) {
                    less_equal = 0;
                }
            }
            if (less_equal == 1) {
                marked[x] = 1;
                num_of_marked++;
                num_of_marked_this_iteration++;
                for (int j = 0; j < column; ++j) {
                    available[j] += C[x][j];
                }
            }
            if (num_of_marked_this_iteration == 0) {
                break;
            }
        }
        x = (x + 1) % row;
    }
    FILE *my_file = fopen("output.txt", "w");
    if (num_of_marked == row) {
        fprintf(my_file, "No deadlocks :)\n");
    } else {
        fprintf(my_file, "Deadlocks present :(\n");
        for (int j = 0; j < row; ++j) {
            if (marked[j] == 0) {
                fprintf(my_file, "%d, ", j);
            }
        }
    }
    fclose(my_file);
    return 0;
}
