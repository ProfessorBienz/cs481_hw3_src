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

void* thread0(void* arg)
{
    lock(&my_lock);
    while (queue_empty(my_lock.queue)) 
        sched_yield();
    unlock(&my_lock);
    printf("queue not empty\n");
    val *= 2;

    printf("val %d\n", val);
    return NULL;
}

void* thread1(void* arg)
{
    val += 1;
    printf("val %d\n", val);
    lock(&my_lock);
    printf("Hvae lock...\n");
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
    val = 0;
    finished = 0;

    pthread_t pthread0;
    pthread_t pthread1;

    pthread_create(&pthread0, NULL, thread0, NULL);
    pthread_create(&pthread1, NULL, thread1, NULL);

    pthread_join(pthread0, NULL);
    printf("pthread0 returned\n");
    while (!finished)
    { 
        pthread_kill(pthread1, SIGCONT);
        sched_yield();
    }
    pthread_join(pthread1, NULL);

    ASSERT_EQ(val, 2);

    destroy(&my_lock);
}
