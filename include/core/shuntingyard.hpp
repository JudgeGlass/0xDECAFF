#ifndef __SHUNTINGYARD_HPP__
#define __SHUNTINGYARD_HPP__

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

#include <core/tokenizer.hpp>

class ShuntingYard{
    public:
        ShuntingYard(std::string &expression);
        ~ShuntingYard();

        std::string toRPN();

        int getPrecedence(const char &c);
        
        bool getAssociativity(const char &c);
        bool isNum(std::string &s);

    private:
        std::string expression;

        Tokenizer *tokenizer;
};

#endif