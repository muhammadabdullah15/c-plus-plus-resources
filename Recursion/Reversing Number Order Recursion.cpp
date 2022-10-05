//REVERSING NUMBER ORDER RECURSION
#include <iostream>
using namespace std;

int reverseNumber(int n)
{
    static int temp, sum;
    if (n <= 0)
    	return sum;    	

    temp = n % 10;
    sum = sum * 10 + temp;
    reverseNumber(n / 10);
}

int main() {

    int n, reverse;

    cout << "Enter number: ";
    cin >> n;

    reverse = reverseNumber(n);

    cout << endl << "Reverse of " << n << " is " << reverse;

    return 0;
}
