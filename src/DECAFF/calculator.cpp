#include <calculator.hpp>


Calculator::Calculator(){
    screen = new Screen();
    graph = new Graph(screen, -10, 10, -10, 10, 320, 240);

    currentState = State::GRAPH;

    std::string func = "3*sin(x)-2";

    graph->setF1(func);

    graph->drawFunc();
    // ShuntingYard sy(func);
    // for(double x = 0; x < 5; x+=0.5){
    //     double y = sy.eval(x);
    //     screen->drawString(5, 5, "X: " + std::to_string(x) + "  Y: " + std::to_string(y), false);
    //     screen->renderFrameBuffer();
    // }



    graph->render();

}



void Calculator::update(){
    char key;
    while((key = pico_keypad_get_key(screen)) == 0);
    screen->drawString(5, 5, std::string(1, key), false);
    // for(int x = 0; x < 40; x++){
    //     for(int y = 0; y < 30; y++){
    //         screen->drawString(x * 8, y * 8, "A", false);
    //     }
    // }

    screen->renderFrameBuffer(false);

    switch(currentState){
        case State::CALCULATION:
            calculator();
            break;
        
        case State::FUNCTION:

            break;

        case State::GRAPH:
            graph->update();
            break;

        case State::TABLE:

            break;

    }
}

void Calculator::calculator(){
    char key = pico_keypad_get_key(screen);

    if(key == 'E'){
        ShuntingYard sy(keyBuff);

    }

    if(key){
        keyBuff += key;
    }
}

Calculator::~Calculator(){
    delete sy;           // DELETE ME!!!
    delete screen;
    delete graph;
}