#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
    struct node
    {
        T value;
        node *next;
        node *prev;
    };
    node *headNode, *tailNode;

    void reverseDisplayList(node *head)
    {
        if (head == NULL)
            return;
        reverseDisplayList(head->next);
        cout << head->value << " ";
    }

    node *reverseLinkedList(node *Node)
    {
        if (Node == NULL)
        {
            return NULL;
        }
        node *temp = Node->next;
        Node->next = Node->prev;
        Node->prev = temp;
        if (Node->prev == NULL)
        {
            return Node;
        }
        reverseLinkedList(Node->prev);
    }

    node *middleNode(node *start, node *last)
    {
        while (start->value != last->value && start->next->value != last->value)
        {
            start = start->next;
            last = last->prev;
        }
        return last;
    }

    node *BinarySearch(node *start, node *last, T val)
    {
        if (val == headNode->value)
        {
            return headNode;
        }
        if (val > last->value || val < start->value)
        {
            return NULL;
        }
        if (start == last && start->value == val)
        {
            return start;
        }
        node *mid = middleNode(start, last);
        if (mid->value == val)
        {
            return mid;
        }
        else if (mid->value > val)
        {
            return BinarySearch(start, mid, val);
        }
        else if (mid->value < val)
        {
            return BinarySearch(mid->next, last, val);
        }
        return NULL;
    }

public:
    LinkedList()
    {
        headNode = NULL;
        tailNode = NULL;
    }

    void insertAtHead(T val)
    {
        if (headNode == NULL)
        {
            node *newNode = new node();
            newNode->value = val;
            newNode->next = newNode->prev = NULL;
            headNode = newNode;
            tailNode = headNode;
            return;
        }
        node *newNode = new node();
        newNode->value = val;
        newNode->next = headNode;
        newNode->prev = NULL;
        headNode->prev = newNode;
        headNode = newNode;
    }

    void insertAtTail(T val)
    {
        if (headNode == NULL)
        {
            insertAtHead(val);
            return;
        }
        node *newNode = new node();
        newNode->value = val;
        newNode->next = NULL;
        newNode->prev = tailNode;
        tailNode->next = newNode;
        tailNode = newNode;
    }

    void addSorted(T val)
    {
        if (headNode == NULL)
        {
            insertAtHead(val);
            return;
        }

        node *newNode = new node, *temp = headNode;
        newNode->value = val;

        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                insertAtTail(val);
                return;
            }
            if (val > temp->value && val < temp->next->value)
            {
                newNode->prev = temp;
                newNode->next = temp->next;
                temp->next = newNode;
                newNode->next->prev = newNode;
                return;
            }
            if (val == temp->value)
            {
                cout << "Duplicate/n";
                return;
            }
            temp = temp->next;
        }
    }

    void BubbleSort()
    {
        node *temp = headNode;
        while (temp != NULL)
        {
            node *current = headNode;
            while (current != NULL)
            {
                if (current->value > temp->value)
                {
                    int temp = current->value;
                    current->value = temp->value;
                    temp->value = temp;
                }
                current = current->next;
            }
            temp = temp->next;
        }
    }

    void displayList()
    {
        if (headNode == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        node *temp = headNode;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void TailPrint()
    {
        if (headNode == NULL)
        {
            return;
        }
        node *temp = tailNode;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->prev;
        }
    }

    void reverse()
    {
        reverseDisplayList(headNode);
    }

    void reverseList()
    {
        headNode = reverseLinkedList(headNode);
    }

    void deleteNode(T val)
    {
        node *temp = bSearch(val);
        cout << temp->value << endl;
        if (temp == NULL)
        {
            cout << "Not Found!" << endl;
            return;
        }
        if (temp == headNode)
        {
            headNode = headNode->next;
        }
        else if (temp == tailNode)
        {
            tailNode = temp->prev;
        }
        else
        {
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
        }
    }

    node *bSearch(T val)
    {
        node *temp = BinarySearch(headNode, tailNode, val);
        return temp;
    }

    void DisplayNode(node *temp)
    {
        if (temp == NULL)
        {
            cout << "Not Found" << endl;
            return;
        }
        cout << temp->value << endl;
    }
};