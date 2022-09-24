#include <cstdlib>
#include <cmath>
#include "pico/stdlib.h"

#include "screen.h"
#include "font.h"
#include "graph.h"

#define LED 25

int main(){
  gpio_init(LED);
  gpio_set_dir(LED, GPIO_OUT);

  Screen s;
  Graph g(&s, -10, 10, -10, 10, 320, 240);
  // s.drawRect(5, 5, 16, 16, true);
  // s.drawRect(25, 5, 16, 16, true);
  // s.drawRect(35, 35, 2, 2, true);
  //s.drawBitmap(30, 30, letterA(), 8, 8);
  std::string ss = "f1(x)= 3*sin(x)";
  g.drawFunc();
  s.drawString(5, 5, ss, false);
  //s.renderFrameBuffer();
  g.render();

  


  while(true){
    gpio_put(LED, 1);
    sleep_ms(300);
    gpio_put(LED, 0);
    sleep_ms(300);
    



  }

  return 0;
}