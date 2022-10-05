//  Factorial Recursion

#include <iostream>
using namespace std;

int factorial(int);

int main() 
{
    int num;
    cout << "Enter an integer for factorial: ";
    cin >> num;

    cout << endl;

    cout << "Factorial of " << num << " is " << factorial(num);

    return 0;
}

int factorial(int num)
{
    if ((num == 0) || (num == 1))
        return 1;
    else
        return (num * factorial(num - 1));
}
