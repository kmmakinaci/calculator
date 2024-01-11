#include <tuple>
#include "calculator.hpp"
#include "calculator.cc"  // Include the implementation file

int main() {
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

        auto operationCreator = OperationSelector::getOperationCreator(operation);

        if (!operationCreator)
            continue;

        Calculator calculator(operationCreator);

        auto userInput = calculator.getUserInput();
        double number1 = userInput.first;
        double number2 = userInput.second;

        double result = calculator.calculate(number1, number2);

        std::cout << "Result: " << result << std::endl;

    } while (operation == '+' || operation == '-' || operation == '*' || operation == '/');

    return 0;
}