#include <core/shuntingyard.hpp>

ShuntingYard::ShuntingYard(std::string &expression){
    this->expression = expression;
    this->expression.erase(std::remove_if(this->expression.begin(), this->expression.end(), ::isspace), this->expression.end());

    tokenizer = new Tokenizer(this->expression);
}

std::string ShuntingYard::toRPN(){      //REMOVE SCREEN
    std::vector<std::string> output;
    std::stack<std::string> opStack;

    std::vector<std::string> tokens = tokenizer->getTokens();   
    
    for(const auto& t: tokens){

        std::string token = t;
        if(isNum(token)){
            output.push_back(token);
        }else if(token == "("){
            opStack.push(token);
        }else if(token == ")"){
            while(opStack.top() != "("){
                output.push_back(opStack.top());
                opStack.pop();
            }

            opStack.pop();
        }else{
            if(opStack.empty()){
                opStack.push(token);
            }else{
                int pres = getPrecedence(token.at(0));
                while(opStack.top() != "(" && ((getPrecedence(opStack.top().at(0)) > pres) || ((getPrecedence(opStack.top().at(0)) == pres) && getAssociativity(opStack.top().at(0))))){
                    output.push_back(opStack.top());
                                    
                    opStack.pop();

                    if(opStack.empty())
                        break;
                }
                opStack.push(token);
            }
        }
    }

    while(!opStack.empty()){
        output.push_back(opStack.top());
        opStack.pop();
    }

    std::string strOut;
    for(const auto& o: output){
        strOut += o + " ";
    }

    return strOut;
}

int ShuntingYard::getPrecedence(const char &c){
    switch (c)
    {
    case '(':
    case ')':
        return 1;
    case '-':
    case '+':
        return 2;
    case '*':
    case '/':
        return 3;
    case '^':
        return 5;
    
    default:
        return 0;
    }
}

/*
    True: left
    False: right
*/
bool ShuntingYard::getAssociativity(const char &c){
    switch (c)
    {
    case '*':
    case '/':
    case '+':
    case '-':
        return true;
    case '^':
        return false;
    
    default:
        return true;
    }
}

bool ShuntingYard::isNum(std::string &s){
    char c = s.at(0);
    return isdigit(c);
}

ShuntingYard::~ShuntingYard(){
    delete tokenizer;
}
