// EXPECT_EQ and ASSERT_EQ are macros
// EXPECT_EQ test execution and continues even if there is a failure
// ASSERT_EQ test execution and aborts if there is a failure
// The ASSERT_* variants abort the program execution if an assertion fails 
// while EXPECT_* variants continue with the run.

#include "gtest/gtest.h"
#include "hw3_src/lock.hpp"
#include <sys/time.h>

lock_t my_lock;
bool first, timed_out;
bool thread0bool, thread1bool;

void timeout_sig_handler(int signum)
{
    timed_out = true;
    unlock(&my_lock);
}

void* thread1(void* arg)
{
    lock(&my_lock);
    thread0bool = first==false;
    first = true;
    unlock(&my_lock);

    return NULL;
}

void* thread0(void* arg)
{
    while (my_lock.S > 0 && !first)
        sched_yield();
    while (my_lock.S <= 0) 
        sched_yield();
    lock(&my_lock);
    thread1bool = first==true;
    unlock(&my_lock);

    return NULL;
}

void* thread_timeout(void* arg)
{
    signal(SIGUSR1, timeout_sig_handler);
    lock(&my_lock);
    lock(&my_lock);

    return NULL;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

void timer_handler(int signum)
{
    timed_out = true;
}

TEST(TLBTest, TestsIntests)
{
    init(&my_lock);
    first = false;

    pthread_t pthread0;
    pthread_t pthread1;

    pthread_create(&pthread0, NULL, thread0, NULL);
    pthread_create(&pthread1, NULL, thread1, NULL);

    pthread_join(pthread0, NULL);
    pthread_join(pthread1, NULL);

    ASSERT_EQ(thread0bool, true);
    ASSERT_EQ(thread1bool, true);

    timed_out = false;
    pthread_create(&pthread0, NULL, thread_timeout, NULL);
    sleep(2);
    pthread_kill(pthread0, SIGUSR1);
    pthread_join(pthread0, NULL);
    ASSERT_EQ(timed_out, true);


    destroy(&my_lock);
}
