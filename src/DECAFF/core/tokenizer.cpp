#include <core/tokenizer.hpp>

Tokenizer::Tokenizer(std::string &expression){
    this->expression = expression;
}

std::vector<std::string> Tokenizer::getTokens(){
    std::vector<std::string> tokens;
    std::vector<int> delimsIndex;

    int lastFound = 0;
    for(uint16_t index = 0; index < expression.size(); index++){
        char currentChar = expression.at(index);
        if(isDelim(currentChar)){
            tokens.push_back(expression.substr(lastFound, index - lastFound));
            //delimsIndex.push_back(index);
            std::string str(1, currentChar);
            tokens.push_back(str);
            lastFound = index + 1;
        }
    }

    tokens.push_back(expression.substr(lastFound, expression.size() - 1));

    return tokens;
}

bool Tokenizer::isDelim(const char &c){
    for(const auto &d: delims){
        if(d == c){
            return true;
        }
    }

    return false;
}