#include <cstdlib>
#include <cmath>
#include "pico/stdlib.h"

#include <graph.hpp>
#include <screen.hpp>

#define LED 25

int main(){
  gpio_init(LED);
  gpio_set_dir(LED, GPIO_OUT);

  Screen s;
  Graph g(&s, -10, 10, -10, 10, 320, 240);
  std::string ss = "f1(x)= 3*cos(x)";
  g.drawFunc();

  s.drawString(5, 5, ss, false);
  
  g.render();

  while(true){
    gpio_put(LED, 1);
    sleep_ms(300);
    gpio_put(LED, 0);
    sleep_ms(300);
  }

  return 0;
}