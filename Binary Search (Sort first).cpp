#include <iostream>
using namespace std;

void printarray(int[], int);
void bubblesortascending(int[], int);
int  binarysearch(int[], int, int, int);

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

    cout << endl << endl << "Printing unsorted Array.... " << endl;
    printarray(arr, size);

    cout << endl << "Sorting the array...." << endl;
    bubblesortascending(arr, size);

    cout << endl << endl << "Printing sorted Array.... " << endl;
    printarray(arr, size);

    cout << endl << endl << "Enter value to search for: ";
    cin >> search;

    cout << endl;

    if (binarysearch(arr, 0, (size - 1), search) == -1)
        cout << "Item not found!";
    else
        cout << "Item found at index " << binarysearch(arr, 0, (size - 1), search);

    cout << endl;
    
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

void bubblesortascending(int arr[], int size)
{
    for (int j = size; j > 0; j--)
    {
        for (int i = 0; i < (j - 1); i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = 0;
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }        
    }
}

int binarysearch(int arr[], int start, int end,int search)
{
    int middle = (start + end) / 2;
    if ((start == end) && (arr[start] != search))
        return -1;
    else if (arr[middle] == search)
        return middle;
    else if (arr[middle] < search)
        return binarysearch(arr, middle + 1, end, search);
    else
        return binarysearch(arr, start, middle - 1, search);
}
