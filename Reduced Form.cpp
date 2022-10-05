#include <iostream>
using namespace std;

class rational
{
private:
    int p, q;

public:
    rational(int numerator = 1, int denominator = 1)
    {
        p = numerator;
        q = denominator;
        reduced_form();
    }

    void reduced_form()
    {
        int hcf = 1;

        for (int i = 2; (i < p || i < q); i++)
            if ((p % i == 0) && (q % i == 0))
                hcf = i;

        p /= hcf;
        q /= hcf;
    }

    void addition(rational r1,rational r2) 
    {
        p = (r1.p * r2.q) + (r2.p * r1.q);
        q = r1.q * r2.q;
    }

    void subtract(rational r1, rational r2) 
    {
        p = (r1.p * r2.q) - (r2.p * r1.q);
        q = r1.q * r2.q;
    }

    void multiply(rational r1, rational r2)
    {
        p = r1.p * r2.p;
        q = r1.q * r2.q;
    }

    void divide(rational r1, rational r2)
    {
        p = r1.p * r2.q;
        q = r1.q * r2.p;
    }

    void display()
    {
        reduced_form();
        cout << p << "/" << q;
    }

    ~rational() {}
};

int main()
{
    rational r1(4, 5);
    rational r2(10, 5);
    rational r3(0, 0);

    cout << "R1 = " ;
    r1.display();
    cout << endl;
    cout << "R2 = ";
    r2.display();
    
    cout << endl << endl;

    r1.display();
    cout << " + ";
    r2.display();
    cout << " = ";
    r3.addition(r1, r2);
    r3.display();

    cout << endl << endl;

    r1.display();
    cout << " - ";
    r2.display();
    cout << " = ";
    r3.subtract(r1, r2);
    r3.display();
    
    cout << endl << endl;

    r1.display();
    cout << " * ";
    r2.display();
    cout << " = ";
    r3.multiply(r1, r2);
    r3.display();

    cout << endl << endl;

    r1.display();
    cout << " / ";
    r2.display();
    cout << " = ";
    r3.divide(r1, r2);
    r3.display();

    return 0;
}
