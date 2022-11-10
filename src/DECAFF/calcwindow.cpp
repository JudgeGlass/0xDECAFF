#include "calcwindow.hpp"

CalcWindow::CalcWindow(){
    std::fill(characterBuffer, characterBuffer + 40 * 30, '\0');
    cursorX = 0;
    cursorY = 0;
}

void CalcWindow::drawBuffer(Screen *screen){
    for(int x = 0; x < 40; x++){
        for(int y = 0; y < 30; y++){
            char currentChar = characterBuffer[x + y * 40];
            if(!currentChar) continue;
            std::string s(1, currentChar);
            screen->drawString(x * 8, y * 8, s, false);
        }
    }

    screen->renderFrameBuffer(true);
}

void CalcWindow::setChar(const char c){
    characterBuffer[cursorX + cursorY * 40] = c;
}

void CalcWindow::update(Screen *screen){
    screen->drawRect((cursorX + 1) * 8, cursorY * 8, 8, 8, true);
    drawBuffer(screen);
    

    char key = getKey();

    if(key == 'B'){
        characterBuffer[cursorX + cursorY * 40] = 0;
        cursorX--;
        return;
    }

    if(key == '\n'){
        std::string func = "";
        for(int i = 1; i < cursorX + 1; i++){
            func += (characterBuffer[i + cursorY * 40]);
        }
        ShuntingYard sy(func);
        std::string ans = std::to_string(sy.eval());
        

        cursorY++;
        for(int i = 0; i< ans.length(); i++){
            characterBuffer[(40 - (ans.length() - i)) + cursorY * 40] = ans.at(i);
        }
        cursorX = 0;
        cursorY++;
        return;
    }

    if(++cursorX > 40){
        cursorX = 0;
        cursorY++;
    }

    setChar(key);
}

void CalcWindow::moveCursor(const int x, const int y){
    cursorX = x;
    cursorY = y;
}