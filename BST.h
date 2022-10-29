#pragma once
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
        if (nodePtr == NULL)
            return;

        /* first delete both subtrees */
        destroySubTree(nodePtr->left);
        destroySubTree(nodePtr->right);

        /* then delete the node */
        cout << "\n Deleting node: " << nodePtr->value;
        // makeDeletion(nodePtr);
        delete nodePtr;
    }

    void deleteNode(int value, treeNode *&nodePtr)
    {
        if (value < nodePtr->value)
            deleteNode(value, nodePtr->left);
        else if (value > nodePtr->value)
            deleteNode(value, nodePtr->right);
        else
            makeDeletion(nodePtr);
    }

    void makeDeletion(treeNode *&nodePtr)
    {
        treeNode *tempPtr; // Used for reattaching left subtree

        if (!nodePtr)
        {
            cout << "Cannot delete empty node\n";
            return;
        }

        if (!nodePtr->right)
        {
            tempPtr = nodePtr;
            nodePtr = nodePtr->left; // Reattach left child
            delete tempPtr;
            return;
        }

        if (!nodePtr->left)
        {
            tempPtr = nodePtr;
            nodePtr = nodePtr->right; // Reattach right child
            delete tempPtr;
            return;
        }

        tempPtr = tempPtr->right;
        while (tempPtr->left)
            tempPtr = tempPtr->left;

        tempPtr->left = nodePtr->left; // Left subtree reattached

        tempPtr = nodePtr;
        nodePtr = nodePtr->right; // Right subtree reattached
        delete tempPtr;
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

    void displayReverseInorder(treeNode *root)
    {
        if (root)
            return;
        displayReverseInorder(root->right);
        cout << root->value << endl;
        displayReverseInorder(root->left);
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

    treeNode *lowestCommonAncestor(treeNode *root, int n1, int n2)
    {
        if (root == NULL)
            return NULL;

        // If both n1 and n2 are smaller than root, then LCA lies in left
        if (root->value > n1 && root->value > n2)
            return lowestCommonAncestor(root->left, n1, n2);

        // If both n1 and n2 are greater than root, then LCA lies in right
        if (root->value < n1 && root->value < n2)
            return lowestCommonAncestor(root->right, n1, n2);

        return root;
    }

    int getCountInRange(treeNode *root, int low, int high)
    {
        if (!root)
            return 0;

        // Special Optional case for improving efficiency
        if (root->value == high && root->value == low)
            return 1;

        // If current node is in range, then include it in count and recur for left and right children of it
        if (root->value <= high && root->value >= low)
            return 1 + getCountInRange(root->left, low, high) +
                   getCountInRange(root->right, low, high);

        // If current node is smaller than low, then recur for right child
        else if (root->value < low)
            return getCountInRange(root->right, low, high);

        // Else recur for left child
        else
            return getCountInRange(root->left, low, high);
    }

    int getCount(treeNode *root)
    {

        if (root == NULL)
            return 0;

        static int res = 1;
        if (root->left)
        {
            res++;
            getCount(root->left);
        }
        if (root->right)
        {
            res++;
            getCount(root->right);
        }
        return res;
    }

    int getHalfCount(treeNode *root)
    {
        if (root == NULL)
            return 0;

        int res = 0;
        if ((root->left == NULL && root->right != NULL) ||
            (root->left != NULL && root->right == NULL))
            res++;

        res += (getHalfCount(root->left) + getHalfCount(root->right));
        return res;
    }

    treeNode *kthSmallest(treeNode *root, int &k)
    {
        static int count = 0;
        if (root == NULL)
            return NULL;
        treeNode *left = kthSmallest(root->left, k);
        if (left != NULL)
            return left;

        count++;
        if (count == k)
            return root;

        return kthSmallest(root->right, k);
    }

    treeNode *kthLargest(treeNode *root, int k)
    {
        static int count = 0;
        if (root == NULL)
            return NULL;
        treeNode *left = kthLargest(root->right, k);
        if (left != NULL)
            return left;

        count++;
        if (count == k)
            return root;

        return kthLargest(root->left, k);
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
                cout << "Value already in tree" << endl;
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

    void printNodesReverseOrder()
    {
        displayReverseInorder(root);
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

    void remove(int num)
    {
        deleteNode(num, root);
        return;
    }

    int getLCA(int n1, int n2)
    {
        return (lowestCommonAncestor(root, n1, n2)->value);
    }

    int minValue(treeNode *node)
    {
        treeNode *temp = node;

        /* loop down to find the leftmost leaf */
        while (temp->left != NULL)
            temp = temp->left;

        return (temp->value);
    }

    int maxValue(treeNode *node)
    {
        treeNode *temp = node;

        /* loop down to find the leftmost leaf */
        while (temp->right != NULL)
            temp = temp->right;

        return (temp->value);
    }

    int getNodesInRange(int low, int high)
    {
        return getCountInRange(root, low, high);
    }

    int count()
    {
        return getCount(root);
    }

    int halfCount()
    {
        return getHalfCount(root);
    }

    int getKthSmallest(int k)
    {
        return kthSmallest(root, k)->value;
    }

    int getKthLargest(int k)
    {
        return kthLargest(root, k)->value;
    }
};