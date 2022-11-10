#ifndef __RIGHTSHIFT_HPP__
#define __RIGHTSHIFT_HPP__

#include "functionsimp.hpp"

class RightShift : public FunctionsImp{
    public:
        double calc(std::vector<double> &args) override{
            return (int) args.at(1) >> (int)args.at(0);
        }

        int getArgCount() override{
            return 2;
        }
};


#endif