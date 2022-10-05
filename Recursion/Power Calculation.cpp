//POWER CALCULATION
#include <iostream>
using namespace std;

int calculate(int base, int power)
{
    if (power == 0)
        return 1;
    else
        return (base * calculate(base, power - 1));
}

int main()
{
    int base, power, result;

    cout << "Enter base number: ";
    cin >> base;

    cout << "Enter power of number (positive integer): ";
    cin >> power;

    result = calculate(base, power);
    cout << endl << base << "^" << power << " = " << result;

    return 0;
}
