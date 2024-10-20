/***********************************************************************
* Program to practice STL containers such as the following
1. Vector
2. List
Author: Iskled Adebayo
***********************************************************************/

#include "functions.h"
#include <iostream>
#include <string>
#include <format>
#include <vector>
#include <fstream>


using namespace std;


int main() {
	while (1) {
		cout << "**********************************************************\n\n";
		cout << "1. File processing\n";
		cout << "2. Book catalogu\n";
		cout << "3. Populate catalogue vector with file\n";
		cout << "4. Quit\n";
		cout << "**********************************************************\n\n";

		int menu;
		do {
			cout << "Enter 1 - 4 for menu items : ";
			cin >> menu;
		} while (menu < 1 || menu >4);

		switch (menu) {

		case 1:
		{
			// Int Score File processing section
			static const char* fileLocation{ "score.txt" };
			ifstream inFile;
			inFile.open(fileLocation);

			if (inFile.is_open()) {
				int readText;


				while (inFile >> readText) {
					cout << readText << "\n";
				}
				inFile.close();
			}

			else
			{
				cout << "Error reading text file...";
			}

			break;


		}

		case 2:
		{
			//Book catalogue processing section
			vector <Books> catalogue;
			int choice{};

			// Section to check if a positive choice is made
			do {
				cout << "Enter number of books to process more than 0? \n\n";
				cin >> choice;

			} while (choice < 1);

			// Loop to process number of books to be entered
			for (int i = 0; i < choice; i++) {
				Books book; //What if the struct object is initialissed to null?
				populate(book); //Add book object details
				catalogue.push_back(book); //Add entered books details to the catalogue
			}
			break;
		}

		case 3:
		{
			// Populate vector catalogue with data from the file
			cout << "Case 3 Selected - Populate vector elements from the text file\n";

			vector<Books> catalogue;
			Books book;
			inPopulate(book);
			catalogue.push_back(book);
			break;
		}

		case 4:
		{
			return 0;
		}
		default: {
		}
			   cout << "Invalid choice selected\n";
		}


	}
}
