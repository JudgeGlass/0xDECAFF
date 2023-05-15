#include "calcwindow.hpp"
#include <stdio.h>

CalcWindow::CalcWindow(){
    std::fill(characterBuffer, characterBuffer + 40 * 30, '\0');
    cursorX = -1;
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
    drawBuffer(screen);
    if(characterBuffer[(cursorX + 1) + cursorY * 40] != 0){
        screen->drawHLine((cursorX+1) * 8, (cursorX+1) * 8 + 8, cursorY*8+8, 2);
    }else{
        screen->drawRect((cursorX+1) * 8, cursorY * 8, 8, 8, true);
    }

    //char key = getKey();
    char key = getchar();

    if(key == 0x1b){
        special_key_t key = escapeSequence();
        if(key == UP){
            cursorY--;
        }else if(key == DOWN){
            cursorY++;
        }else if(key == LEFT){
            cursorX--;
        }else if(key == RIGHT){
            cursorX++;
        }

        return;
    }

    if(key != 0xD || key != 0x7F)
        printf("%c", key);
    else if(key == 0xD)
        printf("\n");

    if(key == 0x7F){ // Backspace
        characterBuffer[cursorX + cursorY * 40] = 0;
        cursorX--;
        return;
    }

    //printf("Cursor X: %d", cursorX);

    if(key == 0xD){ // New line
        std::string func = "";
        for(int i = 0; i < cursorX + 1; i++){
            if(characterBuffer[i + cursorY * 40] == 0) continue;
            func += (characterBuffer[i + cursorY * 40]);
        }
        if(!func.empty()){
            ShuntingYard sy(func);
            std::string ans = std::to_string(sy.eval());
            

            cursorY++;
            for(int i = 0; i< ans.length(); i++){
                characterBuffer[(40 - (ans.length() - i)) + cursorY * 40] = ans.at(i);
            }
        }
        cursorX = 0;
        cursorY++;
        return;
    }

    cursorX++;
    if(cursorX > 40){
        cursorX = 0;
        cursorY++;
    }

    setChar(key);
}

void CalcWindow::moveCursor(const int x, const int y){
    cursorX = x;
    cursorY = y;
}