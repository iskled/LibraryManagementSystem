// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


#include "functions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <thread>
#include <chrono>

using namespace std;
//using this_thread;

// Function printUser definition
void printUser(User u) {
    cout << u.firstName << "\n";
    cout << u.lastName << "\n";
    cout << u.Age << "\n";
    cout << u.Email << "\n";
}

// Function getNectLine definition
string getNextLine(ifstream& inFile) {
    string line;
    getline(inFile, line);
    return line;
}

// Function Populate definition
Books& populate(Books& bookTemplate) {                 // Book& populate(Books &bookTemplate) to be implemented later
    cin.ignore();
    cout << "Enter title of the book : ";
    getline(cin, bookTemplate.title);

    cout << "Enter author : ";
    getline(cin, bookTemplate.author);

    cout << "Publisher : ";
    getline(cin, bookTemplate.publisher);

    cout << "Enter book subject or category ";
    getline(cin, bookTemplate.subject);

    cout << "Enter ISBN : ";
    getline(cin, bookTemplate.ISBN);

    cout << "Enter World category : ";
    getline(cin, bookTemplate.WorldCat);

    cout << "Enter Dewey Decimal : ";
    cin >> bookTemplate.DeweyDecimal;

    cout << "Enter year of publication : ";
    cin >> bookTemplate.pubYear;

    cout << "Enter year of acquire : ";
    cin >> bookTemplate.acqYear;

    cout << "Enter current stock : ";
    cin >> bookTemplate.currStock;
    cin.ignore();

    return bookTemplate;
}

// Function inPopulate definition
Books& inPopulate(Books& bookTemplate) {
    
   
    const char* fileLocation = { "C:\\Users\\user\\OneDrive\\Documents\\iweTable.txt" }; // location of text file on the HDD

    ifstream inFile; 

    inFile.open(fileLocation);

    if (!inFile.is_open()) {
        cout << "\nFile opening unsuccessfull\n";
    }else
    {
        cout << "\nFile opening successfull\n";
        bookTemplate.title = getNextLine(inFile);
        bookTemplate.author = getNextLine(inFile);
        bookTemplate.publisher = getNextLine(inFile);
        bookTemplate.subject = getNextLine(inFile);
        bookTemplate.ISBN = getNextLine(inFile);
        bookTemplate.WorldCat = getNextLine(inFile);
        bookTemplate.DeweyDecimal = stod(getNextLine(inFile));
        bookTemplate.pubYear = stod(getNextLine(inFile));
        bookTemplate.acqYear = stod(getNextLine(inFile));
        bookTemplate.currStock = stod(getNextLine(inFile));
        inFile.close();
    }
    return bookTemplate;

}

// Function mPopulate definition
void mPopulate(Officer& officer) {

    cout << "Enter officer position\n";
    getline(cin, officer.position);

    cout << "Enter officer sex\n";
    cin >> officer.sex;

    cout << "Enter officer age\n";
    cin >> officer.age;
    cin.ignore();

    cout << "Enter officer race\n";    getline(cin, officer.race);

}

// Function WriteFile Definition
void writeFile(map<string, Officer>& staff, ofstream & outFile) {
    for (const auto& pair : staff) {
        outFile << pair.first << "\n";
        outFile << pair.second.fullName<<"\n";
        outFile << pair.second.age<<"\n";
        outFile << pair.second.position<<"\n";
        outFile << pair.second.sex<<"\n";
        outFile << pair.second.race<<"\n";
        outFile << '¬' << "\n";
       /* outFile << pair;*/
    }
}

// #region multitask functions definition
void function1() {
    for (int i = 0; i < 500; i++)
        cout << '-';
    //this_thread::sleep_for(chrono::seconds(1));
    this_thread::sleep_for(chrono::milliseconds(500));
}

void function2() {
    for (int i = 0; i < 500; i++)
        cout << '+';
   this_thread:: sleep_for(chrono::milliseconds(500));
}
// end region of multitask functions

// #region Car Class Implementation
Car::Car(string typ, string tyrNum, string egCap, string engTyp, string country, string mk, string mdl) {
    setType(typ);
    setTyresNum(tyrNum);
    setEngineCapacity(egCap);
    engineType = engTyp;
    countryOrigin = country;
    make = mk;
    model = mdl;
}

string Car::sounds(string vehicleType) {
    if (vehicleType == "sport") {
        return "vroooooooo";
    }
    else if (vehicleType == "Hatchback") {
        return "mooooooovey";
    }
    else return "wroowrow";
}
// #endregion

// #region Book constructor and destructor definition
Books::Books() {}

Books::~Books() {}
// end region Books 

//Plant comnstructor definition
Plant::Plant() {
    plantName = "Kenol";
    plantType = "Hybrid";
    tyreType = "4x4";
    maneuvCapability = "true";
    roughCapability = "YYYYYYY";
}

Plant::~Plant() = default;


Employee::Employee(const string& empId, const string& empName, int empAge, const string& empSex, const string& empAddress, const string& empPosition, const int empSalary)
: ID(empId), name(empName), age(empAge), sex(empSex), address(empAddress), position(empPosition), salary(empSalary) {} // Constuctor for the Employee class with initialization list

// Getter Implementations
string& Employee::getID() { return ID; }
string& Employee::getName() { return name; }
int Employee::getAge() { return age; }
string& Employee::getSex() { return sex; }
string& Employee::getAddress() { return address; }
string& Employee::getPosition() { return position; }
int Employee::getSalary() { return salary; }

// Setter Implementations
void Employee::setID(const string& empId) { ID = empId; }
void Employee::setName(const string& empName) { name = empName; }
void Employee::setAge(int empAge) { age = empAge; }
void Employee::setSex(const string& empSex) { sex = empSex; }
void Employee::setAddress(const string& empAddress) { address = empAddress; }
void Employee::setPosition(const string& empPosition) { position = empPosition; }
void Employee::setSalary(const int empSalary) { salary = empSalary; }

void Employee:: displayInfo() {
    cout << "ID : " << ID << "\n";
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "Sex: " << sex << "\n";
    cout << "Address: " << address << "\n";
    cout << "Position: " << position << "\n";
    cout << "Salary: " << salary << "\n";
}

int Employee::annualSalary(int monthlySalary) {
    return monthlySalary * 12;
}

//Employee Destructor implementation
Employee::~Employee() {};


Manager::Manager(const string& manID, const string& manName, const int manAge, const string& manSex, const string& manAddress, const string& manPosition,
    const int manSalary, const string& officialCar, const string& officialResidence)
    : Employee(manID, manName, manAge, manSex, manAddress, manPosition, manSalary), m_officialCar(officialCar),
    m_officialResidence(officialResidence) {}

// #region Manager properties Getters implementations
string& Manager::getOfficialCar() { return m_officialCar; }

string& Manager::getOfficialResidence() { return m_officialResidence; }
// #end region 

// #region Manager properties Setters implementations
void Manager::setOfficialCar(string& car) { m_officialCar = car; }

void Manager::setOfficialResidence(string& residence) { m_officialResidence = residence; }
// #end region

/* #region overrided displayInfo implementation
* Does not require "override" again as it has already been inclusded in the declaration section inside the header file
*/
void Manager::displayInfo() {
    Employee::displayInfo();
    cout << "Official Car : " 
         << (m_officialCar.empty() ? "Not assigned" : m_officialCar) << "\n";
    cout << "Official Residence : "
        << (m_officialResidence.empty() ? "Not assigned" : m_officialResidence) << "\n";
}
// #end region

//Manager Destructor Definition
Manager::~Manager() {};

// #region class Director definition

Director::Director(const string& dirID, const string& dirName, const int dirAge, const string& dirSex, const string& dirAddress, const string& dirPosition,
    const int dirSalary, const string& dirOfficialCar, const string& dirOfficialResidence, const int dirBudget, const string& dirRegion,
    const string& dirStrategicGoal) : Manager(dirID, dirName, dirAge, dirSex, dirAddress, dirPosition, dirSalary, dirOfficialCar, dirOfficialResidence),
    m_budget(dirBudget), m_region(dirRegion), m_strategicGoal(dirStrategicGoal) {}

    void Director::displayInfo() {
        Manager::displayInfo();
        cout << "Budget : " << m_budget << "\n";
        cout << "Region : "
             << (m_region.empty() ? "Not assigned" : m_region) << "\n";
        cout << "Strategic goal : "
             << (m_strategicGoal.empty() ? "Not assigned" : m_strategicGoal) << "\n";
    }

    Director::~Director() {};
    // end region
  




    // WriteToFile definition
    void writeToFile(ofstream& outFile, Employee& employee) { // Opening and closing stype to be decided later i.e. to be opened once and write all or otherwise

        outFile << employee.getID() << "\n";
        outFile << employee.getName() << "\n";
        outFile << employee.getAge() << "\n";
        outFile << employee.getSex() << "\n";
        outFile << employee.getAddress() << "\n";
        outFile << employee.getPosition() << "\n";
        outFile << employee.getSalary() << "\n";
        outFile << '¬' << "\n";
    }

    void writeToFile(ofstream& outFile, Manager& manager) {
        outFile << manager.getID() << "\n";
        outFile << manager.getName() << "\n";
        outFile << manager.getAge() << "\n";
        outFile << manager.getSex() << "\n";
        outFile << manager.getAddress() << "\n";
        outFile << manager.getPosition() << "\n";
        outFile << manager.getSalary() << "\n";
        outFile << manager.getOfficialCar() << "\n";
        outFile << manager.getOfficialResidence() << "\n";
        outFile << '¬' << "\n";

    }

    void writeToFile(ofstream& outFile, Director& director) {
        outFile << director.getID() << "\n";
        outFile << director.getName() << "\n";
        outFile << director.getAge() << "\n";
        outFile << director.getSex() << "\n";
        outFile << director.getAddress() << "\n";
        outFile << director.getPosition() << "\n";
        outFile << director.getSalary() << "\n";
        outFile << director.getOfficialCar() << "\n";
        outFile << director.getOfficialResidence() << "\n";
        outFile << director.getBudget() << "\n";
        outFile << director.getRegion() << "\n";
        outFile << director.getStrategicGoal() << "\n";
        outFile << '¬' << "\n";

    }