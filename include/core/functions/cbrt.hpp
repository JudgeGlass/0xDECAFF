#ifndef __CBRT_HPP__
#define __CBRT_HPP__

#include "functionsimp.hpp"

class Cbrt : public FunctionsImp{
    public:
        double calc(std::vector<double> &args) override{
            return cbrt(args.at(0));
        }

        int getArgCount() override{
            return 1;
        }
};

#endif