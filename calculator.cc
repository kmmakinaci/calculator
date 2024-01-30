#include "calculator.hpp"
#include "operationselector.hpp"

Calculator::Calculator(std::function<std::unique_ptr<Operation>()> operationCreator)
    : createOperation(std::move(operationCreator)) {}

void Calculator::setOperationCreator(std::function<std::unique_ptr<Operation>()> operationCreator) {
    createOperation = std::move(operationCreator);
}

double Calculator::calculate(double a, double b) const {
    std::unique_ptr<Operation> op = createOperation();
    return op->perform(a, b);
}

void Calculator::runCalculator() {
    double result = 0.0;

    std::cout << "Enter initial number: ";
    std::cin >> result;

    while (true) {
        char operation;
        std::cout << "Enter operation (or '=' to finish): ";
        std::cin >> operation;

        if (operation == '=') {
            std::cout << "Final Result: " << result << std::endl;
            break;
        }

        auto operationCreator = OperationSelector::getOperationCreator(operation);

        if (!operationCreator) {
            std::cout << "Invalid operator! Please try again." << std::endl;
            continue;
        }

        setOperationCreator(operationCreator);

        double number;
        std::cout << "Enter Number: ";
        std::cin >> number;

        result = calculate(result, number);
    }
}