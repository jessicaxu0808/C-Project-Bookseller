#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "InventoryDatabaseModule.h"
#include "ReportModule.h"
#include "CashierModule.h"
#include "BookList.h"

using namespace std;

const int CENTER = 20;
const string INDENT = "     ";
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
	cout << setw(CENTER + 9) << "P.A.J.L. BOOKS" << endl;
	cout << setw(CENTER + 6) << "Main Menu" << endl << endl;
	cout << INDENT << "1: Cashier Module" << endl;
	cout << INDENT << "2: Inventory Database Module" << endl;
	cout << INDENT << "3: Report Module" << endl;
	cout << INDENT << "4: Exit" << endl << endl;
	cout << INDENT << "Select Option: ";
	cin >> choice;			//USER INPUT TO SELECT CHOICE, SAVES INPUT TO INT VARIABLE 'CHOICE'
	cin.clear();
	cin.ignore(1000, '\n');
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4){		//CHECKS FOR INVALID USER INPUT
		cout << INDENT << "Please re-enter your selection: ";
		cin >> choice;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	clearScreen();
	return choice;
}
void cashierModule(){
	int option = 0;
	BookList bookList{ "PAJL.txt" };
	bookList.readFromFile();
	CashierModule cashierModule{ &bookList };
	while (option != 3){
		cout << setw(CENTER + 9) << "P.A.J.L. BOOKS" << endl;
		cout << setw(CENTER + 5) << "Cashier" << endl << endl;
		cout << INDENT << "1: Check out by ISBN" << endl;
		cout << INDENT << "2: Check out by Title" << endl;
		cout << INDENT << "3: Return to Main Menu" << endl << endl;
		cout << INDENT << "Please input your selection:" << endl;
		cout << endl;

		cin >> option;
		cin.clear();
		cin.ignore(1000, '\n');

		while (option != 1 && option != 2 && option != 3){		//CHECKS FOR INVALID USER INPUT
			cout << INDENT << "Please re-enter your selection: ";
			cin >> option;
			cin.clear();
			cin.ignore(1000, '\n');
		}

		switch (option){
		case 1: option = 0;
			clearScreen();
			cashierModule.isbnCheckOut();
			break;
		case 2: option = 0;
			clearScreen();
			cashierModule.titleCheckOut();
			break;
		case 3:
			break;
		}
	}

	option = 0;
	clearScreen();
	mainMenu();
}

void inventoryDatabaseModule(){
	int option = 0;
	bool user_option = false;
	BookList bookList{ "PAJL.txt" };
	bookList.readFromFile();
	InventoryDatabaseModule invModule{ &bookList };
	cout << setw(CENTER + 9) << "P.A.J.L. BOOKS" << endl;
	cout << setw(CENTER + 11) << "Inventory Database" << endl << endl;
	cout << INDENT << "1: Look Up a Book" << endl;
	cout << INDENT << "2: Add a Book" << endl;
	cout << INDENT << "3: Edit a Book's Record" << endl;
	cout << INDENT << "4: Delete a Book" << endl;
	cout << INDENT << "5: Return To Main Menu" << endl;
	cout << endl;
	cin >> option;			//USER INPUT TO SELECT CHOICE, SAVES INPUT TO INT VARIABLE 'CHOICE'
	cin.clear();
	cin.ignore(1000, '\n');
	while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5){		//CHECKS FOR INVALID USER INPUT
		cout << INDENT << "Please re-enter your selection: ";
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
	cout << setw(CENTER + 9) << "P.A.J.L. BOOKS" << endl;
	cout << setw(CENTER + 3) << "Reports" << endl << endl;
	cout << INDENT << "1. Inventory Listing" << endl;
	cout << INDENT << "2. Inventory Wholesale Value" << endl;
	cout << INDENT << "3. Inventory Retail Value" << endl;
	cout << INDENT << "4. Listing by Quantity" << endl;
	cout << INDENT << "5. Listing by Cost" << endl;
	cout << INDENT << "6. Listing by Age" << endl;
	cout << INDENT << "7. Return to Main Menu" << endl << endl;
	cout << INDENT << "Enter Your Choice: ";
	cin >> choiceReport;

	switch (choiceReport)
	{
	case 1:
		cout << repModule.displayInventory();
		break;
	case 2:
		cout << repModule.displayWholeSaleValue();
		break;
	case 3:
		cout << repModule.displayByRetailValue();
		break;
	case 4:
		cout << repModule.listByQuantity();
		break;
	case 5:
		cout << repModule.listByCost();
		break;
	case 6:
		cout << repModule.listByDate();
		break;
	case 7: //exit to main menu
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
