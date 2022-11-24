#pragma once
#include <iostream>
#include <math.h>
#include "LinkedList.h"
using namespace std;

template <typename T>
class Hashing
{
private:
    LinkedList<T> *arr;
    const string mode;
    const int slots;

    int hash(T key)
    {
        if (mode == "division")
            return (key % slots);
        else if (mode == "multiplication")
            return (floor(slots * (fmod(0.618033 * key, 1))));
        else
            return 0;
    }

public:
    Hashing(int arrSlots) : slots(arrSlots), mode("division") { arr = new LinkedList<int>[slots]; }

    Hashing(int arrSlots, string hashMode) : slots(arrSlots), mode(hashMode) { arr = new LinkedList<int>[slots]; }

    void insert(T key) { arr[hash(key)].addNodeAtTail(key); }

    bool search(T key) { return arr[hash(key)]->search(key); }

    void displayAll()
    {
        for (int i = 0; i < slots; i++)
        {
            cout << "SLOT " << i << (i > 9 ? ":\t" : ":\t\t");
            arr[i].printAll();
            cout << endl;
        }
    }
};
