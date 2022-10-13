#ifndef __KEYMATRIX_H__
#define __KEYMATRIX_H__

#include "pico/stdlib.h"
#include "hardware/timer.h"

#define ROW_COUNT 7
#define COL_COUNT 5

static uint cols[4] = {0, 1, 2, 3};
static uint rows[4] = {5, 6, 7, 8};

void pico_keypad_init(uint columns[4], uint rows[4], char matrix_values[16]);

char pico_keypad_get_key(void);

void pico_keypad_irq_enable(bool enable, gpio_irq_callback_t callback);
#endif