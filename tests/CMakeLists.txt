include_directories(${hw3_INCDIR})

add_executable(test_pi_spin test_pi.cpp)
target_link_libraries(test_pi_spin hw3_ticket_spin googletest )
add_test(TestPITicketSpin ./test_pi_spin)

add_executable(test_pi_yield test_pi.cpp)
target_link_libraries(test_pi_yield hw3_ticket_yield googletest )
add_test(TestPITicketYield ./test_pi_yield)

add_executable(test_pi_queue test_pi.cpp)
target_link_libraries(test_pi_queue hw3_queue googletest )
add_test(TestPIQueue ./test_pi_queue)

add_executable(test_pi_semaphore test_pi.cpp)
target_link_libraries(test_pi_semaphore hw3_semaphore googletest )
add_test(TestPISemaphore ./test_pi_semaphore)

add_executable(test_lock_spin test_lock.cpp)
target_link_libraries(test_lock_spin hw3_ticket_spin googletest)
add_test(TestLockSpin ./test_lock_spin)

add_executable(test_lock_yield test_lock.cpp)
target_link_libraries(test_lock_yield hw3_ticket_yield googletest)
add_test(TestLockYield ./test_lock_yield)

add_executable(test_lock_queue test_lock.cpp)
target_link_libraries(test_lock_queue hw3_queue googletest)
add_test(TestLockQueue ./test_lock_queue)

add_executable(test_lock_semaphore test_lock.cpp)
target_link_libraries(test_lock_semaphore hw3_semaphore googletest)
add_test(TestLockSemaphore ./test_lock_semaphore)

