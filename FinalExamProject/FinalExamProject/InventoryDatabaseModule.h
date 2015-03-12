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
1. Class InventoryDatabaseModule is declared which inherits from StoreModule class.
2. It has public members: InventoryDatabaseModule constructor, lookUpBook, addBook, editBook, deleteBook functions are declared.
*/

#ifndef INVENTORY_DATABASE_MODULE
#define INVENTORY_DATABASE_MODULE

#include "StoreModule.h"
#include "Book.h"
#include <vector>
#include <iostream>


using namespace std;

class InventoryDatabaseModule : public StoreModule
{
public:
	InventoryDatabaseModule(BookList*);
	//void act();                  // overriding the virtual method from Module class

	void lookUpBook();            // these are methods that the act() method will call
	void addBook();
	void editBook();
	void deleteBook();


};
#endif 