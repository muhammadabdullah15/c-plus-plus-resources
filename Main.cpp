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

bool isOperation(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '$')
        return true;
    return false;
}

string infixToPostfix(string infix)
{
    string postfix;
    Stack<string> s;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == ' ')
            continue;
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (!s.isEmpty() && hasHigherPrecedence(s.peek(), infix[i]) && s.peek() != "(")
                postfix += s.pop() + ' ';
            string temp;
            temp += infix[i];
            s.push(temp);
        }
        else if (infix[i] == '(')
        {
            string temp;
            temp += infix[i];
            s.push(temp);
        }
        else if (infix[i] == ')')
        {
            while (!s.isEmpty() && s.peek() != "(")
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
            for (; postfix[i] != ' ' && postfix[i] != '\0'; i++)
                a += postfix[i];
            s.push(stoi(a));
        }
    }
    return s.peek();
}

int main()
{
    string infix = "12.3 + 3 * 8 * ( 3 / 4 - 2 )";
    string postfix = infixToPostfix(infix);
    float answer = postfixEvaluator(postfix);

    cout << "Infix:\t\t" << infix << endl
         << "Postfix:\t" << postfix << endl
         << "Answer:\t\t" << answer << endl;

    return 0;
}