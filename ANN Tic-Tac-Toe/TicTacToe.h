#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

/**
 * @brief Stores all training values
 *
 */
struct trainingvalues
{
    float firstchannelweights[3][9];
    float secondchannelweights[3];

    float hiddenlayer[3];
    float finallayer;

    void initializeValues()
    {
        for (int i = 0; i < 3; i++)
        {
            secondchannelweights[i] = (float)rand() / RAND_MAX;
            hiddenlayer[i] = 0.0;
            for (int j = 0; j < 9; j++)
                firstchannelweights[i][j] = (float)rand() / RAND_MAX;
        }

        finallayer = 0.0;
    }
};

/**
 * @brief Base Tic-Tac-Toe Class
 *
 */
class TicTacToe
{
protected:
    char grid[9]; // Current grid
    char player;  // Current player

public:
    /**
     * @brief Default Constructor which initializes player and grid
     *
     */
    TicTacToe()
    {
        player = 'x';
        for (int i = 0; i < 9; i++)
            grid[i] = 'b';
    }

    /**
     * @brief Constructor which initializes grid and player based on passes parameter
     *
     * @param p Default Player
     */
    TicTacToe(char p)
    {
        player = p;
        for (int i = 0; i < 9; i++)
            grid[i] = 'b';
    }

    /**
     * @brief Sets the starting player for a game
     *
     * @param mode Against AI/Human
     */
    void setPlayer(string mode)
    {
        int Set[] = {12, 7, 7}; // DEFAULT COLORS
        int counter = 1;
        char key;

        while (true)
        {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cout << "Select Starting Player:" << endl
                 << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[0]);
            cout << "X" << (mode == "ai" ? " (AI)" : "") << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[1]);
            cout << "O" << (mode == "ai" ? " (Human)" : "") << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Set[2]);
            cout << "Random" << endl;

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cout << endl
                 << "(USE ARROW KEYS TO NAVIGATE AND ENTER KEY TO SELECT)";
            ;

            key = _getch();

            if (key == 72 && ((counter == 2) || (counter == 3)))
                counter--;
            else if (key == 80 && ((counter == 1) || (counter == 2)))
                counter++;
            else if (key == '\r') // ENTER KEY
            {
                if (counter == 3)
                    counter = rand() % 2 + 1;

                if (counter == 1)
                    player = 'x';
                else if (counter == 2)
                    player = 'o';

                return;
            }

            Set[0] = 7;
            Set[1] = 7;
            Set[2] = 7;

            Set[counter - 1] = 12;
        }
    }

    /**
     * @brief Displays formatted grid
     *
     * @param inputgrid Grid to display
     */
    void display(char inputgrid[9])
    {
        for (int i = 0; i < 9; i++)
        {
            cout << (i % 3 == 0 ? "\n   +---+---+---+\n   |" : "");
            if (inputgrid[i] == 'x')
                cout << " X ";
            if (inputgrid[i] == 'o')
                cout << " O ";
            if (inputgrid[i] == 'b')
                cout << "   ";
            cout << "|";
        }
        cout << "\n   +---+---+---+";

        return;
    }

    /**
     * @brief Gets a human move
     *
     * @return human move
     */
    int getHumanMove()
    {
        int i = 0; // Vertical position
        int j = 0; // Horizontal position
        char key;  // Pressed key

        // Stores default position in i,k
        for (int k = 0; k < 9; k++)
            if (isValidMove(grid, k))
            {
                i = k / 3;
                j = k % 3;
                break;
            }

        while (true)
        {
            system("cls");
            for (int k = 0; k < 9; k++)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cout << (k % 3 == 0 ? "\n   +---+---+---+\n   |" : "");

                if ((k == (3 * i + j)) && grid[k] != 'b')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << " - ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else if (grid[k] == 'x')
                    cout << " X ";
                else if (grid[k] == 'o')
                    cout << " O ";
                else if ((grid[k] == 'b') && ((3 * i + j) == k))
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << (player == 'x' ? " X " : " O ");
                }
                else
                    cout << "   ";

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cout << "|";
            }
            cout << "\n   +---+---+---+"
                 << endl
                 << endl
                 << "It is your turn Player O" << endl
                 << (isValidMove(grid, (3 * i + j)) ? "\n" : "CURRENT MOVE IS INVALID!\n")
                 << endl
                 << "(NAVIGATE WITH ARROW KEYS AND PRESS ENTER TO LOCK MOVE)";

            key = _getch();

            if (key == 72 && (i == 1 || i == 2)) // UP
                i--;
            else if (key == 80 && (i == 0 || i == 1)) // DOWN
                i++;
            else if (key == 75 && (j == 1 || j == 2)) // LEFT
                j--;
            else if (key == 77 && (j == 0 || j == 1)) // RIGHT
                j++;
            else if (key == '\r') // ENTER KEY
                if (isValidMove(grid, (3 * i + j)))
                    return (3 * i + j);
        }
    }

    /**
     * @brief Clears the grid for a new game
     *
     * @param mode AI/Human
     */
    void clearGrid(string mode)
    {
        for (int i = 0; i < 9; i++)
            grid[i] = 'b';
        setPlayer(mode);
    }

    /**
     * @brief Plays game against human
     *
     */
    void playAgainstHuman()
    {
        clearGrid("h");
        while (true)
        {
            char gameresult = gameOver(grid); // Current game result
            if (gameresult == 'x' || gameresult == 'o' || gameresult == 'd')
            {
                system("cls");
                display(grid);
                cout << endl
                     << endl
                     << (gameresult == 'x' ? "X is the winner!" : (gameresult == 'o' ? "O is the winner!" : "The game is drawn!")) << endl
                     << endl;
                system("pause");
                break;
            }

            system("cls");
            grid[getHumanMove()] = player;

            if (player == 'x')
                player = 'o';
            else
                player = 'x';
        }
    }

    /**
     * @brief Returns current game state result
     *
     * @param inputgrid Grid to check for result
     * @return Result
     */
    char gameOver(char inputgrid[9])
    {
        /*      Returns the following based on the current state of inputgrid
        x   -   Player X has won
        o   -   Player O has won
        d   -   Game has been drawn
        -   -   Game is ongoing
        */

        // HORIZONTAL CASES
        if ((inputgrid[0] != 'b') && (inputgrid[0] == inputgrid[1]) && (inputgrid[1] == inputgrid[2]))
            return inputgrid[0];
        if ((inputgrid[3] != 'b') && (inputgrid[3] == inputgrid[4]) && (inputgrid[4] == inputgrid[5]))
            return inputgrid[3];
        if ((inputgrid[6] != 'b') && (inputgrid[6] == inputgrid[7]) && (inputgrid[7] == inputgrid[8]))
            return inputgrid[6];

        // VERTICAL CASES
        if ((inputgrid[0] != 'b') && (inputgrid[0] == inputgrid[3]) && (inputgrid[3] == inputgrid[6]))
            return inputgrid[0];
        if ((inputgrid[1] != 'b') && (inputgrid[1] == inputgrid[4]) && (inputgrid[4] == inputgrid[7]))
            return inputgrid[1];
        if ((inputgrid[2] != 'b') && (inputgrid[2] == inputgrid[5]) && (inputgrid[5] == inputgrid[8]))
            return inputgrid[2];

        // DIAGONAL CASES
        if ((inputgrid[0] != 'b') && (inputgrid[0] == inputgrid[4]) && (inputgrid[4] == inputgrid[8]))
            return inputgrid[0];
        if ((inputgrid[2] != 'b') && (inputgrid[2] == inputgrid[4]) && (inputgrid[4] == inputgrid[6]))
            return inputgrid[2];

        for (int i = 0; i < 9; i++)
            if (inputgrid[i] == 'b')
                return '-';

        return 'd';
    }

    /**
     * @brief Checks whether a move is valid
     *
     * @param inputgrid Grid to check move
     * @param move      Move to check
     * @return true when valid move
     * @return false when invalid move
     */
    bool isValidMove(char inputgrid[9], int move)
    {
        if (inputgrid[move] == 'b')
            return true;
        else
            return false;
    }
};

/**
 * @brief Derived Neural Network from Base class TicTacToe
 *
 */
class NeuralNetwork : public TicTacToe
{
private:
    char possiblities[958][9]; // All possible end board scenarios
    char winner[958];          // Winners corresponding to all possibilites
    bool trained;              // AI Trained or not
    int epoch;                 // epoch
    trainingvalues values;     // Training Values

public:
    /**
     * @brief Default Constructor
     *
     */
    NeuralNetwork()
    {
        trained = false;
        readTrainingValues(&(values));
    }

    /**
     * @brief Overloaded constructor takes epoch as param
     *
     * @param e epoch
     */
    NeuralNetwork(int e = 200)
    {
        epoch = e;
        trained = false;
        readTrainingValues(&(values));
    }

    /**
     * @brief Play against AI
     *
     */
    void playAgainstAi()
    {
        clearGrid("ai");

        if (!trained)
        {
            cout << "Training values not found!" << endl
                 << "Commencing Training..." << endl;
            system("pause");
            train();
        }

        while (true)
        {
            char result = gameOver(grid);

            if (result == 'x' || result == 'o' || result == 'd')
            {
                system("cls");
                display(grid);
                cout << endl
                     << endl
                     << (result == 'x' ? "X is the winner!" : (result == 'o' ? "O is the winner!" : "The game is drawn!")) << endl
                     << endl;
                system("pause");
                break;
            }

            system("cls");

            if (player == 'x')
            {
                display(grid);
                grid[getAiMove()] = player;
                player = 'o';
            }
            else
            {
                grid[getHumanMove()] = player;
                player = 'x';
            }
        }
    }

    /**
     * @brief Gets AI move
     *
     * @return AI move
     */
    int getAiMove()
    {
        char *copygrid1 = new char[9];
        char *copygrid2 = new char[9];

        float x_winmaxprob = 0;
        int x_maxprobindex = 4;

        float o_winmaxprob = 0;
        float o_maxprobindex = 4;

        for (int i = 0; i < 9; i++)
        {
            if (isValidMove(grid, i))
            {
                copyGrid(copygrid1);
                copygrid1[i] = 'x';
                float tempxprobability = forwardPropogation(copygrid1, values);

                if (gameOver(copygrid1) == 'x')
                {
                    x_winmaxprob = 1.01;
                    x_maxprobindex = i;
                }

                if (tempxprobability > x_winmaxprob)
                {
                    x_winmaxprob = tempxprobability;
                    x_maxprobindex = i;
                }

                copyGrid(copygrid2);
                copygrid2[i] = 'o';
                if (gameOver(copygrid2) == 'o')
                {
                    o_winmaxprob = 1;
                    o_maxprobindex = i;
                }
            }
        }

        delete[] copygrid1;
        delete[] copygrid2;

        return (x_winmaxprob > o_winmaxprob ? x_maxprobindex : o_maxprobindex);
    }

    /**
     * @brief Copies current grid
     *
     * @param tempgrid Grid to store copy in
     */
    void copyGrid(char *tempgrid)
    {
        for (int i = 0; i < 9; i++)
            tempgrid[i] = grid[i];

        return;
    }

    /**
     * @brief Generates a random index array
     *
     * @return Random index array
     */
    vector<unsigned int> getRandomArray()
    {
        const unsigned range = 958;
        const unsigned numberToSelect = 958;

        vector<unsigned> remainingNumbers(range);
        vector<unsigned> chosenNumbers(numberToSelect);

        for (unsigned i = 0; i < range; i++)
            remainingNumbers[i] = i;

        for (unsigned i = 0; i < numberToSelect; i++)
        {
            int selectedElement = rand() % (range - i);
            chosenNumbers[i] = remainingNumbers[selectedElement];
            remainingNumbers.erase(remainingNumbers.begin() + selectedElement);
        }

        remainingNumbers.clear();

        return chosenNumbers;
    }

    /**
     * @brief Training Function
     *
     */
    void train()
    {
        datasetFileRead();
        values.initializeValues();
        float minprob = 1, maxprob = 0;

        for (int j = 0; j <= epoch; j++)
        {
            vector<unsigned int> arr = getRandomArray();
            for (int i = 0; i < 958; i++)
            {
                // cout << endl
                //      << endl
                //      << "Input state: " << i;
                // display(possiblities[i]);

                float probability = forwardPropogation(possiblities[arr[i]], values);
                float difference = (winner[i] == 'x' ? float(1.0) : float(-1.0)) - probability;

                if (probability > maxprob)
                    maxprob = probability;
                if (probability < minprob)
                    minprob = probability;

                cout << "\nActual Winner:\t\t" << (winner[arr[i]] == 'x' ? "X" : "O / Draw") << endl
                     << "Probabilty (X):\t\t" << probability << endl
                     << "Difference:\t\t" << difference << endl;

                backwardPropogation(possiblities[arr[i]], difference, probability, &values);
            }
        }

        storeTrainingValues(values);
        cout << "Training successful!" << endl
             << "Maxprob:\t" << maxprob << endl
             << "Minprob:\t" << minprob << endl;
        system("pause");
        system("cls");
        return;
    }

    /**
     * @brief Passes a possability through neural network
     *
     * @param inputgrid Passed Grid
     * @param values    Training  Values
     * @return Probabilty of 'X' winning
     */
    float forwardPropogation(char inputgrid[9], trainingvalues values)
    {
        /*
        First layer of neurons has 9 elements
        Second layer of neurons is hidden and has 3 elements with all previous 9 connected to each (i.e 27 channels)
        Third layer is the output where all 3 previous are connected
        */
        float *input = new float[9];

        for (int i = 0; i < 9; i++)
        {
            if (inputgrid[i] == 'x')
                input[i] = +1.0;
            else if (inputgrid[i] == 'o')
                input[i] = -1.0;
            else if (inputgrid[i] == 'b')
                input[i] = 0.01;
        }

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 9; j++)
                values.hiddenlayer[i] += (input[j] * values.firstchannelweights[i][j]);

        delete[] input;

        for (int i = 0; i < 3; i++)
            values.finallayer += (sigmoid(values.hiddenlayer[i]) * values.secondchannelweights[i]);

        float probability = sigmoid(values.finallayer);
        return probability;
    }

    /**
     * @brief Adjusts training values
     *
     * @param inputgrid Passed grid
     * @param probabiltydifference Difference in Actual Probability and Calculted Probabilty
     * @param output    Probability Calculated from forwardPropogation
     * @param values    Training values to adjust
     */
    void backwardPropogation(char inputgrid[9], float probabiltydifference, float output, trainingvalues *values)
    {
        static float learningRate = 0.01; // Rate at which AI adjusts the values
        float *hiddenlayerdifferences = new float[3];
        float *input = new float[9];

        for (int i = 0; i < 9; i++)
        {
            if (inputgrid[i] == 'x')
                input[i] = +1.0;
            if (inputgrid[i] == 'o')
                input[i] = -1.0;
            if (inputgrid[i] == 'b')
                input[i] = 0.01;
        }

        for (int i = 0; i < 3; i++)
            hiddenlayerdifferences[i] = probabiltydifference * values->secondchannelweights[i];

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 9; j++)
                values->firstchannelweights[i][j] += (learningRate * hiddenlayerdifferences[i] * sigmoidDerivative(values->hiddenlayer[i]) * output);

        for (int i = 0; i < 3; i++)
            values->secondchannelweights[i] += (learningRate * probabiltydifference * sigmoidDerivative(values->finallayer) * output);

        delete[] hiddenlayerdifferences;
    }

    /**
     * @brief Sigmoid Activation Function
     *
     * @param value x-value
     * @return y-value
     */
    float sigmoid(float value)
    {
        return 1 / (1 + exp(-value));
    }

    /**
     * @brief Sigmoid Activaiton Function Derivative
     *
     * @param value x-value
     * @return y-value
     */
    float sigmoidDerivative(float value)
    {
        return (sigmoid(value) * (1 - sigmoid(value)));
    }

    /**
     * @brief Reads the dataset and stores all possibilites
     *
     */
    void datasetFileRead()
    {
        ifstream read;
        read.open("tic-tac-toe.data");
        if (!read)
        {
            cout << "Error loading file";
            return;
        }

        for (int i = 0; i < 958; i++)
        {
            string temp;
            read >> temp;

            for (int j = 0; j < 9; j++)
                possiblities[i][j] = temp[(j * 2)];

            if (temp[18] == 'p')
                winner[i] = 'x';
            else
            {
                if (gameOver(possiblities[i]) == 'o')
                    winner[i] = 'o';
                else
                    winner[i] = 'd';
            }
        }
        read.close();

        cout << "File read successfully" << endl;
        return;
    }

    /**
     * @brief Test function to verify the data has been correctly read and stored
     *
     */
    void datasetFileWrite()
    {
        ofstream write;
        write.open("testfilewrite.txt");
        if (!write)
        {
            cout << "Error loading file";
            return;
        }
        for (int i = 0; i < 958; i++)
        {
            for (int j = 0; j < 9; j++)
                write << possiblities[i][j] << " ";

            write << winner[i] << endl;
        }
        write.close();

        return;
    }

    /**
     * @brief Stores Training Values
     *
     * @param values Values to store
     */
    void storeTrainingValues(trainingvalues values)
    {
        ofstream write("trainingvalues.txt");

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 9; j++)
                write << values.firstchannelweights[i][j] << endl;

        for (int i = 0; i < 3; i++)
            write << values.secondchannelweights[i] << endl;

        for (int i = 0; i < 3; i++)
            write << values.hiddenlayer[i] << endl;

        write << values.finallayer << endl;

        write.close();

        return;
    }

    /**
     * @brief Reads Training Values
     *
     * @param values Values to write to
     */
    void readTrainingValues(trainingvalues *values)
    {
        ifstream read("trainingvalues.txt");
        if (!read)
            trained = false;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 9; j++)
                read >> values->firstchannelweights[i][j];

        for (int i = 0; i < 3; i++)
            read >> values->secondchannelweights[i];

        for (int i = 0; i < 3; i++)
            read >> values->hiddenlayer[i];

        read >> values->finallayer;

        read.close();
        trained = true;
        return;
    }
};