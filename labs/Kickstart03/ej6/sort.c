/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    return x->rank <= y->rank;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
       i++;
    }

    return (i == length);
}

void swap(player_t a[], unsigned int i, unsigned int j){
    player_t temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void merge(player_t a[], unsigned int start, unsigned int end){
    if (start < end){
        unsigned int mid = (start + end) /2;
        merge(a, start, mid);
        merge(a, mid + 1, end);
        unsigned int first_left = start, first_rigth = mid + 1 ;
        if (mid < end){
            for (unsigned int i=0; i< end-start; i++){
                if (goes_before(a[first_left], a[first_rigth])){
                    first_left ++;
                } else {
                    for (unsigned int j=first_rigth; j>first_left; j--){
                        swap(a,j,j-1);
                    }
                    first_left ++;
                    first_rigth ++;
                    if (first_rigth ==  end +1) break;
                }
            }
        }
    }
}

void sort(player_t a[], unsigned int length) {
    merge(a, 0, length-1);   
}

