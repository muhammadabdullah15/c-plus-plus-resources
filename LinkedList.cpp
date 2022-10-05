#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct node
    {
        int data;
        node *next;
    };

    node *head;

public:
    LinkedList()
    {
        head = NULL;

        cout << "Enter number of nodes: ";
        int numNodes;
        cin >> numNodes;

        for (int i = 0; i < numNodes; i++)
        {
            cout << "Enter value for node " << i + 1 << ": ";
            int temp;
            cin >> temp;
            addNodeAtTail(temp);
        }
    }

    void addNodeAtTail(int value)
    {
        node *ptrNew = new node, *ptrTemp = head;
        ptrNew->data = value;
        ptrNew->next = NULL;
        if (head == NULL)
        {
            head = ptrNew;
            return;
        }
        while (ptrTemp->next != NULL)
            ptrTemp = ptrTemp->next;
        ptrTemp->next = ptrNew;

        return;
    }

    void addNodeSpecific()
    {
        cout << "Enter value to add after: ";
        int addAfter;
        cin >> addAfter;

        cout << "Enter value to add: ";
        int value;
        cin >> value;

        node *ptrNew = new node, *ptrTemp = head;
        ptrNew->data = value;

        while (ptrTemp->next != NULL)
        {
            if (ptrTemp->data == addAfter)
            {
                ptrNew->next = ptrTemp->next;
                ptrTemp->next = ptrNew;
                return;
            }
            ptrTemp = ptrTemp->next;
        }
        if (ptrTemp->next == NULL)
            cout << addAfter << " not found in list" << endl;

        return;
    }

    void deleteNodeSpecific()
    {
        cout << "Enter value to delete: ";
        int deleteval;
        cin >> deleteval;

        if (head->data == deleteval)
        {
            head = head->next;
            return;
        }

        node *ptrPrev, *ptrTemp = head;

        while (ptrTemp != NULL)
        {
            if (ptrTemp->data == deleteval)
            {
                ptrPrev->next = ptrTemp->next;
                return;
            }
            ptrPrev = ptrTemp;
            ptrTemp = ptrTemp->next;
        }

        if (ptrTemp->next == NULL)
            cout << deleteval << " not found in list" << endl;

        return;
    }

    void updateNodeSpecific()
    {
        cout << "Enter value to update: ";
        int update;
        cin >> update;

        node *ptrTemp = head;

        while (ptrTemp != NULL)
        {
            if (ptrTemp->data == update)
            {
                cout << "Enter new value: ";
                cin >> ptrTemp->data;
                return;
            }
            ptrTemp = ptrTemp->next;
        }
        if (ptrTemp->next == NULL)
            cout << update << " not found in list" << endl;

        return;
    }

    void isEmpty()
    {
        if (head == NULL)
            cout << "List Empty";
        else
            cout << "List not empty";

        return;
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

    void getfirst()
    {
        cout << "First value: " << head->data;
    }

    void printAll()
    {
        node *ptrTemp = head;
        cout << endl;
        while (ptrTemp != NULL)
        {
            cout << ptrTemp->data << (ptrTemp->next == NULL ? "" : ",");
            ptrTemp = ptrTemp->next;
        }
        cout << endl
             << endl;
        return;
    }
};

int main()
{
    LinkedList list;
    list.printAll();
    // list.addNodeSpecific();
    // list.deleteNodeSpecific();
    // list.updateNodeSpecific();

    // list.printAll();
    // list.isEmpty();
    // list.size();
    list.getfirst();
}