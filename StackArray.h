/**
 * @file StackArray.h
 * @author Muhammad Abdullah (2021317)
 * @brief Header file for array-based stack
 * @version 1
 * @date 2022-10-21
 *
 */
#pragma once

#include <iostream>
using namespace std;

/**
 * @brief Stack Class
 *
 * @tparam t Data-type of stack
 */
template <class t>
class Stack
{
private:
    t *stack,          // Pointer to array
        *top;          // Pointer to top of stack
    int size;          // Current Size of Stack
    const int maxSize; // Max capacity of Stack

public:
    /**
     * @brief Construct a new Stack object
     *
     * @param arrSize Max Size
     */
    Stack(int arrSize) : maxSize(arrSize)
    {
        size = 0;
        top = NULL;
        stack = new t[maxSize];
    }

    /**
     * @brief Pushes passed value onto the stack
     *
     * @param value //Data to push
     */
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

    /**
     * @brief Pops top element of stack
     *
     * @return t The popped element
     */
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

    /**
     * @brief Checks if stack is empty
     *
     * @return true if stack is empty
     * @return false if stack is not empty
     */
    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }

    /**
     * @brief Checks if stack is full
     *
     * @return true if stack is full
     * @return false if stack is not full
     */
    bool isFull()
    {
        if (size == maxSize)
            return true;
        return false;
    }

    /**
     * @brief Returns top element of the stack
     *
     * @return t The top element
     */
    t peek()
    {
        if (!isEmpty())
            return *top;

        return 0;
    }

    /**
     * @brief Prints all elements of the stack
     *
     */
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