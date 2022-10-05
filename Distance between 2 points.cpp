#include <iostream>
#include <cmath>
using namespace std;

double distance(double, double, double, double);

int main()
{
    double x1, x2, y1, y2;

    cout << "Enter x1: ";
    cin >> x1;

    cout << "Enter y1: ";
    cin >> y1;

    cout << "Enter x2: ";
    cin >> x2;

    cout << "Enter y2: ";
    cin >> y2;
    
    cout << "Distance between the two points (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") is = " << distance(x1, y1, x2, y2);

    cout << endl << endl;

    return 0;
}
double distance(double x1, double y1, double x2, double y2) 
{
    return sqrt(pow(x2 - x1, 2) + pow((y2 - y1), 2));
}

