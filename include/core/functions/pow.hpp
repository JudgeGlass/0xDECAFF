#ifndef __POW_HPP__
#define __POW_HPP__

#include "functionsimp.hpp"

class Pow : public FunctionsImp{
    public:
        double calc(std::vector<double> &args) override{
            return pow(args.at(1), args.at(0));
        }

        int getArgCount() override{
            return 2;
        }
};

#endif