#pragma once
#include <iostream>
using namespace std;

template <class T>
class Avl
{
private:
    struct AvlNode
    {
        T data;
        AvlNode *left, *right;
        int height;
    };

    AvlNode *root;

    int max(int a, int b)
    {
        if (a > b)
            return a;
        return b;
    }

    int height(AvlNode *position)
    {
        if (position)
            return position->height;
        return -1;
    }

    AvlNode *insert(T val, AvlNode *node)
    {
        if (!node)
        {
            node = new AvlNode;
            node->data = val;
            node->height = 0;
            node->left = node->right = NULL;
        }

        else if (val < node->data)
        {
            node->left = insert(val, node->left);
            if (height(node->left) - height(node->right) == 2)
            {
                if (val < node->left->data)
                    node = singleRotationWithLeft(node);
                else
                    node = doubleRotationWithLeft(node);
            }
        }
        else if (val > node->data)
        {

            node->right = insert(val, node->right);
            if (height(node->right) - height(node->left) == 2)
            {
                if (val > node->right->data)
                    node = singleRotationWithRight(node);
                else
                    node = doubleRotationWithRight(node);
            }
        }
        else
            cout << "Duplicate Value\n";

        node->height = max(height(node->left), height(node->right)) + 1;
        return node;
    }

    AvlNode *singleRotationWithLeft(AvlNode *k2)
    {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), height(k2)) + 1;
        return k1;
    }

    AvlNode *singleRotationWithRight(AvlNode *k1)
    {
        AvlNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->right), height(k1)) + 1;
        return k2;
    }

    AvlNode *doubleRotationWithLeft(AvlNode *k3)
    {
        k3->left = singleRotationWithRight(k3->left);
        return singleRotationWithLeft(k3);
    }

    AvlNode *doubleRotationWithRight(AvlNode *k1)
    {
        k1->right = singleRotationWithLeft(k1->right);
        return singleRotationWithRight(k1);
    }

    AvlNode *makeEmpty(AvlNode *node)
    {
        return NULL;
    }

    AvlNode *search(T val, AvlNode *node)
    {
        while (node)
        {
            if (node->data == val)
                return node;
            else if (val < node->data)
                node = node->left;
            else
                node = node->right;
        }
        return NULL;
    }

    AvlNode *deleteNode(T val, AvlNode *node)
    {
        return NULL;
    }

    AvlNode *getMin(AvlNode *node)
    {
        while (node->left)
            node = node->left;
        return node;
    }

    AvlNode *getMax(AvlNode *node)
    {
        while (node->right)
            node = node->right;
        return node;
    }

    void displayInOrder(AvlNode *nodePtr)
    {
        if (nodePtr)
        {
            displayInOrder(nodePtr->left);
            cout << nodePtr->data << ", ";
            displayInOrder(nodePtr->right);
        }

        return;
    }

    void displayReverseInOrder(AvlNode *nodePtr)
    {
        if (!nodePtr)
            return;
        displayReverseInOrder(nodePtr->right);
        cout << nodePtr->data << ", ";
        displayReverseInOrder(nodePtr->left);
    }

    void displayPreOrder(AvlNode *nodePtr)
    {
        if (nodePtr)
        {
            cout << nodePtr->data << ", ";

            displayPreOrder(nodePtr->left);
            displayPreOrder(nodePtr->right);
        }

        return;
    }

    void displayPostOrder(AvlNode *nodePtr)
    {
        if (nodePtr)
        {
            displayPostOrder(nodePtr->left);
            displayPostOrder(nodePtr->right);
            cout << nodePtr->data << ", ";
        }

        return;
    }

public:
    Avl()
    {
        root = NULL;
    }

    ~Avl()
    {
        makeEmpty(root);
    }

    void insertValue(T val)
    {
        root = insert(val, root);
        return;
    }

    void searchValue(T val)
    {
        if (search(val, root))
            cout << "Found\n";
        else
            cout << "Not Found\n";
        return;
    }

    void printNodesInOrder()
    {
        displayInOrder(root);
        return;
    }

    void printNodesPreOrder()
    {
        displayPreOrder(root);
        return;
    }

    void printNodesPostOrder()
    {
        displayPostOrder(root);
        return;
    }

    void printNodesReverseOrder()
    {
        displayReverseInOrder(root);
        return;
    }

    T min()
    {
        return getMin(root)->data;
    }

    T max()
    {
        return getMax(root)->data;
    }
};