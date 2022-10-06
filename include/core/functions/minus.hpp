#ifndef __MINUS_HPP__
#define __MINUS_HPP__

#include "functionsimp.hpp"

class Minus : public FunctionsImp{
    public:
        double calc(std::vector<double> &args) override{
            return args.at(1) - args.at(0);
        }

        int getArgCount() override{
            return 2;
        }
};

#endif