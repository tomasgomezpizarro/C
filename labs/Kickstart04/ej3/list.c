#include "list.h"
#include <stdlib.h>

struct _list{
    unsigned int len;
    unsigned int max_array;
    list_elem* array;
};

bool elem_compare(list_elem e1, list_elem e2){
    return (e1 == e2);
}

list list_new_with_len(unsigned int len){
    list l = (list)malloc(sizeof(struct _list));
    l->len = 0;
    l->max_array = len * 2;
    l->array = (list_elem *)malloc(sizeof(list_elem) * len * 2);
    return l;
}
list list_new(){
    return list_new_with_len(INITIAL_LENGTH/2);
}
void list_destroy(list l){
    free(l->array);
    free(l);
}
unsigned int list_len(list l){
    return l->len;
}

// Crear desde array
list list_from_array(list_elem arr[], unsigned int len){
    list l = list_new_with_len(len);
    for (unsigned int i = 0; i < len; i++){
        l->array[i] = arr[i];
    }
    l->len = len;
    return l;
}

// Búsqueda y acceso
list_elem list_get(list l, unsigned int index){
    return l->array[index];
}
unsigned int list_count(list l, list_elem e){
    unsigned int count = 0;
    for (unsigned int i = 0; i < l->len; i++){
        if (elem_compare(l->array[i],e)){
            count ++;
        }
    }
    return count;
}
int list_index(list l, list_elem e){ // returns -1 if it is not found
    for (unsigned int i = 0; i < l->len; i++){
        if (elem_compare(l->array[i],e)){
            return i;
        }
    } 
    return -1; 
}
bool list_contains(list l, list_elem e){
    for (unsigned int i = 0; i < l->len; i++){
        if (elem_compare(l->array[i],e)){
            return true;
        }
    } 
    return false;     
}

// Modificación
void list_append(list l, list_elem e){
    list_insert(l, e, l->len);
}
void list_clear(list l){
    l->len = 0;
    l->max_array = INITIAL_LENGTH;
    free(l->array);
    l->array = (list_elem *)malloc(sizeof(list_elem) * INITIAL_LENGTH);
}
void list_insert(list l, list_elem e, unsigned int index){
    if (l->len == l->max_array){
        l->array = realloc(l->array, l->max_array * 2);
        l->max_array *= 2;
    }
    // Corro todos los elementos un índice a la derecha
    for (unsigned int i = l->len; i > index; i--){
        l->array[i] = l->array[i-1];
    }
    l->len ++;
    l->array[index] = e;
}

void list_pop(list l, unsigned int index){
    if (index < l->len/2){
        for (unsigned int i = index; i > 0u; i--){
            l->array[i] = l->array[i-1];
        }
        list_elem* temp = l->array;
        l->array ++;
        free(temp);
        l->max_array --;
    } else {
        for (unsigned int i = index; i<l->len-1u; i++){
            l->array[i] = l->array[i+1];
        }
    }
    l->len --;
    if (l->max_array/l->len > 4u){
        l->array = realloc(l->array, sizeof(list_elem) * l->max_array/2);
        l->max_array /= 2;
    }
}

void list_remove(list l, list_elem e){
    int index = list_index(l, e);
    if (index != -1){
        list_pop(l, (unsigned int)index);
    }
}

// Operaciones entre listas
list list_copy(list l){
    return list_from_array(l->array, l->len);
}
void list_extend(list l_dest, list l_src){
    if (l_dest->len + l_src->len > l_dest->max_array){
        l_dest->array = realloc(l_dest->array, sizeof(list_elem) * (l_dest->len + l_src->len) * 2);
    }
    for (unsigned int i=l_dest->len; i<l_dest->len + l_src->len; i++){
        l_dest->array[i] = l_src->array[i-l_dest->len];
    }
}
bool list_equal(list l1, list l2){
    if (l1->len == l2->len){
        for (unsigned int i = 0; i < l1->len; i++){
            if (!elem_compare(l1->array[i], l2->array[i])){
                return false;
            }
        }
        return true;     
    } return false;
}
