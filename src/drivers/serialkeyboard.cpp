#include <drivers/serialkeyboard.hpp>


special_key_t escapeSequence(){
    // 0x5B
    if(getchar() == 0x5b){
        char curr = getchar();
        switch (curr)
        {
        case 0x41:
            return UP;
        case 0x42:
            return DOWN;
        case 0x43:
            return RIGHT;
        case 0x44:
            return LEFT;
        default:
            break;
        }
    }

    return ESCAPE;
}