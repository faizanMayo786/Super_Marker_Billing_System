#include "item.h"
#include "filestreams.h"
#pragma once
void InsertItem(int created) {
	Queue itemQueue;
	if (created == 1) {
		itemQueue = ReadItemStream(itemQueue);
	}
	created = 1;
	WriteItemStream(itemQueue);
	system("pause");
	system("cls");
}
void DeleteItem(int created) {
	if (created == 1)
	{
		Queue itemQueue;
		int id = -1;
		Item::TitleRibbon();
		itemQueue = ReadItemStream(itemQueue);
		itemQueue.PrintQueue();
		cout << "\nNote: Press \'-1\' to exit this action.\n";
		cout << "\nEnter Item ID to Delete that Item Record:\t";
		cin >> id;

		if (id == -1) {
			system("pause");
			return;
		}
		itemQueue.DeleteSpecific(id);
		OverwriteItemStream(itemQueue);
		system("pause");
		system("cls");
	}
}
void SearchItem(int created) {
	if (created == 1)
	{

		Queue itemQueue;
		int id;
		Item::TitleRibbon();
		itemQueue = ReadItemStream(itemQueue);
		itemQueue.PrintQueue();
		cout << "\nNote: Press \'-1\' to exit this action.\n";
		cout << "\nEnter Item ID to Search that Item Record:\t";
		cin >> id;

		if (id == -1) {
			system("pause");

			return;
		}
		itemQueue.Search(id);

		system("pause");
		system("cls");
	}
}
void DisplayAll(int created) {
	Queue itemQueue;
	Item::TitleRibbon();
	if (created == 1)
	{
		itemQueue = ReadItemStream(itemQueue);
		itemQueue.PrintQueue();
	}
	system("pause");
	system("cls");
}
void UpdateItem(int created) {
	if (created == 1)
	{
		Queue itemQueue;
		int id;
		Item::TitleRibbon();
		itemQueue = ReadItemStream(itemQueue);
		itemQueue.PrintQueue();
		cout << "\nNote: Press \'-1\' to exit this action.\n";
		cout << "\nEnter Item ID to Update/Edit that Item Record:\t";
		cin >> id;
		if (id == -1) {
			system("pause");
			return;
		}
		itemQueue.UpdateData(id);
		OverwriteItemStream(itemQueue);
		system("pause");
		system("cls");
	}
}
void SortItems(int created) {
	if (created == 1)
	{
		Queue itemQueue;
		itemQueue = ReadItemStream(itemQueue);
		itemQueue.Sort();
		Item::TitleRibbon();
		itemQueue.PrintQueue();
		OverwriteItemStream(itemQueue);
		system("pause");
		system("cls");
	}
}
void InsertBill(int created) {
	Stack billStack;
	if (created == 1) {
		billStack = ReadBillStream(billStack);
	}
	created = 1;
	WriteBillStream(billStack);
	system("pause");
	system("cls");
}
void Trasactions(int created) {
	Stack stackBill;
	if (created == 1)
	{
		stackBill = ReadBillStream(stackBill);
		stackBill.Print();
	}
	cout << "Note: Press \'-1\' to Go Back!\n";
	cout << "Enter Invoice ID to See Details of Order:\t";
	int id;
	cin >> id;
	if (id != -1)
	{

		Bill bill = stackBill.Search(id);
		system("cls");
		bill.BillHeader();

	}
	system("pause");
	system("cls");
}
void DeleteBill(int created) {
	if (created == 1)
	{
		Stack stackBill;
		int id = -1;
		stackBill = ReadBillStream(stackBill);
		stackBill.Print();
		cout << "\nNote: Press \'-1\' to exit this action.\n";
		cout << "\nEnter Item ID to Delete that Bill:\t";
		cin >> id;

		if (id == -1) {
			system("pause");
			return;
		}
		stackBill.Delete(id);
		OverwriteBillStream(stackBill);
		system("pause");
		system("cls");
	}
}
void SearchBill(int created) {
	if (created == 1)
	{

		Stack stackBill;
		int id;
		stackBill = ReadBillStream(stackBill);
		stackBill.Print();
		cout << "\nNote: Press \'-1\' to exit this action.\n";
		cout << "\nEnter Item ID to Search that Bill Record:\t";
		cin >> id;

		if (id == -1) {
			system("pause");

			return;
		}
		stackBill.Search(id);

		system("pause");
		system("cls");
	}
}
void UpdateBill(int created) {
	if (created == 1)
	{
		Stack billStack;
		int id;
		billStack = ReadBillStream(billStack);
		billStack.Print();
		Queue read;
		read = ReadItemStream(read);
		cout << "\nNote: Press \'-1\' to exit this action.\n";
		cout << "\nEnter Item ID to Update/Edit that Bill Record:\t";
		cin >> id;
		if (id == -1) {
			system("pause");
			return;
		}
		billStack.Update(id, read);
		OverwriteBillStream(billStack);
		system("pause");
		system("cls");
	}
}
void SystemReset() {
	system("cls");
	fstream file("items.dat", ios::out);
	file.clear();
	file.close();
	fstream file2("bills.dat", ios::out);
	file2.clear();
	file2.close();
	cout << "Factory Reset Complete!\n";
}
