#include "calcwindow.hpp"

CalcWindow::CalcWindow(){
    std::fill(characterBuffer, characterBuffer + 40 * 30, ' ');
}

void CalcWindow::drawBuffer(){
    for(int x = 0; x < 40; x++){
        for(int y = 0; y < 30; y++){
            char currentChar = characterBuffer[x + y * 40];
            if(!currentChar) continue;


        }
    }
}

void CalcWindow::moveCursor(const int x, const int y){
    cursorX = x;
    cursorY = y;
}