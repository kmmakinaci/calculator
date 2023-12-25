#define CALCULATOR_H
#pragma once
#include <iostream>
#include <math.h>
using namespace std;
 
// Class Calculator 
class Calculator
{
   float a, b;
public:
   
    //Function to receive 2 numbers from the user.
    void result() 
    {
        cout << "Enter First Number: ";    
        cin >> a;
        cout << "Enter Second Number: ";   
        cin >> b;
    }
   
    // Function to add two numbers
    float add() 
    {
        return a + b;
    }
   
    // Function to subtract two numbers
    float sub() 
    {
        return a - b;
    }
   
    // Function to multiply two numbers
    float mul() 
    {
        return a * b;
    }
   
    // Function to divide two numbers
    float div() 
    {
        if (b == 0) 
        {
            cout << "Division By Zero" << 
                     endl;
            return INFINITY;
        }
        else
        {
            return a / b;
        }
    }
};