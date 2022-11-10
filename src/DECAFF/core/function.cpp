#include <core/function.hpp>

Function::Function(){
    functionList.insert({"sqrt", new Sqrt()});
    functionList.insert({"mac", new Max()});
    functionList.insert({"sin", new Sin()});
    functionList.insert({"cos", new Cos()});
    functionList.insert({"+", new Add()});
    functionList.insert({"-", new Minus()});
    functionList.insert({"*", new Mul()});
    functionList.insert({"/", new Div()});
    functionList.insert({"^", new Pow()});
    functionList.insert({"cbrt", new Cbrt()});
    functionList.insert({"abs", new Abs()});

    functionList.insert({"lsh", new LeftShift()});
    functionList.insert({"rsh", new RightShift()});
    functionList.insert({"|", new LogicOR()});
    functionList.insert({"&", new LogicAND()});
}

double Function::calc(std::string &func, std::vector<double> &args){
    return functionList[func]->calc(args);
}

int Function::getArgCount(std::string &func){
    return functionList[func]->getArgCount();
}

bool Function::hasFunction(std::string &func){
    return (functionList.find(func) != functionList.end());
}

