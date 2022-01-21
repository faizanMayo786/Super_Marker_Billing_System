#pragma once
#include<iostream>
using namespace std;
struct Date
{
	int day = 0, month = 0, year = 0;
	Date(int day = 0, int month = 0, int year = 0) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	string Show();
};
