//CIS 22B
/*Serendipity BookSeller Program.
Team: Aaron, Jessica, Lakshmi, Pooja.
Author: Pooja Prabhuswamy
Date: 03/19/2015
Description:Serendipity Booksellers is a small bookstore located in a shopping mall. They have a
cashier station equipped with a personal computer. The manager wants you to develop a
point-of-sale (POS) software package that will make the computer function as a cash
register and keep an inventory file. The inventory file will be a database of all the books
in the bookstore. In general, the software is to perform the following tasks:

• Calculate the total of a sale, including sales tax
• When a book is purchased, subtract it from the inventory file
• Add, change, delete, and look up books in the inventory file
• Display various sales reports

Psuedocode:
1. The Date constructors are defined here. The first constructor takes int variables d, m, y which are set to day, month and year. The second
	constructor is set to default values.
2. The getDay function returns the value of day.
3. The getMonth function returns the value of month.
4. The getYear function returns the value of year.
5. The setDay function takes an int variable which is set to day.
6. The setMonth function takes an int variable which is set to day month.
7. The setYear function takes an int variable which is set to day year.
8. The operator < is overloaded which takes a reference variable dOther. It returns true or false based on the result of (year < dOther.year) || 
	(year == dOther.year && month < dOther.month)|| (year == dOther.year && month == dOther.month && day < dOther.day)
9. The operator << is overloaded which takes an ofstream reference variable out and Date reference variable d. The output of the date d is written into
	out and print it onto the screen.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"


using namespace std;



Date::Date(int d, int m, int y) : day(d), month(m), year(y)
{}

Date::Date() : day(0), month(0), year(0)
{}

int Date::getDay() const { return day; }

int Date::getMonth() const { return month; }

int Date::getYear() const{ return year; }

void Date::setDay(int d) { day = d; }

void Date::setMonth(int m) { month = m; }

void Date::setYear(int y) { year = y; }

bool Date::operator<(const Date& dOther)
{
	return (year < dOther.year) || (year == dOther.year && month < dOther.month)
		|| (year == dOther.year && month == dOther.month && day < dOther.day);
}

string Date::toString() const
{
	return to_string(month) + "-" + to_string(day) + "-" + to_string(year);

}


ofstream& operator<<(ofstream& out, const Date& d)
{
	string s = d.toString();
	out.write(s.c_str(), s.size());
	return out;
}

void Date::operator=(string s)
{
	stringstream stream;
	stream << s;
	stream >> month;
	stream >> day;
	stream >> year;
}