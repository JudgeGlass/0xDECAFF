#ifndef __COS_HPP__
#define __COS_HPP__

#include "functionsimp.hpp"

class Cos : public FunctionsImp {
    public:
        double calc(std::vector<double> &args) override{
            return cos(args.at(0));
        }

        int getArgCount() override{
            return 1;
        }
    
};


#endif