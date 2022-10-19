#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include "StackArray.h"
#include <cstdlib>

void clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    std::system("clear");
#endif
}
//^,%
// sudo apt - get purge google - chrome - stable
// rm ~/.config/google-chrome/ -rf

using namespace std;

void add(float op1, float op2, Stack<float> &s)
{
    s.push(op1 + op2);
    return;
}

void subtract(float op1, float op2, Stack<float> &s)
{
    s.push(op2 - op1);
    return;
}

void multiply(float op1, float op2, Stack<float> &s)
{
    s.push(op1 * op2);
    return;
}

void divide(float op1, float op2, Stack<float> &s)
{
    s.push(op2 / op1);
    return;
}

void power(float op1, float op2, Stack<float> &s)
{
    s.push(pow(op2, op1));
    return;
}

void modulus_t(float op1, float op2, Stack<float> &s)
{
    s.push((int)op2 % (int)op1);
    return;
}

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

bool isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '%')
        return true;
    return false;
}

bool isOpeningBracket(char br)
{
    if (br == '(' || br == '{' || br == '[')
        return true;
    return false;
}

bool isClosingBracket(char br)
{
    if (br == ')' || br == '}' || br == ']')
        return true;
    return false;
}

bool isBracket(char br)
{
    if (!isClosingBracket(br) && !isOpeningBracket(br))
        return false;
    return true;
}

string fixInput(string input, int &size)
{
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

            if (isClosingBracket(input[i]))
                size--;

            postfix += input[i];
            postfix += ' ';
            continue;
        }
        postfix += input[i];
    }
    size++;
    cout << postfix << "<-" << size << endl;
    return postfix;
}

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

void infixToPostfix(string infix)
{
    int stackSize = 0;
    infix = fixInput(infix, stackSize);
    cout << "Infix:\t\t" << infix << endl;

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

int main()
{
    // string infix = "12.3+3*8*(3/4-2)"; // INPUT
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