#ifndef __CALCWINDOW_HPP__
#define __CALCWINDOW_HPP__

#include "pico/stdlib.h"

#include <algorithm>

class CalcWindow{
    public:
        CalcWindow();
        void drawBuffer();
        void moveCursor(const int x, const int y);
    private:
        int cursorX;
        int cursorY;
        char characterBuffer[40 * 30]; // 40 8x8 characters wide by 30 
};


#endif