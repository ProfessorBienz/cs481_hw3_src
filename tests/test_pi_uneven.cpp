// EXPECT_EQ and ASSERT_EQ are macros
// EXPECT_EQ test execution and continues even if there is a failure
// ASSERT_EQ test execution and aborts if there is a failure
// The ASSERT_* variants abort the program execution if an assertion fails 
// while EXPECT_* variants continue with the run.

#include "gtest/gtest.h"
#include "hw3_src/compute_pi.hpp"
#include "hw3_src/my_intercept.hpp"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

void init_threads(int num_samples, int num_threads)
{
    calc_t* pi_calc = (calc_t*)malloc(sizeof(calc_t));
    pi_calc->global_sum = 0;
    pi_calc->global_n_samples = num_samples;
    pi_calc->global_n_threads = num_threads;

    pthread_t* threads = (pthread_t*)malloc(num_threads*sizeof(pthread_t));
    thread_data_t* thread_data = (thread_data_t*)malloc(num_threads*sizeof(thread_data_t));

    init(&(pi_calc->lock));
    rand_init(num_samples);
    for (int i = 0; i < num_samples; i++)
        zero_vals(num_samples);

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

    ASSERT_EQ(pi_calc->global_sum, pi_calc->global_n_samples);

    rand_destroy();

    destroy(&(pi_calc->lock));
}


TEST(TLBTest, TestsIntests)
{
  init_threads(100, 1);
  init_threads(100, 3);
  init_threads(100, 7);
}
