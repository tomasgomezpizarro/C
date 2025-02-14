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
    return x.rank <= y.rank;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    for (unsigned int j = 0u; j < length; j++){
        if (!goes_before(atp[j - 1u], atp[j])){
            printf("%d:%s-%s\n",j,atp[j-1u].name, atp[j].name);
        }
    }
    
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

// void print_array(player_t a[], unsigned int length){
//     // fprintf(stderr, "[");
//     for (unsigned int i = 0u; i<length; i++){
//         // fprintf(stderr, "%d", a[i].rank);
//         if (i != length - 1){
//             // fprintf(stderr,", ");
//         }
//     }
//     // fprintf(stderr, "]\n");
// }

void merge(player_t a[], unsigned int start, unsigned int end){
    if (start < end){
        unsigned int mid = (start + end) /2;
        merge(a, start, mid);
        merge(a, mid + 1, end);
        unsigned int first_left = start, first_rigth = mid + 1 ;
        if (mid < end){
            for (unsigned int i=0; i< end-start; i++){
                // fprintf(stderr, "start->%u - end->%u  ...  ", start, end);
                // fprintf(stderr, "%u-%u  ...  ", first_left, first_rigth);
                // print_array(a, LENGTH);
                if (goes_before(a[first_left], a[first_rigth])){
                    first_left ++;
                } else {
                    for (unsigned int j=first_rigth; j>first_left; j--){
                        swap(a,j,j-1);
                    }
                    first_left ++;
                    first_rigth ++;
                    if (first_rigth ==  end +1) break;
                    // i++;
                }
            }
        }
        // fprintf(stderr, "start->%u - end->%u_________________", start, end);
        // print_array(a, LENGTH);
    }
}

void sort(player_t a[], unsigned int length) {
    merge(a, 0, length-1);   
}

