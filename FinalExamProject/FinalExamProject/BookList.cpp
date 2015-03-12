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
1. The BookList constructors are defined here. In first constructor the input it takes is string s which is set to filename.
2. The add function takes a reference variable b of type Book. It uses the push_back method in vector and adds the book b into bookList vector.
3. The get function takes an int variable index. This function returns the book which is at the inex value index in the bookList vector.
4. The remove function takes an int variable index. This function uses the erase method of the vector bookList which takes argument of the index
	equal to bookList begin index and index.
5. The listBooks takes an int info as argument. For loop is defined from int i = 0 to size of the bookList vector where a string s is set to the
	value of ith element of bookList which is converted to string using the toString function. The string s is returned.
6. The tally function takes the int variable info. For loop is defined from int i = 0 to size of the bookList vector and a Book reference variable
	is set to bookList[i]. It calculates the retail and wholesale cost by multiplying the retailCost and Wholesalecost with quantity.
7. operator[] is overloaded which takes int variable index and returns the value of get(index).
8. writeToFile function use the same fileName which was used while reading the file. It opens the file in out mode and For loop is defined from int i = 0 
	to size of the bookList vector and the bookList[i] is written into the file.
9. readFromFile function takes in the filename as string input. It opens the file in in mode and until we receive the eof character in the file,
	we read the file into a Book object b and that is added into the bookList vector.
10. getSize function returns the bookList vector's size.
11. findBooks function takes the input int info, string s vector tempV of Book type. tempV is cleared. For loop is defined from int i = 0 to size 
	of the bookList vector and if the bookList[i] equals to string s and value of bookList[i] is returned from tempV vector.
12. partialFindBooks function takes the input int info, string s vector tempV of Book type. tempV is cleared. For loop is defined from int i = 0 to size 
	of the bookList vector and the bookList[i] is returned from tempV vector.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "BookList.h"
#include <fstream>
#include <string>


using namespace std;


BookList::BookList(string s){ fileName = s; }


void BookList::add(Book &b)
{
	bookList.push_back(b);
}

Book& BookList::get(int index)
{
	return bookList.at(index);
}

void BookList::remove(int index)
{
	bookList.erase(bookList.begin() + index);
}

string BookList::listBooks(int info)
{
	string s;
	for (int i = 0; i < (int)bookList.size(); i++){
		s += bookList[i].toString(info);
		if (i != bookList.size() - 1)
			s += "\n\n";
	}
	return s;
}

double BookList::tally(int info)
{
	double d = 0;
	for (int i = 0; i < (int)bookList.size(); i++)
	{
		Book &b = bookList[i];
		if ((info & Book::RET) != 0)
			d += b.getRetailCost() * b.getQuantity();
		if ((info & Book::WCOST) != 0)
			d += b.getWholesaleCost() * b.getQuantity();
	}
	return d;
}

Book& BookList::operator[](int index)
{
	return get(index);
}


void BookList::writeToFile()
{
	std::remove(fileName.c_str());
	ofstream out;
	out.open(fileName, ios::out);
	for (int i = 0; i < (int)bookList.size(); i++)
	{
		out << bookList[i];
		if (i != bookList.size() - 1)
			out << '\n';
	}
	out.close();
}


void BookList::readFromFile()
{
	bookList.clear();
	ifstream in;
	in.open(fileName, ios::in);
	while (!in.eof())
	{
		Book b;
		in >> b;
		bookList.push_back(b);
	}
	in.close();
}

int BookList::getSize() const
{
	return bookList.size();
}

void BookList::findBooks(int info, string s, vector<Book*>&tempV)
{
	tempV.clear();
	for (int i = 0; i < bookList.size(); i++)
	{
		if (bookList[i].getProperty(info) == s)
			tempV.push_back(&bookList[i]);
	}
}


void BookList::partialFindBooks(int info, string s, vector<Book*>&tempV)
{
	tempV.clear();
	for (int i = 0; i < bookList.size(); i++)
	{
		for (int k = 0; k < s.length(); k++)
		{
			s[k] = toupper(s[k]);
		}

		string bProp = bookList[i].getProperty(info);
		if (s.find(bProp.c_str(), 0, s.size()) == 0)
			tempV.push_back(&bookList[i]);
	}
}