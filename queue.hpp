#ifndef HW3_SRC_QUEUE_HPP
#define HW3_SRC_QUEUE_HPP

#include <pthread.h>
#include <queue>

typedef struct __node_t
{
    struct __node_t* next;
    pthread_t thread;
} node_t;

typedef struct __queue_t
{
    node_t* head;
    node_t* tail;
    int size;
} queue_t;

void queue_init(queue_t& queue);
int queue_empty(queue_t& queue);
void queue_add(queue_t& queue, pthread_t thread);
pthread_t queue_remove(queue_t& queue);


#endif
