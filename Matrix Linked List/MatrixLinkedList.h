/**
 * @file MatrixLinkedList.h
 * @author Muhammad Abdullah
 * @brief Header file for Matrix Linked List
 * @version 1
 * @date 2022-10-06
 *
 */

#pragma once

#include <iostream>
#include <string>
using namespace std;

class MatrixLinkedList;

/**
 * @brief Structure to store user data
 *
 */
struct Data
{
    string phoneNumber, name, address, email;
};

/**
 * @brief Operator overloading for taking input of Data
 *
 * @param input Cin object
 * @param data Data object
 * @return istream& Input buffer
 */
istream &operator>>(istream &input, Data &data)
{
    cout << "Phone Number:\t";
    input.ignore();
    input >> data.phoneNumber;

    cout << "Name:\t\t";
    // input >> data.name;
    input.ignore();
    getline(input, data.name);

    cout << "Address:\t";
    // input >> data.address;
    // input.ignore();
    getline(input, data.address);

    cout << endl
         << "Currently: " << data.phoneNumber << "," << data.name << "," << data.address << endl
         << endl;

    cout << "Use email? (y/n): "; // Ask user if they want to enter email
    char choice;
    // cin.ignore();
    cin >> choice;
    if (choice != 'y' && choice != 'Y')
    {
        data.email = "N/A";
        return input;
    }

    cout << "Email:\t\t";
    // input.ignore();
    input >> data.email;
    return input;
}

/**
 * @brief Swap data of two Data objects
 *
 * @param a First Data
 * @param b Second Data
 */
void swapData(Data &a, Data &b)
{
    Data temp = a;
    a = b;
    b = temp;
    return;
}

/**
 * @brief Matrix class
 *
 */
class MatrixLinkedList
{
private:
    /**
     * @brief Single node of list
     *
     */
    struct node
    {
        Data userData;                  // Data structure object
        node *up, *down, *left, *right; // 4-Directional pointers
        int index;                      // Index of current node
    };

    node *first, *last;   // Pointers to first and last nodes of the matrix
    const int matRows;    // Number of rows
    const int matColumns; // Number of columns

public:
    /**
     * @brief Construct a new Matrix Linked List object
     *
     * @param rows Input number of rows
     * @param columns  Input number of columns
     */
    MatrixLinkedList(int rows, int columns) : matRows(rows), matColumns(columns)
    {
        cout << "Matrix size restricted to: " << rows << "x" << columns << endl;

        first = NULL;
        last = NULL;

        cout << "Enter initial number of nodes: ";
        int numNodes;
        cin >> numNodes;

        for (int i = 0; i < numNodes; i++)
        {
            Data temp;
            cout << "Enter values for node " << i << endl;
            cin >> temp;
            addNodeAtEnd(temp);
        }
    }

    /**
     * @brief Destroy the Matrix Linked List object by clearing all nodes
     *
     */
    ~MatrixLinkedList()
    {
        clearMatrixNodes();
    }

    /**
     * @brief Function to check whether the matrix is empty
     *
     * @return true if matrix is empty
     * @return false if matrix is not empty
     */
    bool isMatrixEmpty()
    {
        if (first == NULL)
            return true;
        return false;
    }

    /**
     * @brief Function to check whether the matrix is full
     *
     * @return true if matrix is full
     * @return false if matrix is not full
     */
    bool isMatrixFull()
    {
        if (last == NULL)
            return false;
        if (last->index == ((matRows * matColumns) - 1))
            return true;

        return false;
    }

    /**
     * @brief Function to add a new node at the end of the matrix
     *
     * @param value Data to add
     */
    void addNodeAtEnd(Data value)
    {
        if (isMatrixFull())
        {
            cout << "Matrix full! No further nodes can be added!" << endl;
            return;
        }

        if (searchMatrix(value))
        {
            cout << "Data with this Phone Number already exists! Try again with different number!\n"
                 << endl;
            return;
        }

        // Creating a new node and assigning data to it
        node *newNode = new node;
        newNode->userData = value;

        if (isMatrixEmpty())
        {
            first = last = newNode;
            first->up = first->down = first->left = first->right = NULL;
            first->index = last->index = 0;

            cout << "Added " << last->userData.name << "'s data at index: " << last->index << endl;

            return;
        }

        node *temp = last;

        if ((temp->index + 1) % matColumns == 0) // Last column (adding in new row)
        {
            for (int j = 0; j < matColumns - 1; j++)
                temp = temp->left;

            temp->down = newNode;
            last = temp->down;

            last->up = temp;
            last->down = last->right = last->left = NULL;
            last->index = temp->index + matColumns;

            cout << "Added " << last->userData.name << "'s data at index: " << last->index << endl;

            return;
        }

        // All other columns
        temp->right = newNode;
        last = temp->right;
        last->left = temp;
        last->index = temp->index + 1;
        last->right = last->down = NULL;

        last->up = NULL;

        if (last->index > matColumns)
            last->up = temp->up->right;

        if (last->index < ((matRows * matColumns)) && last->up != NULL)
            last->up->down = temp->right;

        cout << "Added " << last->userData.name << "'s data at index: " << last->index << endl;

        return;
    }

    /**
     * @brief Function to add a node at a specified index
     *
     */
    void addNodeAtSpecificIndex()
    {
        if (isMatrixFull())
        {
            cout << "Matrix full! No further nodes can be added!" << endl;
            return;
        }

        int index;
        Data value;

        cout << "Enter values for node" << endl;
        cin >> value;
        if (searchMatrix(value))
        {
            cout << "Data with this Phone Number already exists! Try again with different number!\n"
                 << endl;
            return;
        }

        cout << "Enter index to add on: ";
        cin >> index;

        if (index == last->index + 1) //Node to be added after last node
        {
            addNodeAtEnd(value);
            return;
        }
        else if (index > last->index + 1)
        {
            cout << "Cannot add directly to this index! Populate previous matrix first!\n";
            return;
        }

        node *ptrTemp = first;
        bool found = false;
        Data temp;

        while (ptrTemp != NULL) //Traversing the list
        {
            if (found)  //Swapping if data has been found
                swapData(ptrTemp->userData, temp);

            if (ptrTemp->index == index)    //Setting values when data found
            {
                temp = ptrTemp->userData;
                ptrTemp->userData = value;
                found = true;
            }

            if ((ptrTemp->index + 1) % matColumns == 0) //Last column
            {
                for (int k = 0; k < matColumns - 1; k++)
                    ptrTemp = ptrTemp->left;

                ptrTemp = ptrTemp->down;
                continue;
            }

            ptrTemp = ptrTemp->right;
        }

        addNodeAtEnd(temp); //Adding the bubbled up data as a new node to the end
        return;
    }

    /**
     * @brief Function to delete a node based on a specified index
     *
     */
    void deleteNodeSpecific()
    {
        if (isMatrixEmpty())
        {
            cout << "Matrix already empty! No further nodes can be deleted!" << endl;
            return;
        }

        int index;

        cout << "Enter index to delete: ";
        cin >> index;

        if (index == last->index || ((index == 0) && last->index == 0))
        {
            deleteLast();
            return;
        }
        else if (index > last->index)
        {
            cout << "Index doesn't exist!\n";
            return;
        }

        // Storing the last node's data and deleting it
        Data temp = last->userData; 
        deleteLast();

        node *ptrTemp = last;
        while (ptrTemp != NULL) //Reverse traversing the list while bubbling down the data
        {
            if (ptrTemp->index == index)
            {
                cout << "Deleted " << ptrTemp->userData.phoneNumber << endl;
                ptrTemp->userData = temp;
                return;
            }

            // cout << "Swapping " << ptrTemp->userData << " and " << temp;
            swapData(ptrTemp->userData, temp);

            if (ptrTemp->index % matColumns == 0)
            {
                if (ptrTemp->up == NULL)
                    break;

                ptrTemp = ptrTemp->up;

                for (int i = 0; i < matColumns - 1; i++)
                    ptrTemp = ptrTemp->right;

                continue;
            }

            ptrTemp = ptrTemp->left;
        }
        return;
    }

    /**
     * @brief Displays data of node
     *
     * @param temp node to display data of
     */
    void displayNode(node *temp)
    {
        cout << "Node Data:" << endl
             << "Phone Number:\t" << temp->userData.phoneNumber << endl
             << "Name:\t\t" << temp->userData.name << endl
             << "Address:\t" << temp->userData.address << endl
             << "Email:\t\t" << temp->userData.email << endl
             << endl;
    }

    /**
     * @brief Function to print all nodes of matrix
     *
     */
    void printMatrix()
    {
        cout << "\n\nPrinting Matrix....\n\n";

        if (isMatrixEmpty())
        {
            cout << "Empty Matrix!" << endl;
            return;
        }

        node *temp = first;

        while (temp != NULL)    //Traversing list and printing all data of relevant node
        {
            displayNode(temp);

            if ((temp->index + 1) % matColumns == 0 && temp->index > 0)
            {
                // cout << endl;
                for (int j = 0; j < matColumns - 1; j++)
                    temp = temp->left;
                temp = temp->down;

                if (temp == NULL)
                    break;

                continue;
            }

            temp = temp->right;
        }

        cout << endl
             << endl
             << "First Node Data:";
        displayNode(first);
        cout << "Last Node Data:" << endl;
        displayNode(last);

        return;
    }

    /**
     * @brief
     *
     * @param searchData
     * @return true if searchData found
     * @return false if searchData not found
     */
    bool searchMatrix(Data searchData)
    {
        node *ptrTemp = first;
        while (ptrTemp != NULL) //Traversing until match found
        {
            if ((ptrTemp->userData.address == searchData.address) || (ptrTemp->userData.email == searchData.email) || (ptrTemp->userData.name == searchData.name) || (ptrTemp->userData.phoneNumber == searchData.phoneNumber))

            {
                cout << "Found at index " << ptrTemp->index << "!" << endl
                     << "Node Data:" << endl;
                displayNode(ptrTemp);
                return true;
            }

            if ((ptrTemp->index + 1) % matColumns == 0)
            {
                for (int k = 0; k < matColumns - 1; k++)
                    ptrTemp = ptrTemp->left;

                if (ptrTemp->down == NULL)
                    break;

                ptrTemp = ptrTemp->down;
                continue;
            }
            ptrTemp = ptrTemp->right;
        }

        // cout << "User Data not found!\n";
        return false;
    }

    /**
     * @brief Function to delete all matrix nodes
     *
     */
    void clearMatrixNodes()
    {
        if (isMatrixEmpty())
        {
            cout << "Matrix already empty!" << endl;
            return;
        }

        while (!isMatrixEmpty())    //Deleting last nodes until matrix empty
            deleteLast();

        return;
    }

    /**
     * @brief Function to delete the last node of the matrix
     *
     */
    void deleteLast()
    {
        if (isMatrixEmpty())
            cout << "Matrix empty!" << endl;

        cout << "Deleted: " << last->userData.phoneNumber << "'s data" << endl;

        if (first == last)
        {
            first = last = NULL;
            return;
        }

        node *temp = last;
        if (temp->index % matColumns == 0) // first column
        {
            temp = temp->up;
            temp->down = NULL;

            for (int k = 0; k < matColumns - 1; k++)
                temp = temp->right;

            last = temp;
            last->index = temp->index;
            return;
        }

        temp = last->left;
        // if (temp->right->right != NULL)
        // {
        //     temp->right->right->left = NULL;
        //     temp->right->right = NULL;
        // }

        // if (temp->up != NULL)
        // {
        //     temp->right->up->down = NULL;
        //     temp->right->up = NULL;
        // }

        // temp->right->left = NULL;
        temp->right = NULL;

        last = temp;
        // temp->right = NULL;
        last->index = temp->index;

        return;
    }
};