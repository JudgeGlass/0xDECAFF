#include <calculator.hpp>


Calculator::Calculator(){
    screen = new Screen();
    graph = new Graph(screen, -10, 10, -10, 10, 320, 240);

    currentState = State::GRAPH;

    graph->drawFunc();
    graph->render();
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
    delete screen;
    delete graph;
}