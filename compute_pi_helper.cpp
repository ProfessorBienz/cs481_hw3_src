#include "compute_pi.hpp"
#include "lock.hpp"
#include "my_intercept.hpp"

double pthread_compute_pi(int num_threads, int num_samples, int S)
{
    calc_t* pi_calc = (calc_t*)malloc(sizeof(calc_t));
    pi_calc->global_sum = 0;
    pi_calc->global_n_samples = num_samples;
    pi_calc->global_n_threads = num_threads;

    pthread_t* threads = (pthread_t*)malloc(num_threads*sizeof(pthread_t));
    thread_data_t* thread_data = (thread_data_t*)malloc(num_threads*sizeof(thread_data_t));

    init(&(pi_calc->lock));
    rand_init(num_samples);

    for (int i = 0; i < num_threads; i++)
    {
        thread_data[i].pi_calc = pi_calc;
        thread_data[i].thread_id = i;
        pthread_create(&(threads[i]), NULL, compute_pi, &(thread_data[i]));
    }
    for (int i = 0; i < num_threads; i++)
        pthread_join(threads[i], NULL);

    free(threads);
    free(thread_data);

    rand_destroy();

    destroy(&(pi_calc->lock));
    
    return 4.0 * pi_calc->global_sum / (1.0*num_samples);
}
