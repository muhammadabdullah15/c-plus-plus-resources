#include <iostream>
#include <process.h>
using namespace std;

void linearsearch(int[], int, int, int=0);
void printarray(int[], int);

int main()
{
    int size, search, arr[100];

    cout << "Enter number of elements in array: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element at index " << i << ": ";
        cin >> arr[i];
    }

    cout << endl << endl << "Printing Array...." << endl;
    printarray(arr, size);

    cout << endl << endl << "Enter value to search for: ";
    cin >> search;

    cout << endl;
    linearsearch(arr, size, search);
    
    cout << endl;
    
	system("pause");
    return 0;
}

void printarray(int arr[], int size)
{
    cout << "Index:\t";

    for (int i = 0; i < size; i++)
        cout << "\t" << i;

    cout << endl << "Values:\t";

    for (int i = 0; i < size; i++)
        cout << "\t" << arr[i];
}

void linearsearch(int arr[], int size, int search,int prevfoundindex)
{
    int i;
    char furthursearch = 'N';

    for (i = prevfoundindex; i < size; i++)
    {
        if (arr[i] == search)
            break;
    }

    if ((i == size) && (arr[i] != search))
        cout << "Not found!";
    else
    {
        cout << search << " found at index " << i << "!" << endl << "Item found after " << (i + 1) << " steps" << endl << endl;
        if (i != (size - 1))
        {
            cout << "Continue searching for furthur matches ? (Y / N) : ";
            cin >> furthursearch;
            cout << endl;
            if ((furthursearch == 'Y') || (furthursearch == 'y'))
                linearsearch(arr, size, search, (i + 1));
        }
        
    }
}
