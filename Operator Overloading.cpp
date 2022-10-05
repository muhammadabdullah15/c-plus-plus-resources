#include<iostream>
using namespace std;

class cal{
	private:
	int a;
	int b;
	
	public:
	void set()
	{
		cout<<"Enter value of A-> ";
		cin>>a;
		
		cout<<"Enter value of B-> ";
		cin>>b;
	}	
	
	void display()
	{
		cout<<"A= "<<a<<endl;
		cout<<"B= "<<b<<endl;
		
	}
	
	cal operator + (cal);
	cal operator - (cal);
	cal operator * (cal);
	cal operator / (cal);
	
		
};

cal cal::operator +(cal d1)
{
	cal temp;
	
	temp.a=a+d1.a;
	temp.b=b+d1.b;
	
	return temp;
	
}


cal cal::operator -(cal d1)
{
	cal temp;
	temp.a=a-d1.a;
	temp.b=b-d1.b;
	
	return temp;
	
}

cal cal::operator *(cal d1)
{
	
	cal temp;
	
	temp.a=a*d1.a;
	temp.b=b*d1.b;	
	
	return temp;
}

cal cal::operator /(cal d1)
{
	cal temp;
	temp.a=a/d1.a;
	temp.b=b/d1.b;
	
	return temp;
	

}

int main()
{
	cal ob1,ob2,ob3;
	int ch;
	
	cout<<"First number.."<<endl;
	ob1.set();
	
	cout<<"second number.. "<<endl;
	ob2.set();
	
	cout<<"1) Addition. "<<endl
		<<"2) Subtraction. "<<endl	
		<<"3) Multiplication. "<<endl
		<<"4) Division."<<endl;	
	cin>>ch;
	
	switch(ch)
	{
		case 1 : ob3=ob1+ob2;
		ob3.display();
		break;
		
		case 2 : ob3=ob1-ob2;
		ob3.display();
		break;
		
		case 3: ob3=ob1*ob2;
		ob3.display();
		break;
		
		case 4: ob3=ob1/ob2;
		ob3.display();
		break;
		
			
		
		default :
		cout<<"wrong input..";
		
	}	
	
	
	return 0;
}























