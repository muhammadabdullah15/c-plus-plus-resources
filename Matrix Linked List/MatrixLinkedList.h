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
using namespace std;

/**
 * @brief Structure to store user data
 *
 */
struct Data
{
    string phoneNumber, name, address, email;
};

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
        Data userData;
        node *up, *down, *left, *right;
        int index;
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
            cout << "Phone Number: ";
            cin >> temp.phoneNumber;
            cout << "Name: ";
            cin >> temp.name;
            cout << "Address: ";
            cin >> temp.address;
            cout << "Email: ";
            cin >> temp.email;
            addNodeAtEnd(temp);
        }
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

        node *newNode = new node;
        newNode->userData = value;

        if (isMatrixEmpty())
        {
            first = newNode;
            last = newNode;
            first->up = NULL;
            first->down = NULL;
            first->left = NULL;
            first->right = NULL;
            first->index = 0;
            last->index = 0;

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
            last->down = NULL;
            last->right = NULL;
            last->left = NULL;
            last->index = temp->index + matColumns;

            cout << "Added " << last->userData.name << "'s data at index: " << last->index << endl;

            return;
        }

        temp->right = newNode;
        last = temp->right;
        last->left = temp;
        last->index = temp->index + 1;
        last->right = NULL;
        last->down = NULL;

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
        cout << "Phone Number: ";
        cin >> value.phoneNumber;

        if (searchMatrix(value))
        {
            cout << "Phone number already exists!\nPLease try again with different number\n";
            return;
        }

        cout << "Name: ";
        cin >> value.name;
        cout << "Address: ";
        cin >> value.address;
        cout << "Email: ";
        cin >> value.email;

        cout << "Enter index to add on: ";
        cin >> index;

        if (index == last->index + 1)
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

        while (ptrTemp != NULL)
        {
            if (found)
            {
                Data temp2 = ptrTemp->userData;
                ptrTemp->userData = temp;
                temp = temp2;
            }

            if (ptrTemp->index == index)
            {
                temp = ptrTemp->userData;
                ptrTemp->userData = value;
                found = true;
            }

            if ((ptrTemp->index + 1) % matColumns == 0)
            {
                for (int k = 0; k < matColumns - 1; k++)
                    ptrTemp = ptrTemp->left;

                ptrTemp = ptrTemp->down;
                continue;
            }

            ptrTemp = ptrTemp->right;
        }

        addNodeAtEnd(temp);
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

        Data temp = last->userData;

        deleteLast();

        node *ptrTemp = last;

        while (ptrTemp != NULL)
        {
            if (ptrTemp->index == index)
            {
                cout << "Deleted " << ptrTemp->userData.phoneNumber << endl;
                ptrTemp->userData = temp;
                return;
            }

            // cout << "Swapping " << ptrTemp->userData << " and " << temp;
            Data temp2 = ptrTemp->userData;
            ptrTemp->userData = temp;
            temp = temp2;

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

        while (temp != NULL)
        {
            cout << "Node Data:" << endl
                 << "Phone Number:\t" << temp->userData.phoneNumber << endl
                 << "Name:\t\t" << temp->userData.name << endl
                 << "Address:\t\t" << temp->userData.address << endl
                 << "Email:\t\t" << temp->userData.email << endl
                 << endl;

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
             << "First Node Data:" << endl
             << "Phone Number:\t" << temp->userData.phoneNumber << endl
             << "Name:\t\t" << temp->userData.name << endl
             << "Address:\t\t" << temp->userData.address << endl
             << "Email:\t\t" << temp->userData.email << endl
             << endl
             << "Last Node Data:" << endl
             << "Phone Number:\t" << temp->userData.phoneNumber << endl
             << "Name:\t\t" << temp->userData.name << endl
             << "Address:\t\t" << temp->userData.address << endl
             << "Email:\t\t" << temp->userData.email << endl
             << endl;

        return;
    }

    /**
     * @brief
     *
     * @param searchData
     * @return true if searchData found
     * @return false if not found
     */
    bool searchMatrix(Data searchData)
    {
        if ((first->userData.address == searchData.address) || (first->userData.email == searchData.email) || (first->userData.name == searchData.name) || (first->userData.phoneNumber == searchData.phoneNumber))
        {
            cout << "Found at index 0!" << endl
                 << "Node Data:" << endl
                 << "Phone Number:\t" << first->userData.phoneNumber << endl
                 << "Name:\t\t" << first->userData.name << endl
                 << "Address:\t\t" << first->userData.address << endl
                 << "Email:\t\t" << first->userData.email << endl
                 << endl;
            return true;
        }
        else if ((last->userData.address == searchData.address) || (last->userData.email == searchData.email) || (last->userData.name == searchData.name) || (last->userData.phoneNumber == searchData.phoneNumber))
        {
            cout << "Found at index 15!" << endl
                 << "Node Data:" << endl
                 << "Phone Number:\t" << last->userData.phoneNumber << endl
                 << "Name:\t\t" << last->userData.name << endl
                 << "Address:\t\t" << last->userData.address << endl
                 << "Email:\t\t" << last->userData.email << endl
                 << endl;
            return true;
        }

        node *ptrTemp = first->right;
        while (ptrTemp != last)
        {
            if ((ptrTemp->userData.address == searchData.address) || (ptrTemp->userData.email == searchData.email) || (ptrTemp->userData.name == searchData.name) || (ptrTemp->userData.phoneNumber == searchData.phoneNumber))

            {
                cout << "Found at index " << ptrTemp->index << "!" << endl
                     << "Node Data:" << endl
                     << "Phone Number:\t" << last->userData.phoneNumber << endl
                     << "Name:\t\t" << last->userData.name << endl
                     << "Address:\t\t" << last->userData.address << endl
                     << "Email:\t\t" << last->userData.email << endl
                     << endl;
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

        while (!isMatrixEmpty())
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