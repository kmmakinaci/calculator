#include <iostream>
#include "calculator.hpp"
#include "operationselector.hpp"  // Include the operation selector
#include "calculator.cc"

int main() {
    Calculator calculator(OperationSelector::getOperationCreator('+'));  // Specify start operator

    while (true) {
        calculator.runCalculator();  // Starting number is obtained from the user

        std::cout << "Do you want to perform more calculations? (y/n): ";
        char choice;
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    return 0;
}