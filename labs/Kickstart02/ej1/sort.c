#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    for (unsigned int j = i; j>0u; j--){
        if (!goes_before(a[j],a[j-1])) break;
        swap(a, j, j-1);
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        assert(array_is_sorted(a, i-1));
        insert(a, i);
    }
}
