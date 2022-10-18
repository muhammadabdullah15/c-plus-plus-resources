#include <iostream>
#include <string>
#include "Stack.h"

//^,%,decimal, stack array

using namespace std;

bool hasHigherPrecedence(string a, char b)
{
    int a_prec, b_prec;

    if (a == "(" || a == ")")
        a_prec = 1;
    else if (a == "*" || a == "/")
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

string infixToPostfix(string infix)
{
    string postfix;
    Stack<string> s;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == ' ')
            continue;
        else if (isOperator(infix[i]))
        {
            while (!s.isEmpty() && hasHigherPrecedence(s.peek(), infix[i]) && !isOpeningBracket(s.peek()))
                postfix += s.pop() + ' ';
            string temp;
            temp += infix[i];
            s.push(temp);
        }
        else if (isOpeningBracket(infix[i]))
        {
            string temp;
            temp += infix[i];
            s.push(temp);
        }
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
    // Infix:          12 + 3 * 8 * ( 3 / 4 - 2)

    while (!s.isEmpty())
    {
        postfix += s.pop();
        postfix += ' ';
    }

    return postfix;
}

float postfixEvaluator(string postfix)
{
    int length_postfix;
    for (length_postfix = 0; postfix[length_postfix] != '\0'; length_postfix++)
        ;

    Stack<float> s;

    for (int i = 0; i < length_postfix; i++)
    {
        if (postfix[i] == ' ')
            continue;
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
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
            string a;
            for (; postfix[i] != ' ' && postfix[i] != '\0' && !isOperator(postfix[i]); i++)
                a += postfix[i];
            s.push(stoi(a));
        }
    }
    return s.peek();
}

string fixInput(string input)
{
    string postfix;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
            continue;
        if (isOperator(input[i]) || isBracket(input[i]))
        {
            if (!isOpeningBracket(input[i]))
                postfix += ' ';
            postfix += input[i];
            postfix += ' ';
            continue;
        }
        postfix += input[i];
    }

    return postfix;
}

int main()
{
    cout << "TEST: " << (isClosingBracket(')') ? "yes" : "no") << endl;
    string infix = "12.3+3*8*(3/4-  2)"; // INPUT

    infix = fixInput(infix);
    cout << "Infix:\t\t" << infix << endl;

    string postfix = infixToPostfix(infix);
    cout << "Postfix:\t" << postfix << endl;

    float answer = postfixEvaluator(postfix);
    cout << "Answer:\t\t" << answer << endl;

    return 0;
}