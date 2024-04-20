#ifndef INFIX_POSTFIX
#define INFIX_POSTFIX

#include <string>

std::string infixToPostfix(const std::string &infix);
double evaluatePostfix(const std::string &postfix);

#endif
