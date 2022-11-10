#ifndef __ABS_HPP__
#define __ABS_HPP__

#include "functionsimp.hpp"

class Abs : public FunctionsImp{
    public:
        double calc(std::vector<double> &args) override{
            return fabs(args.at(0));
        }

        int getArgCount() override{
            return 1;
        }
};

#endif