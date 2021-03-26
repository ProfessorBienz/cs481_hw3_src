#ifndef FUTEX_HPP
#define FUTEX_HPP

void mutex_init(int mutex);
void mutex_lock(int mutex);
void mutex_unlock(int mutex);

#endif
