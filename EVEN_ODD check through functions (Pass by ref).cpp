#include <iostream>
using namespace std;

int  getNumber();                           //FUNCTION PROTOTYPES
void initialize(int&, int&);
void classifyNumber(int, int&, int&);
void printresults(int, int);

int main()
{
    int oddcount, evencount, num;                   //DECLARNG COUNTERS AND NUMBER
    
    initialize(oddcount, evencount);                //INITIALIZING COUNTERS

    for (int c = 1; c <= 20; c++)                   //LOOP FOR 20 NUMBERS
    {
        num = getNumber();                          //CALLING getnumber FUNCITON TO INPUT NUMBER
        cout << "You entered " << num << endl;;     //OUTPUTTING THE ENTERED NUMBER
        classifyNumber(num, oddcount, evencount);   //CALLING CLASSIFY NUMBER TO CLASSIFY THE NUMBER
    }
    printresults(oddcount, evencount);              //CALLING PRINT RESULTS TO PRINT THE COUNTERS

    return 0;
}

void initialize(int& oddcount, int& evencount)      //FUNCTION TAKES THE TWO COUNTERS AS REFERENCE PARAMETERS AND SETS THEM TO 0
{
    oddcount = 0;
    evencount = 0;
}

int getNumber()                                     //FUNCTION RETURNS INT AFTER TAKING INPUT
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    return num;
}

void classifyNumber(int n, int& oddcount, int& evencount)   //FUNCTION TAKES THE NUMBER AS NORMAL INPUT AND TWO COUNTERS AS REFERENCE PARAMETERS AND CHECKS IF EVEN
{
    if ((n % 2) == 0)                                       //IF EVEN, INCREMENTS EVEN COUNTER
    {
        cout << "The number is even";
        evencount++;
    }
    else                                                    //IF ODD INCREMENT ODD COUNTER
    {
        cout << "The number is odd";
        oddcount++;
    }
    cout << endl << endl;
}

void printresults(int o, int e)                             //FUNCTION TAKES THE TWO COUNTERS AS NORMAL PARAMETERS AND OUTPUTS THEM
{
    cout << endl;
    cout << "Number of odd  numbers are  " << o << endl;
    cout << "Number of even numbers are  " << e << endl;
    cout << endl;
}
