/**
 * @file Main.cpp
 * @author Muhammad Abdullah (2021317), Mohammad Umer Tayyab (2021306)
 * @brief Driver code for a word-search program
 * @date 10-11-2022
 *
 */
#include <iostream>
#include <fstream>
#include <string>

#include "tries.h"
#include "charArr2D.h"
#include "WordSearch.h"

using namespace std;

// Test Array
char Array[7][12] = {'d', 'o', 'g', 'x', 'b', 'x', 'x', 'x', 'n', 'o', 'o', 'n',
                     'r', 'h', 'e', 'l', 'l', 'o', 't', 'h', 'e', 'r', 'e', 'x',
                     'o', 'k', 'c', 'i', 'u', 'q', 'b', 'r', 'o', 'w', 'n', 'm',
                     'w', 'x', 'w', 'g', 'e', 'x', 'l', 'x', 'h', 'j', 'i', 'j',
                     'o', 'o', 'z', 'o', 'k', 'v', 'u', 'x', 'd', 'r', 'o', 'w',
                     'r', 'l', 'x', 'd', 'r', 'x', 'e', 'x', 't', 'x', 'j', 'a',
                     'd', 'r', 'o', 'w', 'b', 'l', 'o', 'n', 'k', 'g', 'o', 'd'};

/**
 * @brief Function to clear the console
 *
 */
void clearScreen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    std::system("clear");
#endif
}

/**
 * @brief Adds a pause before clearing the screen
 *
 */
void pause()
{
    cin.ignore();
    cout << "\nPress any key to continue...\n";
    getchar();
    return;
}

/**
 * @brief Driver code
 *
 * @return error code if any
 */
int main()
{

    Array2D *arr;
    WordSearch ws;

    int choice;
    while (true)
    {
        clearScreen();
        cout << "1) Use already entered array" << endl
             << "2) Enter custom array" << endl
             << "3) Exit" << endl
             << endl
             << "Enter choice: ";
        cin >> choice;
        clearScreen();

        switch (choice)
        {
        case 1:
        {
            arr = new Array2D(12);
            for (int i = 0; i < 7; i++)
                arr->insert(Array[i]);
            clearScreen();
            cout << "Entered Array:" << endl
                 << *arr << endl
                 << "Results:" << endl;
            ws.searchAll(*arr);
            pause();
            break;
        }
        case 2:
        {
            cout << "Enter number of columns: ";
            int columns;
            cin >> columns;
            arr = new Array2D(columns);
            cin >> *arr;
            clearScreen();
            cout << "Entered Array:" << endl
                 << *arr << endl
                 << "Results:" << endl;
            ws.searchAll(*arr);
            pause();
            break;
        }
        case 3:
        {
            exit(0);
        }
        default:
            cout << "Invalid choice entered!\nPLease try again\n";
        }
    }

    return 0;
}
