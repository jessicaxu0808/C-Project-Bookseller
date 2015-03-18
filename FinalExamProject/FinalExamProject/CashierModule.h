#ifndef CASHIER_MODULE
#define CASHIER_MODULE

#include "StoreModule.h"
#include "InventoryDatabaseModule.h"
#include <vector>
#include <iostream>

using namespace std;

class CashierModule : public StoreModule
{
private:
	string titles[500]; //tracks titles for checkout and receipt
	double prices[500]; //tracks prices for subtotal and receipt
	int items = 0; //counter to track how many items per checkout
	double taxRate = 0.085;
	double subTotal = 0;
	double total = 0;
	static int orderNumber; //tracks how many times the checkout operation has been executed
public:
	CashierModule(BookList*);
	void isbnCheckOut();
	void titleCheckOut();
	void printReceipt();
};

#endif
