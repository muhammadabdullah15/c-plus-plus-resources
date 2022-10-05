#include <iostream>
#include <string    >
using namespace std;

class Stack
{
private:
    struct node
    {
        string data;
        node *next;
    };

    node *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(string value)
    {
        node *ptrNew = new node, *ptrTemp = head;
        ptrNew->data = value;
        ptrNew->next = NULL;

        if (head == NULL)
        {
            head = ptrNew;
            return;
        }

        ptrNew->next = head;
        head = ptrNew;
        return;
    }

    void push(char value)
    {
        node *ptrNew = new node, *ptrTemp = head;
        ptrNew->data = value;
        ptrNew->next = NULL;

        if (head == NULL)
        {
            head = ptrNew;
            return;
        }

        ptrNew->next = head;
        head = ptrNew;
        return;
    }

    string pop()
    {

        if (isEmpty())
        {
            cout << "Stack Empty!" << endl;
            return "";
        }
        string value = head->data;

        head = head->next;
        return value;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }

    void size()
    {
        int size = 0;

        node *ptrTemp = head;

        while (ptrTemp != NULL)
        {
            size++;
            ptrTemp = ptrTemp->next;
        }

        cout << size << " elements in list";
        return;
    }

    string peek()
    {
        if (!isEmpty())
            return head->data;

        return "";
    }

    void printAll()
    {
        node *ptrTemp = head;
        cout << endl;
        while (ptrTemp != NULL)
        {
            cout << ptrTemp->data;
            ptrTemp = ptrTemp->next;
        }
        cout << endl
             << endl;
        return;
    }
};

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

string infixToPostfix(string infix)
{
    cout << "Converting " << infix << " to Postfix:" << endl;

    int infix_length;
    for (infix_length = 0; infix[infix_length] != '\0'; infix_length++)
        ;

    string postfix;
    Stack s;

    for (int i = 0; i < infix_length; i++)
    {
        if (infix[i] == ' ')
            continue;
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (!s.isEmpty() && hasHigherPrecedence(s.peek(), infix[i]) && s.peek() != "(")
                postfix += s.pop();
            s.push(infix[i]);
        }
        else if (infix[i] == '(')
            s.push(infix[i]);
        else if (infix[i] == ')')
        {
            while (!s.isEmpty() && s.peek() != "(")
                postfix += s.pop();
            s.pop();
        }
        else
            postfix += infix[i];
    }

    while (!s.isEmpty())
        postfix += s.pop();

    return postfix;
}

int main()
{
    cout << "Enter infix expression (with spaces): ";
    string infix;
    std::getline(cin, infix);
    cout << infixToPostfix(infix);
}
