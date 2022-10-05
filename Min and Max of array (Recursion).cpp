//LAB10 TASK1
#include <iostream>
using namespace std;

int max(int[], int size);
int min(int[], int size);

int main()
{
    int arr[100];
    int size;

    cout << "Enter number of elements in array: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element at index " << i << ": ";
        cin >> arr[i];
    }

    cout << endl << endl << "Maximimum element of array is " << max(arr, size - 1) << endl 
                         << "Minimum   element of array is " << min(arr, size - 1) << endl;
}

int max(int arr[], int index) 
{
    static int maximum = -10000;
    if (index < 0)
        return maximum;
    else if (arr[index] > maximum)
        maximum = arr[index];
    
    return max(arr, index - 1);
}

int min(int arr[], int index)
{
    static int minimum = 10000;
    if (index < 0)
        return minimum;
    else if (arr[index] < minimum)
        minimum = arr[index];

    return min(arr, index - 1);
}
