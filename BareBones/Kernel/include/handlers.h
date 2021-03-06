#ifndef HANDLERS_H
#define HANDLERS_H
#include <stdint.h>
#include <types.h>
#define READ 0
#define WRITE 1
#define SOUND 2


void irqDispatcher(dword irq, dword syscall);
void handler(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);


#endif
