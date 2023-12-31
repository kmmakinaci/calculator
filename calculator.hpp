#include <iostream>
#include <memory>
#include <functional>
#include "operation.hpp"

// Calculator class responsible for performing calculations
class Calculator {
private:
    std::function<std::unique_ptr<Operation>()> createOperation;

public:
    explicit Calculator(std::function<std::unique_ptr<Operation>()> operationCreator)
        : createOperation(std::move(operationCreator)) {}

    double calculate(char operation, double a, double b) const {
        std::unique_ptr<Operation> op = createOperation();
        return op->perform(a, b);
    }
};