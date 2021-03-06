#include <stdint.h>
#include <keyboard.h>
#include <naiveConsole.h>
#include <interrupts.h>

#define NUMBER 1
#define LETTER 2
#define SYMBOL 3
#define OTHER 0


static uint8_t kbdTable[128] = {
    0, /* No key for scan code 0 */ 
    27, '1', '2', '3', '4', '5', '6', '7', '8',	'9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r',	't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, /* 29   - Control */
    
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0,	/* Left shift */
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
    0,	/* Right shift */
    0,  /*PrtScr */
    0,	/* Alt */
    ' ',/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
    0,
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
    0,
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0	/* All other keys are undefined */
};


static uint8_t shiftedKbdTable[128] = {
    0,  /* No key for scan code 0 */
    27, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b',
    '\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',
    0,  /* 29   - Control */
    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '\"', '~',
    0,  /* Left shift */
    '|', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?',
    0,  /* Right shift */
    0,  /*PrtScr*/
    0,  /* Alt */
    ' ',/* Space bar */
    0,  /* Caps lock */
    0,  /* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,  /* < ... F10 */
    0,  /* 69 - Num lock*/
    0,  /* Scroll Lock */
    0,  /* Home key */
    0,  /* Up Arrow */
    0,  /* Page Up */
    0,
    0,  /* Left Arrow */
    0,
    0,  /* Right Arrow */
    0,
    0,  /* 79 - End key*/
    0,  /* Down Arrow */
    0,  /* Page Down */
    0,  /* Insert Key */
    0,  /* Delete Key */
    0,   0,   0,
    0,  /* F11 Key */
    0,  /* F12 Key */
    0  /* All other keys are undefined */
};


static uint16_t notesTable[128] =
    {
    0,  27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    27,
    9121, 8609, 8126, 7670, 7239, 6833, 6449, 6087, 5746,
    0, 0, 0, 0,
    5423, 5119, 4831, 4560, 4304, 4063, 3834, 3619, 3416,
    0, 0, 0,   0, 0,
    3224, 3043, 2873, 2711, 2559, 2415, 2280,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
    0,  0,  0,  0,  0,  0,  0  
};





static int analizeScanCode(uint64_t code) {

    
    if (code >= 2 && code <= 11) {
        return NUMBER;
    }
    if ( (code >= 16 && code <= 25) || (code >= 30 && code <= 38) || (code >= 44 && code <= 50) ) {
        return LETTER;
    }
    if (code == 1 || code == 12 || code == 13 || code == 14 || code == 15
        || code == 26 || code == 27 || code == 28 || code == 39 || code == 40
        || code == 41 || code == 43 || code == 51 || code == 52 || code == 53 || code == 57) {
        return SYMBOL;
    }
    return OTHER;
}

uint64_t checkKbdInterrupt(void) {

	uint8_t code = peekKey();
	if (code >= 128 || code < 0) {
		dequeueKey();
	}
	return  (uint64_t)((code >= 128 || code < 0) ? 0 : 1);

}


char getCharFromKbd() {

    uint8_t code = dequeueKey();
    int flag = analizeScanCode(code);
    char result = -1;
	int shift, capsLock, numLock;
	shift = isShifted();
	capsLock = isCapsLockOn();
	numLock = isNumLockOn();


    switch(flag) {

        case NUMBER: {
            int numbers = ((shift != 0)? 1 : 0) - numLock; /* XOR operation */
            if (!numbers) {
                result = shiftedKbdTable[code];
            } else {
                result = kbdTable[code];
            }
            break;
        }
        case LETTER: {
            int maysuc = ((shift != 0)? 1 : 0) - capsLock; /* XOR operation */
            if (maysuc) {
                result = shiftedKbdTable[code];
            } else {
                result = kbdTable[code];
            }
            break;
        }
        case SYMBOL: {
            if (shift) {
                result = shiftedKbdTable[code];
            } else {
                result = kbdTable[code];
            }
            break;
        }
    }
    return result;
}


uint16_t getNoteFromKbd() {

    uint8_t code = dequeueKey();
	uint16_t note = -1;
	if (code == -1) {
		return -1;
	}
    
    if (code > 128) {
        return 0; /* A break code represents a stop sound event */
    }
    note = notesTable[code];

    if (note == 27) {
        return 1; /* There's no note defined for value 1, so we use to represent an exit event */
    }
    return note;
}









