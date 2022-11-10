#ifndef __LOGICAND_HPP__
#define __LOGICAND_HPP__

#include "functionsimp.hpp"

class LogicAND : public FunctionsImp{
    public:
        double calc(std::vector<double> &args) override{
            return (int) args.at(0) & (int)args.at(1);
        }

        int getArgCount() override{
            return 2;
        }
};


#endif