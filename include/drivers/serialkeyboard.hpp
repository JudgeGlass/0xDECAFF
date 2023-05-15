#ifndef __SERIAL_KEYBOARD__
#define __SERIAL_KEYBOARD__

#include <stdio.h>

typedef enum SPECIAL_KEYS{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    INSERT,
    HOME,
    END,
    DEL,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    ESCAPE
} special_key_t;

special_key_t escapeSequence();

#endif