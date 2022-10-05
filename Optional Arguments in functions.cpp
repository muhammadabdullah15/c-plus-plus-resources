#include <iostream>
using namespace std;

void printchar(int = 1, char = '&');

int main()
{
    char c;
    int n;

    cout << "Passing no argumnents:" << endl;
    printchar();

    cout << endl << endl;

    cout << "Passing number of times to print:" << endl 
         << "Enter number of times to print: ";
    cin >> n;
    printchar(n);

    cout << endl << endl;

    cout << "Passing both number of times to print and character to print:" << endl 
         << "Enter number of times to print: ";
    cin >> n;
    cout << "Enter character to print: ";
    cin >> c;
    printchar(n,c);

    cout << endl << endl;

    return 0;
}
void printchar(int n, char c)
{
    for (int l = 1; l <= n; l++)
        cout << c;
}

