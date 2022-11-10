#include <core/shuntingyard.hpp>

ShuntingYard::ShuntingYard(std::string &expression){
    this->expression = expression;
    this->expression.erase(std::remove_if(this->expression.begin(), this->expression.end(), ::isspace), this->expression.end());

    functionStore = new Function();                                     // Init the function store
    tokenizer = new Tokenizer(this->expression);
    rpnTokens = toRPN();                                                // Break string expression into RPN expression
}

/**
 *  Find the value of a function at a specific x value 
 * **/

double ShuntingYard::eval(double x){
    this->x = x;

    return r_eval(rpnTokens);
}

/**
 *  Find the value of an expression (no x value)
 * **/

double ShuntingYard::eval(){
    double rr = r_eval(rpnTokens);

    return rr;
}

/**
 *  A recursive function that evaluates RPN tokens
 * **/

double ShuntingYard::r_eval(std::vector<std::string> rpnExpression){
    std::cout.precision(16);
    if(rpnExpression.size() == 1){                                       // Check to see if the rpnExpression has only one value, if so then return it as it should be the answer
        return std::stod(rpnExpression.at(0));
    }
    
    std::string token;
    int index = 0;
    while(!functionStore->hasFunction(token = rpnExpression.at(index))){ // Loop through tokens until a function or operator is found
        index++;
    }

    int argCount = functionStore->getArgCount(token);                   // Get operator / function argument size
    std::vector<double> args;
    for(int i = 1; i < argCount + 1; i++){
        if(rpnExpression.at(index - i).find("x") != std::string::npos){                         // If 'x' is found, replace it with specified number
            args.push_back(x);
        }else
            args.push_back(std::stod(rpnExpression.at(index - i)));
    }

    for(int i = 1; i < argCount + 1; i++){                              // Pop the used rpn tokens
        rpnExpression.erase(rpnExpression.begin() + (index - i));
    }

    index -= argCount;

    double cc = functionStore->calc(token, args);                       // Calculate the operator

    rpnExpression.at(index) = std::to_string(cc);                       // push the calculated value

    return r_eval(rpnExpression);                                       // Repeat until rpnExpression size equals 1 
}

/**
 *  Shunting Yard algorithm
 *  https://en.wikipedia.org/wiki/Shunting_yard_algorithm
 * **/

std::vector<std::string> ShuntingYard::toRPN(){
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
                while(opStack.top() != "(" && ((getPrecedence(opStack.top().at(0)) > pres) 
                || ((getPrecedence(opStack.top().at(0)) == pres) && getAssociativity(opStack.top().at(0))))){
                    
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

/**
 *  Check to see if string token is a basic operator
 * **/

bool ShuntingYard::isOp(std::string &token){
    return (token == "+" || token == "-" || token == "^" || token == "*" || token == "/" || token == "&" || token == "|");
}

/**
 *  Get the precedence of operator
 * **/

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

/**
 *  Get the associativity of operator
 *  True: left
 *  False: right
 * **/

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
