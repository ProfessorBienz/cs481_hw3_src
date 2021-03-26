#ifndef COMPUTE_PI_HPP
#define COMPUTE_PI_HPP

// Sloppiness Factor
int S;
int global_sum;

void* compute_pi(void* arg);

void pthread_compute_pi(int num_threads, int num_samples)
{
    global_sum = 0;

    pthread_t* threads = (pthread_t*)malloc(num_threads*sizeof(pthread_t));
    for (int i = 0; i < num_threads; i++)
        pthread_create(&(threads[i]), NULL, compute_pi, NULL);
    for (int i = 0; i < n_threads; i++)
        pthread_join(threads[i], NULL);

    free(threads);
    
    return global_sum;
}



#endif
