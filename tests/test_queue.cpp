// EXPECT_EQ and ASSERT_EQ are macros
// EXPECT_EQ test execution and continues even if there is a failure
// ASSERT_EQ test execution and aborts if there is a failure
// The ASSERT_* variants abort the program execution if an assertion fails 
// while EXPECT_* variants continue with the run.

#include "gtest/gtest.h"
#include "hw3_src/lock.hpp"

lock_t my_lock;
int val;
int finished;

void sig_handler(int signum)
{
}

void* thread0(void* arg)
{
    lock(&my_lock);
    while (queue_empty(my_lock.queue)) 
        sched_yield();
    unlock(&my_lock);
    for (int i = 0; i < 10000; i++)
        val--;

    return NULL;
}

void* thread1(void* arg)
{
    signal(SIGUSR1, sig_handler);
    for (int i = 0; i < 10000; i++)
        val++;
    lock(&my_lock);
    unlock(&my_lock);
    finished = 1;

    return NULL;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(TLBTest, TestsIntests)
{
    init(&my_lock);
    val = 1;
    finished = 0;

    pthread_t pthread0;
    pthread_t pthread1;

    pthread_create(&pthread0, NULL, thread0, NULL);
    pthread_create(&pthread1, NULL, thread1, NULL);

    pthread_join(pthread0, NULL);
    while (!finished)
    { 
        pthread_kill(pthread1, SIGUSR1);
        sched_yield();
    }
    pthread_join(pthread1, NULL);

    ASSERT_EQ(val, 1);

    destroy(&my_lock);
}
