#include <windows.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);  
void fontsize(int a, int b)
{  
	HWND hWnd = GetConsoleWindow();
  	ShowWindow(hWnd,SW_SHOWMAXIMIZED);    

	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();  
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
	lpConsoleCurrentFontEx->dwFontSize.X = a;  
	lpConsoleCurrentFontEx->dwFontSize.Y = b;  
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
	
}  

int main()
{ 
	string str = "UPPER-CASE";
	transform(str.begin(),str.end(),str.begin(),(int(*)(int))std::tolower);
	fontsize(35, 35);  
	cout << str << endl;
	cin.ignore();
	return 0;
}
