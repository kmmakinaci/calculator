#include "calculator.h"
#include <iostream>

using namespace std;

int main() 
{
    char operation;
    Calculator c; 
    cout << "Enter + to Add 2 Numbers" << 
            "\nEnter - to Subtract 2 Numbers" << 
            "\nEnter * to Multiply 2 Numbers" << 
            "\nEnter / to Divide 2 Numbers" << 
            "\nEnter 0 To Exit\n";
         
    do
    {
        cout << "\nEnter Choice: ";
        cin >> operation;
        switch (operation)
        {
        case '+':
             
            // result function invoked
            c.result();     
             
            // function to calculate summation
            cout << "Result: " << 
                     c.add() << endl; 
            break;
        case '-':
             
            // function to calculate subtraction
            c.result();
            cout << "Result: " << 
                     c.sub() << endl; 
            break;
        case '*':
            c.result();
             
            // function to calculate multiplication
            cout << "Result: " << 
                     c.mul() << endl; 
            break;
        case '/':
            c.result();
             
            // function to calculate division
            cout << "Result: " << 
                     c.div() << endl; 
            break;
        }
         
    } while (operation == '+' || operation == '-' || operation == '*' || operation == '/');
     
    return 0;
}		