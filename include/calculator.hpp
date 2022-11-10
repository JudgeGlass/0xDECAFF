#ifndef __CALCULATOR_HPP__
#define __CALCULATOR_HPP__

#include <drivers/keymatrix.h>

#include <graph.hpp>
#include <screen.hpp>
#include <calcwindow.hpp>
#include <core/shuntingyard.hpp>

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

        void calculator();
        void update();
    private:
        Screen *screen = nullptr;
        Graph *graph = nullptr;
        CalcWindow *calcWindow = nullptr;
        std::string keyBuff;
        
        State currentState;
        ProcessorState currentProcessorState;

        ShuntingYard *sy;

};

#endif