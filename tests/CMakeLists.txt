include_directories(${hw3_INCDIR})
link_directories(${hw3_INCDIR}/hw3_src)

add_executable(test_pi test_pi.cpp)
target_link_libraries(test_pi hw3_mutex googletest)
add_test(TestPI ./test_pi)

add_executable(test_pi_yield test_pi.cpp)
target_link_libraries(test_pi_yield hw3_ticket_yield googletest )
add_test(TestPIYield ./test_pi_yield)

add_executable(test_pi_semaphore test_pi.cpp)
target_link_libraries(test_pi_semaphore hw3_semaphore googletest )
add_test(TestPISemaphore ./test_pi_semaphore)

add_executable(test_lock_yield test_lock.cpp)
target_link_libraries(test_lock_yield hw3_ticket_yield googletest)
add_test(TestAdditionYield ./test_lock_yield)

add_executable(test_spin_lock test_spin_lock.cpp)
target_link_libraries(test_spin_lock hw3_ticket_spin googletest)
add_test(TestSpinLock ./test_spin_lock)

add_executable(test_yield_lock test_yield_lock.cpp)
target_link_libraries(test_yield_lock hw3_ticket_yield googletest)
add_test(TestYieldLock ./test_yield_lock)

add_executable(test_semaphore_lock test_semaphore_lock.cpp)
target_link_libraries(test_semaphore_lock hw3_semaphore googletest)
add_test(TestSemaphorenLock ./test_semaphore_lock)

add_executable(test_queue_lock test_queue_lock.cpp)
target_link_libraries(test_queue_lock hw3_queue googletest)
add_test(TestQueueLock ./test_queue_lock)

add_executable(test_queue test_queue.cpp)
target_link_libraries(test_queue hw3_queue googletest)
add_test(TestAddPopQueue ./test_queue)

