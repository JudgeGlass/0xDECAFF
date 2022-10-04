#include <cstdlib>
#include <cmath>
#include "pico/stdlib.h"

#include <calculator.hpp>

#define LED 25

int main(){
  gpio_init(LED);
  gpio_set_dir(LED, GPIO_OUT);

  Calculator calc;

  while(true){
    gpio_put(LED, 1);
    sleep_ms(300);
    gpio_put(LED, 0);
    sleep_ms(300);

    calc.update();
  }

  return 0;
}