#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"
 
typedef struct s_stack_node {
    struct s_stack_node* next;
    stack_elem elem;
}* stack_node;

struct _s_stack {
    stack_node first;
};

stack stack_empty(){
    stack s = NULL;
    s = (stack)malloc(sizeof(struct _s_stack));
    if (s==NULL){
        fprintf(stderr,"Error al asignar memoria al empty stack");
        exit(EXIT_FAILURE);
    }
    s->first = NULL;
    return s;
}


stack stack_push(stack s, stack_elem e){
    stack_node temp = s->first;
    s->first = malloc(sizeof(struct s_stack_node));
    s->first->elem = e;
    s->first->next = temp;
    return s;
}


stack stack_pop(stack s){
    assert(!stack_is_empty(s));
    stack_node temp = s->first;
    s->first = s->first->next;
    free(temp);
    return s;
}


unsigned int stack_size(stack s){
    unsigned int count = 0;
    stack_node temp = s->first;
    while (temp != NULL){
        count ++;
        temp = temp->next;
    }
    return count;
}


stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->first->elem;
}


bool stack_is_empty(stack s){
    return (s->first == NULL);
}


stack_elem *stack_to_array(stack s){
    unsigned int size = stack_size(s);
    stack_elem* a = calloc(size, sizeof(stack_elem));
    stack_node temp = s->first;
    for (int i = size-1; i >= 0; i--){
        a[i] = temp->elem;
        temp = temp->next;
    }
    return a;
}


stack stack_destroy(stack s){
    stack_node temp;
    while (s->first != NULL){
        temp = s->first;
        s->first = s->first->next;
        free(temp);
    }
    free(s); 
    return s;   
}
