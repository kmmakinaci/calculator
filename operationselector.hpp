#ifndef OPERATIONSELECTOR_H
#define OPERATIONSELECTOR_H

#include <functional>
#include <memory>
#include "operation.hpp"

class OperationSelector {
public:
    static std::function<std::unique_ptr<Operation>()> getOperationCreator(char operation) {
        switch (operation) {
            case '+':
                return []() { return std::make_unique<Addition>(); };
            case '-':
                return []() { return std::make_unique<Subtraction>(); };
            case '*':
                return []() { return std::make_unique<Multiplication>(); };
            case '/':
                return []() { return std::make_unique<Division>(); };
            default:
                std::cout << "Invalid operator!" << std::endl;
                return nullptr;
        }
    }
};

#endif  // OPERATIONSELECTOR_H

