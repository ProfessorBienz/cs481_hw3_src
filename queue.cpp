#include "queue.hpp"
#include <stdlib.h>
#include <stdio.h>

void queue_init(queue_t& queue)
{
    node_t* head = (node_t*)malloc(sizeof(node_t));
    head->next = NULL;
    queue.head = head;
    queue.tail = head;
    queue.size = 0;
}

int queue_empty(queue_t& queue)
{
    return (queue.size == 0);
}

void queue_add(queue_t& queue, pthread_t thread)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->next = NULL;
    queue.tail->next = new_node;
    queue.size++; 
}

pthread_t queue_remove(queue_t& queue)
{
    node_t* front_thread = queue.head->next;
    queue.head->next = front_thread->next;
    if (front_thread == queue.tail) 
        queue.tail = queue.head;
    queue.size--;
    pthread_t thread = front_thread->thread;
    free(front_thread);
    return thread;
}

void queue_destroy(queue_t& queue)
{
    free(queue.head);
}

