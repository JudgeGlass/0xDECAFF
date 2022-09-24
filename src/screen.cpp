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

void Screen::drawString(uint16_t x, uint16_t y, std::string text, bool inverse){
    //std::transform(text.begin(), text.end(), text.begin(), ::toupper);
    int xOffset = 0;
    for(int i = 0; i < text.length(); i++){
        if(text[i] == '\n'){
            y += 8;
            xOffset = i * 8 + 8;
        }

        int index = chars.find((char)text[i]);

        int sx = (index % 32);
        int sy = (index / 32);

        if(index >= 0){
            for(int j = 0; j < 8; j++){
                drawByteToBuffer(fontArray[sx + (sy * 8 + j) * 32], x + (i * 8) - xOffset, y + j, inverse);
            }
        }
    }
}

void Screen::drawByteToBuffer(uint8_t d, uint16_t x, uint8_t y, bool inverse){
    if(inverse) d = ~d;
    for(int i = 0; i < 8; i++){
        uint8_t bit = (d << i) & 0b10000000;
        drawPixel((bit) ? Color::GREEN : Color::BLACK, x + i, y);
    }
}

void Screen::renderFrameBuffer(){
    renderFrameBuffer(true);
}

void Screen::renderFrameBuffer(bool clear){
    ili9341_write_buffer((uint8_t *)_fbuff, sizeof(_fbuff));
    
    if(clear){
        clearBuffer();
    }
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

/*
    Bresenham's line algorithm
    https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
*/
void Screen::drawLine(int x1, int y1, int x2, int y2){
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int error = dx + dy;

    while(true){
        drawPixel(Color::YELLOW, x1, y1);
        if(x1 == x2 && y1 == y2) break;
        int e2 = 2 * error;
        if(e2 >= dy){
            if(x1 == x2) break;
            error += dy;
            x1 += sx;
        }

        if(e2 <= dx){
            if(y1 == y2) break;
            error += dx;
            y1 += sy;
        }
    }
}

void Screen::drawHLine(uint16_t sx, uint16_t ex, uint16_t y, uint8_t thickness){
    for(uint8_t i = 0; i < thickness; i++){
        for(uint16_t xx = sx; xx < ex; xx++){
            drawPixel(Color::GREEN, xx, y + i);
        }
    }
}

void Screen::drawVLine(uint16_t sy, uint16_t ey, uint16_t x, uint8_t thickness){
    for(uint8_t i = 0; i < thickness; i++){
        for(uint16_t yy = sy; yy < ey; yy++){
            drawPixel(Color::GREEN, x + i, yy + i);
        }
    }
}