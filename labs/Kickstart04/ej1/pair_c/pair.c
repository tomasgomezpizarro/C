#include "pair.h"
#include <stdlib.h>

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y){
    pair_t p = (pair_t)malloc(sizeof(struct s_pair_t));
    p->fst = x;
    p->snd = y;
    return p;
}

int pair_first(pair_t p){
    return p->fst;
}

int pair_second(pair_t p){
    return p->snd;
}

pair_t pair_swapped(pair_t p){
    return pair_new(p->snd, p->fst);
}

pair_t pair_destroy(pair_t p){
    free(p);
    return p;
}