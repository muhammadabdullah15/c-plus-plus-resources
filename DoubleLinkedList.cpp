#include <iostream>
using namespace std;

class DoubleLinkedList
{
private:
    struct node
    {
        int data;
        node *next, *prev;
    };

    node *head;
    node *tail;

public:
    DoubleLinkedList()
    {
        head = NULL;
        tail = NULL;

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
        node *ptrTemp = new node;
        ptrTemp->data = value;
        ptrTemp->prev = tail;
        if (head == NULL)
        {
            tail = ptrTemp;
            head = ptrTemp;
            return;
            // head->next = NULL;
        }

        tail->next = ptrTemp;
        tail = ptrTemp;
        tail->next = NULL;

        return;
    }

    void updateSpecific()
    {
        cout << "Enter node value to update: ";
        int node_value;
        cin >> node_value;

        node *ptrTemp = head;
        while (ptrTemp != NULL)
        {
            if (ptrTemp->data == node_value)
            {
                cout << "Enter new value: ";
                cin >> ptrTemp->data;
                return;
            }
            ptrTemp = ptrTemp->next;
        }

        cout << "Value not found in list!\n";
        return;
    }

    void deleteSpecific()
    {
        cout << "Enter node value to delete: ";
        int node_value;
        cin >> node_value;

        node *ptrTemp = head;
        while (ptrTemp != NULL)
        {
            if (ptrTemp->data == node_value)
            {
                ptrTemp->next->prev = ptrTemp->prev;
                ptrTemp->prev->next = ptrTemp->next;
                ptrTemp = NULL;
                return;
            }
            ptrTemp = ptrTemp->next;
        }

        cout << "Value not found in list!\n";
        return;
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
    DoubleLinkedList list;
    list.printAll();

    list.deleteSpecific();
    list.printAll();

    return 0;
}

