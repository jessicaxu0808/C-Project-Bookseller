Enter file contents here#define _CRT_SECURE_NO_WARNINGS
#include "CashierModule.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int CashierModule::orderNumber = 1;

CashierModule::CashierModule(BookList *b) :StoreModule(b)
{
	items = 0;
}

void CashierModule::isbnLookUp(string book){
	vector<Book*> tempV;
	bookList->partialFindBooks(1, book, tempV);
	if (tempV.size() == 1){
		items++;
		titles[items] = tempV[0]->getBookTitle();
		prices[items] = tempV[0]->getRetailCost();
		subTotal += tempV[0]->getRetailCost();
		cout << endl << "$" << fixed << setprecision(2) << prices[items] << "     " << titles[items] << endl << endl;
	}
	else if (tempV.size() > 1)
	{
		cout << "Multiple Books found, please specify your selection: " << endl;
		for (int i = 0; i < tempV.size(); i++)
			cout << (i + 1) << ") " << tempV[i]->toString(Book::ISB | Book::BKTTLE) << endl << endl;
		cout << "Type in the number which corresponds to the book you want: ";
		int answ;
		while (!readInt(answ) || (answ < 1) || (answ >tempV.size())) {
			cout << "\nPlease enter a number between 1 and " << tempV.size() << ": ";
		}
		items++;
		titles[items] = tempV[0]->getBookTitle();
		prices[items] = tempV[0]->getRetailCost();
		subTotal += tempV[0]->getRetailCost();
		cout << endl << "$" << fixed << setprecision(2) << prices[items] << "     " << titles[items] << endl << endl;
	}
	else{
		cout << "Sorry, the book you entered was not found." << endl << endl;
	}
}

void CashierModule::titleLookUp(string book){
	vector<Book*> tempV;
	bookList->partialFindBooks(2, book, tempV);
	if (tempV.size() == 1){
		items++;
		titles[items] = tempV[0]->getBookTitle();
		prices[items] = tempV[0]->getRetailCost();
		subTotal += tempV[0]->getRetailCost();
		cout << endl << "$" << fixed << setprecision(2) << prices[items] << "     " << titles[items] << endl << endl;
	}
	else if (tempV.size() > 1)
	{
		cout << "Multiple Books found, please specify your selection: " << endl;
		for (int i = 0; i < tempV.size(); i++)
			cout << (i + 1) << ") " << tempV[i]->toString(Book::ISB | Book::BKTTLE) << endl << endl;
		cout << "Type in the number which corresponds to the book you want: ";
		int answ;
		while (!readInt(answ) || (answ < 1) || (answ >tempV.size())) {
			cout << "\nPlease enter a number between 1 and " << tempV.size() << ": ";
		}
		items++;
		titles[items] = tempV[0]->getBookTitle();
		prices[items] = tempV[0]->getRetailCost();
		subTotal += tempV[0]->getRetailCost();
		cout << endl << "$" << fixed << setprecision(2) << prices[items] << "     " << titles[items] << endl << endl;
	}
	else{
		cout << "Sorry, the book you entered was not found." << endl << endl;
	}
}

void CashierModule::isbnCheckOut(){
	if (system("CLS")) system("clear");
	string book = "default";
	char yn;
	bool exit = false;
	bool checkout = false;
	cout << setw(30) << "Order Number 000" << orderNumber << endl;
	cout << setw(49) << "Type 'Checkout' to complete purchase, or 'Exit' to cancel." << endl << endl;

	while (exit == false){
		while (checkout == false){
			cout << "     Please enter the ISBN of the book you wish to purchase: ";
			cin >> book;
			cin.clear();
			cin.ignore(1000, '\n');

			if (book == "checkout" || book == "Checkout"){
				checkout = true;
				break;
			}

			if (book == "exit" || book == "Exit"){
				exit = true;
				break;
			}

			isbnLookUp(book);

		}
		if (exit == true){
			break;
		}

		else{
			orderNumber++;
			cout << endl << "                                             Subtotal: " << subTotal << endl;
			cout << "                                             Tax:      " << subTotal * taxRate << endl;
			cout << "                                             Total:    " << subTotal * (1 + taxRate) << endl << endl;
			cout << "Would you like to a printable copy of your receipt? (Y/N)" << endl;
			cin >> yn;
			cin.clear();
			cin.ignore(1000, '\n');

			while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N'){
				cout << "Please select 'Y' or 'N': " << endl;
				cin >> yn;
				cin.clear();
				cin.ignore(1000, '\n');
			}

			if (yn == 'y' || yn == 'Y'){
				printReceipt();
			}
			items = 0;
			exit = true;
		}
	}
	system("pause");

	if (system("CLS")) system("clear");
}

void CashierModule::titleCheckOut(){
	if (system("CLS")) system("clear");
	string book = "default";
	char yn;
	bool exit = false;
	bool checkout = false;
	cout << setw(30) << "Order Number 000" << orderNumber << endl;
	cout << setw(49) << "Type 'Checkout' to complete purchase, or 'Exit' to cancel." << endl << endl;

	while (exit == false){
		while (checkout == false){
			cout << "     Please enter the ISBN of the book you wish to purchase: ";
			cin >> book;
			cin.clear();
			cin.ignore(1000, '\n');

			if (book == "checkout" || book == "Checkout"){
				checkout = true;
				break;
			}

			if (book == "exit" || book == "Exit"){
				exit = true;
				break;
			}

			titleLookUp(book);

		}
		if (exit == true){
			break;
		}

		else{
			orderNumber++;
			cout << endl << "                                             Subtotal: " << subTotal << endl;
			cout << "                                             Tax:      " << subTotal * taxRate << endl;
			cout << "                                             Total:    " << subTotal * (1 + taxRate) << endl << endl;
			cout << "Would you like to a printable copy of your receipt? (Y/N)" << endl;
			cin >> yn;
			cin.clear();
			cin.ignore(1000, '\n');

			while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N'){
				cout << "Please select 'Y' or 'N': " << endl;
				cin >> yn;
				cin.clear();
				cin.ignore(1000, '\n');
			}

			if (yn == 'y' || yn == 'Y'){
				printReceipt();
			}
			items = 0;
			exit = true;
		}
	}
	system("pause");

	if (system("CLS")) system("clear");
}

void CashierModule::printReceipt(){
	if (system("CLS")) system("clear");
	cout << setw(30) << "Order Number 000" << orderNumber - 1 << endl << endl;
	for (int i = 0; i < items; i++){
		cout << titles[i + 1] << endl;
		cout << "                             $" << fixed << setprecision(2) << prices[i + 1] << endl << endl;
	}
	cout << "-------------------------------------------------" << endl;
	cout << "                             Subtotal: " << subTotal << endl;
	cout << "                             Tax:      " << subTotal * taxRate << endl;
	cout << "                             Total:    " << subTotal * (1 + taxRate) << endl << endl;
	cout << "Thank you for shopping at P.A.J.L Books! We hope you come again!" << endl << endl << endl;
	cin.get();
}
