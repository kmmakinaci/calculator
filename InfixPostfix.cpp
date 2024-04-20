#include "InfixPostfix.hpp"
#include <stack>
#include <sstream>
#include <unordered_map>
#include <math.h>

// Function to determine precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^' || op == 's') // Assuming 's' for square root
        return 3;
    return 0;
}

std::string infixToPostfix(const std::string &infix)
{
    std::stringstream ss(infix);
    std::string postfix;
    std::stack<char> operators;
    std::unordered_map<char, int> precedenceMap = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}, {'s', 3}};

    char ch;
    while (ss >> ch)
    {
        if (isdigit(ch))
        {
            postfix += ch;
            postfix += ' '; // Add space as delimiter
        }
        else if (ch == '(')
        {
            operators.push(ch);
        }
        else if (ch == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.pop(); // Pop '('
        }
        else
        {
            while (!operators.empty() && precedenceMap[ch] <= precedenceMap[operators.top()])
            {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty())
    {
        postfix += operators.top();
        postfix += ' ';
        operators.pop();
    }

    return postfix;
}

double evaluatePostfix(const std::string &postfix)
{
    std::stringstream ss(postfix);
    std::stack<double> numbers;

    double num;
    char ch;
    while (ss >> ch)
    {
        if (isdigit(ch))
        {
            ss.putback(ch);
            ss >> num;
            numbers.push(num);
        }
        else if (ch == ' ')
        {
            continue; // Skip delimiter
        }
        else
        {
            double num2 = numbers.top();
            numbers.pop();
            double num1 = numbers.top();
            numbers.pop();
            double result;
            switch (ch)
            {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            case '^':
                result = pow(num1, num2);
                break;
            case 's':
                result = sqrt(num1);
                break;
            default:
                throw std::runtime_error("Invalid operator!");
            }
            numbers.push(result);
        }
    }

    return numbers.top();
}
