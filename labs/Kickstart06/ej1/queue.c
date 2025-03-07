#include "queue.h"
#include <stdio.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

struct Queue {
    Node *front, *rear;
    unsigned int size;
};

// Crear una nueva cola vacía
Queue queue_create(void) {
    Queue q = malloc(sizeof(*q));
    if (q == NULL) return NULL;
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Encolar un elemento
void queue_enqueue(Queue q, void *data) {
    if (q == NULL) return;

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) return;
    new_node->data = data;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

// Desencolar un elemento
void* queue_dequeue(Queue q) {
    if (q == NULL || queue_is_empty(q)) return NULL;

    Node *temp = q->front;
    void *data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
    return data;
}

// Verificar si la cola está vacía
bool queue_is_empty(Queue q) {
    return q == NULL || q->front == NULL;
}

// Obtener el tamaño de la cola
unsigned int queue_size(Queue q) {
    return q != NULL ? q->size : 0;
}

// Destruir la cola y liberar memoria
void queue_destroy(Queue q) {
    if (q == NULL) return;

    while (!queue_is_empty(q)) {
        queue_dequeue(q);
    }
    free(q);
}
