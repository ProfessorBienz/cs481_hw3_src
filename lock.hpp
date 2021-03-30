#ifndef HW3_SRC_LOCK_HPP
#define HW3_SRC_LOCK_HPP

#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include "queue.hpp"
#include <signal.h>

typedef struct __lock_t
{
    // Needed for ticket locks
    int ticket;
    int turn;

    // Needed for semaphore lock
    int S;
    pthread_mutex_t mutex; 

    // Needed for queue lock
    int flag;
    int guard;
    queue_t* queue;
} lock_t;

void init(lock_t* lock);
void lock(lock_t* lock);
void unlock(lock_t* lock);
void destroy(lock_t* lock);

#endif

