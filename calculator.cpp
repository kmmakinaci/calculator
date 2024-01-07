#include "calculator.hpp"

Calculator::Calculator(std::map<char, std::function<std::unique_ptr<Operation>()>> opCreators)
    : operationCreators(std::move(opCreators)) {}

void Calculator::getInput(double &a, double &b, char &operation) const
{
    std::cout << "Enter First Number: ";
    std::cin >> a;

    std::cout << "Enter Second Number: ";
    std::cin >> b;

    std::cout << "Enter Operator (+, -, *, /): ";
    std::cin >> operation;
}

std::unique_ptr<Operation> Calculator::createOperation(char operation) const {
    if (operationCreators.find(operation) != operationCreators.end()) {
        return operationCreators.at(operation)();
    } else {
        throw std::runtime_error("Invalid operation!");
    }
}

void Calculator::performCalculation() const {
    double a, b;
    char operation;

    do {
        getInput(a, b, operation);

        if (operation == '0') {
            std::cout << "Exiting...\n";
            break;
        }

        try {
            std::unique_ptr<Operation> op = createOperation(operation);
            double result = op->perform(a, b);
            std::cout << "Result: " << result << std::endl;
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }

    } while (operation != '0');
}
