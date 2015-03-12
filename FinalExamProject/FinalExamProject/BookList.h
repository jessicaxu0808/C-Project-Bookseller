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
1. Class BookList is declared.
2. It has private members: bookList vector of Book, filename.
3. It has public members: BookList constructors, add, get, remove, operator[], listBooks, tally, uppercase, writeToFile, readFromFile, getsize,
	findBooks and partailFindBooks methods.
*/

#ifndef BOOK_LIST
#define BOOK_LIST

#include <vector>
#include "Book.h"



using namespace std;

class BookList
{
private:
	vector<Book> bookList;
	string fileName;

public:
	BookList(string);
	void add(Book&);
	Book& get(int);
	void remove(int);
	Book& operator[](int);
	string listBooks(int);
	double tally(int);
	string upperCase(string);
	void writeToFile();
	void readFromFile();

	int getSize() const;


	//template<typename T>
	void findBooks(int info, string, vector<Book*>&);       /* - the int info parameter denotes what property of a Book object does the user
															want to search the list with(for now, only book properties which are strings can be searched)
															If a match is found between a book objects specific property and the string passed in, then
															that book object is added to the vector which was also passed in to the method(its a parameter)
															- the */

	void partialFindBooks(int info, string, vector<Book*>&);  /*This is the same method as the top one, except the string passed does not have
															  to completely equal the a books title or ISBN, instead, it only has partially equal
															  a books properties and that book will be added to the vector
															  - ie. if the contents of a string passed in was "Alice", then a book
															  with a title of "Alice in Wonderland" would get added to the vector
															  - the string passed in has to match a book titles or ISBN's first N characters only
															  - N is the number of characters in the string passed in*/





};












#endif