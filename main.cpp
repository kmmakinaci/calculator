#include <iostream>
#include <map>
#include "Calculator.hpp"
#include "Operation.hpp"

int main() 
{
    auto additionCreator = []() { return std::make_unique<Addition>(); };
    auto subtractionCreator = []() { return std::make_unique<Subtraction>(); };
    auto multiplicationCreator = []() { return std::make_unique<Multiplication>(); };
    auto divisionCreator = []() { return std::make_unique<Division>(); };

    std::map<char, std::function<std::unique_ptr<Operation>()>> operationMap = {
        {'+', additionCreator},
        {'-', subtractionCreator},
        {'*', multiplicationCreator},
        {'/', divisionCreator}
    };

    Calculator calculator(operationMap);
    std::cout << "Welcome to the Calculator!\n";

    calculator.performCalculation();

    return 0;
}
