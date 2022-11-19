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

char pico_keypad_get_key() {
    if(cool > 0){
        cool--;
        return '\0';
    }
    for(int c = 0; c < COL_COUNT; c++){
        sleep_ms(7);
        gpio_put(cols[c], 1);
        sleep_ms(7);
        uint8_t rowStat[7];

        rowStat[0] = gpio_get(rows[0]);
        rowStat[1] = gpio_get(rows[1]);
        rowStat[2] = gpio_get(rows[2]);
        rowStat[3] = gpio_get(rows[3]);
        rowStat[4] = gpio_get(rows[4]);
        rowStat[5] = gpio_get(rows[5]);
        rowStat[6] = gpio_get(rows[6]);        

        if(rowStat[0] + rowStat[1] + rowStat[2] + rowStat[3] + rowStat[4] + rowStat[5] + rowStat[6] != 0){
            int i;
            for(i = 0; i < 7; i++){
                if(rowStat[i]){
                    break;
                }
            }

            sleep_ms(7);
            gpio_put(cols[c], 0);
            sleep_ms(7);
            cool = 1000;
            return matrix[i][c];
        }

        sleep_ms(7);
        gpio_put(cols[c], 0);
        sleep_ms(7);

    }
    cool = 1000;
    return '\0';
}

char getKey(){
    sleep_ms(65);
    char key;
    while((key = pico_keypad_get_key()) == 0);
    return key;
}