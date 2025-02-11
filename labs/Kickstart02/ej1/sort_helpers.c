#include <stdbool.h>

bool goes_before(int x, int y){
    return x<y;
}
/* Abstract total order for sorting algorithms */

bool array_is_sorted(int a[], unsigned int length){
    for (unsigned int i=1; i<length;i++){
        if (goes_before(a[i], a[i-1])){
            return 0;
        }
    }
    return 1;
}

void swap(int a[], unsigned int i, unsigned int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}