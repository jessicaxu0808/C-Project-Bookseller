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

*********************************PSUEDO CODE***************************************
The functions implemented are -

1. Display inventory
displayInventory() -
This function displays list of information on all the books.
2. Display and tally the wholesale value
displayWholeSaleValue()
This function displays list of the wholesale value of all the books in the inventory and the total wholesale value
of the inventory.
3. Display and tally the retail value 
displayByRetailValue()
This function displays a list of the retail value of all books in the inventory and the total retail value of the 
inventory.
4. List by quantity
listByQuantity()
This function displays a list of all books in the inventory sorted by quantity on hand. The books with the 
greatest quantity on hand will be listed first.
5. List by cost
listByCost()
This function displays a list of all books in the inventory, sorted by wholesale cost. The
books with the greatest wholesale cost will be listed first.
6. List by age
listByDate()
A list of all books in the inventory, sorted by purchase date. The books that have been in the inventory 
longest will be listed first.
7. The sort() function uses the selection sort algorithm.
- locate the i-th smallest element in the AccountInfo array
- move the i-th smallest element to the i-th position, and move the element which was previously at the i-th index into the now vacant indice
- call the recursive function again
- base case: if the int i is == size-1, then return out of method
*/

#define _CRT_SECURE_NO_WARNINGS
#include "ReportModule.h"
#include <vector>
#include <iostream>
#include "Book.h"

ReportModule::ReportModule(BookList*b) : StoreModule(b)
{
}

string ReportModule::displayInventory()
{
	return bookList->listBooks(Book::EVERYTHING);
}

string ReportModule::displayWholeSaleValue()
{
	string s = bookList->listBooks(Book::ISB | Book::BKTTLE | Book::AUTHNAME | Book::WCOST);
	s += "\n\nTotal Wholesale Value: " + to_string(bookList->tally(Book::WCOST));
	return s;
}
string ReportModule::displayByRetailValue()
{
	string s = bookList->listBooks(Book::ISB | Book::BKTTLE | Book::AUTHNAME | Book::RET);
	s += "\n\nTotal Retail Value: " + to_string(bookList->tally(Book::RET));
	return s;
}
string ReportModule::listByQuantity()
{
	sort(lQT);
	return bookList->listBooks(Book::ISB | Book::BKTTLE | Book::AUTHNAME | Book::QUANT);

}
string ReportModule::listByCost()
{
	sort(lWSVAL);
	return bookList->listBooks(Book::ISB | Book::BKTTLE | Book::AUTHNAME | Book::WCOST);
}
string ReportModule::listByDate()
{
	sort(lDT);
	return bookList->listBooks(Book::ISB | Book::BKTTLE | Book::AUTHNAME | Book::DATE);
}


void ReportModule::sort(int st)
{
	int i, j, first;
	Book temp;
	int numLength = bookList->getSize();
	for (i = 0; i < numLength; i++) {
		first = i;
		for (j = i; j < numLength; j++) {

			if (st == lQT){
				if ((*bookList)[j].getQuantity() < (*bookList)[first].getQuantity())
					first = j;
			}
			else if (st == lWSVAL){
				if ((*bookList)[j].getWholesaleCost() <(*bookList)[first].getWholesaleCost())
					first = j;
			}
			else if (st == lDT){
				if ((*bookList)[j].getDate() < (*bookList)[first].getDate())
					first = j;
			}
		}
		temp = (*bookList)[first];   // Swap smallest found with element in position i.
		(*bookList)[first] = (*bookList)[i];
		(*bookList)[i] = temp;
	}
}

