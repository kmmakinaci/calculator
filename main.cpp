#include <iostream>
#include <map>
#include "calculator.hpp"
#include "operation.hpp"


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

    std::cout << "Enter + to Add 2 Numbers"
              << "\nEnter - to Subtract 2 Numbers"
              << "\nEnter * to Multiply 2 Numbers"
              << "\nEnter / to Divide 2 Numbers"
              << "\nEnter 0 To Exit\n";

    calculator.performCalculation();

    return 0;
}