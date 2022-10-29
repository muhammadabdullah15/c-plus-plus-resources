#pragma once
#include <iostream>
using namespace std;

class Set
{
private:
    struct node
    {
        int value;
        node *next;
        node *prev;
    };

    node *headNode;

public:
    Set()
    {
        headNode = NULL;
    }

    void insertAtTail(int val)
    {
        node *newNode = new node;
        newNode->value = val;
        newNode->next = NULL;

        if (headNode == NULL)
        {
            headNode = newNode;
            return;
        }

        node *temp = headNode;
        while (temp->next)
        {
            if (temp->value == val || temp->next->value == val)
            {
                cout << "Duplicate\n";
                return;
            }
            temp = temp->next;
        }

        temp->next = newNode;
        // cout << "Added " << val << endl;
        return;
    }

    void displayList()
    {
        if (headNode == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        cout << "{";
        node *temp = headNode;
        while (temp != NULL)
        {
            cout << temp->value << (temp->next ? "," : "}");
            temp = temp->next;
        }
        cout << endl;
    }

    node *search(int val)
    {
        node *temp = headNode;
        while (temp)
        {
            if (temp->value == val)
                return temp;
            temp = temp->next;
        }
        return NULL;
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

    void BubbleSort()
    {
        node *traverse = headNode;
        while (traverse != NULL)
        {
            node *current = headNode;
            while (current != NULL)
            {
                if (current->value > traverse->value)
                {
                    int temp = current->value;
                    current->value = traverse->value;
                    traverse->value = temp;
                }
                current = current->next;
            }
            traverse = traverse->next;
        }
    }

    Set *unionUnsorted(Set b)
    {
        node *tempA = this->headNode, *tempB = b.headNode;
        Set *result = new Set;
        while (tempA)
        {
            result->insertAtTail(tempA->value);
            tempA = tempA->next;
        }
        while (tempB)
        {
            result->insertAtTail(tempB->value);
            tempB = tempB->next;
        }

        return result;
    }

    Set *unionSorted(Set b)
    {
        node *tempA = this->headNode, *tempB = b.headNode;
        Set *result = new Set;
        while (tempA || tempB)
        {
            if (!tempA)
            {
                result->insertAtTail(tempB->value);
                tempB = tempB->next;
                continue;
            }

            if (!tempB)
            {
                result->insertAtTail(tempA->value);
                tempA = tempA->next;
                continue;
            }

            if (tempA && (tempA->value < tempB->value))
            {
                result->insertAtTail(tempA->value);
                tempA = tempA->next;
                continue;
            }

            if (tempB && (tempB->value < tempA->value))
            {
                result->insertAtTail(tempB->value);
                tempB = tempB->next;
                continue;
            }
        }
        return result;
    }
    Set *intersectionUnsorted(Set b)
    {
        node *tempA = this->headNode;
        Set *result = new Set;
        while (tempA)
        {
            node *tempB = b.headNode;
            while (tempB)
            {
                if (tempA->value == tempB->value)
                {
                    result->insertAtTail(tempA->value);
                    break;
                }
                tempB = tempB->next;
            }
            tempA = tempA->next;
        }
        return result;
    }

    Set *intersectionSorted(Set b)
    {
        node *tempa = this->headNode;
        Set *result = new Set;
        while (tempa)
        {
            node *tempb = b.headNode;
            while (tempb && (tempa->value >= tempb->value))
            {
                if (tempa->value == tempb->value)
                {
                    result->insertAtTail(tempa->value);
                    break;
                }

                tempb = tempb->next;
            }
            tempa = tempa->next;
        }
        return result;
    }
    Set *Minus(Set b)
    {
        node *tempA = this->headNode;
        Set *result = new Set;
        bool found = false;
        while (tempA)
        {
            found = false;
            node *tempB = b.headNode;
            while (tempB)
            {
                if (tempA->value == tempB->value)
                {
                    found = true;
                    break;
                }
                tempB = tempB->next;
            }
            if (!found)
                result->insertAtTail(tempA->value);
            tempA = tempA->next;
        }
        return result;
    }

    bool isSubset(Set b)
    {
        node *tempA = this->headNode;
        while (tempA)
        {
            node *tempB = b.headNode;
            bool found = false;
            while (tempB)
            {
                if (tempA->value == tempB->value)
                {
                    found = true;
                    break;
                }
                tempB = tempB->next;
            }
            if (!found)
                return false;
            tempA = tempA->next;
        }
        return true;
    }
};