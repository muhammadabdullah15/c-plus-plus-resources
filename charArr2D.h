/**
 * @file charArr2D.h
 * @brief 2D Dynamic Character Array implementation
 */
#pragma once

#include <iostream>
using namespace std;

/**
 * @brief 2D Dynamic Character Array Class
 *
 */
class Array2D
{
private:
    char **arr;            // Pointer to 2D Array
    const int columnCount; // Number of columns
    int rowCount;          // Number of rows

    /**
     * @brief Utility function to create and add a new empty ow in the array
     *
     */
    void addRow()
    {
        rowCount++;
        // If the array was previously empty create new array with 1 row
        if (rowCount == 1)
        {
            arr = new char *[1];
            arr[0] = new char[columnCount];
            return;
        }

        // Else create a new array with an extra row
        char **temp = new char *[rowCount];
        for (int i = 0; i < rowCount; i++)
            temp[i] = new char[columnCount];

        // Copy all the previous rows
        for (int i = 0; i < rowCount - 1; i++)
            for (int j = 0; j < columnCount; j++)
                temp[i][j] = arr[i][j];

        // Replace old pointer with new array
        delete[] arr;
        arr = temp;
    }

public:
    /**
     * @brief Construct a new Array 2D object
     *
     * @param columns Number of columns
     */
    Array2D(int columns) : columnCount(columns)
    {
        rowCount = 0;
    }

    /**
     * @brief Inserts a new row into the array
     *
     * @param temp 1D Array to add
     */
    void insert(char *temp)
    {
        addRow(); // Creates new empty row

        // Copy the new elements column-wise
        for (int i = 0; i < columnCount; i++)
            if (temp[i] == '\0')
                arr[rowCount - 1][i] = '-';
            else
                arr[rowCount - 1][i] = temp[i];
    }

    // Friend functions/Classes Prototypes
    friend istream &operator>>(istream &, Array2D &);
    friend ostream &operator<<(ostream &, const Array2D &);
    friend class WordSearch;
};

/**
 * @brief Overloaded function to input 2D array
 *
 * @param inp istream object
 * @param array Array to input
 * @return input stream
 */
istream &operator>>(istream &inp, Array2D &array)
{
    char temp[array.columnCount];
    cout << "Enter " << array.columnCount << " characters at a time,(/ to terminate):\n";
    while (true)
    {
        inp >> temp;
        if (temp[0] == '/')
            break;
        array.insert(temp);
    }
    return inp;
}

/**
 * @brief Overloaded function to print 2D Array
 *
 * @param out ostream object
 * @param array Array to print
 * @return output stream
 */
ostream &operator<<(ostream &out, const Array2D &array)
{
    for (int i = 0; i < array.rowCount; i++)
    {
        for (int j = 0; j < array.columnCount; j++)
            out << array.arr[i][j];
        out << endl;
    }
    out << endl;
    return out;
}