#include <iostream>
#include <windows.h>
#include <conio.h>

#include "MatrixLinkedList.h"

using namespace std;
/**
 * @brief Provides scrollable menu for add-to-matrix options
 *
 * @param matrix Pointer to matrix object
 */
void addMenu(MatrixLinkedList *matrix)
{
    int Set[] = {12, 7, 7}; // DEFAULT COLORS
    int counter = 1;
    char key;

    while (true)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "Please choose from the following options:" << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[0]);
        cout << "1) Add at end";

        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[1]);
        cout << "2) Add at specific index";

        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[2]);
        cout << "3) Return to previous menu";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        cout << endl;

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 3))
            counter--;
        if (key == 80 && (counter >= 1 && counter <= 2))
            counter++;
        if (key == '\r') // ENTER KEY
        {
            switch (counter)
            {
            case 1:
                system("cls");
                {
                    Data temp;
                    cin >> temp;
                    matrix->addNodeAtEnd(temp);
                    system("pause");
                }
                break;
            case 2:
                system("cls");
                matrix->addNodeAtSpecificIndex();
                system("pause");
                break;
            case 3:
                system("cls");
                // system("pause");
                return;
            }
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;

        Set[counter - 1] = 12;
    }
}

/**
 * @brief Provides scrollable menu for delete-from-matrix options
 *
 * @param matrix Pointer to matrix object
 */
void deleteMenu(MatrixLinkedList *matrix)
{
    int Set[] = {12, 7, 7}; // DEFAULT COLORS
    int counter = 1;
    char key;

    while (true)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "Please choose from the following options:" << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[0]);
        cout << "1) Remove last";

        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[1]);
        cout << "2) Remove specific index";

        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[2]);
        cout << "3) Return to previous menu";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        cout << endl;

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 3))
            counter--;
        if (key == 80 && (counter >= 1 && counter <= 2))
            counter++;
        if (key == '\r') // ENTER KEY
        {
            switch (counter)
            {
            case 1:
                system("cls");
                matrix->deleteLast();
                system("pause");
                break;
            case 2:
                system("cls");
                matrix->deleteNodeSpecific();
                system("pause");
                break;
            case 3:
                system("cls");
                system("pause");
                return;
            }
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;

        Set[counter - 1] = 12;
    }
}

/**
 * @brief Provides scrollable menu for searh-matrix options
 *
 * @param matrix Pointer to matrix object
 */
void searchMenu(MatrixLinkedList *matrix)
{
    Data searchData;
    searchData.address = searchData.email = searchData.name = "";

    int Set[] = {12, 7, 7, 7}; // DEFAULT COLORS
    int counter = 1;
    char key;

    while (true)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "Please choose from the following options:" << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[0]);
        cout << "1) Search by Name";

        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[1]);
        cout << "2) Search by Address";

        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[2]);
        cout << "3) Search by Email";

        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[3]);
        cout << "4) Return to previous menu";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        cout << endl;

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 4))
            counter--;
        if (key == 80 && (counter >= 1 && counter <= 3))
            counter++;
        if (key == '\r') // ENTER KEY
        {
            switch (counter)
            {
            case 1:
            {
                system("cls");
                cout << "Enter name to search: ";
                cin >> searchData.name;
                if (!matrix->searchMatrix(searchData))
                    cout << "User data not found!\n";
                system("pause");
                break;
            }
            case 2:
            {
                system("cls");
                cout << "Enter address to search: ";
                cin >> searchData.address;
                if (!matrix->searchMatrix(searchData))
                    cout << "User data not found!\n";
                system("pause");
                break;
            }
            case 3:
            {
                system("cls");
                cout << "Enter email to search: ";
                cin >> searchData.email;
                if (!matrix->searchMatrix(searchData))
                    cout << "User data not found!\n";
                system("pause");
                break;
            }
            case 4:
            {
                system("cls");
                system("pause");
                return;
            }
            }
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;

        Set[counter - 1] = 12;
    }
}

/**
 * @brief Provides the main scrollable menu
 *
 * @param matrix Pointer to matrix object
 */
void mainMenu(MatrixLinkedList *matrix)
{
    int Set[] = {12, 7, 7, 7, 7, 7}; // DEFAULT COLORS
    int counter = 1;
    char key;

    while (true)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "Please choose from the following options:" << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[0]);
        cout << "1) Create list";

        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[1]);
        cout << "2) Insert phone number in directory";

        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[2]);
        cout << "3) Delete phone number from directory";

        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[3]);
        cout << "4) Search number using name/address/email";

        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[4]);
        cout << "5) Display all numbers";

        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[5]);
        cout << "6) Exit";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        cout << endl;

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 6))
            counter--;
        if (key == 80 && (counter >= 1 && counter <= 5))
            counter++;
        if (key == '\r') // ENTER KEY
        {
            switch (counter)
            {
            case 1:
            {
                system("cls");
                int rows, columns;

                cout << "Enter rows: ";
                cin >> rows;

                cout << "Enter columns: ";
                cin >> columns;

                matrix = new MatrixLinkedList(rows, columns);
                system("pause");
                break;
            }
            case 2:
            {
                system("cls");

                if (matrix == NULL)
                {
                    cout << "Create list first!" << endl;
                    system("pause");
                    break;
                }
                addMenu(matrix);
                system("pause");
                break;
            }
            case 3:
            {
                system("cls");

                if (matrix == NULL)
                {
                    cout << "Create list first!" << endl;
                    system("pause");
                    break;
                }

                deleteMenu(matrix);
                system("pause");
                break;
            }
            case 4:
            {
                system("cls");

                if (matrix == NULL)
                {
                    cout << "Create list first!" << endl;
                    system("pause");
                    break;
                }

                searchMenu(matrix);
                system("pause");
                break;
            }
            case 5:
            {
                system("cls");

                if (matrix == NULL)
                {
                    cout << "Create list first!" << endl;
                    system("pause");
                    break;
                }

                matrix->printMatrix();
                system("pause");
                break;
            }
            case 6:
                system("cls");
                return;
            }
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;
        Set[4] = 7;
        Set[5] = 7;

        Set[counter - 1] = 12;
    }
    mainMenu(matrix);
}

/**
 * @brief Driver function
 *
 * @return output error if any
 */
int main()
{
    MatrixLinkedList *matrix = NULL;
    mainMenu(matrix);
    return 0;
}