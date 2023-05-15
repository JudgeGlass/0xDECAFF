#ifndef __CALCWINDOW_HPP__
#define __CALCWINDOW_HPP__

#include "pico/stdlib.h"

#include <algorithm>
#include <screen.hpp>
#include <drivers/keymatrix.h>
#include <drivers/serialkeyboard.hpp>
#include <core/shuntingyard.hpp>

class CalcWindow{
    public:
        CalcWindow();
        
        void moveCursor(const int x, const int y);
        void setChar(const char c);
        void update(Screen *screen);
    private:
        void drawBuffer(Screen *screen);
        int cursorX;
        int cursorY;
        char characterBuffer[40 * 30]; // 40 8x8 characters wide by 30 
};


#endif