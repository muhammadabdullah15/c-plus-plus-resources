//  Fibonacci Series Recursion

#include <iostream>
using namespace std;

int fibonacci(int);

int main() 
{
    int num_terms;
    cout << "Enter the number of terms of fibonacci series : ";
    cin >> num_terms;
    cout << endl;
    for (int c = 0; c < num_terms; c++)
        cout << fibonacci(c) << " ";

    return 0;
}

int fibonacci(int x) 
{
    if ((x == 1) || (x == 0))
        return(x);
    else
        return(fibonacci(x - 1) + fibonacci(x - 2));
}
