#ifndef __CALCULATOR_HPP__
#define __CALCULATOR_HPP__

#include <graph.hpp>
#include <screen.hpp>

enum State{
    CALCULATION,
    GRAPH,
    TABLE,
    FUNCTION
};

enum ProcessorState{
    CALCULATING,
    INTURRUPT,
    READY
};

class Calculator{
    public:
        Calculator();
        ~Calculator();

        void update();
    private:
        Screen *screen = nullptr;
        Graph *graph = nullptr;
        
        State currentState;
        ProcessorState currentProcessorState;

};

#endif