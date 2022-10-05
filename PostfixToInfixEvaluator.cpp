#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    struct node
    {
        int data;
        node *next;
    };

    node *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(int value)
    {
        node *ptrNew = new node, *ptrTemp = head;
        ptrNew->data = value;
        ptrNew->next = NULL;

        if (head == NULL)
        {
            head = ptrNew;
            printAll();

            return;
        }

        ptrNew->next = head;
        head = ptrNew;

        printAll();

        return;
    }

    int pop()
    {

        if (isEmpty())
        {
            cout << "Stack Empty!" << endl;
            printAll();

            return -1;
        }
        int value = head->data;

        head = head->next;
        printAll();

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

    int peek()
    {
        if (!isEmpty())
            return head->data;

        return -1;
    }

    void printAll()
    {
        node *ptrTemp = head;
        cout << endl
             << "Stack:   ";
        while (ptrTemp != NULL)
        {
            cout << ptrTemp->data << ' ';
            ptrTemp = ptrTemp->next;
        }
        //        cout << endl;
        return;
    }
};

int postfixToInfix(string postfix)
{
    cout << "Converting " << postfix << " to Infix" << endl;
    int length_postfix;
    for (length_postfix = 0; postfix[length_postfix] != '\0'; length_postfix++)
        ;

    Stack s;

    for (int i = 0; i < length_postfix; i++)
    {
        if (postfix[i] == ' ')
            continue;
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            int operand1 = s.pop();
            int operand2 = s.pop();

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
            if (postfix[i + 1] != ' ' && postfix[i + 1] != '\0')
            {
                string a;
                a += postfix[i];
                a += postfix[i + 1];
                s.push(stoi(a));
                i++;
            }
            else
            {
                string temp;
                temp += postfix[i];

                s.push(stoi(temp));
            }
        }
    }
    return s.peek();
}

int main()
{
    cout << "\n\nFinal Answer: " << postfixToInfix("12 7 3 - / 2 1 5 + * +");
}
