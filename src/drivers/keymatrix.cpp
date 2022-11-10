#include <drivers/keymatrix.h>


void pico_keypad_init() {
    for(int r = 0; r < ROW_COUNT; r++){
        gpio_init(rows[r]);
        gpio_set_dir(rows[r], GPIO_IN);
        //gpio_put(rows[x], 1);
        gpio_pull_down(rows[r]);
    }

    for(int x = 0; x < COL_COUNT; x++){
        gpio_init(cols[x]);
        gpio_set_dir(cols[x], GPIO_OUT);
        gpio_put(cols[x], 1);
    }
    
}

char pico_keypad_get_key(Screen *s) {
    for(int c = 0; c < COL_COUNT; c++){
        asm volatile("nop \n nop \n nop");
        gpio_put(cols[c], 1);
        asm volatile("nop \n nop \n nop");
        uint8_t rowStat[7];

        rowStat[0] = gpio_get(rows[0]);
        rowStat[1] = gpio_get(rows[1]);
        rowStat[2] = gpio_get(rows[2]);
        rowStat[3] = gpio_get(rows[3]);
        rowStat[4] = gpio_get(rows[4]);
        rowStat[5] = gpio_get(rows[5]);
        rowStat[6] = gpio_get(rows[6]);

        std::string cols_s;
        cols_s.append("C: " + std::to_string(c));
        for(int i = 0; i < 7; i++){
            cols_s.append(std::to_string(rowStat[i]) + " ");
        }

        

        if(rowStat[0] + rowStat[1] + rowStat[2] + rowStat[3] + rowStat[4] + rowStat[5] + rowStat[6] != 0){
            int i;
            for(i = 0; i < 7; i++){
                if(rowStat[i]){
                    break;
                }
            }

            s->drawString(5, 15, "R: " + std::to_string(i) + "   C: " + std::to_string(c), true);
            s->drawString(5, 30, cols_s, true);
            s->renderFrameBuffer(false);

            asm volatile("nop \n nop \n nop");
            gpio_put(cols[c], 0);
            asm volatile("nop \n nop \n nop");

            return matrix[i][c];
        }

        asm volatile("nop \n nop \n nop");
        gpio_put(cols[c], 0);
        asm volatile("nop \n nop \n nop");

    }
    return '\0';
}