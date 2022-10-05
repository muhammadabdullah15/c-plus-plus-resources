#include <iostream>
using namespace std;

void main()
{
	float x,n,sum=0;
	
	cout << "Enter the value of x: ";
	cin >> x;

	cout << "Enter the power value(n): ";
	cin >> n;

	for (float s = 1; s <= n; s+=2)
	{
		float numerator = 1, denominator = 1;
	
		for (float p = 1; p <= s; p++)														//CALCULATING NUMERATOR (POWER)
			numerator *= x;
		//cout << "Numerator: " << x << "^" << s << " = " << numerator << endl;				//TESTING PURPOSE
		
		for (float f = 1; f <= s; ++f)														//CALCULATING DENOMINATOR (FACTORIAL)
			denominator *= f;
		//cout << "Fact of " << s << " = " << denom << endl;								//TESTING PURPOSE
		
		sum += (numerator / denominator);													//CALCULATING SUM OF TERM

		if (s != n)																			//CHECKING IF LAST TERM TO DECIDE WHETHER TO PRINT '+' OR '='
			cout << "(" << x << "^" << s << "/" << s << "!) + ";
		else
			cout << "(" << x << "^" << s << "/" << s << "!) = " << sum;
	}
	
}
