#include <cstdlib>
#include "pico/stdlib.h"
#include "screen.h"
#include "font.h"

#define LED 25

int main(){
  gpio_init(LED);
  gpio_set_dir(LED, GPIO_OUT);

  Screen s;
  // s.drawRect(5, 5, 16, 16, true);
  // s.drawRect(25, 5, 16, 16, true);
  // s.drawRect(35, 35, 2, 2, true);
  //s.drawBitmap(30, 30, letterA(), 8, 8);
  std::string ss = "Hello there!\nHow are you doing?\nDo you feel fine?\nQuick! Run!";
  
  //s.drawString(5, 70, ss, true);
  s.drawByteToBuffer(0b11001100, 100, 100, false);
  s.renderFrameBuffer();

  


  while(true){
    gpio_put(LED, 1);
    s.drawString(5, 60, ss, true);
    s.renderFrameBuffer();
    sleep_ms(300);
    gpio_put(LED, 0);
    s.drawString(5, 60, ss, false);
    s.renderFrameBuffer();
    sleep_ms(300);
    



  }

  return 0;
}