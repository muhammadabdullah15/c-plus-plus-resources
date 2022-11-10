/**
 * @file WordSearch.h
 * @brief A class that searches for english words in a 2D character array
 */

#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "tries.h"
#include "charArr2D.h"

using namespace std;

/**
 * @brief A class that searches for english words in a 2D character array
 *
 */
class WordSearch
{
private:
    Trie dictionary;                       // Trie structure used as dictionary
    ifstream readFile;                     // ifstream object to read text file
    ofstream writeFile;                    // ofstream object to write text file
    const string readPath = "words.txt";   // readPath
    const string WritePath = "result.txt"; // writePath

    /**
     * @brief Initializes the trie by reading all words from file and adding them to trie
     *
     */
    void initializeDictionary()
    {
        readFile.open(readPath);

        string temp;
        while (!readFile.eof())
        {
            readFile >> temp;
            if (temp.length() >= 3 && temp.length() <= 10)
                dictionary.insert(temp);
        }
        readFile.close();
        return;
    }

    /**
     * @brief Called when word is found in the array, writes coordinates to the file
     *
     * @param word      Found word
     * @param startRow  //Starting row position
     * @param startCol  //Starting column position
     * @param endRow    //Ending Row Position
     * @param endCol    //Ending Column Position
     */
    void writeResult(string word, unsigned int startRow, unsigned int startCol, unsigned int endRow, unsigned int endCol)
    {
        writeFile.open(WritePath, ios_base::out | ios_base::app); // Append mode used so previous results not discarded
        writeFile << word << " (" << startRow << "," << startCol << ") (" << endRow << "," << endCol << ")" << endl;
        cout << word << "\t(" << startRow << "," << startCol << ") (" << endRow << "," << endCol << ")" << endl;
        writeFile.close();
    }

    /**
     * @brief Checks all possible horizontal/reverse-horizontal words beginning from the passed position
     *
     * @param array Array to check
     * @param i Row index
     * @param j Column index
     */
    void horizontal(Array2D array, int i, int j)
    {
        string temp;

        // FORWARD HORIZONTAL
        temp = "";
        for (int k = j; k < array.columnCount; k++) // Traverses in the right direction
        {
            temp += array.arr[i][k];
            if (dictionary.searchTrie(temp))
                writeResult(temp, i + 1, j + 1, i + 1, j + temp.length());
        }

        // BACKWARD HORIZONTAL
        temp = "";
        for (int l = array.columnCount - j - 1; l >= 0; l--) // Traverses in the left direction
        {
            temp += array.arr[i][l];
            if (dictionary.searchTrie(temp))
                writeResult(temp, i + 1, l + temp.length(), i + 1, l + 1);
        }
    }

    /**
     * @brief Checks all possible vertical/reverse-vertical words beginning from the passed position
     *
     * @param array Array to check
     * @param i Row index
     * @param j Column index
     */
    void vertical(Array2D array, int i, int j)
    {
        string temp;
        // FORWARD VERTICAL
        temp = "";
        for (int k = i; k < array.rowCount; k++) // Traverses in the up direction
        {
            temp += array.arr[k][j];
            if (dictionary.searchTrie(temp))
                writeResult(temp, i + 1, j + 1, i + temp.length(), j + 1);
        }

        // BACKWARD VERTICAL
        temp = "";
        for (int k = i; k >= 0; k--) // Traverses in the down direction
        {
            temp += array.arr[k][j];
            if (dictionary.searchTrie(temp))
                writeResult(temp, i + 1, j + 1, i - temp.length() + 2, j + 1);
        }
    }

    /**
     * @brief Checks all possible diagonal/reverse-diagonal words beginning from the passed position
     *
     * @param array Array to check
     * @param i Row index
     * @param j Column index
     */
    void diagonal(Array2D array, int i, int j)
    {
        string temp;

        // UPPER LEFT DIAGONAL
        temp = "";
        for (int k = i, l = j; k >= 0 && l >= 0; k--, l--) // Traverses in the upper-left direction
        {
            temp += array.arr[k][l];
            if (dictionary.searchTrie(temp))
                writeResult(temp, i + 1, j + 1, i - temp.length() + 2, j - temp.length() + 2);
        }

        // UPPER RIGHT DIAGONAL
        temp = "";
        for (int k = i, l = j; k >= 0 && l < array.columnCount; k--, l++) // Traverses in the upper-right direction
        {
            temp += array.arr[k][l];
            if (dictionary.searchTrie(temp))
                writeResult(temp, i + 1, j + 1, i - temp.length() + 2, j + temp.length());
        }

        // LOWER LEFT DIAGONAL
        temp = "";
        for (int k = i, l = j; k < array.rowCount && l >= 0; k++, l--) // Traverses in the lower-left direction
        {
            temp += array.arr[k][l];
            if (dictionary.searchTrie(temp))
                writeResult(temp, i + 1, j + 1, i + temp.length(), j - temp.length() + 2);
        }

        // LOWER RIGHT DIAGONAL
        temp = "";
        for (int k = i, l = j; k < array.rowCount && l < array.columnCount; k++, l++) // Traverses in the lower-right direction
        {
            temp += array.arr[k][l];
            if (dictionary.searchTrie(temp))
                writeResult(temp, i + 1, j + 1, i + temp.length(), j + temp.length());
        }
    }

public:
    /**
     * @brief Construct a new Word Search object, calls the initialize function to initialize the dictionary
     *
     */
    WordSearch()
    {
        initializeDictionary();
    }

    /**
     * @brief Searches for all words in passed array
     *
     * @param array Array to search
     */
    void searchAll(Array2D array)
    {
        // Clearing the previous results
        writeFile.open(WritePath);
        writeFile.close();

        // Traverses the array and for each element check for any possible words beginning with that element
        for (int i = 0; i < array.rowCount; i++)
        {
            for (int j = 0; j < array.columnCount; j++)
            {
                horizontal(array, i, j);
                vertical(array, i, j);
                diagonal(array, i, j);
            }
        }
    }
};