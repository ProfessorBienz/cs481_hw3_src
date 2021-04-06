set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(src_SOURCES
    hw3_src/queue.hpp
    hw3_src/queue.cpp
    hw3_src/lock.hpp
    hw3_src/compute_pi.hpp
    hw3_src/compute_pi_helper.cpp
    hw3_src/intercept.hpp
    hw3_src/my_intercept.hpp
    hw3_src/my_intercept.cpp
    PARENT_SCOPE
    )

add_library(hw3_mutex STATIC
    queue.hpp
    queue.cpp
    lock.hpp
    compute_pi.hpp
    compute_pi_helper.cpp
    intercept.hpp
    my_intercept.hpp
    my_intercept.cpp
    ${hw3_INCDIR}/compute_pi.cpp
    mutex_lock.cpp
    )
target_link_libraries(hw3_mutex pthread)
