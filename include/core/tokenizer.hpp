
#ifndef __TOKENIZER_HPP__
#define __TOKENIZER_HPP__

#include <string>
#include <vector>

class Tokenizer{
    public:
        Tokenizer(std::string &expression);

        void setExpression(std::string &expression);
        void replaceMinus();       
        std::vector<std::string> getTokens();
        bool isDelim(const char &c);
    private:
        std::string expression;
        std::string delims = "+-/*()^,&|";

};


#endif