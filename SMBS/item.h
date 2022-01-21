#pragma once
#include "date.h"
#include <string>
#include <conio.h>
using  namespace std;
class Item
{
private:
	int id = 0, discount = 0, tax = 0;
	double price = 0;
	char name[15] = { "" };
	Date expiryDate;
	Date manufactureDate;
public:
	Item(int id = 0, string name = "", double price = 0.0, int discount = 0, int tax = 0, Date expiryDate = Date(), Date manufactureDate = Date()) {
		SetID(id);
		SetName(name);
		SetPrice(price);
		SetDiscount(discount);
		SetTax(tax);
		SetExpiryDate(expiryDate);
		SetManufactureDate(manufactureDate);
	}int GetID();
	int GetDiscount();
	int GetTax();
	double GetPrice();
	string GetName();
	Date GetExpiryDate();
	Date GetManufactureDate();
	void SetID(int);
	void SetName(string);
	void SetDiscount(int);
	void SetTax(int);
	void SetPrice(double);
	void SetExpiryDate(Date);
	void SetManufactureDate(Date);
	void Display();
	static void TitleRibbon();
	void Input();
	static void Line();
};
