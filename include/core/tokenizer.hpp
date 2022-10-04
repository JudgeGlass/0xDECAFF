#ifndef __TOKENIZER_HPP__
#define __TOKENIZER_HPP__

#include <string>
#include <vector>

class Tokenizer{
    public:
        Tokenizer(std::string &expression);

        
        std::vector<std::string> getTokens();
    private:
        bool isDelim(const char &c);

        std::string expression;
        std::string delims = "+-/*()^,";

};


#endif