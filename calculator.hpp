#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <memory>
#include <map>
#include <functional>
#include "operation.hpp"

// Calculator class responsible for performing calculations
class Calculator {
private:
    std::map<char, std::function<std::unique_ptr<Operation>()>> operationCreators;

public:
    explicit Calculator(std::map<char, std::function<std::unique_ptr<Operation>()>> opCreators);

    void getInput(double& a, double& b, char& operation) const;
    std::unique_ptr<Operation> createOperation(char operation) const;
    void performCalculation() const;
};
#endif //CALCULATOR_H