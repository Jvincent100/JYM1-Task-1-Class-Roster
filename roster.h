#include <iostream>
#include "student.h"
using namespace std;


class Roster {

public:

    Student* classRosterArray[5];
    int rosterSize = sizeof(classRosterArray) / sizeof(classRosterArray[0]);

    Roster();

    ~Roster();

void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram, int index);
void remove(string studentID);
void printAll();
void printAverageDaysInCourse(string studentID);
 void printInvalidEmails();
void printByDegreeProgram(DegreeProgram degreeProgram);
};