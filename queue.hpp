#ifndef HW3_SRC_QUEUE_HPP
#define HW3_SRC_QUEUE_HPP

#include <pthread.h>
#include <queue>

typedef struct __queue_t
{
    std::queue<pthread_t> pthread_queue;
} queue_t;

void queue_init(queue_t* queue)
{

}

int queue_empty(queue_t* queue)
{
    return queue->pthread_queue.empty();
}

void queue_add(queue_t* queue, pthread_t thread)
{
    queue->pthread_queue.push(thread);
}

pthread_t queue_remove(queue_t* queue)
{
    pthread_t front_thread = queue->pthread_queue.front();
    queue->pthread_queue.pop();
    return front_thread;
}


#endif