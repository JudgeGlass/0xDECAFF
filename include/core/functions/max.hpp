#ifndef __MAX_HPP__
#define __MAX_HPP__

#include "functionsimp.hpp"

class Max : public FunctionsImp{
    public:
        double calc(std::vector<double> &args) override{
            if(args.at(1) > args.at(0)) return args.at(1);
            return args.at(0);
        }

        int getArgCount() override{
            return 2;
        }
};


#endif