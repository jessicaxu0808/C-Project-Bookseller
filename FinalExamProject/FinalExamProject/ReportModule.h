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
		lQT = 4,
		lWSVAL = 5,
		lDT = 6;

	void sort(int st);		//sort method

};

#endif
