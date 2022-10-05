#include <iostream>
#include <process.h>

using namespace std;

void bubblesort(int[], int);
void printarray(int[], int);

int main()
{
    int size, arr[100];

    cout << "Enter number of elements in array: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element at index " << i << ": ";
        cin >> arr[i];
    }
      
    cout << endl << endl << "Array before sorting: " << endl;
    printarray(arr, size);
    
    cout << endl << endl << "Sorting array..." << endl << endl;
    bubblesort(arr, size);
    
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

void bubblesort(int arr[], int size)
{
    for (int j = size; j > 0; j--)
    {
        for (int i = 0; i < (j - 1); i++)
        {
            if (arr[i] < arr[i + 1])
            {
                int temp = 0;
				temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        cout << "Bubble iteration " << (size - j + 1) << " result: " << endl;
        printarray(arr, size);
        cout << endl << endl;
    }
}
