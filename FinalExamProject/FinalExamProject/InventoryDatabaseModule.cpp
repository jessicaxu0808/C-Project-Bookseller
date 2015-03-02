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

void clearScrn(){
	if (system("CLS")) system("clear");		//CALLS CLEARSCREEN FUNCTION TO CLEAR THE MAIN MENU AWAY;;
}
