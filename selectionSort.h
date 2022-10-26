void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, minElementIndex;
    for (i = 0; i < n - 1; i++)
    {
        minElementIndex = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minElementIndex])
                minElementIndex = j;

        if (minElementIndex != i)
            swap(&arr[minElementIndex], &arr[i]);
    }
}