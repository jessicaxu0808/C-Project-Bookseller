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
1. Class Date is declared.
2. It has private members: day, month, year.
3. It has public members: Date constructors, setDay, setMonth, setYear, getDay, getMonth, getYear functions, toString function, operator < overloading,
	operator << overloading function, operator = overloaded function.
*/

#ifndef DATE_CLASS
#define DATE_CLASS
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>



class Date
{
private:
	int day, month, year;

public:
	Date();
	Date(int, int, int);

	void setDay(int);
	void setMonth(int);
	void setYear(int);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	std::string toString() const;
	bool operator<(const Date&);

	friend std::ofstream& operator<<(std::ofstream& out, const Date&d);


	void operator=(std::string);

};

#endif