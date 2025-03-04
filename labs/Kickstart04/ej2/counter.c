#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = (counter)malloc(sizeof(struct _counter));
    if (c != NULL){
        c->count = 0;
    } else {
        fprintf(stdout, "NO HAY LUGAR PARA ALOCAR EL PUNTERO\n");
        exit(EXIT_FAILURE);
    }
    assert (counter_is_init(c));
    return c;
}

void counter_inc(counter c) {
    c->count ++;
}

bool counter_is_init(counter c) {
    return (c != NULL && c->count == 0);
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count --;
}

counter counter_copy(counter c) {
    counter n = counter_init();
    n->count = c->count;
    return n;
}

void counter_destroy(counter c) {
    free(c);
}
