#include <iostream>
#include <cstdlib>					//LIBRARY FOR RAND/SRAND FUNCTION
#include <time.h>					//LIBRARY FOR TIME FUNCTION

using namespace std;

int main()
{
	int sum = 0, counter = 1;
	cout << "Enter Sum to check: ";
	cin >> sum;
	while ((sum < 2) || (sum > 12))	//CONFIRMING SUM IS BETWEEN 2 AND 12 ELSE TAKING INPUT AGAIN
	{
		cout << endl << "ERROR!" << endl << "Sum of two dice must be between 2 and 12 : ";
		cin >> sum;
	}
	
	srand(time(0));						//SETTING RANDOM NUMBER STARTING POSITION RANDOMLY ACCORDING TO CURRENT TIME

	while (true)						//STARTING INFINITE LOOP
	{
		int dice1 = rand() % 6 + 1;		//ROLLING DICE 1	rand() gives a random number, rand()%6 will give a number between 0 and 5 so we add 1 to get number between 1 and 6
		int dice2 = rand() % 6 + 1;		//ROLLING DICE 2	rand() gives a random number, rand()%6 will give a number between 0 and 5 so we add 1 to get number between 1 and 6
		cout << endl << endl << "Try number " << counter << endl	//OUTPUTTING CURRENT TRY NUMBER (COUNTER)
			 << "Dice 1 rolled a " << dice1 << endl					//OUTPUTTING DICE 1 RESULT
			 << "Dice 2 rolled a " << dice2 << endl					//OUTPUTTING DICE 2 RESULT
			 << "Sum=" << (dice1 + dice2) << endl;					//OUTPUTTING SUM
	
		if ((dice1 + dice2) == sum)									//CHECKING IF THE SUM OF DICE IS SAME AS INPUT, WE BREAK LOOP
			break;
		counter++;													//INCREMENTING TRY NUMBER
	}
	cout << "It took " << counter << " tries to get Sum=" << sum << endl;		//OUTPUTTING NUMBER OF TRIES TAKEN TO GET DESIRED RESULT

	return 0;
}
