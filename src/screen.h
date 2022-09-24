#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <string>

#include "pico/stdlib.h"
#include "ili9341.h"
#include "font.h"

static std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ      0123456789.,!?'\"-+=/\\%()<>:;_     " ;

enum Color{
    GREEN = 0b00011110,
    BLACK = 0b00000000
};

class Screen{
    public:
        Screen();
        
        void drawPixel(uint16_t color, uint16_t x, uint16_t y);
        void drawBitmap(uint16_t x, uint16_t y, uint8_t* bitArray, uint16_t w, uint16_t h);

        void drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
        void drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, bool setFilled);
        void drawString(uint16_t x, uint16_t y, std::string &text, bool inverse);
        void drawByteToBuffer(uint8_t d, uint16_t x, uint8_t y);

        void renderFrameBuffer();
        void clearBuffer();

    private:
        uint16_t _fbuff[240 * 320];

};


#endif