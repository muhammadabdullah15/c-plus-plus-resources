#include <iostream>
using namespace std;

class BinaryTree
{
private:
    struct treeNode
    {
        int value;
        treeNode *left, *right;
    };

    treeNode *root;

    void destroySubTree(treeNode *nodePtr)
    {
        return;
    }

    void deleteNode(int value, treeNode *&nodePtr)
    {
        return;
    }

    void makeDeletion(treeNode *&nodePtr)
    {
        return;
    }

    void displayInOrder(treeNode *nodePtr)
    {
        if (nodePtr)
        {
            displayInOrder(nodePtr->left);
            cout << nodePtr->value << endl;
            displayInOrder(nodePtr->right);
        }

        return;
    }

    void displayPreOrder(treeNode *nodePtr)
    {
        if (nodePtr)
        {
            cout << nodePtr->value << endl;
            displayPreOrder(nodePtr->left);
            displayPreOrder(nodePtr->right);
        }

        return;
    }

    void displayPostOrder(treeNode *nodePtr)
    {
        if (nodePtr)
        {
            displayPostOrder(nodePtr->left);
            displayPostOrder(nodePtr->right);
            cout << nodePtr->value << endl;
        }

        return;
    }

public:
    BinaryTree()
    {
        root = NULL;
    }

    ~BinaryTree()
    {
        destroySubTree(root);
    }

    void insertNode(int value)
    {
        treeNode *newnode, *tempPtr;

        newnode = new treeNode;
        newnode->value = value;
        newnode->left = newnode->right = NULL;

        if (!root)
        {
            root = newnode;
            return;
        }

        tempPtr = root;
        while (tempPtr)
        {
            if (value < tempPtr->value)
            {
                if (tempPtr->left)
                    tempPtr = tempPtr->left;
                else
                {
                    tempPtr->left = newnode;
                    return;
                }
            }
            else if (value > tempPtr->value)
            {
                if (tempPtr->right)
                    tempPtr = tempPtr->right;
                else
                {
                    tempPtr->right = newnode;
                    return;
                }
            }
            else
            {
                cout << "03074344309 Lun na khara hone ki surat mein iss number pe rabta karein ~ Umer Tayyab";
                return;
            }
        }

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

    bool searchNode(int value)
    {
        treeNode *tempPtr = root;
        while (tempPtr)
        {
            if (tempPtr->value == value)
                return true;
            else if (value < tempPtr->value)
                tempPtr = tempPtr->left;
            else
                tempPtr = tempPtr->right;
        }
        return false;
    }

    
};

int main()
{
    return 0;
}
