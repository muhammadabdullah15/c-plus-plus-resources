#include <iostream>
using namespace std;

// const int MatSize = 4;

class MatrixLinkedList
{
private:
    struct node
    {
        int data, index;
        node *up, *down, *left, *right;
    };

    node *first, *last;
    const int matRows;
    const int matColumns;

public:
    MatrixLinkedList(int rows, int columns) : matRows(rows), matColumns(columns)
    {
        first = NULL;
        last = NULL;

        cout << "Enter initial number of nodes: ";
        int numNodes;
        cin >> numNodes;

        for (int i = 0; i < numNodes; i++)
        {
            cout << "Enter value for node " << i << ": ";
            int value;
            cin >> value;
            addNodeAtEnd(value);
        }
    }

    MatrixLinkedList(int rows, int columns, int numNodes) : matRows(rows), matColumns(columns)
    {
        cout << "Matrix size restricted to: " << rows << "x" << columns << endl;

        first = NULL;
        last = NULL;

        for (int i = 0; i < numNodes; i++)
            addNodeAtEnd(i);
    }

    bool isMatrixEmpty()
    {
        if (first == NULL)
            return true;
        return false;
    }

    bool isMatrixFull()
    {
        if (last == NULL)
            return false;
        if (last->index == ((matRows * matColumns) - 1))
            return true;

        return false;
    }

    void addNodeAtEnd(int value)
    {
        if (isMatrixFull())
        {
            cout << "Matrix full! No further nodes can be added!" << endl;
            return;
        }

        node *newNode = new node;
        newNode->data = value;

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

            cout << "Added " << last->data << " at index: " << last->index << endl;

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

            cout << "Added " << last->data << " at index: " << last->index << endl;

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

        cout << "Added " << last->data << " at index: " << last->index << endl;

        return;
    }

    void addNodeAtSpecificIndex()
    {
        if (isMatrixFull())
        {
            cout << "Matrix full! No further nodes can be added!" << endl;
            return;
        }

        int value, index;
        cout << "Enter value to add: ";
        cin >> value;

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
        int temp;

        while (ptrTemp != NULL)
        {
            if (found)
            {
                int temp2 = ptrTemp->data;
                ptrTemp->data = temp;
                temp = temp2;
            }

            if (ptrTemp->index == index)
            {
                temp = ptrTemp->data;
                ptrTemp->data = value;
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

    void deleteNodeSpecific()
    {
        if (isMatrixEmpty())
        {
            cout << "Matrix already empty! No further nodes can be deleted!" << endl;
            return;
        }

        int value, index;

        cout << "Enter index to delete: ";
        cin >> index;

        if (index == last->index || ((index == 0) && last->index == 0))
        {
            cout << "delete last waala";
            deleteLast();
            return;
        }
        else if (index > last->index + 1)
        {
            cout << "Index doesn't exist!\n";
            return;
        }

        int temp = last->data;

        deleteLast();

        node *ptrTemp = last;

        while (ptrTemp != NULL)
        {
            if (ptrTemp->index == index)
            {
                ptrTemp->data = temp;
                return;
            }

            cout << "Swapping " << ptrTemp->data << " and " << temp;
            int temp2 = ptrTemp->data;
            ptrTemp->data = temp;
            temp = temp2;

            if (ptrTemp->index % matColumns == 0)
            {
                /*if (ptrTemp->up == NULL)
                    break;*/
                ptrTemp = ptrTemp->up;
                continue;
            }

            ptrTemp = ptrTemp->left;
        }
        return;
    }

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
            cout << temp->data << "\t";

            if ((temp->index + 1) % matColumns == 0 && temp->index > 0)
            {
                cout << endl;
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
             << "First data: " << first->data << endl
             << "Last data: " << last->data << endl
             << endl;

        return;
    }

    void printAllLinks()
    {
        cout << "\n\nPrinting Matrix Links....\n\n";

        if (isMatrixEmpty())
        {
            cout << "Empty Matrix!" << endl;
            return;
        }

        node *temp = first;
        while (temp != NULL)
        {
            cout << endl
                 << "Element " << temp->index << endl;

            if (temp->up == NULL)
                cout << "\tNULL\n";
            else
                cout << "\t" << temp->up->data << endl;

            if (temp->left == NULL)
                cout << "NULL";
            else
                cout << temp->left->data;

            cout << "\t" << temp->data;

            if (temp->right == NULL)
                cout << "\tNULL\n";
            else
                cout << "\t" << temp->right->data << endl;

            if (temp->down == NULL)
                cout << "\tNULL\n";
            else
                cout << "\t" << temp->down->data << endl;

            if ((temp->index + 1) % matColumns == 0 && temp->index > 0)
            {
                cout << endl;
                for (int j = 0; j < matColumns - 1; j++)
                    temp = temp->left;
                temp = temp->down;

                continue;
            }

            temp = temp->right;
        }

        return;
    }

    void searchMatrix()
    {
        cout << "Enter node value to search: ";
        int nodeData;
        cin >> nodeData;

        if (first->data == nodeData)
        {
            cout << "Found at index 0!\n";
            return;
        }
        else if (last->data == nodeData)
        {
            cout << "Found at index 15!\n";
            return;
        }

        node *ptrTemp = first->right;
        while (ptrTemp != last)
        {
            if (ptrTemp->data == nodeData)
            {
                cout << "Found at index " << ptrTemp->index << "!\n";
                return;
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

        cout << "Data not found!\n";
        return;
    }

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

    void deleteLast()
    {
        if (isMatrixEmpty())
            cout << "Matrix empty!" << endl;

        cout << "Deleted: " << last->data << endl;

        if (first == last)
        {
            first = last = NULL;
            return;
        }

        node *temp = last;
        if (temp->index % matColumns == 0) // first column
        {
            temp = temp->up;
            temp->down->up = NULL;
            temp->down = NULL;

            for (int k = 0; k < matColumns - 1; k++)
                temp = temp->right;

            last = temp;
            return;
        }

        temp = last->left;
        if (temp->right->right != NULL)
        {
            temp->right->right->left = NULL;
            temp->right->right = NULL;
        }

        if (temp->up != NULL)
        {
            temp->right->up->down = NULL;
            temp->right->up = NULL;
        }

        temp->right->left = NULL;
        temp->right = NULL;

        last = temp;
        last->index = temp->index;

        return;
    }
};

int main()
{

    MatrixLinkedList list(4, 4);
    // MatrixLinkedList list(5, 6, 30);
    list.printMatrix();

    list.printMatrix();
    list.deleteNodeSpecific();
    system("pause");
    system("CLS");

    list.printMatrix();
    list.deleteNodeSpecific();
    system("pause");
    system("CLS");

    list.printMatrix();
    list.deleteNodeSpecific();
    system("pause");
    system("CLS");

    list.printMatrix();
    list.deleteNodeSpecific();
    system("pause");
    system("CLS");

    list.printMatrix();
    list.deleteNodeSpecific();
    system("pause");
    system("CLS");

    /*for (int i = 0; i <= 17; i++)
    {
        MatrixLinkedList list(4, 4, i);
         list.printMatrix();
         list.printAllLinks();

         system("pause");
         system("CLS");
     }*/

    return 0;
}