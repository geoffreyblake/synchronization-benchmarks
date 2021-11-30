#pragma once

#ifdef initialize_lock
#undef initialize_lock
#endif

#define initialize_lock(lock, threads) semaphore_lock_init(lock, threads)

#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <semaphore.h>
#include "lockhammer.h"

static sem_t semaphore;

void semaphore_lock_init(uint64_t *lock, uint64_t threads)
{
  sem_init(&semaphore, 0, 1);
  return;
}

static inline unsigned long lock_acquire(uint64_t *lock, unsigned long threadnum) {
  int ret;
  do {
    ret = sem_wait(&semaphore);
  } while(ret == -1 && errno == EINTR);
  return 0;
}

static inline void lock_release(uint64_t *lock, unsigned long threadnum) {
  int ret;
  ret = sem_post(&semaphore);
  assert(ret == 0);
}