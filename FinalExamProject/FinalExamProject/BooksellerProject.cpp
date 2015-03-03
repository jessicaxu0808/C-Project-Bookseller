#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "InventoryModule.h"
#include "ReportModule.h"
#include "BookList.h"

using namespace std;

const int CENTER = 20;
const int INDENT = 5;
void clearScreen();
int mainMenu();
void cashierModule();
void inventoryDatabaseModule();
void reportModule();
fstream file;



int main(){

	int choice = 0;
	while (choice != 4){
		//MAIN MENU (SCREEN OUTPUT)
		choice = mainMenu();
		switch (choice){
		case 1: cashierModule();
			break;
		case 2: inventoryDatabaseModule();
			break;
		case 3: reportModule();
			break;
		case 4: break;
		}

	}
	system("pause");
	return 0;
}
void clearScreen(){
	if (system("CLS")) system("clear");		//CALLS CLEARSCREEN FUNCTION TO CLEAR THE MAIN MENU AWAY;;
}
int mainMenu(){
	int choice;
	for (int i = 0; i < (CENTER - 7); i++){
		cout << " ";
	}
	cout << "P.A.J.L. BOOKS" << endl;
	for (int i = 0; i < (CENTER - 5); i++){
		cout << " ";
	}
	cout << "Main Menu" << endl << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "1: Cashier Module" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "2: Inventory Database Module" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "3: Report Module" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "4: Exit" << endl << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "Select Option: ";
	cin >> choice;			//USER INPUT TO SELECT CHOICE, SAVES INPUT TO INT VARIABLE 'CHOICE'
	cin.clear();
	cin.ignore(1000, '\n');
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4){		//CHECKS FOR INVALID USER INPUT
		for (int i = 0; i < INDENT; i++){
			cout << " ";
		}
		cout << "Please re-enter your selection: ";
		cin >> choice;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	clearScreen();
	return choice;
}
void cashierModule(){
	string book;
	double price;
	double subTotal = 0;
	double total = 0;
	bool gMainMenu = false;
	bool checkout = false;

	for (int i = 0; i < (CENTER - 7); i++){
		cout << " ";
	}
	cout << "P.A.J.L. BOOKS" << endl;
	for (int i = 0; i < (CENTER - 5); i++){
		cout << " ";
	}
	cout << "Cashier" << endl << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "Type Exit to go to Main Menu" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "Type Checkout to Checkout" << endl << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}

	cout << endl;

	while (gMainMenu == false){
		while (checkout == false){
			cout << "Book Name: ";
			cin >> book;			//USER INPUT TO SELECT CHOICE, SAVES INPUT TO STRING VARIABLE 'BOOK'
			cin.clear();
			cin.ignore(1000, '\n');

			if (book == "checkout"){
				checkout = true;
				break;
			}

			if (book == "exit"){
				gMainMenu = true;
				break;
			}

			/*
			while (book != inventoryBook){		//CHECKS FOR INVALID USER INPUT
			for (int i = 0; i < INDENT; i++){
			cout << " ";
			}
			cout << "Please re-enter your selection: ";
			cin >> choice;
			cin.clear();
			cin.ignore(1000, '\n');
			}
			*/

			price = 8.25; //temp price till inventory is created for books
			subTotal = subTotal + price;
			total = (subTotal * 2);
		}

		if (gMainMenu == true)
			break;

		else
		{
			cout << "Sub-Total: " << subTotal << endl;
			for (int i = 0; i < INDENT; i++){
				cout << " ";
			}
			cout << "Total: " << subTotal << endl << endl;
			for (int i = 0; i < INDENT - 20; i++){
				cout << " ";
			}
			cout << "Thank you for shopping at  P.A.J.L. BOOKS" << endl << endl;
			for (int i = 0; i < INDENT; i++){
				cout << " ";
			}
		}

		system("pause");

		clearScreen();
		cashierModule();
	}

	clearScreen();
	gMainMenu = false;
	checkout = false;
	mainMenu();
}

void inventoryDatabaseModule(){
	int option = 0;
	bool user_option = false;
	BookList bookList{ "PAJL.txt" };
	bookList.readFromFile();
	InventoryDatabaseModule invModule{ &bookList };
	for (int i = 0; i < (CENTER - 7); i++){
		cout << " ";
	}
	cout << "P.A.J.L. BOOKS" << endl;
	for (int i = 0; i < (CENTER - 5); i++){
		cout << " ";
	}
	cout << "Inventory Database" << endl << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "1. Look Up a Book" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "2. Add a Book" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "3. Edit a Book's Record" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "4. Delete a Book" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "5. Return To Main Menu" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << endl;
	cin >> option;			//USER INPUT TO SELECT CHOICE, SAVES INPUT TO INT VARIABLE 'CHOICE'
	cin.clear();
	cin.ignore(1000, '\n');
	while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5){		//CHECKS FOR INVALID USER INPUT
		for (int i = 0; i < INDENT; i++){
			cout << " ";
		}
		cout << "Please re-enter your selection: ";
		cin >> option;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	switch (option){
	case 1:
		invModule.lookUpBook();
		break;
	case 2:
		cout << "Still working on it" << endl;
		break;
	case 3:
		invModule.editBook();
		break;
	case 4:
		invModule.deleteBook();
		break;
	case 5:
		user_option = true;
		break;
	}
	if (user_option == true)
	{
		clearScreen();
		mainMenu();
	}
	clearScreen();
}
void reportModule(){
	//cout << "WORKING 3" << endl;
	int option = 0;
	bool user_option = false;
	BookList bookList{ "PAJL.txt" };
	bookList.readFromFile();
	ReportModule repModule{ &bookList };

	int choiceReport = 0;
	for (int i = 0; i < (CENTER - 7); i++){
		cout << " ";
	}
	cout << "P.A.J.L. BOOKS" << endl;
	for (int i = 0; i < (CENTER - 5); i++){
		cout << " ";
	}
	cout << "Reports" << endl << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "1. Inventory Listing" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "2. Inventory Wholesale Value" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "3. Inventory Retail Value" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "4. Listing by Quantity" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "5. Listing by Cost" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "6. Listing by Age" << endl;
	for (int i = 0; i < INDENT; i++){
		cout << " ";
	}
	cout << "7. Return to Main Menu" << endl << endl;
	for (int i = 0; i < (INDENT - 1); i++){
		cout << " ";
	}
	cout << "Enter Your Choice: ";
	cin >> choiceReport;

	switch (choiceReport)
	{
	case 1: 
		cout << repModule.displayInventory();
		//repListing()
		break;
	case 2: 
		cout << repModule.displayWholeSaleValue();
		//repWholesale()
		break;
	case 3: 
		cout << repModule.displayByRetailValue();
		//repRetail()
		break;
	case 4: 
		cout << repModule.listByQuantity();
		//repQty()
		break;
	case 5: 
		cout << repModule.listByCost();
		//repCost()
		break;
	case 6: 
		cout << repModule.listByDate();
		//repAge()
		break;
	case 7: //exit to main menu
		//clearScreen();
		user_option = true;
		break;
	default: "Please enter a valid choice: 1,2,3,4,5,6 or 7.";
		break;
	}

	if (user_option == true)
	{
		clearScreen();
		mainMenu();
	}
	system("pause");
	clearScreen();
}
