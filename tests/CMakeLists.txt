include_directories(${hw3_INCDIR})

add_executable(test_pi test_pi.cpp)
target_link_libraries(test_pi hw3 googletest )
add_test(TestPI ./test_pi)

