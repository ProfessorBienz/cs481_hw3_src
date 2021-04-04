#include "my_intercept.hpp"
#include <stdlib.h>

long* my_rand_vals;
int my_rand_ctr;

long my_time(void* arg)
{
    return 2743532;
}

void rand_init(int global_n)
{
    my_rand_ctr = 0;
    my_rand_vals = (long*)malloc(2*global_n*sizeof(long));

    srand(my_time(NULL));
    for (int i = 0; i < 2*global_n; i++)
        my_rand_vals[i] = rand();
}

void rand_destroy()
{
    free(my_rand_vals);
}

int my_rand()
{
    return my_rand_vals[my_rand_ctr++];
}
