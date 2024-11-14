// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com



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
#include <map>
#include <sstream>
#include <thread>


using namespace std;


int main() {
	while (1) {
		cout << "**********************************************************\n\n";
		cout << "1. File processing\n";
		cout << "2. Book catalogu\n";
		cout << "3. Populate catalogue vector with file\n";
		cout << "4. Map processing and storage in the text file\n";
		cout << "5. Demostrate multitasking\n";
		cout << "6. Plant Objects\n";
		cout << "7. Other classes\n";
		cout << "8. Quit\n";
		cout << "9. Another Demonstration of a class Behaviour\n";
		cout << "10. Vehicle manufacture \n";
		cout << "11. Employee Class Implementation\n";
		cout << "**********************************************************\n\n";

		int menu;
		do {
			cout << "Enter 1 - 11 for menu items : ";
			cin >> menu;
		} while (menu < 1 || menu >11);

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
			vector <map<string, int>> xyz;  //to be tested!!!
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
			// Map processing and storage in the text file

			map<string, Officer> staff;
			char choice;
			do {

				cout << "Enter name of officer to process\n";
				string fullName, firstName;
				cin.ignore();
				getline(cin, fullName);
				istringstream iss(fullName);
				iss >> firstName;

				Officer officer;
				officer.fullName = fullName;
				mPopulate(officer);

				staff.insert({ firstName, officer });

				cout << "File successfully created on the map\n";

				cout << "Press Y (to continue) or N (to Quit)\n";
				cin >> choice;
			} while (choice != 'N');


			cout << "File now being written to the text file\n";

			ofstream outFile;
			outFile.open("staff.txt");

			if (!outFile.is_open()) {
				cout << "*** File opened unsuccessfully ***\n";
			}
			else
			{
				writeFile(staff, outFile);
				outFile.close();

				cout << "*** Object written to file successfully ***\n";
			}
			break;
		}

		case 5:
		{
			//Demonstrating real-time multi tasking
			cout << "Demonstrating real-time multi tasking\n";

			thread  osThread1(function1);
			thread osThread2(function2);


			osThread1.join();
			osThread2.join();

			break;
		}

		case 6: {
			Plant plant;


			
			cout << "plant name " << plant.roughCapability;
			break;
		}

		case 8:
		{
			return 0;
		}

		case 7: {
			User user2;
			User user1("Iskled", "Adebayo", 38);
			printUser(user1);
			printUser(user2);
			/*{


				fname = "Iskeld";
				lastName = "Adebayo";
				Age = 39;
			}*/
			
				
				break;
			
		}

		case 9: {
			Stadium stadium("Stamford Bridge", 40000, "London");

			cout << "Welcome to " << stadium.getName() << "\n";
			cout << "Our minimum capacity = " << stadium.minimumCapacity() << "\n";
			cout << "And our maximum capacity = " << stadium.maxCapacity() << "\n";
			break;

		}

		case 10: {
			Vehicle vehicle;
			Car car("Trailer", "483/90R34", "6.8", "ICE", "Germany", "Mercedes", "434");
			
		}

		case 11: {

			cout << "Enter an Employee information\n\n";

			string ID, name, sex, address, position;
			int age, salary;

			cout << "Enter employee ID :";
			cin.ignore(); // Clear the buffer
			getline(cin, ID);


			cout << "Enter employee Name :";
			getline(cin, name);

			cout << "Enter employee Age :";
			cin >> age;

			cout << "Enter gender :";
			cin >> sex;
			
			cout << "Enter Address :";
			cin.ignore();
			getline(cin, address);

			cout << "Enter employee position: ";
			getline(cin, position);

			cout << "Enter employee salary: ";
			cin >> salary;

			Employee employee(ID, name, age, sex, address, position, salary);

			/*
			Write Employee data to file
			However, function writeFile to be explored further so it can be re-used
			*/ 

			cout << "Employee file now being written to the text file\n";

			ofstream outFile;
			static const char* fileLocation = "Employee.txt";
			outFile.open(fileLocation);

			if (!outFile.is_open()) {
				cout << "*** File opened unsuccessfully ***\n";
			}
			else
			{
				writeToFile(employee, outFile);
				outFile.close();

				cout << "*** Employee record written to file successfully ***\n";
			}


			break;
		}

		default: {

			cout << "Invalid choice selected\n";
		}

		}
	}
}
