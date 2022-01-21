#include "item.h"
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Item::TitleRibbon() {
	cout << "\t\t\t\t\t\t" << char(254) << " Items " << char(254) << "\t\t\t\t\n";
	cout << "\t\t\t\t\t\t" << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << "  \t\t\t\t\n";
	cout << "      " << char(201);
	for (int i = 0; i < 91; i++)
	{
		cout << char(205);
	}
	cout << char(187) << endl;
	cout << "      " << char(186) << " " << setw(6) << left << "ID";
	cout << setw(15) << left << "Name" << right;
	cout << fixed << setprecision(2) << setw(10) << left << "Price" << right;
	cout << fixed << setprecision(2) << setw(12) << "Discount";
	cout << setw(12) << fixed << setw(12) << "Tax";
	cout << setw(15) << left << "      EXD" << right;
	cout << setw(13) << "MFD";
	cout << setw(8) << char(186) << endl;
	cout << "      " << char(204);
	for (int i = 0; i < 91; i++)
	{
		cout << char(205);
	}
	cout << char(185) << "\n";


}
void Item::Input()
{
	int discount = 0, tax = 0, day = 0, month = 0, year = 0;
	double price = 0;
	string name = "";
	cout << "Enter Name:\t";
	cin >> name;
	SetName(name);
	cout << "Enter Price:\t";
	cin >> price;
	SetPrice(price);
	cout << "Enter Discount:\t";
	cin >> discount;
	SetDiscount(discount);
	cout << "Enter Tax:\t";
	cin >> tax;
	SetTax(tax);
	cout << "Enter Manufacture Date(dd mm yyyy):-\n";
	cin >> day >> month >> year;
	SetExpiryDate(Date(day, month, year));
	cout << "Enter Expiry Date(dd mm yyyy):-\n";
	cin >> day >> month >> year;
	SetManufactureDate(Date(day, month, year));

}
void Item::Line()
{
	cout << "      " << char(200);
	for (int i = 0; i < 91; i++)
	{
		cout << char(205);
	}
	cout << char(188) << "\n";
}
void Item::Display() {
	cout << "      " << char(186) << " " << setw(6) << left << this->id;
	cout << setw(15) << left << this->name << right;
	cout << fixed << setprecision(2) << setw(10) << this->price;
	cout << fixed << setprecision(2) << setw(11) << this->discount << "%";
	cout << setw(11) << GetTax() << "%";
	cout << setw(16) << expiryDate.Show();
	cout << setw(18) << manufactureDate.Show() << " " << char(186);
	cout << endl;
}
int Item::GetID() {
	return id;
}
int Item::GetDiscount() {
	return discount;
}
int Item::GetTax() {
	return tax;
}
double Item::GetPrice() {
	return price;
}
string Item::GetName() {
	return name;
}
Date Item::GetExpiryDate() {
	return expiryDate;
}
Date Item::GetManufactureDate() {
	return manufactureDate;
}
void Item::SetID(int id) {
	this->id = id;
}
void Item::SetName(string name) {

	int length = name.size();
	length = (length < 15 ? length : 14);
	name.copy(this->name, length);
	name[length] = '\0';
}
void Item::SetDiscount(int discount) {
	if (discount > 0)
		this->discount = discount;
	else
		this->discount = 0;
}
void Item::SetTax(int tax)
{
	if (tax > 0)
		this->tax = tax;
	else
		this->tax = 0;
}
void Item::SetPrice(double price) {
	if (price > 0)
		this->price = price;
	else
		this->price = 0;
}
void Item::SetExpiryDate(Date  expiryDate) {
	this->expiryDate = expiryDate;
}
void Item::SetManufactureDate(Date manufactureDate) {
	this->manufactureDate = manufactureDate;
}
