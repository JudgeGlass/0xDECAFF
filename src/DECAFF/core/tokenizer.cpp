#include <core/tokenizer.hpp>

Tokenizer::Tokenizer(std::string &expression){
    this->expression = expression;
}

std::vector<std::string> Tokenizer::getTokens(){
    std::vector<std::string> tokens;

    replaceMinus();

    int lastFound = 0;
    for(uint16_t index = 0; index < expression.size(); index++){
        char currentChar = expression.at(index);
        if(isDelim(currentChar)){
            std::string t = expression.substr(lastFound, index - lastFound);
            if(t.size() != 0 || !t.empty()){
                tokens.push_back(t);
            }
            
            std::string str(1, currentChar);
            tokens.push_back(str);
            lastFound = index + 1;
        }
    }

    if(!expression.substr(lastFound, expression.size() - 1).empty()){
        tokens.push_back(expression.substr(lastFound, expression.size() - 1));
    }

    for(auto& t: tokens){
        if(t.at(0) == '_'){
            t.at(0) = '-';
        }
    }

    return tokens;
}

void Tokenizer::replaceMinus(){
    for(int i = 0; i < expression.size(); i++){
        char c = expression.at(i);
        if(c == '-'){
            if(i == 0){
                expression.at(i) = '_';
            }else{
                if((isDelim(expression.at(i-1)) && expression.at(i-1) != ')') || expression.at(i-1) == '(' || expression.at(i-1) == ','){
                    expression.at(i) = '_';
                }
            }
        }
    }
}

void Tokenizer::setExpression(std::string &expression){
    this->expression = expression;
}

bool Tokenizer::isDelim(const char &c){
    for(const auto &d: delims){
        if(d == c){
            return true;
        }
    }

    return false;
}