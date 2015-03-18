//CIS 22B
/*Serendipity BookSeller Program.
Team: Aaron, Jessica, Lakshmi, Pooja.
Author: Jessica Xu
Date: 03/19/2015
Description: The Cashier Module handles the following functions:

• Calculate the total of a sale, including sales tax
• When a book is purchased, subtract it from the inventory
• Allow an order to be canceled without changing the inventory
• Print an optional receipt upon purchase

Pseudocode:
1. CashierModule inherits BookList pointer b from StoreModule, which opens the inventory file from Booklist.h
2. The constructor sets 'items', which tracks how many books are in the checkout queue, to 0.
3. isbnCheckOut allows the user to input up to 500 books and choose to either checkout or cancel the order.
	-Begins loop for multiple consecutive checkouts
		-Begins loop for multiple book purchases each time the checkout loop is run
			-Asks user for the ISBN of the book being purchased
			-Searches booklist for a matching ISBN or partial ISBN
			-If exactly one match is found, checks if quantity in stock > 0
				-If so, add the book to the checkout queue, deduct one from inventory quantity, and store book info in titles[] and prices[] for receipt. Increment items by 1.
				-If not, output a message that the book is out of stock
			-If more than one match is found, output a list of all partial matches and allow user to choose
				-Loop to check for a valid choice from the list
				-Check if the quantity of the selected book > 0
					-If so, add the book to the checkout queue, deduct one from inventory quantity, and store book info in titles[] and prices[] for receipt Increment items by 1.
					-If not, output a message that the book is out of stock
			-In every loop, check if the word 'Checkout' or 'checkout' is inputted
				-If so, break loop and proceed to checkout
					-Calculate amd output subtotal by totalling all elements in prices[]
					-Reset items to zero
					-Calculate and output sales tax
					-Calculate and output total
					-Ask user if they wish to print a receipt
			-In every loop, check if the word 'Exit' or 'exit' is inputted
				-If so, break loop and return to checkout menu
				-Restore all inventory quantities to original amounts before that iteration of the checkout loop
				-Reset items to zero
4. titleCheckOut performs the same function as isbnCheckOut, except it searches books by title or partial title instead of isbn
5. printReceipt uses the titles[] and prices[] array to output a list off all books purchased in that iteration of the checkout loop, along with the subtotal, tax, and total
*/


#define _CRT_SECURE_NO_WARNINGS
#include "CashierModule.h"
#include "Book.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int CashierModule::orderNumber = 1;

CashierModule::CashierModule(BookList *b) :StoreModule(b)
{
	items = 0;
}

void CashierModule::isbnCheckOut(){
	if (system("CLS")) system("clear");
	string bookName = "default";
	char yn;
	bool exit = false;		//flag for breaking the checkout loop and returning to checkout menu
	bool checkout = false;  //flag for breaking the book input loop and proceeding to checkout
	cout << setw(30) << "Order Number 000" << orderNumber << endl;
	cout << setw(49) << "Type 'Checkout' to complete purchase, or 'Exit' to cancel." << endl << endl;

	while (exit == false){
		while (checkout == false){
			cout << "     Please enter the ISBN of the book you wish to purchase: ";
			cin >> bookName;
			cin.clear();
			cin.ignore(1000, '\n');
			vector<Book*> tempV;		//temporary vector for storing information for a specific book being checked out
			Book* book;

			if (bookName == "checkout" || bookName == "Checkout"){		//breaks loop if 'checkout' or 'Checkout' is inputted
				checkout = true;
				bookList->writeToFile();	//updates inventory quantities to reflect bookList with edited quantities of each book
				break;
			}

			if (bookName == "exit" || bookName == "Exit"){
				for (int i = 0; i < items; i++){		//loop resets bookList to the previous quantities of each book because checkout was cancelled
					bookList->partialFindBooks(2, titles[i], tempV);	
					if (tempV.size() == 1){ //searches for matches for the books and restores the deducted quantities when a match is found
						tempV[0]->setQuantity(tempV[0]->getQuantity() + 1);
					}
				}
				exit = true;
				break;
			}

			bookList->partialFindBooks(1, bookName, tempV); //Searches for a book and saves the book information from bookList to tempV
			if (tempV.size() == 1){ //checks if only one match was found (tempV.size is the number of matches)
				if (tempV[0]->getQuantity() > 0){ //checks if the book is in stock
					tempV[0]->setQuantity(tempV[0]->getQuantity() - 1);	//Reduces stock by one
					titles[items] = tempV[0]->getBookTitle();	//stores titles for receipt
					prices[items] = tempV[0]->getRetailCost();	//stores prices for receipt
					subTotal += tempV[0]->getRetailCost();		//increments subtotal
					items++;	//counter items increases by one
					cout << endl << "$" << fixed << setprecision(2) << prices[items-1] << "     " << titles[items-1] << endl << endl; //Outputs book name and price for confirmation
				}
				else{
					cout << "Out of Stock" << endl << endl;
				}
			}
			else if (tempV.size() > 1) //checks if more than one match was found
			{
				cout << "Multiple Books found, please specify your selection: " << endl;
				for (int i = 0; i < tempV.size(); i++)	//outputs each book that partially matches to a numbered list (tempV.size is the number of matches)
					cout << (i + 1) << ") " << tempV[i]->toString(Book::ISB | Book::BKTTLE) << endl << endl;
				cout << "Type in the number which corresponds to the book you want: "; //user inputs selection
				int answ;
				while (!readInt(answ) || (answ < 1) || (answ >tempV.size())) { //checks if user selection is valid. If not, user must re-input selection
					cout << "\nPlease enter a number between 1 and " << tempV.size() << ": ";
				}
				if (tempV[0]->getQuantity() > 0){ //checks if the book is in stock
					tempV[0]->setQuantity(tempV[0]->getQuantity() - 1); //Reduces stock by one
					titles[items] = tempV[0]->getBookTitle(); //stores titles for receipt
					prices[items] = tempV[0]->getRetailCost(); //stores prices for receipt
					stock[items] = tempV[0]->getQuantity(); //increments subtotal
					subTotal += tempV[0]->getRetailCost(); //counter items increase by one
					items++;
					cout << endl << "$" << fixed << setprecision(2) << prices[items-1] << "     " << titles[items-1] << endl << endl;
				}
				else{
					cout << "Out of Stock" << endl << endl;
				}
			}
			else{ //if no matches were found
				cout << "Sorry, the book you entered was not found." << endl << endl;
			}

		}
		if (exit == true){ //breaks both loops and returns to checkout menu
			break;
		}

		else{ //outputs the subtotal, tax, and total, then asks user if they want a receipt
			orderNumber++;
			cout << endl << "                                             Subtotal: " << subTotal << endl;
			cout << "                                             Tax:      " << subTotal * taxRate << endl;
			cout << "                                             Total:    " << subTotal * (1 + taxRate) << endl << endl;
			cout << "Would you like to a printable copy of your receipt? (Y/N)" << endl; //User may input 'Y' or 'y' for a receipt, 'N' or 'n' to continue without receipt
			cin >> yn;
			cin.clear();
			cin.ignore(1000, '\n');

			while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N'){ //checks for valid input
				cout << "Please select 'Y' or 'N': " << endl;
				cin >> yn;
				cin.clear();
				cin.ignore(1000, '\n');
			}

			if (yn == 'y' || yn == 'Y'){ //if user selected 'y' or 'Y', prints a receipt
				printReceipt();
			}
			items = 0; //resets items counter to zero after one iteration of the checkout loop
			exit = true;
		}
	}
	system("pause");

	if (system("CLS")) system("clear"); //clears screen for a new checkout
}

void CashierModule::titleCheckOut(){
	if (system("CLS")) system("clear");
	string bookName = "default";
	char yn;
	bool exit = false;		//flag for breaking the checkout loop and returning to checkout menu
	bool checkout = false;  //flag for breaking the book input loop and proceeding to checkout
	cout << setw(30) << "Order Number 000" << orderNumber << endl;
	cout << setw(49) << "Type 'Checkout' to complete purchase, or 'Exit' to cancel." << endl << endl;

	while (exit == false){
		while (checkout == false){
			cout << "     Please enter the ISBN of the book you wish to purchase: ";
			cin >> bookName;
			cin.clear();
			cin.ignore(1000, '\n');
			vector<Book*> tempV;		//temporary vector for storing information for a specific book being checked out
			Book* book;

			if (bookName == "checkout" || bookName == "Checkout"){		//breaks loop if 'checkout' or 'Checkout' is inputted
				checkout = true;
				bookList->writeToFile();	//updates inventory quantities to reflect bookList with edited quantities of each book
				break;
			}

			if (bookName == "exit" || bookName == "Exit"){
				for (int i = 0; i < items; i++){		//loop resets bookList to the previous quantities of each book because checkout was cancelled
					bookList->partialFindBooks(2, titles[i], tempV);
					if (tempV.size() == 1){ //searches for matches for the books and restores the deducted quantities when a match is found
						tempV[0]->setQuantity(tempV[0]->getQuantity() + 1);
					}
				}
				exit = true;
				break;
			}

			bookList->partialFindBooks(2, bookName, tempV); //Searches for a book and saves the book information from bookList to tempV
			if (tempV.size() == 1){ //checks if only one match was found (tempV.size is the number of matches)
				if (tempV[0]->getQuantity() > 0){ //checks if the book is in stock
					tempV[0]->setQuantity(tempV[0]->getQuantity() - 1);	//Reduces stock by one
					titles[items] = tempV[0]->getBookTitle();	//stores titles for receipt
					prices[items] = tempV[0]->getRetailCost();	//stores prices for receipt
					subTotal += tempV[0]->getRetailCost();		//increments subtotal
					items++;	//counter items increases by one
					cout << endl << "$" << fixed << setprecision(2) << prices[items - 1] << "     " << titles[items - 1] << endl << endl; //Outputs book name and price for confirmation
				}
				else{
					cout << "Out of Stock" << endl << endl;
				}
			}
			else if (tempV.size() > 1) //checks if more than one match was found
			{
				cout << "Multiple Books found, please specify your selection: " << endl;
				for (int i = 0; i < tempV.size(); i++)	//outputs each book that partially matches to a numbered list (tempV.size is the number of matches)
					cout << (i + 1) << ") " << tempV[i]->toString(Book::ISB | Book::BKTTLE) << endl << endl;
				cout << "Type in the number which corresponds to the book you want: "; //user inputs selection
				int answ;
				while (!readInt(answ) || (answ < 1) || (answ >tempV.size())) { //checks if user selection is valid. If not, user must re-input selection
					cout << "\nPlease enter a number between 1 and " << tempV.size() << ": ";
				}
				if (tempV[0]->getQuantity() > 0){ //checks if the book is in stock
					tempV[0]->setQuantity(tempV[0]->getQuantity() - 1); //Reduces stock by one
					titles[items] = tempV[0]->getBookTitle(); //stores titles for receipt
					prices[items] = tempV[0]->getRetailCost(); //stores prices for receipt
					stock[items] = tempV[0]->getQuantity(); //increments subtotal
					subTotal += tempV[0]->getRetailCost(); //counter items increase by one
					items++;
					cout << endl << "$" << fixed << setprecision(2) << prices[items - 1] << "     " << titles[items - 1] << endl << endl;
				}
				else{
					cout << "Out of Stock" << endl << endl;
				}
			}
			else{ //if no matches were found
				cout << "Sorry, the book you entered was not found." << endl << endl;
			}

		}
		if (exit == true){ //breaks both loops and returns to checkout menu
			break;
		}

		else{ //outputs the subtotal, tax, and total, then asks user if they want a receipt
			orderNumber++;
			cout << endl << "                                             Subtotal: " << subTotal << endl;
			cout << "                                             Tax:      " << subTotal * taxRate << endl;
			cout << "                                             Total:    " << subTotal * (1 + taxRate) << endl << endl;
			cout << "Would you like to a printable copy of your receipt? (Y/N)" << endl; //User may input 'Y' or 'y' for a receipt, 'N' or 'n' to continue without receipt
			cin >> yn;
			cin.clear();
			cin.ignore(1000, '\n');

			while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N'){ //checks for valid input
				cout << "Please select 'Y' or 'N': " << endl;
				cin >> yn;
				cin.clear();
				cin.ignore(1000, '\n');
			}

			if (yn == 'y' || yn == 'Y'){ //if user selected 'y' or 'Y', prints a receipt
				printReceipt();
			}
			items = 0; //resets items counter to zero after one iteration of the checkout loop
			exit = true;
		}
	}
	system("pause");

	if (system("CLS")) system("clear"); //clears screen for a new checkout
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
