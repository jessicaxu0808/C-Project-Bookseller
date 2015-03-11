#ifndef CASHIER_MODULE
#define CASHIER_MODULE

#include "StoreModule.h"
#include "Book.h"
#include <vector>
#include <iostream>

using namespace std;

class CashierModule : public StoreModule
{
private:
	string titles[500];
	double prices[500];
	int items = 0;
	double taxRate = 0.085;
	double subTotal = 0;
	double total = 0;
	static int orderNumber;
public:
	CashierModule(BookList*);
	void isbnLookUp(string);
	void titleLookUp(string);
	void isbnCheckOut();
	void titleCheckOut();
	void printReceipt();
};

#endif
