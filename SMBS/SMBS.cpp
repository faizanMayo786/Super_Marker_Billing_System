#include <iostream>
#include <string>
#include <fstream>
#include "queue.h"
#include "item.h"
#include "menu.h"
#include "functions.h"
#include "bill.h"
#include <conio.h>
using namespace std;

int main() {
	HWND hWnd = GetConsoleWindow();
	MoveWindow(hWnd, 100, 86, 950, 500, TRUE);
	int created = 1;
	while (true)
	{
		system("cls");
		char status = Login();
		while (true)
		{
			if (status == '1') {
				Queue itemQueue;
				system("cls");
				char choice;
				choice = AdminMenu();
				system("cls");
				if (choice == '1') {
					InsertItem(created);
				}
				else if (choice == '2')
				{
					DisplayAll(created);
				}
				else if (choice == '3')
				{
					DeleteItem(created);
				}
				else if (choice == '4')
				{
					UpdateItem(created);
				}
				else if (choice == '5') {
					SearchItem(created);
				}
				else if (choice == '6') {
					SortItems(created);
				}
				else if (choice == '7')
				{
					break;
				}
				else if (choice == '8')
				{
					return 0;
				}
				else
				{
					choice = NULL;
					continue;
				}
			}
			else if (status == '2')
			{
				system("cls");
				Stack stackBill;
				char choice = CustomerMenu();
				system("cls");
				if (choice == '1')
				{
					InsertBill(created);
				}
				else if (choice == '2')
				{
					Trasactions(created);
				}
				else if (choice == '3')
				{
					UpdateBill(created);
				}
				else if (choice == '4')
				{
					SearchBill(created);
				}
				else if (choice == '5')
				{
					DeleteBill(created);
				}
				else if (choice == '6')
				{
					break;
				}
				else if (choice == '7')
				{
					return 0;
				}
				else
				{
					choice = NULL;
					continue;
				}
			}
			else if (status == '3') {
				SystemReset();
				cout << "Restart the System!\n";
				system("puase");
				return 0;
			}
			else if (status == '4') {
				system("cls");
				return 0;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}
