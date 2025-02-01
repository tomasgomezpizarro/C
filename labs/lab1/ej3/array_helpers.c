#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h" 

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    FILE *f = fopen(filepath, "r");

    int length ;
    fscanf(f, "%d\n", &length);

    if(length>(int)max_size || length<=0){
        printf("Error: Invalid array length. Must be between 1 and 100000\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < length-1; i++){
        fscanf(f, "%d ", &(array[i]));
    }
    fscanf(f, "%d", &(array[length-1]));
    fclose(f);
    return (unsigned int)length;
}

void array_dump(int a[], unsigned int length) {
    printf("[");
    for (unsigned int i = 0; i < length; i++){
        printf(" %d,", a[i]);
    }
    printf("]\n");
}
