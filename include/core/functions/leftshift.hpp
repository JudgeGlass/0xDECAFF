#ifndef __LEFTSHIFT_HPP__
#define __LEFTSHIFT_HPP__

#include "functionsimp.hpp"

class LeftShift : public FunctionsImp{
    public:
        double calc(std::vector<double> &args) override{
            return (int) args.at(1) << (int)args.at(0);
        }

        int getArgCount() override{
            return 2;
        }
};


#endif