// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com



/***********************************************************************
* Program used STL containers such as the following
1. Vector
2. List
Author: Iskled Adebayo
***********************************************************************/

#include "functions.h"
#include <iostream>
#include <string>
#include <format>
#include <vector>   // for using the library objects
#include <fstream>
#include <map>   // for using the map from STL
#include <sstream>   // for using the istringstream function
#include <thread>     // for  using the multi-threading library


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
		cout << "12. Multi-threaded programming\n";
		cout << "13. Evaluate execution timings\n";
		cout << "**********************************************************\n\n";

		int menu;
		do {
			cout << "Enter 1 - 12 for menu items : ";
			cin >> menu;
		} while (menu < 1 || menu >12);

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

			int choice;
			
			while (true) {	// Loop to control exit from inner case switch
				do {				// Loop to control exit from inner menu display
					cin.ignore();
					cout << "\nEnter Employee information\n\n";
					cout << "1. Junior officer\n";
					cout << "2. Manager\n";
					cout << "3. Director\n";
					cout << "4. Quit\n\n";
					cout << "Enter choice : ";
					cin >> choice;
				} while (choice < 1 || choice > 4);

				if (choice == 4) break;
				

				// Employee record common to all (Employee, Manager, Director class)

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

				// Choose proper class to process
				switch (choice) {

					//Employee class case
				case 1: {

					Employee employee(ID, name, age, sex, address, position, salary); // Should be able to use a constructor ovwerload!!!!!!

					// Open file to be written to

					string fileLocation = "Employee.txt";
					fileProcessing(fileLocation, employee);
					break;
				}
				case 2:{

					string officialCar, officialResidence;
					
					cout << "Enter manager official car Make and Model : ";
					cin.ignore();
					getline(cin, officialCar);

					cout << "Enter manager official residencial address : ";
					getline(cin, officialResidence);

					Manager manager(ID, name, age, sex, address, position, salary, officialCar, officialResidence);
					
					string fileLocation = "Manager.txt";

					fileProcessing(fileLocation, manager);
					break;
				}
				case 3: {
					int budget;
					string region, strategicGoal, officialCar, officialResidence;

					cout << "Enter Director official car : ";
					cin.ignore();
					getline(cin, officialCar);

					cout << "Enter Director official residence : ";
					getline(cin, officialResidence);

					cout << "Enter director budget : ";
					cin>>budget;

					cout << "Enter Director region : ";
					cin.ignore();
					getline(cin, region);

					cout << "Enter Director strategic goal : ";
					getline(cin, strategicGoal);

					Director director(ID, name, age, sex, address, position, salary, officialCar, officialResidence, budget, region, strategicGoal);

					string fileLocation = "Director.txt";

					fileProcessing(fileLocation, director);					
					break;
				}

				default: {
					break;
				}
				}
			}
				 
			/*
			Write Employee data to file
			However, function writeFile to be explored further so it can be re-used
			*/ 

			

			break;
		}

		case 12: {
			// Multi-threaded programming

			// Create a thread

			

			thread T1(funRun, 100);

			cout << " Thread function must have been created and just returned \n";

			//if (T1.joinable())
				T1.detach();


			break;
		}

		case 13: {
			// Evaluating execution times

			ull start = 0, end = 1900000000, totalEven{ 0 }, totalOdd{ 18776 };
			
			auto startTime = high_resolution_clock::now(); // Starting time-stamp

			thread evenThread(evenSum, start, end, ref(totalEven));
			thread oddThread(oddSum, start, end, ref(totalOdd));

			evenThread.join();
			oddThread.join();
			
			cout << "Sum of number of odd numbers between  " << start << " and " << end << " = " << totalOdd << "\n";
			cout << "Sum of number of even numbers between  " << start << " and " << end << " = " << totalEven << "\n";

			auto stopTime = high_resolution_clock::now(); // Stop time-stamp

			auto duration = duration_cast<microseconds>(stopTime - startTime );

			cout << "Here is the execution time taken = " << duration.count()/1000000 << "\n";
		}

		default: {

			cout << "Invalid choice selected\n";
		}

		}
	}
}
