#ifndef __SIN_HPP__
#define __SIN_HPP__

#include "functionsimp.hpp"

class Sin : public FunctionsImp{
    public:
        double calc(std::vector<double> &args) override{
            return sin(args.at(0));
        }

        int getArgCount() override{
            return 1;
        }
};

#endif