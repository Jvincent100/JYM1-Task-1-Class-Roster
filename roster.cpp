#include "roster.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//E.  Create a Roster class (roster.cpp) by doing the following
Roster::Roster() {
//1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
    Student* classRosterArray[5];
//2.  Create a student object for each student in the data table and populate classRosterArray.
    string StudentID;
    string firstName;
    string lastName;
    string email;
    string ageString;
    int age;
    string daysInCourse1String;
    string daysInCourse2String;
    string daysInCourse3String;
    int daysInCourse1;
    int daysInCourse2;
    int daysInCourse3;
    string degreeProgramString;
    DegreeProgram degreeProgram;

    const string studentData[] =
    {
      "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Joshua,Vincent,jvinc84@.wgu.edu,21,20,15,10,SOFTWARE"
    };

    int number = sizeof(studentData) / sizeof(studentData[0]);

    for (int i = 0; i < number; i++) {

        string name;

        string myString = studentData[i];
        stringstream myStream(myString);

        getline(myStream, StudentID, ',');
        getline(myStream, firstName, ',');
        getline(myStream, lastName, ',');
        getline(myStream, email, ',');
        getline(myStream, ageString, ',');
        age = stoi(ageString);
        getline(myStream, daysInCourse1String, ',');
        daysInCourse1 = stoi(daysInCourse1String);
        getline(myStream, daysInCourse2String, ',');
        daysInCourse2 = stoi(daysInCourse2String);
        getline(myStream, daysInCourse3String, ',');
        daysInCourse3 = stoi(daysInCourse3String);
        getline(myStream, degreeProgramString, ',');

        if (degreeProgramString == "SECURITY") {
            degreeProgram = SECURITY;
        }
        else if (degreeProgramString == "NETWORK") {
            degreeProgram = NETWORK;
        }
        else if (degreeProgramString == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        }

        add(StudentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram, i);

    }
    cout << endl;
}

//3.  Define the following functions
void Roster::add(string studentID, string firstName, string lastName, string email, int ageInput, int daysInCourse1Input, int daysInCourse2Input, int daysInCourse3Input, DegreeProgram degreeProgramInput, int index) {

    int daysSplit[] = { daysInCourse1Input, daysInCourse2Input, daysInCourse3Input };

    classRosterArray[index] = new Student(studentID, firstName, lastName, email, ageInput, daysSplit, degreeProgramInput);
};

void Roster::printAll() {
    cout << "Displaying all Students information:" << endl;

    for (int i = 0; i < rosterSize; i++) {

        if (classRosterArray[i] != nullptr || classRosterArray[i] != 0) {
            classRosterArray[i]->print();
        }
    }

    cout << endl;
};

void Roster::printInvalidEmails() {

    cout << "Below are the inalid emails in the data set:" << endl;
    for (int i = 0; i < rosterSize; i++) {
        string email = classRosterArray[i]->GetEmail();

        if (email.find(' ') != string::npos) {
            cout << "Email: " << email << "is Invalid: Spaces are illegal " << endl;
        }

        if (email.find('.') != string::npos) {
            //Pass this is Good email
        }
        else {
            cout << "Email: " << email << "is Invalid: '.' is required " << endl;
        };

        if (email.find('@') != string::npos) {
            
        }
        else {
            cout << "Email: " << email << "is Invalid: '@' is required " << endl;
        }

    }

    cout << endl;
};

void Roster::printAverageDaysInCourse(string studentID) {

    for (int i = 0; i < rosterSize; i++) {
        string sID = classRosterArray[i]->GetStudentID();

        if (studentID == sID) {

            int courseLen1 = classRosterArray[i]->GetDaysInCourse()[0];
            int courseLen2 = classRosterArray[i]->GetDaysInCourse()[1];
            int courseLen3 = classRosterArray[i]->GetDaysInCourse()[2];

            cout << classRosterArray[i]->GetFirstName() << "'s average days in courses is: " << (courseLen1 + courseLen2 + courseLen3) / 3;

        }

    }
    cout << endl;
};

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

    string degreeProgramString;


    if (degreeProgram == SECURITY) {
        degreeProgramString = "SECURITY";
    }
    else if (degreeProgram == NETWORK) {
        degreeProgramString = "NETWORK";
    }
    else if (degreeProgram == SOFTWARE) {
        degreeProgramString = "SOFTWARE";
    }

    cout << endl;
    cout << "The following are the students enrolled in the program entitled: " << degreeProgramString << endl;

    for (int i = 0; i < rosterSize; i++) {

        DegreeProgram degreeProg = classRosterArray[i]->GetDegreeProgram();

        if (classRosterArray[i] != 0) {

            if (degreeProgram == degreeProg) {
                classRosterArray[i]->print();
            }

        }

    }

    cout << endl;


};

void Roster::remove(string studentID) {

    cout << "Attempting to remove studentID: " << studentID << endl;
    for (int i = 0; i < rosterSize; i++) {

        if (classRosterArray[i] != 0) {

            string sID = classRosterArray[i]->GetStudentID();

            if (studentID == sID) {
                classRosterArray[i] = 0;
                cout << "Sucessfully removed Student from roster!" << endl;
            }

        }

        else {
            cout << "ERROR: Student does not exist at this roster index" << endl;
        }

    }

    cout << endl;
};

Roster::~Roster() {
    cout << "Roster Destructor called";
}
