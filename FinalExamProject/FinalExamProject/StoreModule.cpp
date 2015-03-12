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
1. The StoreModule constructor takes in the BookList pointer b. The bookList is set to b.
2. readString function takes in the string reference variable strP as input. The input is read into a character array for 500 characters and 
	the char array is set to strP. This function returns true.
3. readInt function takes in the int reference variable intP as input. The input is read into a character array for 500 characters and 
	the char array is set to intP. This function returns true.
4. readDouble function takes in the int reference variable doubP as input. The input is read into a character array for 500 characters and 
	the char array converted to float is set to doubP. This function returns true.
5. readChar function takes in the char reference variable doubP as input. The input is read into a character array for 500 characters and 
	the char array is set to c. This function returns true.
6. isStringDouble function takes in cArray character pointer. For each value in cArray it checks if there is decimal point and if all the elements
	in the cArray is digit. The function returns true.
*/

#include "StoreModule.h"
#include <iostream>
#include <string>
#include "Book.h"
#include <vector>

using namespace std;

StoreModule::StoreModule(BookList *b)
{
	this->bookList = b;
}

bool StoreModule::readString(string& strP)        // this method will be always called if a module wants to take in any type of string formatted user input
{
	char cArray[500];
	cin.getline(cArray, 500, '\n\r');
	cin.clear();
	strP = cArray;
	return true;

}

bool StoreModule::readInt(int &intP)         // this method will be always called if a module wants to take in any type of double formatted user input
{
	bool returnVal;
	char cArray[500];
	cin.getline(cArray, 500, '\n\r');


	double d = atof(cArray);
	returnVal = isStringDouble(cArray) & fabs(fmod(d, 1))<0.001;  // if the double is divisible by 1, then the double is an integer
	intP = d;

	return returnVal;
}

bool StoreModule::readDouble(double &doubP)
{
	bool returnVal;
	char cArray[500];
	cin.getline(cArray, 500, '\n\r');

	doubP = atof(cArray);
	return isStringDouble(cArray);
}

bool StoreModule::readChar(char &c)
{
	bool returnVal;
	char cArray[500];
	cin.getline(cArray, 500, '\n\r');
	if (*(cArray + 1) != '\0')
		returnVal = false;
	else
		returnVal = true;
	c = *cArray;
	return returnVal;

}

bool StoreModule::isStringDouble(char *cArray)
{
	bool decFlag = true;                                   // a flag indicating 1 decimal point was reached(a number cannot have 2 decimal points)
	for (int i = 0; *(cArray + i) != '\0'; i++)             // cycles through the cstring passed in
	{
		char let = *(cArray + i);
		if (!(isdigit(let) || (decFlag && let == '.')))            // checks if the current character is not a digit or a '.'
			return false;
		if (let == '.')
			decFlag = false;                                       // toggles the flag that 1 decimal point has been reached
	}
	return true;
}