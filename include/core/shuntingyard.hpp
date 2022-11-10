#ifndef __SHUNTINGYARD_HPP__
#define __SHUNTINGYARD_HPP__

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

#include "tokenizer.hpp"
#include "function.hpp"

class ShuntingYard{
    public:
        ShuntingYard(std::string &expression);
        ~ShuntingYard();

        std::vector<std::string> toRPN();
        double eval();
        double eval(double x);
        double r_eval(std::vector<std::string> rpnExpression);

        int getPrecedence(const char &c);
        
        bool getAssociativity(const char &c);
        bool isNum(std::string &s);
        bool isOp(std::string &token);

    private:
        std::string expression;
        std::vector<std::string> rpnTokens;

        double x;

        Function *functionStore;
        Tokenizer *tokenizer;
};

#endif