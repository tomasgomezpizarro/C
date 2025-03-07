#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

// Definición del tipo Queue como un puntero a estructura opaca
typedef struct Queue *Queue;

// Crear una nueva cola
Queue queue_create(void);

// Encolar un elemento (puntero)
void queue_enqueue(Queue q, void *data);

// Desencolar un elemento (retorna el puntero)
void* queue_dequeue(Queue q);

// Ver si la cola está vacía
bool queue_is_empty(Queue q);

// Obtener el tamaño de la cola
unsigned int queue_size(Queue q);

// Liberar la memoria de la cola
void queue_destroy(Queue q);

#endif // QUEUE_H
