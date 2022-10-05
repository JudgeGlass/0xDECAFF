#include <calculator.hpp>


Calculator::Calculator(){
    screen = new Screen();
    graph = new Graph(screen, -10, 10, -10, 10, 320, 240);

    currentState = State::GRAPH;

    // graph->drawFunc();
    // graph->render();

    // TEMP JUST FOR TESTING

    std::string func = "3+4*2/(1-5)^2^3";
    sy = new ShuntingYard(func);

    screen->drawString(5, 5, "Infix: " + func, false);
    screen->drawString(5, 16,"  RPN: " + sy->toRPN(), false);

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