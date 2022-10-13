#include <cstdlib>
#include <cmath>
#include "pico/stdlib.h"

#include <calculator.hpp>
#include <drivers/keymatrix.h>

#define LED 25

char matrix[16] = {
  '1', '2', '3', '+',
  '4', '5', '6', '-',
  '7', '8', '9', '^',
  '*', '0', '/', 'E'
};

int main(){
  gpio_init(LED);
  gpio_set_dir(LED, GPIO_OUT);

  Calculator calc;

  pico_keypad_init(cols, rows, matrix);

  while(true){
    //keymatrix_read_keys();
    gpio_put(LED, 1);
    sleep_ms(300);
    gpio_put(LED, 0);
    sleep_ms(300);

    calc.update();
  }

  return 0;
}