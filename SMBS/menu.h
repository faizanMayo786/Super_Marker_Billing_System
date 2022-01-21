#pragma once
#include <iostream>
#include <conio.h>
#include <ctime>
#include <Windows.h>

using namespace std;
char Login() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 20;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_THIN;
	wcscpy_s(cfi.FaceName, L"Raster"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	system("color 0f");
	cout << "\t\t\t\t\t" << char(254) << "      Login Menu       " << char(254) << "\n";
	cout << "\t\t\t\t\t";
	for (int i = 0; i < 25; i++)
	{
		cout << char(178);
	}
	cout << "\n";
	cout << "\t\t\t\t\t" << char(178) << "  1----->Admin         " << char(178) << "\n";
	cout << "\t\t\t\t\t" << char(177) << "  2----->Customer      " << char(177) << "\n";
	cout << "\t\t\t\t\t" << char(177) << "  3----->System Reset  " << char(177) << "\n";
	cout << "\t\t\t\t\t" << char(176) << "  4----->Exit          " << char(176) << "\n";
	cout << "\t\t\t\t\t";
	for (int i = 0; i < 25; i++)
	{
		cout << char(176);
	}
	cout << "\n";
	cout << char(175) << char(175) << char(175) << char(175) << "Enter Choice:\t";
	char status = NULL;
	status = _getche();
	return status;
}
char AdminMenu() {
	system("color 0a");
	cout << "\t\t\t\t\t" << char(254) << "       Admin Menu      " << char(254) << " \n";
	cout << "\t\t\t\t\t";
	for (int i = 0; i < 25; i++)
	{
		cout << char(178);
	}
	cout << "\n";
	cout << "\t\t\t\t\t" << char(178) << "   1----->Add Item     " << char(178) << "\n";
	cout << "\t\t\t\t\t" << char(178) << "   2----->Show Items   " << char(178) << "\n";
	cout << "\t\t\t\t\t" << char(178) << "   3----->Delete Item  " << char(178) << "\n";
	cout << "\t\t\t\t\t" << char(177) << "   4----->Update Item  " << char(177) << "\n";
	cout << "\t\t\t\t\t" << char(177) << "   5----->Search Item  " << char(177) << "\n";
	cout << "\t\t\t\t\t" << char(177) << "   6----->Sort Items   " << char(177) << "\n";
	cout << "\t\t\t\t\t" << char(176) << "   7----->Logout       " << char(176) << "\n";
	cout << "\t\t\t\t\t" << char(176) << "   8----->Exit         " << char(176) << "\n";
	cout << "\t\t\t\t\t";
	for (int i = 0; i < 25; i++)
	{
		cout << char(176);
	}
	cout << "\n";
	cout << char(175) << char(175) << char(175) << char(175) << "Enter Choice:\t";
	char choice = NULL;
	choice = _getche();
	return choice;
}
char CustomerMenu() {

	system("color 06");
	cout << "\t\t\t\t\t" << char(254) << "      Customer Menu     " << char(254) << "\n";
	cout << "\t\t\t\t\t";
	for (int i = 0; i < 26; i++)
	{
		cout << char(178);
	}
	cout << "\n";
	cout << "\t\t\t\t\t" << char(178) << " 1----->Bill            " << char(178) << "\n";
	cout << "\t\t\t\t\t" << char(178) << " 2----->Trnsaction List " << char(178) << "\n";
	cout << "\t\t\t\t\t" << char(177) << " 3----->Update Bill     " << char(177) << "\n";
	cout << "\t\t\t\t\t" << char(177) << " 4----->Search Bill     " << char(177) << "\n";
	cout << "\t\t\t\t\t" << char(177) << " 5----->Delete Bill     " << char(177) << "\n";
	cout << "\t\t\t\t\t" << char(176) << " 6----->Logout          " << char(176) << "\n";
	cout << "\t\t\t\t\t" << char(176) << " 7----->Exit            " << char(176) << "\n";
	cout << "\t\t\t\t\t";
	for (int i = 0; i < 26; i++)
	{
		cout << char(176);
	}
	cout << "\n";
	cout << char(175) << char(175) << char(175) << char(175) << "Enter Choice:\t";
	char choice = NULL;
	choice = _getche();
	return choice;
}
