#ifndef __SHUNTINGYARD_HPP__
#define __SHUNTINGYARD_HPP__

#include <string>
#include <algorithm>
#include <stack>

#include <screen.hpp>
#include <core/tokenizer.hpp>

class ShuntingYard{
    public:
        ShuntingYard(std::string &expression);
        ~ShuntingYard();

        std::string toRPN(Screen *screen);

        int getPrecedence(const char &c);

        bool isNum(std::string &s);

    private:
        std::string expression;

        Tokenizer *tokenizer;
};

#endif