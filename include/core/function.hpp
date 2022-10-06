#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include <map>
#include <string>
#include <vector>
#include <cmath>

#include "functions/functionsimp.hpp"

#include "functions/sqrt.hpp"
#include "functions/max.hpp"
#include "functions/sin.hpp"
#include "functions/cbrt.hpp"

#include "functions/add.hpp"
#include "functions/minus.hpp"
#include "functions/mul.hpp"
#include "functions/div.hpp"
#include "functions/pow.hpp"

class Function{
    public:
        Function();

        double calc(std::string &func, std::vector<double> &args);
        int getArgCount(std::string &func);
        bool hasFunction(std::string &func);

    private:
        std::map<std::string, FunctionsImp*> functionList;

        

};


#endif