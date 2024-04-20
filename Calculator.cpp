#include "Calculator.hpp"
#include <iostream>

Calculator::Calculator(std::map<char, std::function<std::unique_ptr<Operation>()>> opCreators)
    : operationCreators(std::move(opCreators)) {}

void Calculator::getInput(std::string &expression) const
{
    std::cout << "Enter the mathematical expression (e.g., 2 + 3 * 4): ";
    std::getline(std::cin, expression);
}

std::unique_ptr<Operation> Calculator::createOperation(char operation) const
{
    if (operationCreators.find(operation) != operationCreators.end())
    {
        return operationCreators.at(operation)();
    }
    else
    {
        throw std::runtime_error("Invalid operation!");
    }
}

void Calculator::performCalculation() const
{
    std::string expression;

    do
    {
        getInput(expression);

        if (expression == "0")
        {
            std::cout << "Exiting...\n";
            break;
        }

        try
        {
            std::string postfix = infixToPostfix(expression);
            double result = evaluatePostfix(postfix);
            std::cout << "Result: " << result << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

    } while (expression != "0");
}
