#include <core/shuntingyard.hpp>

ShuntingYard::ShuntingYard(std::string &expression){
    this->expression = expression;

    tokenizer = new Tokenizer(this->expression);
}

std::string ShuntingYard::toRPN(Screen *screen){      //REMOVE SCREEN
    std::vector<std::string> output;
    std::vector<std::string> opStack;

    std::vector<std::string> tokens = tokenizer->getTokens();

    std::vector<std::string>::iterator it = tokens.begin();
    while(it != tokens.end()){

        std::string token = *it;

        if(isNum(token)){
            output.push_back(token);
        }else if(token == "("){
            opStack.push_back(token);
        }else if(token == ")"){
            while(opStack.at(opStack.size() - 1) != "("){
                output.push_back(opStack.at(opStack.size() - 1));
                opStack.erase(opStack.end());
                
                screen->drawString(5, 100, "OP: " + opStack.at(opStack.size() - 1), false);
                screen->renderFrameBuffer(false);

                if(opStack.at(opStack.size() - 1) == "(")
                    break;
            }

            opStack.erase(opStack.end());
        }else{
            if(opStack.empty()){
                opStack.push_back(token);
            }else{
                int pres = getPrecedence(token[0]);
                while(opStack.at(opStack.size() - 1) != "(" && ((getPrecedence(opStack.at(opStack.size() - 1)[0]) > pres) || (getPrecedence(opStack.at(opStack.size() - 1)[0]) == pres))){
                    output.push_back(opStack.at(opStack.size() - 1));
                                    
                    opStack.erase(opStack.end());

                    if(opStack.empty())
                        break;
                }
                opStack.push_back(token);
            }
        }

        ++it;
    }

    while(!opStack.empty()){
        output.push_back(opStack.at(opStack.size() - 1));
        opStack.erase(opStack.end());
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

bool ShuntingYard::isNum(std::string &s){
    char c = s.at(0);
    return isdigit(c);
}

ShuntingYard::~ShuntingYard(){
    delete tokenizer;
}

