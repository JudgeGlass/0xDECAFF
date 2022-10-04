#include <calculator.hpp>


Calculator::Calculator(){
    screen = new Screen();
    graph = new Graph(screen, -10, 10, -10, 10, 320, 240);

    currentState = State::GRAPH;

    // graph->drawFunc();
    // graph->render();

    // TEMP JUST FOR TESTING

    std::string func = "3+(5-8)*5";
    sy = new ShuntingYard(func);

    screen->drawString(5, 5, "OUT:\n" + sy->toRPN(screen), false);

    screen->renderFrameBuffer();
    // END TEMP
}

void Calculator::update(){
    switch(currentState){
        case State::CALCULATION:

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

Calculator::~Calculator(){
    delete sy;           // DELETE ME!!!
    delete screen;
    delete graph;
}