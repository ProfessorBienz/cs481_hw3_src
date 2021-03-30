#ifndef HW3_SRC_QUEUE_HPP
#define HW3_SRC_QUEUE_HPP

#include <pthread.h>
#include <queue>

typedef struct __queue_t
{
    std::queue<pthread_t> pthread_queue;
} queue_t;

void queue_init(queue_t& queue);
int queue_empty(queue_t& queue);
void queue_add(queue_t& queue, pthread_t thread);
pthread_t queue_remove(queue_t& queue);


#endif
