#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <screen.hpp>
#include <graph.hpp>

enum State{
    CALCULATION,
    GRAPH,
    TABLE,
    FUNCTION
};

enum ProcessorState{
    CALCULATING,
    INTURRUPT
};

class Calculator{
    public:
        Calculator();
        ~Calculator();
    private:
        Graph *graph;
        Screen *screen;

};

#endif