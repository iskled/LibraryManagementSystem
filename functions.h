//#pragma once

#ifndef FUNCTIONS_H

#define FUNCTIONS_H




#include <iostream>
#include <string>
#include <map>
#include <fstream>


using namespace std;

// Books struct declaration
struct Books {
	string title{},author{}, publisher{},subject{}, ISBN{},WorldCat{};
	double DeweyDecimal{};
	int pubYear{ 0 }, acqYear{0},currStock{0};
		
	// The following constructor and destructors are useless since they implicitely defined already by the compiler
	Books();
	~Books();
};

struct Officer {
	string fullName{};
	string position{};
	char sex{};
	int age{};
	string race{};

	//want to make the default constructor or destructor explicitly visible for documentation purposes.
	Officer() {

	}

	~Officer() {

	}
};



class User {
public:
	string firstName;
	string lastName;
	int Age;
	string Email;

	// Default constructor
	User() {
		firstName = "";
		lastName = "";
		Age = 10;
		Email = "";
	}

	// Params constructor
	User(string& fname, string& lname, int age, string& email) :  firstName(fname), lastName(lname), Age(
		age), Email(email){}

	User(string fname, string lname, int age) {
		firstName = fname;
		lastName = lname;
		Age = age;
		Email = fname + "." + lname + "@gmail.com";
	}
};

Books& inPopulate(Books& bookTemplate); //Should be able to use one for both DNRY, with medium being a parameter
Books& populate(Books& bookTemplate);
string getNextLine(ifstream& inFile);
void mPopulate(Officer& officer);
void writeFile(map < string, Officer> & staff, ofstream& outFile);

void function1();
void function2();
void printUser(User u);

class Stadium {
	string name;
	int capacity;
	string location;

	int minCapacity() {
		return capacity / 2;
	}

public:
	int maxCapacity() {
		return capacity * 2; // Because maxCapacity() is a member of the function but not private, this has to be used to access private member
}

	Stadium(string n, int c, string l) {
		name = n;
		capacity = c;
		location = l;
	}

	int minimumCapacity(void) {
		return minCapacity();
	}

	string& getName() {
		return name;
	}

	void setName(string& n) {
		this->name = n;
	}
};

class Vehicle {
	string type;
	string tyresNum;
	string engineCapacity;

protected:
	string engineType;
	void setTyresNum(string tyrNum) { tyresNum = tyrNum; }
	void setEngineCapacity(string engCap) { engineCapacity = engCap; }


public: 
	string getType() { 
		return type;
	}  // May be used while writing to a file
	void setType(string type) { this->type = type; } // Creating access to private member can be done at Protected (accessible to inherited class) or Public (Accessible to everyone)

	string countryOrigin;

	Vehicle() {};
	
	Vehicle(string t, string tyre, string eng, string engType) {
		type = t;
		tyresNum = tyre;
		engineCapacity = eng;
		engineType = engType;
	}


};

// ~region Car class declaration
class Car : public Vehicle {
public:
	string make;
	string model;

	Car(string typ, string tyrNum, string egCap, string engTyp, string country, string mk, string mdl);
	string sounds(string vehicleType);
};
// #end of region

// Plant Declaration
class Plant {
public:
	string plantName{}, plantType{}, tyreType{}, maneuvCapability, roughCapability;

	Plant();

	~Plant();

};

// Base class
class Employee {
protected:
	string ID;
	string name;
	int age;
	string sex;
	string address;
	string position;
	int salary;

public:

	//Constructor declaration
	Employee(const string& empId, const string& empName, int empAge, const string& empSex,
		const string& empAddress, const string& empPosition, const int empSalary);

	// Getters declaration
	string& getID();
	string& getName();
	int getAge();
	string& getSex();
	string& getAddress();
	string& getPosition();
	int getSalary();

	// Setters declaration
	void setID(const string& empId);
	void setName(const string& empName);
	void setAge(int empAge);
	void setSex(const string& empSex);
	void setAddress(const string& empAddress);
	void setPosition(const string& empPosition);
	void setSalary(const int empSalary);

	// Print Employee data to the screen

	virtual void displayInfo();

	//Calculate Annual Salary
	int annualSalary(int monthlySalary);

	//Update residential address..............to be implemented later



  ~Employee();
	
};

// Derived class linking with base class
class Manager : public Employee {
	string m_officialCar;
	string m_officialResidence;

public:

	// Constructor with using the initialization list of the parent Employee
	Manager(const string& manID, const string& manName, const int manAge, const string& manSex, const string& manAddress, const string& manPosition,
		const int manSalary, const string& m_officialCar, const string& m_officialResidence);

	// Getters
	string& getOfficialCar();
	string& getOfficialResidence();

	//Setters
	void setOfficialCar(string& officialCar);
	void setOfficialResidence(string& officialResidence);

	// Fucntion to display manager content including employee
	void displayInfo() override;

	//Conduct meeting

	//Manager Destructor declaration 
	~Manager();
};

//Another derived class on Employee
class Director : public Manager {
	int m_budget = 0;
	string m_region;
	string m_strategicGoal;

public:
	Director(const string& dirID, const string& dirName, const int dirAge, const string& dirSex, const string& dirAddress, const string& dirPosition,
		const int dirSalary, const string& dirOfficialCar, const string& dirOfficialResidence, const int dirBudget, const string& dirRegion,
		const string& dirStrategicGoal);

	void displayInfo() override;

	//Director Setters
	void setBudget(int budget) { m_budget = budget; }
	void setRegion(string& region) { m_region = region; }
	void setStrategicGoal(string& goal) { m_strategicGoal = goal; }

	//Director Getters
	int getBudget() { return m_budget; }
	string& getRegion() { return m_region; }
	string& getStrategicGoal() { return m_strategicGoal; }

	//Director Destructor Declaration
	~Director();
};

// FIle processing declaration

template <class T>

void fileProcessing(string& m_fileLocation, T& m_staff) {

	ofstream outFile;
	outFile.open(m_fileLocation, ios::app);

	if (!outFile.is_open()) {
		cout << "*** File opened unsuccessfully ***\n";
	}
	else
	{
		writeToFile(outFile, m_staff);
		outFile.close();

		cout << "\n\n*** Staff record written to file successfully ***\n";
	}
}

void writeToFile(ofstream& outFile, Employee& employee);
void writeToFile(ofstream& outFile, Manager& manager);
void writeToFile(ofstream& outFile, Director& director);



/*

TO DO NEXT

Namespace to be streamlined
Classes to be expanded 
Functions to be reviewed to include map
Entered data to be printed to a file

*/

#endif // FUNCTIONS_H