#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "functionsimp.hpp"

class Div : public FunctionsImp{
    public:
        double calc(std::vector<double> &args) override{
            return args.at(1) / args.at(0);
        }

        int getArgCount() override{
            return 2;
        }
};

#endif