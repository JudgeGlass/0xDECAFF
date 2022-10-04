#include <calculator.hpp>


Calculator::Calculator(){
    screen = new Screen();
    graph = new Graph(screen, -10, 10, -10, 10, 320, 240);

    currentState = State::GRAPH;

    // graph->drawFunc();
    // graph->render();

    // TEMP JUST FOR TESTING

    std::string func = "8*(sin(x))^2-6x+8^x";
    tokenizer = new Tokenizer(func);

    screen->drawString(5, 5, "Exp: " + func, false);
    std::vector<std::string> tokens = tokenizer->getTokens();

    std::string strTokens;
    for(const auto& t: tokens){
        strTokens += t;
    }

    screen->drawString(5, 20, "Tokens:\n " + strTokens, false);

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
    delete tokenizer;           // DELETE ME!!!
    delete screen;
    delete graph;
}