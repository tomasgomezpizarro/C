#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int* y) { 
    if (x >= 0) {
        *y = x;
    } else{
        *y = -x;
    }

}

int main(void) {
    int a=-10, *res=(int*)malloc(sizeof(int));
    absolute(a, res);
    printf("%d", *res);
    return EXIT_SUCCESS;
}

