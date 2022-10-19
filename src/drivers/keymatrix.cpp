#include <drivers/keymatrix.h>


void pico_keypad_init() {
    for(int x = 0; x < ROW_COUNT; x++){
        gpio_init(rows[x]);
        gpio_set_dir(rows[x], GPIO_OUT);
        gpio_put(rows[x], 1);
    }

    for(int x = 0; x < COL_COUNT; x++){
        gpio_init(cols[x]);
        gpio_set_dir(cols[x], GPIO_IN);
        gpio_pull_up(cols[x]);
    }
    
}

char pico_keypad_get_key(Screen *s) {
    for(int r = 0; r < ROW_COUNT; ++r){
        gpio_put(rows[r], 0);
        uint8_t colStat[5];

        colStat[0] = gpio_get(cols[0]);
        colStat[1] = gpio_get(cols[1]);
        colStat[2] = gpio_get(cols[2]);
        colStat[3] = gpio_get(cols[3]);
        colStat[4] = gpio_get(cols[4]);

        if((colStat[0] + colStat[1] + colStat[2] + colStat[3] + colStat[4]) != 5){
            int i;
            for(i = 0; i < 5; i++){
                if(!colStat[i]){
                    break;
                }
            }
            char key;

            s->drawString(5, 15, "R: " + std::to_string(r) + "   C: " + std::to_string(i), true);
            s->renderFrameBuffer(false);

            if(i == 0){
                key = matrix[r-1][i];
            }else{
                key = matrix[r][i];
            }

            //currentKey = key; 
            gpio_put(rows[i], 1);
            return key;
        }

        gpio_put(rows[r], 1);
    }
    sleep_ms(30);

    //currentKey = '\0';
    return '\0';
}