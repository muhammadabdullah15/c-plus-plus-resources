#include <iostream>  
#include <Windows.h>  
using namespace std;  
HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);  
void fontsize(int,int);  
void testfunc(){
	cout<<"TEST";
}

int main()
{  
	fontsize(25, 25);  
	
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos( consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
	
	cout << "This is a symmetrical font" << endl;  
	testfunc();
}  
void fontsize(int a, int b)
{  
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();  
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
	lpConsoleCurrentFontEx->dwFontSize.X = a;  
	lpConsoleCurrentFontEx->dwFontSize.Y = b;  
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
}  
