
#pragma once
#include <string>
#include <vector>
#include <map>
#include <fstream>


using namespace std;

struct Books {
	string title{};
	string author{};
	string publisher{};
	string subject{};
	string ISBN{};
	string WorldCat{};
	double DeweyDecimal{};
	int pubYear{};
	int acqYear{};
	int currStock{};
};

struct Officer {
	string fullName{};
	string position{};
	char sex{};
	int age{};
	string race{};
};

Books& inPopulate(Books& bookTemplate); //Should be able to use one for both DNRY, with medium being a parameter
Books& populate(Books& bookTemplate);
string getNextLine(ifstream& inFile);
void mPopulate(Officer& officer);
void writeFile(map < string, Officer> & staff, ofstream& outFile);

void function1();
void function2();