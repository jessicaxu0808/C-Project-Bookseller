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
1. Class StoreModule is declared.
2. It has protected memeber booklist pointer of type BookList.
3. It has public members: StoreModule constructor, readString, readDouble, readInt, readChar functions are declared.
4. It has private member: isStringDouble function.
*/

#ifndef STORE_MODULE
#define STORE_MODULE

#include "BookList.h"
#include <vector>

using namespace std;

class StoreModule
{
protected:                           //this is defined as protected so that inheriting classes can have acces to it
	BookList *bookList;
public:
	StoreModule(BookList *bookList);           //the constructor
	//virtual void act() = 0;          //the pure virtual function, the act() method basically contains the menu for all classes which choose to inherit of this class
	// also when this method returns, then the option "Return to Main Menu" has probably been called

	/*All modules will have these methods which they call call whenever they want to take in user input.
	All the methods return a boolean, if the boolean is true, that means it succesfully read a double,string,int etc.
	Although if a method returns false, then the user input was invalid, and the method did not succesfully read user input
	For example, if readDouble(&doubTemp) returns false, then the user had probably inputed a word when they were
	only supposed to input letters*/
	bool readString(string&);
	bool readDouble(double&);
	bool readInt(int&);
	bool readChar(char&);

private:
	bool isStringDouble(char*);
};
#endif