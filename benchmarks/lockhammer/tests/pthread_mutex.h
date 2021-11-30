#pragma once

#ifdef initialize_lock
#undef initialize_lock
#endif

#define initialize_lock(lock, threads) pthread_lock_init(lock, threads)

#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <pthread.h>

static pthread_mutex_t mutex;

void pthread_lock_init(uint64_t *lock, uint64_t threads)
{
  pthread_mutex_init(&mutex, NULL);
  return;
}

static inline unsigned long lock_acquire(uint64_t *lock, unsigned long threadnum) {
  int ret;
  ret = pthread_mutex_lock(&mutex);
  assert(ret == 0);
  return 0;
}

static inline void lock_release(uint64_t *lock, unsigned long threadnum) {
  int ret;
  ret = pthread_mutex_unlock(&mutex);
  assert(ret == 0);
}