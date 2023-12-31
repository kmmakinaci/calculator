#define CALCULATOR_H

#include <iostream>
#include <math.h>
#include <memory>


//Abstract base class for operation
class Operation {
public:
    virtual double perform(double a, double b) const=0;
    virtual ~Operation()=default; //Virtual destructor for polymorphic behaviour
};

class Addition : public Operation {
public:
    double perform(double a, double b) const override {
        return a+b;
    }
};

class Subtraction : public Operation {
public:
    double perform(double a, double b) const override {
        return a-b;
    }
};

// Multiplication operation inheriting from Addition (for demonstration)
class Multiplication : public Addition {
public:
    double perform(double a, double b) const override {
        double result = 0;
        for (int i=0; i<b; ++i) {
            result = Addition::perform(result,a);
        }
        return result;
    }
};

class Division : public Operation {
public:
    double perform(double a, double b) const override {
        if (b==0) {
            std::cout << "Error: Division by zero is not allowed." << std::endl;
            return INFINITY;
        }
        return a/b;
    }
};