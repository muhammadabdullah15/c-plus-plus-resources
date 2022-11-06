#include <iostream>
#include <fstream>
#include <string>
#include "tries.h"
using namespace std;

const int COLS = 12;
void horizontal(char[COLS]);
void horizontalReverse(char[COLS]);

/*
dogxbxxxnoon
rhellotherex
okciuqbrownm
wxwgexlxhjij
oozokvuxdrow
rlxdrxextxja
drowblonkgod
*/

class Array2D
{
private:
    char **arr;
    const int columns = 12;
    int rowCount;

    void addRow()
    {
        rowCount++;
        if (rowCount == 1)
        {
            arr = new char *[1];
            arr[0] = new char[columns];
            return;
        }

        char **temp = new char *[rowCount];
        for (int i = 0; i < rowCount; i++)
            temp[i] = new char[columns];

        for (int i = 0; i < rowCount - 1; i++)
            for (int j = 0; j < columns; j++)
                temp[i][j] = arr[i][j];

        delete[] arr;
        arr = temp;
    }

public:
    Array2D()
    {
        rowCount = 0;
    }

    Array2D(char arr[][12], int rows)
    {
        rowCount = 0;
        for (int i = 0; i < rows; i++)
            insert(arr[i]);
    }

    void insert(char *temp)
    {
        addRow();
        for (int i = 0; i < columns; i++)
            arr[rowCount - 1][i] = temp[i];
    }

    friend istream &operator>>(istream &, Array2D &);
    friend ostream &operator<<(ostream &, const Array2D &);
    friend class WordSearch;
};

istream &operator>>(istream &inp, Array2D &array)
{
    char temp[array.columns];
    cout << "Enter 12 characters at a time,(/ to terminate):\n";
    while (true)
    {
        inp >> temp;
        if (temp[0] == '/')
            break;
        array.insert(temp);
    }
    return inp;
}

ostream &operator<<(ostream &out, const Array2D &array)
{
    for (int i = 0; i < array.rowCount; i++)
    {
        for (int j = 0; j < array.columns; j++)
            out << array.arr[i][j];
        out << endl;
    }
    return out;
}

class WordSearch
{
private:
    Trie dictionary;
    ifstream readFile;
    ofstream writeFile;
    const string readPath = "words.txt";
    const string WritePath = "result.txt";

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

    void writeResult(string word, unsigned int startRow, unsigned int startCol, unsigned int endRow, unsigned int endCol)
    {
        writeFile.open(WritePath, ios_base::out | ios_base::app);
        writeFile << word << " (" << startRow << "," << startCol << ") (" << endRow << "," << endCol << ")" << endl;
        cout << word << "\t(" << startRow << "," << startCol << ") (" << endRow << "," << endCol << ")" << endl;
        writeFile.close();
    }

    void horizontal(Array2D array)
    {
        string temp;
        for (int i = 0; i < array.rowCount; i++)
        {
            // FORWARD HORIZONTAL
            for (int j = 0; j < array.columns; j++)
            {
                // FORWARD HORIZONTAL
                temp = "";
                for (int k = j; k < array.columns; k++)
                {
                    temp += array.arr[i][k];
                    if (dictionary.searchTrie(temp))
                        writeResult(temp, i + 1, j + 1, i + 1, j + temp.length());
                }

                // BACKWARD HORIZONTAL
                temp = "";
                for (int l = array.columns - j - 1; l >= 0; l--)
                {
                    temp += array.arr[i][l];
                    if (dictionary.searchTrie(temp))
                        writeResult(temp, i + 1, l + temp.length(), i + 1, l + 1);
                }
            }
        }
    }

    void vertical(Array2D array)
    {
        string temp;
        for (int i = 0; i < array.columns; i++)
        {
            for (int j = 0; j < array.rowCount; j++)
            {
                // FORWARD VERTICAL
                temp = "";
                for (int k = j; k < array.rowCount; k++)
                {
                    temp += array.arr[k][i];
                    if (dictionary.searchTrie(temp))
                        writeResult(temp, j + 1, i + 1, j + 1, i + temp.length());
                }

                // BACKWARD VERTICAL
                temp = "";
                for (int l = array.rowCount - j - 1; l >= 0; l--)
                {
                    temp += array.arr[l][i];
                    if (dictionary.searchTrie(temp))
                        writeResult(temp, l + temp.length(), i + 1, l + 1, i + 1);
                }
            }
        }
    }

    void diagonal(Array2D array)
    {
        string temp;
        for (int i = 0; i < array.rowCount; i++)
        {
            for (int j = 0; j < array.columns; j++)
            {
                // FORWARD DIAGONAL
                temp = "";
                for (int k = i; k < array.rowCount; k++)
                {
                    for (int l = j; l < array.columns; l++)
                    {
                        if (k - i == l - j)
                        {
                            temp += array.arr[k][l];
                            if (dictionary.searchTrie(temp))
                                writeResult(temp, i + 1, j + 1, i + temp.length(), j + temp.length());
                        }
                    }
                }
            }
        }
    }

    void diagonalReverse(Array2D array) {}

public:
    WordSearch()
    {
        initializeDictionary();
    }

    void searchAll(Array2D array)
    {
        // Clearing the file
        writeFile.open(WritePath);
        writeFile.close();

        // horizontal(array);
        // cout << endl;
        // vertical(array);
        // cout << endl;
        diagonal(array);
        cout << endl;
        diagonalReverse(array);
        cout << endl;
    }
};

int main()
{
    char Array[7][COLS] = {'d', 'o', 'g', 'x', 'b', 'x', 'x', 'x', 'n', 'o', 'o', 'n',
                           'r', 'h', 'e', 'l', 'l', 'o', 't', 'h', 'e', 'r', 'e', 'x',
                           'o', 'k', 'c', 'i', 'u', 'q', 'b', 'r', 'o', 'w', 'n', 'm',
                           'w', 'x', 'w', 'g', 'e', 'x', 'l', 'x', 'h', 'j', 'i', 'j',
                           'o', 'o', 'z', 'o', 'k', 'v', 'u', 'x', 'd', 'r', 'o', 'w',
                           'r', 'l', 'x', 'd', 'r', 'x', 'e', 'x', 't', 'x', 'j', 'a',
                           'd', 'r', 'o', 'w', 'b', 'l', 'o', 'n', 'k', 'g', 'o', 'd'};

    Array2D ar(Array, 7);
    // cin >> ar;
    cout << ar << endl
         << endl;

    WordSearch ws;
    ws.searchAll(ar);

    return 0;
}
