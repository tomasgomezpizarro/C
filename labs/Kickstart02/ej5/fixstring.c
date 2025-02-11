#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int recursive_lenght(fixstring s, unsigned int min, unsigned int max) {
    if (s[min] == '\0') return min;
    
    unsigned int mid = (min + max)/2;
    if ((int)(s[mid]) == 0){
        return recursive_lenght(s, min, mid);        
    } else {
        return recursive_lenght(s, mid+1, max);
    }
}

unsigned int fstring_length(fixstring s) {
    unsigned int min = 0, max=FIXSTRING_MAX;
    return recursive_lenght(s, min, max);
}

bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int l1 = fstring_length(s1), l2 = fstring_length(s2);
    if (l1 != l2) return 0;
    for (unsigned int i = 0; i < l1; i++){
        if (s1[i] != s2[i]) return 0;
    }
    return 1;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int l1 = fstring_length(s1), l2 = fstring_length(s2), max;
    max = (l1 < l2) * l2 + (l1 >= l2) * l1;
    for (unsigned int i = 0; i < max; i++){
        if ((int)(s1[i]) < (int)(s2[i])) return 1;
        if ((int)(s1[i]) > (int)(s2[i])) return 0;
    }
    return 1;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void copy_in(fixstring s1, fixstring s2){
    for (unsigned int i=0u; i<FIXSTRING_MAX; i++){
        s2[i] = s1[i];
    }   
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    copy_in(s1, aux);
    copy_in(s2, s1);
    copy_in(aux, s2);
}


