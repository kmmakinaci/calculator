/*#include "calculator.hpp"
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
}*/
//(5+3)*2+4+16/8 % 3 =
/*
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
*/
/*
#include "calculator.hpp"
#include "operationselector.hpp"
#include <stack>

// Define precedence function
int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0; // Parantezleri veya diğer karakterleri düşük öncelikli olarak işaretleyin
}

Calculator::Calculator(std::function<std::unique_ptr<Operation>()> operationCreator)
    : createOperation(std::move(operationCreator)) {}

void Calculator::setOperationCreator(std::function<std::unique_ptr<Operation>()> operationCreator) {
    createOperation = std::move(operationCreator);
}

double Calculator::calculate(double a, double b, char op) const {
    std::unique_ptr<Operation> operation = createOperation();
    return operation->perform(a, b);
}

void Calculator::runCalculator() {
    std::stack<double> values;
    std::stack<char> ops;
    double result = 0.0;

    std::cout << "Enter expression: ";
    std::string expression;
    std::cin >> expression;

    for (size_t i = 0; i < expression.length(); ++i) {
        char currentChar = expression[i];

        if (isdigit(currentChar)) {
            double num = currentChar - '0';
            while (i + 1 < expression.length() && isdigit(expression[i + 1])) {
                num = num * 10 + (expression[i + 1] - '0');
                ++i;
            }
            values.push(num);
        } else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(currentChar)) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(calculate(a, b, op));
            }
            ops.push(currentChar);
        }
    }

    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(calculate(a, b, op));
    }

    result = values.top();
    std::cout << "Result: " << result << std::endl;
}*/
/*
#include "calculator.hpp"


double Calculator::calculate(double a, double b, char op) const {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                return INFINITY;
            }
            return a / b;
        default:
            std::cout << "Invalid operator!" << std::endl;
            return 0;
    }
}

int Calculator::precedence(char op) const {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void Calculator::runCalculator() {
    std::cout << "Enter expression: ";
    std::string expression;
    std::cin >> expression;

    for (size_t i = 0; i < expression.length(); ++i) {
        char currentChar = expression[i];
        if (isdigit(currentChar)) {
            double num = currentChar - '0';
            while (i + 1 < expression.length() && isdigit(expression[i + 1])) {
                num = num * 10 + (expression[i + 1] - '0');
                ++i;
            }
            values.push(num);
        } else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(currentChar)) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(calculate(a, b, op));
            }
            ops.push(currentChar);
        }
    }

    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(calculate(a, b, op));
    }

    if (!values.empty()) {
        std::cout << "Result: " << values.top() << std::endl;
    }
}
*/

#include "calculator.hpp"
#include <cctype>
#include <sstream>

double Calculator::calculate(double a, double b, char op) const {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                return INFINITY;
            }
            return a / b;
        default:
            std::cout << "Invalid operator!" << std::endl;
            return 0;
    }
}

int Calculator::precedence(char op) const {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void Calculator::runCalculator() {
    std::cout << "Enter expression: ";
    std::string expression;
    std::cin >> expression;

    bool expectingNumber = true;

    for (size_t i = 0; i < expression.length(); ++i) {
        char currentChar = expression[i];
        if (isdigit(currentChar)) {
            double num = currentChar - '0';
            while (i + 1 < expression.length() && isdigit(expression[i + 1])) {
                num = num * 10 + (expression[i + 1] - '0');
                ++i;
            }
            values.push(num);
            expectingNumber = false;
        } else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            if (expectingNumber && (currentChar == '+' || currentChar == '-')) {
                // Handle leading + or - signs
                if (i + 1 < expression.length() && isdigit(expression[i + 1])) {
                    ++i;
                    double num = expression[i] - '0';
                    while (i + 1 < expression.length() && isdigit(expression[i + 1])) {
                        num = num * 10 + (expression[i + 1] - '0');
                        ++i;
                    }
                    if (currentChar == '-') {
                        num = -num;
                    }
                    values.push(num);
                    expectingNumber = false;
                    continue;
                } else {
                    std::cout << "Error: Invalid expression." << std::endl;
                    return;
                }
            }
            while (!ops.empty() && precedence(ops.top()) >= precedence(currentChar)) {
                if (values.size() < 2) {
                    std::cout << "Error: Invalid expression." << std::endl;
                    return;
                }
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(calculate(a, b, op));
            }
            ops.push(currentChar);
            expectingNumber = true;
        } else {
            std::cout << "Error: Invalid character in expression." << std::endl;
            return;
        }
    }

    while (!ops.empty()) {
        if (values.size() < 2) {
            std::cout << "Error: Invalid expression." << std::endl;
            return;
        }
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(calculate(a, b, op));
    }

    if (!values.empty()) {
        std::cout << "Result: " << values.top() << std::endl;
    } else {
        std::cout << "Error: Invalid expression." << std::endl;
    }
}