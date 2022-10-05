/*
CS112 Solo Project
Spring 22

Muhammad Abdullah
2021317
*/

#include <iostream>
#include <windows.h>
#include <process.h>
#include <algorithm>
#include <conio.h>
#include <time.h>

#include "TicTacToe.h"

using namespace std;

/**
 * @brief Main menu to present all choices to user
 *
 * @param NN The passed instance of Neural Network
 */
void menu(NeuralNetwork NN)
{
    int Set[] = {12, 7, 7, 7}; // Default Colors
    int counter = 1;           // Tracks position of selection
    char key;                  // Stores pressed key

    while (true)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "                TIC-TAC-TOE              " << endl
             << endl
             << "Please choose from the following options:" << endl
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[0]);
        cout << "Train AI (Training will take ~5 minutes to complete)" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[1]);
        cout << "Play Against AI" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[2]);
        cout << "Play Against Human" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[3]);
        cout << "Exit" << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << endl
             << "(USE ARROW KEYS TO NAVIGATE AND ENTER KEY TO SELECT)";

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 4)) // Up key
            counter--;
        if (key == 80 && (counter >= 1 && counter <= 3)) // Down Key
            counter++;
        if (key == '\r') // ENTER KEY
        {
            switch (counter)
            {
            case 1:
                NN.train();
                break;
            case 2:
                NN.playAgainstAi();
                break;
            case 3:
                NN.playAgainstHuman();
                break;
            case 4:
                cout << endl
                     << endl;
                system("pause");
                cout << endl
                     << endl;
                exit(0);
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
 * @brief main driver function
 *
 * @return int
 */
int main()
{
    srand(time(0));
    NeuralNetwork NN(200);
    menu(NN);
    return 0;
}