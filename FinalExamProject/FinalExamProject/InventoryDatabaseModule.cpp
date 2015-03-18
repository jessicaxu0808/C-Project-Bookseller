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
1. InventoryDatabaseModule takes BookList pointer b which inherits from StoreModule.
2. lookUpBook function asks the users to search book by ISBN or book title or to exit. It checks if the user has given the proper input
	if not it asks again.
3. For case 1: int variable info is set to Book:ISB. The user is asked to type the ISBN number. The ISBN number is read using readString function,
4. For case 2: int variable info is set to Book:BKTITLE. The user is asked to type the book title. The book title is read using 
	readString function.
5. For case 3: The program exits and variable exit is set to true.
6. tempV is initialized as vector of type Book.
7. bookList partialBooks function is called which takes in infor, findS and tempV as arguments.
8. If tempV.size() is returned as 1 then the book being searched is found. It prints all the details of the book.
9. If tempV.size is returned as greater than 1, it prints more than 1 book is found and prints out the ISBN and title of these books to be chosen 
	by the user. Once the user chooses which book user wants the book details are printed on the screen.
10. editBook function asks the user to enter unique ISBN number. If the book with that particular ISBN number exists then the user is asked to
	What to edit. The user can enter the details which he wants to edit. once the user enters the value the values are set using the relevant set
	functions. The values are changed in bookList vector. If book is not found it prints book not found on the screen.
11. deleteBook function asks the user for the ISBN number or book title which they want to delete. Using the partialFindBooks function we search
	if the book exists in the tempV vector of Book type. If the size of vector tempV is 1 then the user is told that the book is found and
	deleted. If the size of vector tempV is greater than 1 then all the books with that particular ISBN number or title is printed out so
	that the user can choose which book to delete and that book is printed as deleted.
12. addBook function creates a book of type Book and tempV vector of type Book. The user is asked to enter the ISBN number. If the ISBN number
	already exits then the user is asked to enter a unique ISBN number. The user is then asked to enter book title, author, publisher, quantity, 
	date added, wholesale cost and retail cost. It prints that the book is added.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "InventoryDatabaseModule.h"

using namespace std;

void clearScrn();

InventoryDatabaseModule::InventoryDatabaseModule(BookList *b) :StoreModule(b)
{
}

void InventoryDatabaseModule::lookUpBook()
{
	bool exit = false;
	char cInput;                                                   //DO THE PARTIAL FIND IDEA
	cout << endl << "You can search a book by typing all the characters of a books property or only the first couple characters of a books property" << endl;
	cout << endl << "1. To search book by ISBN" << endl;
	cout << "2. To search book by Book Title" << endl;
	cout << "3. To exit " << endl;
	while (!readChar(cInput) || (cInput < '1') || (cInput > '3')) {
		cout << "Please enter a number between 1 and 3: ";
	}
	cout << endl;
	int info;
	string findS;
	while (!exit){
		switch (cInput){
		case '1':
		{
			info = Book::ISB;
			cout << "Type in the ISBN of the book you want to look up: ";
			readString(findS);
			break;
		}
		case '2': //cInput has to be == '2'
		{
			info = Book::BKTTLE;
			cout << "Type in the title of the book you want to look up: ";
			readString(findS);
			break;
		}
		case '3':
			exit = true;
			break;
		}

		if (exit == true)
		{
			clearScrn();
			break;
		}

		else
		{
			cout << endl;
			vector<Book*> tempV;
			bookList->partialFindBooks(info, findS, tempV);
			if (tempV.size() == 1){
				cout << "Book Found, Listing Book Details..." << endl;
				cout << tempV[0]->toString(Book::EVERYTHING) << endl;
			}
			else if (tempV.size() > 1)
			{
				cout << "Multiple Books were found with those credentials, please choose one of them" << endl << endl;
				for (int i = 0; i < tempV.size(); i++)
					cout << (i + 1) << ") " << tempV[i]->toString(Book::ISB | Book::BKTTLE) << endl << endl;
				cout << "Type in the number which corresponds to the book you want: ";
				int answ;
				while (!readInt(answ) || (answ < 1) || (answ >tempV.size())) {
					cout << "\nPlease enter a number between " << 1 << " and " << tempV.size() << ": ";
				}
				cout << endl << "Listing Book Details..." << endl;
				cout << tempV[answ - 1]->toString(Book::EVERYTHING) << endl;
			}
			else
				cout << "Sorry, no books were found with those credentials" << endl;
		}
		system("pause");
		clearScrn();
		break;
	}
}

void InventoryDatabaseModule::editBook()
{
	string bookCode;
	string change;
	string option = "Y";
	cout << "Please enter the unique ISBN code of the book you wish to edit: ";
	readString(bookCode);

	vector<Book*> tempV;
	bookList->findBooks(Book::ISB, bookCode, tempV);   // since we are asking the method to find books by ISBN value, only 1 Book should be in the vector
	Book* book = tempV.size() > 0 ? tempV[0] : NULL;
	if (book != NULL) //If the book was found (NULL means the book wasn't found)
	{
		while (option == "y" || option == "Y") //do-while loop to allow the user to keep editing the book info to their heart's content
		{
			//Ask the user what they want to change
			cout << endl << "What would you like to edit? " << endl;
			cout << "1. ISBN\n";
			cout << "2. Title\n";
			cout << "3. Author\n";
			cout << "4. Publisher\n";
			cout << "5. Date Added\n";
			cout << "6. Quantity-On-Hand\n";
			cout << "7. Wholesale Cost\n";
			cout << "8. Retail Price\n";
			cout << "Please enter the corresponding number: ";

			//Input check
			while (!readString(change) || change > "8" || change < "1")
			{
				cout << "That was not a valid input." << endl;
				cout << "Please try again: ";
			}
			string newChangeSTR; //this variable holds properties of the book which are strings
			int newChangeINT;    //this variable holds properties of the book which are ints
			double newChangeDB;  ////this variable holds properties of the book which are doubles

			cout << endl;
			//Depending on what the user chose...
			//They can edit the field of the corresponding number
			if (change == "1")
			{
				//Get variable newChange
				cout << "What do you want to change the ISBN to: ";
				readString(newChangeSTR);
				book->setISBN(newChangeSTR);
			}
			else if (change == "2")
			{
				//Get variable newChange
				cout << "What do you want to change the Title to: ";
				readString(newChangeSTR);					 //change the info from the book to newChange value
				book->setBookTitle(newChangeSTR);
			}
			else if (change == "3")
			{
				//Get variable newChange
				cout << "What do you want to change the author to: ";
				readString(newChangeSTR); //change the info from the book to newChange value
				book->setAuthorName(newChangeSTR);
			}
			else if (change == "4")
			{
				//Get variable newChange
				cout << "What do you want to change the publisher to: ";
				readString(newChangeSTR);	 //change the info from the book to newChange value
				book->setPublisher(newChangeSTR);
			}
			else if (change == "5")
			{
				//date has 3 parts therefore, there must be three different input values

				//Get variable newChange
				cout << "What do you want to change the date to: ";
				cout << "Month: ";
				readInt(newChangeINT); book->setMonth(newChangeINT);
				cout << "Day: ";
				readInt(newChangeINT); book->setDay(newChangeINT);
				cout << "Year: ";
				readInt(newChangeINT); book->setYear(newChangeINT);
			}
			else if (change == "6")
			{
				//Get variable newChange
				cout << "What do you want to change the quantity to: ";
				readInt(newChangeINT);
				book->setQuantity(newChangeINT);//change the info from the book to newChange value
			}
			else if (change == "7")
			{
				//Get variable newChange
				cout << "What do you want to change the cost to: ";
				readDouble(newChangeDB);
				book->setWholesaleCost(newChangeDB); //change the info from the book to newChange value
			}
			else if (change == "8")
			{
				//Get variable newChange
				cout << "What do you want to change the resale value to: ";
				readDouble(newChangeDB);
				book->setRetailCost(newChangeDB); //change the info from the book to newChange value
			}

			cout << "Is there anything else you wish to edit from this book?(Type 'Y' or 'N'): ";
			cin >> option;
			//Input check
			while (!readString(option) && (option != "n" || option != "N") && (option != "y" || option != "Y"))
			{
				cout << "That was not a valid input." << endl;
				cout << "Please try again" << endl;
				cin >> option;
				//change = tolower(change);
			}
		} 

		//Display vthe editted and non-editted book information
		cout << endl << "New book information: " << endl;
		string s = book->toString(Book::EVERYTHING);
		cout << s << endl;
	}
	else //if book was not found
	{
		cout << "Book was not found." << endl;
	}
	system("pause");
	clearScrn();
}

void InventoryDatabaseModule::deleteBook()
{
	bool exit = false;
	char cInput;                                                   //DO THE PARTIAL FIND IDEA
	cout << endl << "You can delete a book by typing all the characters of a books property or only the first couple characters of a books property" << endl;
	cout << endl << "1. To search book by ISBN" << endl;
	cout << "2. To search book by Book Title" << endl;
	cout << "3. To exit " << endl;
	while (!readChar(cInput) || (cInput < '1') || (cInput > '3')) {
		cout << "Please enter a number between 1 and 3: ";
	}
	cout << endl;
	int info;
	string findS;
	while (!exit){
		switch (cInput){
		case '1':
		{
		info = Book::ISB;
		cout << "Type in the ISBN of the book you want to delete: ";
		readString(findS);
		break;
		}
		case '2':
		{
			info = Book::BKTTLE;
			cout << "Type in the title of the book you want to delete: ";
			readString(findS);
			break;
		}
		case '3':
			exit = true;
			break;
		}

		if (exit == true)
		{
			break;
		}

		else
		{
			cout << endl;
			vector<Book*> tempV;
			bookList->partialFindBooks(info, findS, tempV);
			int index = -1;
			if (tempV.size() == 1){
				index = tempV[0] - &bookList->get(0);
			}
			else if (tempV.size() > 1)
			{
				cout << "Multiple Books were found with those credentials, please choose one of them" << endl << endl;
				for (int i = 0; i < tempV.size(); i++)
					cout << (i + 1) << ") " << tempV[i]->toString(Book::ISB | Book::BKTTLE) << endl << endl;
				cout << "Type in the number which corresponds to the book you want: ";
				int answ;
				while (!readInt(answ) || (answ < 1) || (answ >tempV.size())) {
					cout << "\nPlease enter a number between " << 1 << " and " << tempV.size() << ": ";
				}
				index = tempV[answ - 1] - &bookList->get(0);
			}
			else //tempV.size() == 0
				cout << "Sorry, no books were found with those credentials" << endl;
			if (index != -1)
			{
				cout << "Book Found, Deleting Book..." << endl;
				bookList->remove(index);
				cout << "Book Deleted Succesfully" << endl;
			}
		}
	system("pause");
	clearScrn();
	break;
	}
}

void InventoryDatabaseModule::addBook()
{
	Book book;
	string addStr;
	int addInt;
	double addDouble;
	vector<Book*> tempV;

	cout << "Enter in the ISBN: ";
	do{
		readString(addStr);
		bookList->findBooks(Book::ISB, addStr, tempV);
		if (tempV.size() > 0){
			cout << "Error, ISBN allready exists" << endl;
			cout << "Please enter a unique ISBN: ";
		}
	} while (tempV.size() > 0);
	book.setISBN(addStr);
	cout << "Enter in the Title: "; readString(addStr); book.setBookTitle(addStr);
	cout << "Enter in the Author: "; readString(addStr); book.setAuthorName(addStr);
	cout << "Enter in the Publisher: "; readString(addStr); book.setPublisher(addStr);
	cout << "Entering in the Date Added(just type in integers)... " << endl;

	cout << "Enter the Month: ";
	while (!readInt(addInt) || addInt < 1 || addInt > 12)                   //Error checking, just making sure they dont enter in words or decimals
		cout << "Enter in a integer between 1 and 12: ";
	book.setMonth(addInt);

	cout << "Enter the Day: ";
	while (!readInt(addInt) || addInt < 1 || addInt > 30)					//Error checking
		cout << "Enter in a integer between 1 and 30: ";
	book.setDay(addInt);

	cout << "Enter the Year: ";
	while (!readInt(addInt) || addInt < 0)					//Error checking
		cout << "Enter in a positive integer: ";
	book.setYear(addInt);

	cout << "Enter in the Quantity-On-Hand: ";
	while (!readInt(addInt) || addInt < 0)					//Error checking
		cout << "Enter in an positive integer or 0: ";
	book.setQuantity(addInt);

	cout << "Enter in the Wholesale Cost: ";
	while (!readDouble(addDouble) || addDouble < 0)					//Error checking
		cout << "Enter in an positive decimal: ";
	book.setWholesaleCost(addDouble);

	cout << "Enter in the Retail Price: ";
	while (!readDouble(addDouble) || addDouble < 0)					//Error checking
		cout << "Enter in an positive decimal: ";
	book.setRetailCost(addDouble);

	cout << endl << "Displaying the Books Information..." << endl;
	cout << book.toString(Book::EVERYTHING) << endl;
	bookList->add(book);

	system("pause");
}

void clearScrn(){
	if (system("CLS")) system("clear");		//CALLS CLEARSCREEN FUNCTION TO CLEAR THE MAIN MENU AWAY;;
}
