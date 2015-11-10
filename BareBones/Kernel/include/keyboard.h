#ifndef KEYBOARD_H
#define KEYBOARD_H

void keyboardISR(void);
uint8_t dequeueKey(void);
uint8_t peekKey(void);

int isShifted(void);
int isCapsLockOn(void);
int isNumLockOn(void);

#endif
