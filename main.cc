#include <iostream>

int main() 
{
    std::unique_ptr<Operation> addition = std::make_unique<Addition>();
    std::unique_ptr<Operation> substraction = std::make_unique<Subtraction>();
    std::unique_ptr<Operation> multiplication = std::make_unique<Multiplication>();
    std::unique_ptr<Operation> division = std::make_unique<Division>();

    double number1{}, number2{};
    char operation{};
    double result{};

    std::cout << "Enter + to Add 2 Numbers" << 
            "\nEnter - to Subtract 2 Numbers" << 
            "\nEnter * to Multiply 2 Numbers" << 
            "\nEnter / to Divide 2 Numbers" << 
            "\nEnter 0 To Exit\n";

    do {
        std::cout << "\nEnter Choice: ";
        std::cin >> operation;

        if(operation =='0')
            return 0;

        std::cout << "Enter First Number: ";
        std::cin >> number1;

        std::cout << "Enter Second Number: ";
        std::cin >> number2;


        switch(operation) {
            case '+':
                result = addition->perform(number1, number2);
                break;
            case '-':
                result = substraction->perform(number1, number2);
                break;
            case '*':
                result = multiplication->perform(number1, number2);
                break;
            case '/':
                result = division->perform(number1,number2);
                break;
            default:
                std::cout << "Invalid operator!" << std::endl;
                return 1; //Exiting with an error code
        }

        std::cout << "Result:" << result << std::endl;
    } while (operation == '+' || operation == '-' || operation == '*' || operation == '/');

    return 0;
}		