#ifndef __FUNCTIONSIMP_HPP__
#define __FUNCTIONSIMP_HPP__

#include <cmath>
#include <vector>

class FunctionsImp{
    public:
        //virtual ~FunctionsImp();
        virtual double calc(std::vector<double> &args) = 0;
        virtual int getArgCount() = 0;
};

#endif