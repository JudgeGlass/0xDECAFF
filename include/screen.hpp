#ifndef __SCREEN_HPP__
#define __SCREEN_HPP__

#include <string>
#include <algorithm>

#include "pico/stdlib.h"
#include <drivers/ili9341.h>
#include <font.hpp>

static std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ|*^   0123456789.,!?'\"-+=/\\%()<>:;_   abcdefghijklmnopqrstuvwxyz█     " ;

enum Color{
    GREEN = 0b00011110,
    BLACK = 0b00000000,
    YELLOW = 0b11111111
};

class Screen{
    public:
        Screen();
        
        void drawPixel(uint16_t color, uint16_t x, uint16_t y);
        void drawPixelRAM(uint16_t color, uint16_t x, uint16_t y);
        void drawBitmap(uint16_t x, uint16_t y, uint8_t* bitArray, uint16_t w, uint16_t h);

        void drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
        void drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, bool setFilled);
        void drawHLine(uint16_t sx, uint16_t ex, uint16_t y, uint8_t thickness);
        void drawVLine(uint16_t sy, uint16_t ey, uint16_t x, uint8_t thickness);
        void drawLine(int x1, int y1, int x2, int y2);
        void drawString(uint16_t x, uint16_t y, std::string text, bool inverse);
        void drawByteToBuffer(uint8_t d, uint16_t x, uint8_t y, bool inverse);

        void renderFrameBuffer();
        void renderFrameBuffer(bool clear);
        void clearBuffer();

    private:
        uint16_t _fbuff[240 * 320];

};


#endif