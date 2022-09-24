#include "screen.h"

#include "font.h"

Screen::Screen(){
    ili9341_init_SPI();
    ili9341_init_display();
    ili9341_init_drawing();

    clearBuffer();
}

void Screen::drawPixel(uint16_t color, uint16_t x, uint16_t y){
    if (x >= 320 || y >= 240)
        return;
    uint16_t * pix = &_fbuff[(320-x-1)*240+y];
    (*pix) = (uint16_t) color;
}

void Screen::drawBitmap(uint16_t x, uint16_t y, uint8_t* bitArray, uint16_t w, uint16_t h){
    for(uint16_t xx = x; xx < x + w; xx++){
        for(uint16_t yy = y; yy < y + h; yy++){
            uint16_t bitX = (xx - x);
            uint16_t bitY = (yy - y);

            if(bitArray[bitX + bitY * w] == 0){
                continue;
            }

            drawPixel(Color::GREEN, xx, yy);
        }
    }
}

void Screen::drawString(uint16_t x, uint16_t y, std::string &text, bool inverse){
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);
    int xOffset = 0;
    for(int i = 0; i < text.length(); i++){
        
        if(text[i] == '\n'){
            y += 8;
            xOffset = i * 8;
        }

        int index = chars.find((char)text[i]);

        int sx = (index % 32);
        int sy = (index / 32);

        if(index >= 0){
            for(int j = 0; j < 8; j++){
                if(inverse){
                    drawByteToBuffer(~fontArray[sx + (sy * 8 + j) * 32], x + (i * 8) - xOffset, y + j);
                }else{
                    drawByteToBuffer(fontArray[sx + (sy * 8 + j) * 32], x + (i * 8) - xOffset, y + j);
                }
            }
        }
    }
}

void Screen::drawByteToBuffer(uint8_t d, uint16_t x, uint8_t y){
    for(int i = 0; i < 8; i++){
        uint8_t bit = (d << i) & 0b10000000;
        if(bit){
            drawPixel(Color::GREEN, x + i, y);
        }else{
            drawPixel(Color::BLACK, x + i, y);
        }
    }
}

void Screen::renderFrameBuffer(){
    ili9341_write_buffer((uint8_t *)_fbuff, sizeof(_fbuff));
    
    clearBuffer();
}

void Screen::clearBuffer(){
    for(int i = 0; i < 320 * 240; i++){
        _fbuff[i] = 0;
    }
}

void Screen::drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h){
    drawRect(x, y, w, h, false);
}

void Screen::drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, bool setFilled){
    for(uint16_t xx = x; xx < x + w; xx++){
        for(uint16_t yy = y; yy < y + h; yy++){
            if(!setFilled){
                if(xx == x || xx == x + w - 1 || yy == y || yy == y + h - 1){
                    drawPixel(Color::GREEN, xx, yy);
                    continue;
                }

                drawPixel(Color::BLACK, xx, yy);
            }else{
                drawPixel(Color::GREEN, xx, yy);
            }

            
        }
    }
}