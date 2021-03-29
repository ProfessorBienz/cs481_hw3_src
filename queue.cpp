#include "queue.hpp"

static void queue_init(queue_t* queue)
{

}

static int queue_empty(queue_t* queue)
{
    return queue->pthread_queue.empty();
}

static void queue_add(queue_t* queue, pthread_t thread)
{
    queue->pthread_queue.push(thread);
}

static pthread_t queue_remove(queue_t* queue)
{
    pthread_t front_thread = queue->pthread_queue.front();
    queue->pthread_queue.pop();
    return front_thread;
}

