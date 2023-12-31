#include "calculator.hpp"
#include <iostream>

int main() 
{
    auto additionCreator = []() { return std::make_unique<Addition>(); };
    auto subtractionCreator = []() { return std::make_unique<Subtraction>(); };
    auto multiplicationCreator = []() { return std::make_unique<Multiplication>(); };
    auto divisionCreator = []() { return std::make_unique<Division>(); };

    Calculator calculatorAddition(additionCreator);
    Calculator calculatorSubtraction(subtractionCreator);
    Calculator calculatorMultiplication(multiplicationCreator);
    Calculator calculatorDivision(divisionCreator);

    double number1, number2;
    char operation;

    std::cout << "Enter + to Add 2 Numbers"
              << "\nEnter - to Subtract 2 Numbers"
              << "\nEnter * to Multiply 2 Numbers"
              << "\nEnter / to Divide 2 Numbers"
              << "\nEnter 0 To Exit\n";

    do {
        std::cout << "\nEnter Choice: ";
        std::cin >> operation;

        if (operation == '0')
            return 0;

        std::cout << "Enter First Number: ";
        std::cin >> number1;

        std::cout << "Enter Second Number: ";
        std::cin >> number2;

        double result;
        switch (operation) {
            case '+':
                result = calculatorAddition.calculate(operation, number1, number2);
                break;
            case '-':
                result = calculatorSubtraction.calculate(operation, number1, number2);
                break;
            case '*':
                result = calculatorMultiplication.calculate(operation, number1, number2);
                break;
            case '/':
                result = calculatorDivision.calculate(operation, number1, number2);
                break;
            default:
                std::cout << "Invalid operator!" << std::endl;
                break;
        }

        std::cout << "Result: " << result << std::endl;

    } while (operation == '+' || operation == '-' || operation == '*' || operation == '/');

    return 0;
}