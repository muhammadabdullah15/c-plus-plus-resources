#pragma once

#include <iostream>
using namespace std;

template <class t>
class Stack
{
private:
    t *stack, *top;
    int size;
    const int maxSize;

public:
    Stack(int arrSize) : maxSize(arrSize)
    {
        size = 0;
        top = NULL;
        stack = new t[maxSize];
    }

    void push(t value)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        stack[size++] = value;
        top = (stack + size - 1);
        return;
    }

    t pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return 0;
        }

        size--;
        t value = stack[size];
        top = stack + size - 1;

        return value;
    }

    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }

    bool isFull()
    {
        if (size == maxSize)
            return true;
        return false;
    }

    t peek()
    {
        if (!isEmpty())
            return *top;

        return 0;
    }

    void printAll()
    {
        cout << endl;
        for (int i = size - 1; i >= 0; i--)
            cout << stack[i] << ((i == 0) ? "" : ",");
        cout << endl
             << endl;
        return;
    }
};