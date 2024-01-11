#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <memory>
#include <functional>
#include "operation.hpp"

// Calculator class responsible for performing calculations
class Calculator {
private:
    std::function<std::unique_ptr<Operation>()> createOperation;

public:
    explicit Calculator(std::function<std::unique_ptr<Operation>()> operationCreator);

    std::pair<double, double> getUserInput() const;

    double calculate(double a, double b) const;
};

#endif