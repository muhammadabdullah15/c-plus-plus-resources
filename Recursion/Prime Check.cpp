//PRIME CHECK RECURSION
#include <iostream>
using namespace std;

bool isprime(int num, int i = 2)
{
	if (num == i)
		return true;
	if (num % i == 0)
		return false;
	else
		return isprime(num, i + 1);
}

int main()
{
	int num;
	
	cout << "Enter number to check prime: ";
	cin >> num;

	cout << endl;

	if (isprime(num,2))
		cout << num <<" is a Prime Number";
	else
		cout << num << " is not a Prime Number";

	return 0;
}
