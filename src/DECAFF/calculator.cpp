#include <calculator.hpp>


Calculator::Calculator(){
    screen = new Screen();
    graph = new Graph(screen, -10, 10, -10, 10, 320, 240);
    calcWindow = new CalcWindow();

    currentState = State::CALCULATION;

    std::string func = "2+sqrt(x-2)";

    graph->setF1(func);

    screen->drawString(5, 5, "Please Wait...", false);
    screen->renderFrameBuffer();

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
    
    switch(currentState){
        case State::CALCULATION:
            calcWindow->update(screen);
            //ili9341_plot_pixel(40, 14, (uint16_t)0xf800);
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
    char key = pico_keypad_get_key();

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
    delete calcWindow;
}