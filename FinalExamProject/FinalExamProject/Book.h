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
1. Class Book is declared.
2. It has private members: ISBN, bookTitle, authorName, publisher, date, quantity, wholesaleCost, retailCost and bool function.
3. It has public members: Book constructors, setISBN, setBookTitle, setAuthorName, setPublisher, setQuantity, setWholesaleCost, setRetailCost,
	setDay, setMonth, setYear, getISBN, getBookTitle, getAuthorName, getPublisher, getQuantity, getWholesaleCost, getRetailCost,
	getDay, getMonth, getYear, getProperty, operator >> overloaded function, operator << overloaded function.
4. The values of ISB, BKTTLE = 2, AUTHNAME = 4,	PUB = 8, DATE = 16,	QUANT = 32,	WCOST = 64, RET = 128,
	EVERYTHING = 255 are set as constant static int.
*/
#ifndef BOOKARRAY_H
#define BOOKARRAY_H

#include <string>
#include <iostream>
#include <fstream>
#include "Date.h"


using namespace std;



class Book //Class to outline the information of a book
{




private:
	string ISBN; //Int code
	string bookTitle; //Title of the book
	string authorName; //Author's name
	string publisher; //Book's Publisher

	Date date;
	int quantity; //How many copies of the book is there
	double wholesaleCost; //Price of the book
	double retailCost; //Sellback price of the book

	string help(bool&);


public:
	//constructors
	Book(string, string, string, string, int, int, int, int, double, double); //Constructor
	Book();

	string toString(int);
	string upperCase(string);



	//Mutators
	void setISBN(string);
	void setBookTitle(string);
	void setAuthorName(string);
	void setPublisher(string);
	void setQuantity(int);
	void setWholesaleCost(double);
	void setRetailCost(double);
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	//Accessors
	string getISBN() const;
	string getBookTitle() const;
	string getAuthorName() const;
	string getPublisher() const;
	int getMonth() const;           //SHOULD WE DELETE THESE OTHER METHODS?
	int getDay() const;
	int getYear() const;
	Date getDate() const;
	int    getQuantity() const;
	double getWholesaleCost() const;
	double getRetailCost() const;

	//template<typename T >
	string getProperty(int);


	friend ofstream& operator<<(ofstream& out, Book& b);
	friend ifstream& operator>>(ifstream& in, Book&b);

	//static
	const static int ISB = 1,                  // the purpose of these static variables is for the ReportModule to decide which properties of Book do we want to display out
		BKTTLE = 2,
		AUTHNAME = 4,
		PUB = 8,
		DATE = 16,
		QUANT = 32,
		WCOST = 64,
		RET = 128,                    //it ended exactly at 8, so these values can be representated with 1 int
		EVERYTHING = 255;

};
#endif