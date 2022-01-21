#include "bill.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Bill::Input(Queue itemQueue)
{
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	string customerName, contactNo;
	cout << "Enter Name of Customer:\t";
	getline(cin, customerName);
	cout << "Enter Contact Number:\t";
	cin >> contactNo;

	SetContactNo(contactNo);
	SetCustomerName(customerName);
	SetDate();
	cout << "If you want to Buy Items Press \'1\' or any key to Abort!";
	char key = '0';
	key = _getche();
	if (key == '1')
	{
		BuyItems(itemQueue);

	}

}
void Bill::BuyItems(Queue itemQueue) {

	system("cls");
	int id = 0;
	while (id != -1)
	{
		system("cls");
		Item::TitleRibbon();
		itemQueue.PrintQueue();
		cout << "Note:- Enter \'-1\' to Stop Buying Items.\n";
		double discountAmount = 0;
		double taxAmount = 0;
		cout << "Enter Item ID to Buy that item:\t";
		cin >> id;
		if (itemQueue.Search(id).GetID() == 0) {
			return;
		}
		this->item[itemIndexNo] = itemQueue.Search(id);

		cout << "Enter Quantity of Item:\t";
		cin >> quantity[itemIndexNo];
		CalculateTotalAmount(itemIndexNo);
		itemIndexNo++;
	}
}
double Bill::CalculateTotalAmount(int index) {
	double price = item[index].GetPrice() * quantity[index];
	double discountAmount = price - (price * item[index].GetDiscount() * 0.01);
	double taxAmount = price * (item[index].GetTax() * 0.01);
	totalamount[index] = 0;
	totalamount[index] = discountAmount + taxAmount;
	return totalamount[index];
}
void Bill::BillHeader() {
	cout << "Invoice\n";
	for (int i = 0; i < 8; i++)
	{
		cout << char(205);
	}
	cout << "\n\n";
	cout << "Shopping Billing Managment System\n";
	for (int i = 0; i < 34; i++)
	{
		cout << char(205);
	}
	cout << "\n\n";
	cout << setw(70) << left << "Bill To" << setw(15) << "Invoice #" << setw(26) << right << invoiceID << endl;
	cout << setw(70) << left << customerName << setw(15) << "Date&Time:" << setw(27) << right << datetime;
	cout << setw(70) << left << contactNo << right << endl;
	for (int i = 0; i < 112; i++)
	{
		cout << char(205);
	}
	cout << endl;
	cout << setw(8) << left << "Order#" << setw(10) << "Item ID" << setw(20) << "Item Description" << setw(15) << "Quantity" << setw(15) << "Unit Price" << setw(15) << "Discount" << setw(15) << "Tax" << setw(15) << "Total Amount" << endl;
	for (int i = 0; i < 112; i++)
	{
		cout << char(205);
	}
	cout << endl;
	for (int i = 0; i < 20; i++)
	{
		if (item[i].GetID() != 0)
		{
			cout << left << setw(8) << i + 1 << setw(10) << left << item[i].GetID() << setw(20) << item[i].GetName() << setw(8) << right << quantity[i] << setw(17) << item[i].GetPrice() << setw(13) << item[i].GetDiscount() << "%" << setw(11) << item[i].GetTax() << "%" << setw(23) << fixed << setprecision(2) << CalculateTotalAmount(i) << endl;
		}
	}
	for (int i = 0; i < 112; i++)
	{
		cout << char(205);
	}
	cout << endl;
	cout << right << setw(92) << "Total Dues:" << setw(20) << fixed << setprecision(2) << Max() << endl;
	for (int i = 0; i < 112; i++)
	{
		cout << char(205);
	}
	cout << endl;

	cout << "\t\t\t\t" << char(201) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(187) << " " << char(203) << "    " << char(203) << " " << char(201) << char(205) << char(205) << char(205) << char(205) << char(187) << " " << char(201) << char(205) << char(187) << "  " << char(203) << " " << char(203) << "    " << char(203) << endl;
	cout << "\t\t\t\t" << "    " << char(186) << "     " << char(186) << "    " << char(186) << " " << char(186) << "    " << char(186) << " " << char(186) << " " << char(186) << "  " << char(186) << " " << char(186) << "   " << char(201) << char(188) << endl;
	cout << "\t\t\t\t" << "    " << char(186) << "     " << char(186) << "    " << char(186) << " " << char(186) << "    " << char(186) << " " << char(186) << " " << char(186) << "  " << char(186) << " " << char(186) << "  " << char(201) << char(188) << endl;
	cout << "\t\t\t\t" << "    " << char(186) << "     " << char(204) << char(205) << char(205) << char(205) << char(205) << char(185) << " " << char(204) << char(205) << char(205) << char(205) << char(205) << char(185) << " " << char(186) << " " << char(186) << "  " << char(186) << " " << char(204) << char(205) << char(205) << char(185) << "  " << endl;
	cout << "\t\t\t\t" << "    " << char(186) << "     " << char(186) << "    " << char(186) << " " << char(186) << "    " << char(186) << " " << char(186) << " " << char(186) << "  " << char(186) << " " << char(186) << "  " << char(200) << char(187) << "  " << char(201) << char(205) << char(185) << endl;
	cout << "\t\t\t\t" << "    " << char(186) << "     " << char(186) << "    " << char(186) << " " << char(186) << "    " << char(186) << " " << char(186) << " " << char(186) << "  " << char(186) << " " << char(186) << "   " << char(200) << char(187) << " " << char(200) << char(205) << char(187) << endl;
	cout << "\t\t\t\t" << "    " << char(202) << "     " << char(202) << "    " << char(202) << " " << char(202) << "    " << char(202) << " " << char(202) << " " << char(200) << char(205) << char(205) << char(188) << " " << char(202) << "    " << char(202) << " " << char(204) << char(205) << char(188);
	cout << "For the Shopping!\n";
}
double Bill::Max() {
	double max = 0;
	for (int i = 0; i < this->itemIndexNo; i++)
	{
		max += totalamount[i];
	}
	return max;
}
void Bill::TitleRibbon()
{
	cout << "\t\t\t\t\t\t    " << char(254) << " Invoices " << char(254) << "\t\t\t\t\n";
	cout << "\t\t\t\t\t\t      " << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << "  \t\t\t\t\n";
	cout << "\t\t     " << char(201);
	for (int i = 0; i < 74; i++)
	{
		cout << char(205);
	}
	cout << char(187) << endl;
	cout << "\t\t     " << char(186) << " " << setw(14) << left << "Invoice ID";
	cout << setw(16) << left << "Customer Name";
	cout << setw(18) << "Contact Number";
	cout << setw(14) << "Date/Time" << right << "           " << char(186) << endl;
	cout << "\t\t     " << char(204);
	for (int i = 0; i < 74; i++)
	{
		cout << char(205);
	}
	cout << char(185) << endl;
}
void Bill::Display()
{
	cout << "\t\t     " << char(186) << " " << setw(14) << left << GetInvoiceID();
	cout << setw(16) << left << GetCustomerName();
	cout << setw(18) << GetContactNo();
	cout << setw(0) << GetDate() << " " << char(186) << endl;
}
void Bill::Line() {
	cout << "\t\t     " << char(200);
	for (int i = 0; i < 74; i++)
	{
		cout << char(205);
	}
	cout << char(188) << endl;
}
void Bill::SetInvoiceID(int id)
{
	this->invoiceID = id;
}
void Bill::SetCustomerName(string customerName)
{
	int length = customerName.size();
	length = (length < 15 ? length : 14);
	customerName.copy(this->customerName, length);
	customerName[length] = '\0';
}
void Bill::SetContactNo(string contactNo)
{
	int length = contactNo.size();
	length = (length < 13 ? length : 12);
	contactNo.copy(this->contactNo, length);
	contactNo[length] = '\0';
}
void Bill::SetDate()
{
	time_t now = time(0);
	char dt[26];
	ctime_s(dt, sizeof(dt), &now);
	for (int i = 0; i < 26; i++)
	{
		datetime[i] = dt[i];
	}
}
int Bill::GetInvoiceID()
{
	return invoiceID;
}
string Bill::GetCustomerName()
{
	return customerName;
}
string Bill::GetContactNo()
{
	return contactNo;
}
string Bill::GetDate()
{
	string str = "";
	for (size_t i = 0; i < 24; i++)
	{
		str += datetime[i];
	}
	return str;
}
