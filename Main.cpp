#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include "StackArray.h"
#include <cstdlib>
using namespace std;

/**
 * @brief Clears the terminal
 *
 */
void clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    std::system("clear");
#endif
}
// check operations=operands- 1

/**
 * @brief Adds two operands and pushes result onto the stack
 *
 * @param op1   Operand 1
 * @param op2   Operand 2
 * @param s     Stack
 */
void add(float op1, float op2, Stack<float> &s)
{
    s.push(op1 + op2);
    return;
}

/**
 * @brief Subtracts two operands and pushes result onto the stack
 *
 * @param op1   Operand 1
 * @param op2   Operand 2
 * @param s     Stack
 */
void subtract(float op1, float op2, Stack<float> &s)
{
    s.push(op2 - op1);
    return;
}

/**
 * @brief Multiplies two operands and pushes result onto the stack
 *
 * @param op1   Operand 1
 * @param op2   Operand 2
 * @param s     Stack
 */
void multiply(float op1, float op2, Stack<float> &s)
{
    s.push(op1 * op2);
    return;
}

/**
 * @brief Divides two operands and pushes result onto the stack
 *
 * @param op1   Operand 1
 * @param op2   Operand 2
 * @param s     Stack
 */
void divide(float op1, float op2, Stack<float> &s)
{
    s.push(op2 / op1);
    return;
}

/**
 * @brief Raises operand to the power of other operand pushes result onto the stack
 *
 * @param op1   Operand 1
 * @param op2   Operand 2
 * @param s     Stack
 */
void power(float op1, float op2, Stack<float> &s)
{
    s.push(pow(op2, op1));
    return;
}

/**
 * @brief Calculates modulus pushes result onto the stack
 *
 * @param op1   Operand 1
 * @param op2   Operand 2
 * @param s     Stack
 */
void modulus_t(float op1, float op2, Stack<float> &s)
{
    s.push((int)op2 % (int)op1);
    return;
}

/**
 * @brief Checks precedence level of two passed operators
 *
 * @param a Operator 1
 * @param b Operator 2
 * @return true if operator1 has higher precedence
 * @return false if operator2 has higher precedence
 */
bool hasHigherPrecedence(char a, char b)
{
    int a_prec, b_prec;

    if (a == '(' || a == ')')
        a_prec = 1;
    else if (a == '*' || a == '/')
        a_prec = 2;
    else
        a_prec = 3;

    if (b == '(' || b == ')')
        b_prec = 1;
    else if (b == '*' || b == '/')
        b_prec = 2;
    else
        b_prec = 3;

    if (a_prec < b_prec)
        return true;

    return false;
}

/**
 * @brief Checks if passed character is a digit/decimal
 *
 * @param a Character to check
 * @return true if a is digit/decimal
 * @return false of a is not a digit/decimal
 */
bool isDigit(char a)
{
    if ((((int)a - ((int)'0') >= 0) && ((int)a - ((int)'0') <= 9)) || a == '.')
        return true;
    return false;
}

/**
 * @brief Checks if passed character is an operator
 *
 * @param op    Character to check
 * @return true if op is an operator
 * @return false if op is not an operator
 */
bool isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '%')
        return true;
    return false;
}

/**
 * @brief Checks if passed character is an opening bracket
 *
 * @param br    Character to check
 * @return true if br is an opening bracket
 * @return false if br is not an opening bracket
 */
bool isOpeningBracket(char br)
{
    if (br == '(' || br == '{' || br == '[')
        return true;
    return false;
}

/**
 * @brief Checks if passed character is a closing bracket
 *
 * @param br Character to check
 * @return true if br is a closing bracket
 * @return false if br is not a closing bracket
 */
bool isClosingBracket(char br)
{
    if (br == ')' || br == '}' || br == ']')
        return true;
    return false;
}

/**
 * @brief Checks if passed character is a bracket
 *
 * @param br Character to check
 * @return true if br is a bracket
 * @return false if br is not a bracket
 */
bool isBracket(char br)
{
    if (!isClosingBracket(br) && !isOpeningBracket(br))
        return false;
    return true;
}

/**
 * @brief Fixes & error-handles the user input
 *
 * @param input //User input
 * @param size //Passed reference to the size of the stack array
 * @return string Properly formatted and error checked string
 */
string fixInput(string input, int &size)
{
    int brackets = 0;
    string postfix;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
            continue;
        if (isOperator(input[i]) || isBracket(input[i]))
        {
            if (!isOpeningBracket(input[i]))
            {
                size++;
                postfix += ' ';
            }

            if (isOpeningBracket(input[i]))
                brackets++;

            if (isClosingBracket(input[i]))
            {
                brackets--;
                size--;
            }

            postfix += input[i];
            postfix += ' ';
            continue;
        }
        if (!isDigit(input[i]))
            return "numeralError";
        postfix += input[i];
    }
    size++;

    if (brackets != 0)
        return "bracketError";

    return postfix;
}

/**
 * @brief Evaluates the postfix expression
 *
 * @param postfix   Postfix expression
 * @param stackSize Size of the stack
 */
void postfixEvaluator(string postfix, int stackSize)
{
    Stack<float> s(stackSize);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (postfix[i] == ' ')
            continue;
        else if (isOperator(postfix[i]))
        {
            float operand1 = s.pop();
            float operand2 = s.pop();

            if (postfix[i] == '+')
                add(operand1, operand2, s);
            else if (postfix[i] == '-')
                subtract(operand1, operand2, s);
            else if (postfix[i] == '*')
                multiply(operand1, operand2, s);
            else if (postfix[i] == '/')
                divide(operand1, operand2, s);
            else if (postfix[i] == '^')
                power(operand1, operand2, s);
            else if (postfix[i] == '%')
                modulus_t(operand1, operand2, s);
        }
        else
        {
            string temp;
            for (; postfix[i] != ' ' && postfix[i] != '\0' && !isOperator(postfix[i]); i++)
                temp += postfix[i];

            s.push(stof(temp));
        }
    }
    cout << "Answer:\t\t" << s.peek() << endl;
}

/**
 * @brief Converts user-inputted infix string to postfix
 *
 * @param infix //User-input infix string
 */
void infixToPostfix(string infix)
{
    int stackSize = 0;
    infix = fixInput(infix, stackSize);

    if (infix == "bracketError")
    {
        cout << "Expression error!\nBrackets opened must be equal to brackets closed!\n";
        return;
    }
    else if (infix == "numeralError")
    {
        cout << "Expression error!\nOperands must be numbers!\n";
        return;
    }

    cout << "Infix:\t\t" << infix << endl;
    // cout << "Size" << stackSize << endl;

    if (stackSize == 1)
    {
        cout << "Postfix:\t" << infix << endl
             << "Answer:\t\t" << infix << endl;
        return;
    }

    string postfix;
    Stack<char> s(stackSize);

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == ' ')
            continue;
        else if (isOperator(infix[i]))
        {
            while (!s.isEmpty() && hasHigherPrecedence(s.peek(), infix[i]) && !isOpeningBracket(s.peek()))
            {
                postfix += s.pop();
                postfix += ' ';
            }
            s.push(infix[i]);
        }
        else if (isOpeningBracket(infix[i]))

            s.push(infix[i]);
        else if (isClosingBracket(infix[i]))
        {
            while (!s.isEmpty() && !isOpeningBracket(s.peek()))
                postfix += s.pop();
            s.pop();
        }
        else
        {
            for (; infix[i] != ' ' && infix[i] != '\0'; i++)
                postfix += infix[i];

            postfix += ' ';
        }
    }

    postfix += ' ';

    while (!s.isEmpty())
    {
        postfix += s.pop();
        postfix += ' ';
    }

    cout << "Postfix:\t" << postfix << endl;
    postfixEvaluator(postfix, stackSize);
    return;
}

/**
 * @brief Driver code
 *
 * @return int Errors (if any)
 */
int main()
{
    // string infix = "1+3*8*(3/4-2)"; // INPUT
    while (true)
    {
        string infix;
        clear_screen();
        cout << "Enter Infix expression (or 0 to exit): ";
        getline(cin, infix);
        if (infix == "0")
            break;
        clear_screen();
        infixToPostfix(infix);
        cout << "Press any key to continue\n";
        getchar();
    }
    return 0;
}