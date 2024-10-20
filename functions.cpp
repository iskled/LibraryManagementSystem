#include "functions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

string getNextLine(ifstream& inFile) {
    string line;
    getline(inFile, line);
    return line;
}

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


void mPopulate(Officer& officer) {

    cout << "Enter officer position\n";
    getline(cin, officer.position);

    cout << "Enter officer sex\n";
    cin >> officer.sex;

    cout << "Enter officer age\n";
    cin >> officer.age;
    cin.ignore();

    cout << "Enter officer race\n";
    getline(cin, officer.race);

}

void writeFile(map<string, Officer>& staff, ofstream & outFile) {
    for (const auto& pair : staff) {
        outFile << pair.first, pair.second;
    }
}