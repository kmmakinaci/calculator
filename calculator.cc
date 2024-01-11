#include "calculator.hpp"
#include "operationselector.hpp"

Calculator::Calculator(std::function<std::unique_ptr<Operation>()> operationCreator)
    : createOperation(std::move(operationCreator)) {}

std::pair<double, double> Calculator::getUserInput() const {
    double number1, number2;
    std::cout << "Enter First Number: ";
    std::cin >> number1;
    std::cout << "Enter Second Number: ";
    std::cin >> number2;
    return {number1, number2};
}

double Calculator::calculate(double a, double b) const {
    std::unique_ptr<Operation> op = createOperation();
    return op->perform(a, b);
}