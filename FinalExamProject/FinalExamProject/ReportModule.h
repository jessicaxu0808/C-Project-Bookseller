/*CIS 22B
Serendipity BookSeller Program.
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

***********************PSUEDO CODE**********************************
1. Class ReportModule is declared. It inherits from StoreModule class.
2. Private constant static variables are declared. These variables choose how the elemets in booklist are sorted.
const static int dInv = 1
dWSVal = 2,
dRVal = 3,
listQT = 4,
listWSVAL = 5,
listDT = 6;
3. sort() function

4. It has public members : 
ReportModule overloaded constructor
act() function of type void
displayInventory() function of type string
displayWholeSaleValue() function of type string
displayByRetailValue() function of type string
listByQuantity() function of type string
listByCost() function of type string
listByDate() function of type string
*/

#ifndef REPORT_MODULE
#define REPORT_MODULE

#include "StoreModule.h"
#include "Book.h"
#include <vector>

class ReportModule : public StoreModule
{



public:
	ReportModule(BookList*);
	void act();
	string displayInventory();           
	string displayWholeSaleValue();
	string displayByRetailValue();
	string listByQuantity();
	string listByCost();
	string listByDate();


private:           // these variables choose how the elements in bookList are to be sorted 
	const static int dInv = 1,
		dWSVal = 2,
		dRVal = 3,
		listQT = 4,
		listWSVAL = 5,
		listDT = 6;

	void sort(int st);		//sort method

};

#endif
