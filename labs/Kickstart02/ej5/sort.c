#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    fixstring pivot_value;
    copy_in(a[izq], pivot_value);
    unsigned int i=izq+1, j=der;
    while (i != j+1){
        if (goes_before(a[i], pivot_value)){
            swap(a, i, i-1);
            i++;
        } else {
            swap(a, i, j);
            j--;
        }
    }
    return j;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int pivot = partition(a, izq, der);
    if (pivot > izq+1) quick_sort_rec(a, izq, pivot-1);
    if (pivot+1 < der) quick_sort_rec(a, pivot + 1, der);
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


