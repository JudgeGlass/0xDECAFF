#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "functionsimp.hpp"

class Add : public FunctionsImp{
    public:
        double calc(std::vector<double> &args) override{
            return args.at(0) + args.at(1);
        }

        int getArgCount() override{
            return 2;
        }
};

#endif