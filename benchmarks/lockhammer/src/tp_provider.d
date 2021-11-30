provider lockhammer_usdt {
  probe lock_acquire(uint64_t lock_addr);
  probe lock_acquired(uint64_t lock_addr);

  probe lock_release(uin64_t lock_addr);
  probe lock_released(uint64_t lock_addr);
}