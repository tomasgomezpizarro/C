#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

void read(int indexes[], char letters[], FILE *file, unsigned int *lenght){
    for (unsigned int i = 0u; i<MAX_SIZE; i++){
        if (feof(file)) break;
        fscanf(file, "%d -> *%s*", &(indexes[i]), &(letters[i]));
        if (letters[i] == '*') {
            letters[i] = ' ';
        }
        (*lenght)++;
    }
    (*lenght) --;
}

void sort(unsigned int indexes[], char letters[], char sorted[], unsigned int length){
    for (unsigned int j=0u; j < length; j++) {
        sorted[indexes[j]] = letters[j];
    }
}

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[argc-1], "r");
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    read((int *)indexes, letters, file, &length);
    sort(indexes, letters, sorted, length);
    dump(sorted, length);

    return EXIT_SUCCESS;
}

