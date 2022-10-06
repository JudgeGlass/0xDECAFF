#include <core/shuntingyard.hpp>

ShuntingYard::ShuntingYard(std::string &expression){
    this->expression = expression;
    this->expression.erase(std::remove_if(this->expression.begin(), this->expression.end(), ::isspace), this->expression.end());

    functionStore = new Function();
    tokenizer = new Tokenizer(this->expression);
    rpnTokens = toRPN();
}

double ShuntingYard::eval(double x){

    this->x = x;
    rpnTokens = toRPN();

    return r_eval(rpnTokens);
}

double ShuntingYard::eval(){
    std::vector<std::string> rpnExpression = toRPN();
    double rr =  r_eval(rpnExpression);

    return rr;
}

double ShuntingYard::r_eval(std::vector<std::string> &rpnExpression){
    // std::cout << "EXPRESSION: ";
    // for(const auto&t: rpnExpression){
    //     std::cout << t << " ";
    // }
    // std::cout << std::endl;

    //std::cout << "SIZE: " << rpnExpression.size() << std::endl;

    std::cout.precision(16);
    if(rpnExpression.size() == 1){
        return std::stod(rpnExpression.at(0));
    }
    
    std::string token;
    int index = 0;
    while(!functionStore->hasFunction(token = rpnExpression.at(index))){
        index++;
    }

    int argCount = functionStore->getArgCount(token);
    std::vector<double> args;
    for(int i = 1; i < argCount + 1; i++){
        if(rpnExpression.at(index - i) == "x"){
            //std::cout << "IS XXX!!!!" << std::endl;
            args.push_back(x);
        }else
            args.push_back(std::stod(rpnExpression.at(index - i)));
    }

    for(int i = 1; i < argCount + 1; i++){
        rpnExpression.erase(rpnExpression.begin() + (index - i));
    }

    index -= argCount;

    //std::cout << "ARGS: " << args.at(0) << " " << args.at(1) << std::endl;
    double cc = functionStore->calc(token, args);
    //std::cout << "CAL: " << cc << "\tT: " << token << "\tA1: " << args.at(0) << "\tA2:" << args.at(1) << std::endl;

    rpnExpression.at(index) = std::to_string(cc);

    return r_eval(rpnExpression);

    //return 0;
}

std::vector<std::string> ShuntingYard::toRPN(){      //REMOVE SCREEN
    std::vector<std::string> output;
    std::stack<std::string> opStack;

    std::vector<std::string> tokens = tokenizer->getTokens();   
    
    for(const auto& t: tokens){
        std::string token = t;
        
        if(token == ","){
            continue;
        }

        if(isNum(token) || token == "x"){
            output.push_back(token);
        }else if(!isOp(token) && functionStore->hasFunction(token)){
            opStack.push(token);
        }else if(token == "("){
            opStack.push(token);
        }else if(token == ")"){
            while(opStack.top() != "("){
                output.push_back(opStack.top());
                opStack.pop();
            }

            opStack.pop();
            if(functionStore->hasFunction(opStack.top())){
                output.push_back(opStack.top());
                opStack.pop();
            }
        }else{
            if(opStack.empty()){
                opStack.push(token);
            }else{
                int pres = getPrecedence(token.at(0));
                while(opStack.top() != "(" && ((getPrecedence(opStack.top().at(0)) > pres) || ((getPrecedence(opStack.top().at(0)) == pres) && getAssociativity(opStack.top().at(0))))){
                    
                    output.push_back(opStack.top());
                                    
                    opStack.pop();
                    if(opStack.empty()){
                        break;
                    }
                }
                opStack.push(token);
            }
        }
    }

    while(!opStack.empty()){
        if(opStack.top() == "(" || opStack.top() == ")"){
            output.clear();
            return output;
        }
        
        output.push_back(opStack.top());
        opStack.pop();
    }

    return output;
}

bool ShuntingYard::isOp(std::string &token){
    //std::cout << "TOKEN! " << token << std::endl;
    return (token == "+" || token == "-" || token == "^" || token == "*" || token == "/");
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
    delete functionStore;
    delete tokenizer;
}
