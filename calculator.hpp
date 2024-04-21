/*#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <memory>
#include <functional>
#include "operation.hpp"

class Calculator {
private:
    std::function<std::unique_ptr<Operation>()> createOperation;

public:
    explicit Calculator(std::function<std::unique_ptr<Operation>()> operationCreator);

    void setOperationCreator(std::function<std::unique_ptr<Operation>()> operationCreator);

    std::pair<double, char> getUserInput() const;

    double calculate(double a, double b) const;

    void runCalculator();  // Updated prototype
};

#endif*/
/*
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <memory>
#include <functional>
#include "operation.hpp"

class Calculator {
private:
    std::function<std::unique_ptr<Operation>()> createOperation;

public:
    explicit Calculator(std::function<std::unique_ptr<Operation>()> operationCreator);

    void setOperationCreator(std::function<std::unique_ptr<Operation>()> operationCreator);

    std::pair<double, char> getUserInput() const;

    double calculate(double a, double b) const;

    void runCalculator();  // Updated prototype
};

#endif
*/
/*
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <memory>
#include <functional>
#include "operation.hpp"

class Calculator {
private:
    std::function<std::unique_ptr<Operation>()> createOperation;

public:
    explicit Calculator(std::function<std::unique_ptr<Operation>()> operationCreator);

    void setOperationCreator(std::function<std::unique_ptr<Operation>()> operationCreator);

    double calculate(double a, double b, char op) const;

    void runCalculator();
};

#endif // CALCULATOR_H*/

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <stack>
#include <string>
#include "operation.hpp"

class Calculator {
private:
    std::stack<double> values;
    std::stack<char> ops;

    double calculate(double a, double b, char op) const;

    int precedence(char op) const;

public:
    void runCalculator();
};

#endif // CALCULATOR_H