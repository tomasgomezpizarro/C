#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct Item
{
    int valor;
    struct Item* next;
};


struct Lista{
    struct Item* first;
    unsigned int length;
};

bool empty(struct Lista* l){
    return (l->length == 0);
}

struct Lista* new_lista(){
    struct Lista *l = (struct Lista*)malloc(sizeof(struct Lista));
    l->first = NULL;
    l->length = 0;
    return l;
}

struct Item* getElement(struct Lista* l, unsigned int index){
    assert((index<l->length));
    struct Item* temp = l->first;
    for (unsigned int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp;
}

void insert(struct Lista* l, int valor, unsigned int index){
    assert((index<=l->length));

    struct Item* to_add = (struct Item*)malloc(sizeof(struct Item)); // Se deberia revisar que se reservo el espacio
    to_add->valor = valor;

    if (l->length == 0){
        to_add->next = NULL;
        l->first = to_add;
    } else {
        struct Item* temp;
        if (index == 0){
            temp = l->first;
            l->first = to_add;
            to_add->next = temp;
        } else{
            struct Item* prev = getElement(l, index-1u);
            temp = prev->next;
            prev->next = to_add;
            to_add->next = temp;
        }
    }
    l->length ++;
}

void append(struct Lista* l, int valor){
    insert(l, valor, l->length);
}

void pop(struct Lista* l, unsigned int index){
    assert(index<l->length);

    struct Item* temp;
    if (index == 0){
        temp = l->first->next;
        free(l->first);
        l->first=temp;
    } else{
        struct Item* prev = getElement(l, index-1u);
        temp = prev->next;
        prev->next = temp->next;
        free(temp);
        }
    l->length --;    
}

void replace(struct Lista* l, int valor, unsigned int index){
    pop(l, index);
    insert(l, valor, index);
}

unsigned int index(struct Lista* l, int valor){
    bool found = false;
    struct Item* pointer_to_current_item = l->first;
    unsigned int ix;
    for (unsigned int i = 0; i < l->length; i++){
        if (pointer_to_current_item->valor == valor){
            found = true;
            ix = i;
            break;
        }
        pointer_to_current_item = pointer_to_current_item->next;
    }
    assert(found);
    return ix;
}

void delete(struct Lista* l, int valor){
    pop(l, index(l, valor));
}

void imprimir(struct Lista* l){
    printf("%d\n",l->length);
    printf("[");
    bool not_first = 0;
    struct Item* pointer_to_current_item = l->first;
    if (pointer_to_current_item != NULL){
        while (pointer_to_current_item->next != NULL){
            if (not_first) {
                printf(", ");
            }
            not_first = 1;
            printf("%d", pointer_to_current_item->valor);
            pointer_to_current_item = pointer_to_current_item->next;
        }        
        if (not_first) {
            printf(", ");
        }
        printf("%d", pointer_to_current_item->valor);
    }
    printf("]\n");
}

void destruir_lista(struct Lista* l) {
    struct Item* actual = l->first;
    while (actual != NULL) {
        struct Item* temp = actual;
        actual = actual->next;
        free(temp);
    }
    free(l);
}

int main(){
    struct Lista* l = new_lista();
    append(l, 10);
    append(l, 9);
    insert(l, 5, 2u);
    imprimir(l);
    insert(l, 0, 3u);
    imprimir(l);
    replace(l, 0, 2u);
    imprimir(l);
    delete(l, 9);
    imprimir(l);
    destruir_lista(l);
    return EXIT_SUCCESS;
}