#include <iostream>
#include <string>
#include "Stack.h"

//^,%, stack array

using namespace std;

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
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '$')
        return true;
    return false;
}

bool isOpeningBracket(char br)
{
    if (br == '(' || br == '{' || br == '[')
        return true;
    return false;
}

bool isOpeningBracket(string br)
{
    if (br == "(" || br == "{" || br == "[")
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
                // cout << "Incremented size when char=" << input[i] << endl;
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
                s.push(operand1 + operand2);
            else if (postfix[i] == '-')
                s.push(operand2 - operand1);
            else if (postfix[i] == '*')
                s.push(operand1 * operand2);
            else if (postfix[i] == '/')
                s.push(operand2 / operand1);
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
    string infix = "12.3+3*8*(3/4-2)"; // INPUT
    infixToPostfix(infix);
    return 0;
}