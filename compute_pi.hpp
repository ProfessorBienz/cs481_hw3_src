#ifndef HW3_SRC_COMPUTE_PI_HPP
#define HW3_SRC_COMPUTE_PI_HPP

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "lock.hpp"
#include "intercept.hpp"

typedef struct __calc_t
{
    int global_sum;
    int global_n_samples;
    int global_n_threads;
    lock_t lock;
} calc_t;

typedef struct __thread_data_t
{
    calc_t* pi_calc;
    int thread_id;
} thread_data_t;

void* compute_pi(void* arg);

double pthread_compute_pi(int num_threads, int num_samples, int S);


#endif
