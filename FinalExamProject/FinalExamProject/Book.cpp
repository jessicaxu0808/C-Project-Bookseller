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
1. The Book constructors are defined here. In first constructor all the values of variables are set to default values. ISBN = "",bookTitle = "",
	authorName = "", publisher = "", date, quantity = 0, wholesaleCost = 0, retailCost = 0.
2. The second constructor takes in the value of string ISBN, string b, string a, string p, int day, int month, int year, int q, double c, double r
	as input and sets them to ISBN, bookTitle, authorName, publisher, date, quantity, wholesaleCost, retailCost.
3. toString function has multiple if else condition where it checks if the info value which is the input for this function and the values 
	of ISB, BKTTLE, AUTHNAME, PUB, DATE, QUANT, WCOST, RET is != 0 in each case and then sets the value of string s to respective values of 
	ISBN, Book title, Author, Publisher, date, Wholesale Cost, Retail Cost in the form of string. s retruned at the end of this function.
4. upperCase function takes a string input. for each character of the string the funtion toUpper is called and the character is set to upper case
	and the string is returned.
5. help function takes a boolean reference variable b. If !b it sets b to 1 and returns null value. Else it returns "\n" value.
6. setISBN takes a string input. This input is set to value of ISBN.
7. setBookTitle takes a string input. This input is set to value of bookTitle.
8. setAuthorName takes a string input. This input is set to value of authorName.
9. setPublisher takes a string input. This input is set to value of publisher.
10. setQuantity takes a int input. This input is set to value of quantity.
11. setWholesaleCost takes a double input. This input is set to value of wholesaleCost.
12. setRetailCost takes a double input. This input is set to value of retailCost.
13. setDay takes a int input. This input is set to value of day of date class.
14. setMonth takes a int input. This input is set to value of month of date class.
15. setYear takes a int input. This input is set to value of year of date class.
16. getISBN returns value of ISBN.
17. getBookTitle returns value of bookTitle.
18. getAuthorName returns value of authorName.
19. getPublisher returns value of publisher.
20. getQuantity returns value of quantity.
21. getWholesaleCost returns value of wholesaleCost.
22. getRetailCost returns value of retailCost.
23. getProperty checks if input infor and Book class's ISB, BKTITLE, AUTHNAME, PUB is != 0 and then returns ISBN, bookTitle in uppercase,
	authorName and publisher.
24. Opertor << is overloaded using reference variables ofstream out and Book b. It outputs b.ISBN, b.bookTitle, b.authorName, b.publisher,
	b.date, b.quantity, b.wholesaleCost, b.retailCost along with \n.
25. Operator >> is overloaded using the reference variables ifstream in and Book b. It takes in the input of 500 characters and stores it into 
	b.ISBN, b.bookTitle, b.authorName, b.publisher,	b.date, b.quantity, b.wholesaleCost, b.retailCost.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

using namespace std;

Book::Book()
{

	//set all variables to a 'default' value
	ISBN = "";
	bookTitle = "";
	authorName = "";
	publisher = "";

	date;

	quantity = 0;
	wholesaleCost = 0;
	retailCost = 0;

}
Book::Book(string ISBN, string b, string a, string p, int day, int month, int year, int q, double c, double r) :
ISBN(ISBN), bookTitle(b), authorName(a), publisher(p), date(day, month, year), quantity(q), wholesaleCost(c), retailCost(r)
{}



//SHOULD WE ADD A NEW LINE IN FRONT OF ISBN?
string Book::toString(int info)
{
	string s;
	bool flag = 0;
	int inc = 0;
	if ((info & Book::ISB) != 0)  // 1
		s += help(flag) + "ISNB: " + ISBN;
	if ((info & Book::BKTTLE) != 0)  // 2
		s += help(flag) + "Title: " + bookTitle;
	if ((info & Book::AUTHNAME) != 0)  // 4
		s += help(flag) + "Author: " + authorName;
	if ((info & Book::PUB) != 0)   // 8
		s += help(flag) + "Publisher: " + publisher;
	if ((info & Book::DATE) != 0)   // 16
		s += help(flag) + "Date Added: " + date.toString();
	if ((info & Book::QUANT) != 0)   // 32
		s += help(flag) + "Quantity-On-Hand: " + to_string(quantity);
	if ((info & Book::WCOST) != 0)   // 64
		s += help(flag) + "Wholesale Cost: " + to_string(wholesaleCost);
	if ((info & Book::RET) != 0)   // 128
		s += help(flag) + "Retail Price: " + to_string(retailCost);
	return s;
}

string Book::upperCase(string name)
{
	for (int s = 0; s < name.length(); s++)
	{
		name[s] = toupper(name[s]);
	}
	return name;
}

string Book::help(bool &b)
{
	if (!b){
		b = 1;
		return "";
	}
	return "\n";

}

void Book::setISBN(string number)
{
	ISBN = number;
}

void Book::setBookTitle(string title)
{
	bookTitle = title;
}

void Book::setAuthorName(string Aname)
{
	authorName = Aname;
}

void Book::setPublisher(string pub)
{
	publisher = pub;
}
void Book::setQuantity(int number)
{
	quantity = number;
}

void Book::setWholesaleCost(double price)
{
	wholesaleCost = price;
}

void Book::setRetailCost(double sellBack)
{
	retailCost = sellBack;
}

void Book::setDay(int d)
{
	date.setDay(d);
}

void Book::setMonth(int m)
{
	date.setMonth(m);
}

void Book::setYear(int y)
{
	date.setYear(y);
}

string Book::getISBN() const
{
	return ISBN;
}
string Book::getBookTitle() const
{
	return bookTitle;
}
string Book::getAuthorName() const
{
	return authorName;
}
string Book::getPublisher() const
{
	return publisher;
}
int Book::getMonth() const
{
	return date.getMonth();
}
int Book::getDay() const
{
	return date.getDay();
}
int Book::getYear() const
{
	return date.getYear();
}
Date Book::getDate() const
{
	return date;
}
int Book::getQuantity() const
{
	return quantity;
}
double Book::getWholesaleCost() const
{
	return wholesaleCost;
}
double Book::getRetailCost() const
{
	return retailCost;
}

//template<typename T>
string Book::getProperty(int info)
{
	string title;
	title = upperCase(bookTitle);
	if ((info & Book::ISB) != 0)  // 1
		return this->ISBN;
	else if ((info & Book::BKTTLE) != 0)  // 2
		return title;
	else if ((info & Book::AUTHNAME) != 0)  // 4
		return authorName;
	else if ((info & Book::PUB) != 0)   // 8
		return publisher;

	//right now, the code can only handle getters of properties that are strings
	//the code really shouldnt reach here
	return "";
}


ofstream& operator<<(ofstream& out, Book& b)
{
	//PUT ENDLINE INSTEAD?
	const char endL = '\n';
	out << b.ISBN << endL;
	out << b.bookTitle << endL;
	out << b.authorName << endL;
	out << b.publisher << endL;
	out << b.date.getMonth() << ' ' << b.date.getDay() << ' ' << b.date.getYear() << endL;   //ONCE THE PROGRAM IS WORKING, MAKE A << OPERATOR FOR DATE
	out << b.quantity << endL;
	out << b.wholesaleCost << endL;
	out << b.retailCost;
	return out;
}

ifstream& operator>>(ifstream& in, Book&b)
{
	const char endL = '\n';
	char c[500];
	in.getline(c, 500, endL);
	b.ISBN = c;
	in.getline(c, 500, endL);
	b.bookTitle = c;
	in.getline(c, 500, endL);
	b.authorName = c;
	in.getline(c, 500, endL);
	b.publisher = c;
	in.getline(c, 500, endL);
	string sTemp(c);                //ONCE THE PROGRAM IS WORKING, MAKE A >> OPERATOR FOR DATE
	b.date = sTemp;
	in.getline(c, 500, endL);
	b.quantity = atoi(c);
	in.getline(c, 500, endL);
	b.wholesaleCost = atof(c);
	in.getline(c, 500, endL);
	b.retailCost = atof(c);
	return in;
}