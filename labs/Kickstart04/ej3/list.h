#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

#define INITIAL_LENGTH 16

typedef int list_elem;
typedef struct _list* list;

// Constructor y destructor
list list_new_with_len(unsigned int len);
list list_new();
void list_destroy(list l);
unsigned int list_len(list l);

// Crear desde array
list list_from_array(list_elem arr[], unsigned int len);

// Búsqueda y acceso
list_elem list_get(list l, unsigned int index);
unsigned int list_count(list l, list_elem e);
int list_index(list l, list_elem e);
bool list_contains(list l, list_elem e);

// Modificación
void list_append(list l, list_elem e);
void list_clear(list l);
void list_insert(list l, list_elem e, unsigned int index);
void list_pop(list l, unsigned int index);
void list_remove(list l, list_elem e);

// Operaciones entre listas
list list_copy(list l);
void list_extend(list l_dest, list l_src);
bool list_equal(list l1, list l2);

#endif
