#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void menu();
void func(int);

void menu()
{
	int Set[] = {12,7,7,7,7,7,7,7}; // DEFAULT COLORS
    int counter = 1;
    char key;

    while(true)
    {
    	system("cls");
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    	cout << "Please choose from the following options:" << endl;
    	
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),Set[0]);
        cout<<"1) Add new user";

        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),Set[1]);
        cout<<"2) Delete an existing user";

        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),Set[2]);
        cout<<"3) Search user and their outstanding books";

        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),Set[3]);
        cout<<"4) Loan book to user";

        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),Set[4]);
        cout<<"5) Return book from user";
        
        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),Set[5]);
        cout<<"6) Display list of users";
        
        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),Set[6]);
        cout<<"7) Display list of books and their status";
        
        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),Set[7]);
        cout<<"8) Exit program";
        
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        
        cout<<endl;

        key = _getch();

        if(key == 72 && (counter >=2 && counter <= 8))
            counter--;
        if(key == 80 && (counter >=1 && counter <= 7))
            counter++;
        if(key == '\r')		//ENTER KEY
        {
            switch (counter)
		    {
		    case 1:
		        system("cls");
				func(1);
		        break;
		    case 2:
		        system("cls");
		        func(2);
		        break;
		    case 3:
		        system("cls");
		        func(3);
		        break;
		    case 4:
		        system("cls");
		        func(4);
		        break;
		    case 5:
		        system("cls");
		        func(5);
		        break;
		    case 6:
		        system("cls");
		        func(6);
		        break;
		    case 7:
		        system("cls");
		        func(7);
		        break;
		    case 8:
		        system("cls");
		        func(8);
		        break;
		    default:
		        cout << "Invalid entry! Please enter correct choice" << endl << endl;
		        menu();
		    }
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;
        Set[4] = 7;
        Set[5] = 7;
        Set[6] = 7;
        Set[7] = 7;

		Set[counter-1] = 12;
	}
		
}

void func(int a)
{
	cout<<a<<endl;
	system("pause");
	menu();
}

int main()
{
 	menu();   
 	return 0;
}
