#ifndef __SQRT_HPP__
#define __SQRT_HPP__

#include "functionsimp.hpp"

class Sqrt : public FunctionsImp{
    public:
        double calc(std::vector<double> &args) override{
            return sqrt(args.at(0));
        }

        int getArgCount() override{
            return 1;
        }
};

#endif