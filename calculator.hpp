#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <memory>
#include <map>
#include <functional>
#include "operation.hpp"
#include "infix_postfix.hpp"

// Calculator class responsible for performing calculations
class Calculator {
public:
    explicit Calculator(std::map<char, std::function<std::unique_ptr<Operation>()>> opCreators);

    void getInput(std::string& expression) const;
    std::unique_ptr<Operation> createOperation(char operation) const;
    void performCalculation() const;

private:
    std::map<char, std::function<std::unique_ptr<Operation>()>> operationCreators;
};

#endif //CALCULATOR_H
