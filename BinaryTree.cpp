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
};

int main()
{
    BinaryTree tree;
    cout << "Inserting nodes. ";
    tree.insertNode(5);
    tree.insertNode(8);
    tree.insertNode(3);
    tree.insertNode(12);
    tree.insertNode(9);
    tree.printNodesInOrder();
    return 0;
}
