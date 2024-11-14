
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>


using namespace std;

struct Books {
	string title{};
	// This is a personal academic project. Dear PVS-Studio, please check it.
    // PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
	
	string author{};
	string publisher{};
	string subject{};
	string ISBN{};
	string WorldCat{};
	double DeweyDecimal{};
	int pubYear{};
	int acqYear{};
	int currStock{};

	Books() {

	}

	~Books() {

	}
};

struct Officer {
	string fullName{};
	string position{};
	char sex{};
	int age{};
	string race{};

	Officer() {

	}

	~Officer() {

	}
};


class Plant {
	string plantName{};
	string plantType{};
	string tyreType{};
		string maneuvCapability;



public:

	int roughCapability{ 10 };
	Plant() {
		int reachHeight{ 20 };
		bool outDoorCapability;
		bool autonomousCapable{ 1 };
		int payloadCapable;
		int lifeSpan;
		string engineType{ "ICE" };
	}

	~Plant() = default;

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
	User(string& fname, string& lname, int age, string& email) :  firstName(fname), lastName(lname), Age(age), Email(email){}

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

static class Vehicle {
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

class Car : public Vehicle {
public:
	string make;
	string model;

	Car(string typ, string tyrNum, string egCap, string engTyp, string country, string mk, string mdl) {
		setType(typ);
		setTyresNum(tyrNum);
		setEngineCapacity(egCap);
		engineType = engTyp;
		countryOrigin = country;
		make = mk;
		model = mdl;
	};

	string sounds(string vehicleType) {
		if (vehicleType == "sport") {
			return "vroooooooo";
		}
		else if (vehicleType == "Hatchback") {
			return "mooooooovey";
		}
		else return "wroowrow";

	}
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
	Employee(const string& empId, const string& empName, int empAge, const string& empSex,const string& empAddress, const string& empPosition, const int empSalary ) 
		: ID(empId),name(empName),age(empAge),sex(empSex),address(empAddress),position(empPosition),salary(empSalary) {} // Constuctor for the Employee class with initialization list

	// Getters
	string& getID() { return ID; }
	string& getName() { return name; }
	int getAge() { return age; }
	string& getSex() { return sex; }
	string& getAddress() { return address; }
	string& getPosition() { return position; }
	int getSalary() { return salary; }

	// Setters
	void setID(const string& empId) { ID = empId; }
	void setName(const string& empName) { name = empName; }
	void setAge(int empAge) { age = empAge; }
	void setSex(const string& empSex) { sex = empSex; }
	void setAddress(const string& empAddress) { address = empAddress; }
	void setPosition(const string& empPosition) { position = empPosition; }
	void setSalary(const int empSalary) { salary = empSalary; }

	// Print Employee data to the screen
	virtual void displayInfo() {
		cout << "ID : " << ID << "\n";
		cout << "Name: " << name << "\n";
		cout << "Age: " << age << "\n";
		cout << "Sex: " << sex << "\n";
		cout << "Address: " << address << "\n";
		cout << "Position: " << position << "\n";
		cout << "Salary: " << salary << "\n";
	}

	//Calculate Annual Salary
	int annualSalary(int monthlySalary) {
		return monthlySalary * 12;
	}

	//Update residential address..............to be implemented later
	
};

// Derived class linking with base class
class Manager : public Employee {
	string officialCar;
	string officialResidence;

public:

	// Constructor with using the initialization list of the parent Employee
	Manager(const string& manID, const string& manName, const int manAge, const string& manSex, const string& manAddress, const string& manPosition, 
		const int manSalary, const string& manOfficialCar, const string& manOfficialResidence) 
		: Employee(manID, manName, manAge, manSex, manAddress, manPosition, manSalary), officialCar(manOfficialCar), 
		officialResidence(manOfficialResidence){}

	// Getters
	string getOfficialCar() { return officialCar; }
	string& getOfficialResidence() { return officialResidence; }

	//Setters
	void setOfficialCar(string& oc) { officialCar = oc; }
	void setOfficialResidence(string& orr) { officialResidence = orr; }

	// Fucntion to display manager content including employee
	void displayInfo() override {  // const to be researched
		Employee::displayInfo(); 
			cout << "Official Car :" << officialCar << "\n";
			cout << "Official Residence :" << officialResidence << "\n";
	}

	//Conduct meeting

	// Assign tax
};

//Another derived class on Employee
class Director : public Employee {
	int budget;
	string& region;
	string& strategicGoal;

//public:
//	Director(const string& dirID, const string& dirName, const int dirAge, const string& dirSex, const string& dirAddress, const string& dirPosition,
//		const int dirSalary, const string& dirOfficialCar, const string& dirOfficialResidence, const int dirBudget, const string& dirRegion, 
//		const string& dirStrategicGoal) : Manager(dirID, dirName, dirAge, dirSex, dirAddress, dirPosition, dirSalary, dirOfficialCar, dirOfficialResidence), 
//		budget(dirBudget), region(dirRegion), strategicGoal(dirStrategicGoal) {};

	/*Director(const string& dirID, const string& dirName, const int dirAge, const string& dirSex, const string& dirAddress, const string& dirPosition,
		const int dirSalary, const string& dirOfficialCar, const string& dirOfficialResidence, const int dirBudget, const string& dirRegion,
		const string& dirStrategicGoal) : Employee(dirID, dirName, dirAge, dirSex, dirAddress, dirPosition, dirSalary, dirOfficialCar, dirOfficialResidence),
		budget(dirBudget), region(dirRegion), strategicGoal(dirStrategicGoal) {};*/

	


};


void writeToFile(Employee& employee, ofstream& outFile);
void writeToFile(Manager& manager, ofstream& outFile);
void writeToFile(Director& director, ofstream& outFile);



/*

TO DO NEXT

Namespace to be streamlined
Classes to be expanded 
Functions to be reviewed to include map
Entered data to be printed to a file

*/

