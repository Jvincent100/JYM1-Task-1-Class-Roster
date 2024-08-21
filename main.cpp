#include <iostream>
#include<sstream>
#include <vector>
#include "roster.h"
using namespace std;


int main() {
   //1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    cout << "Application: Student Roster Database Mock::  JYM1 TASK 1: CLASS ROSTER" << endl;
    cout << "Course Title: Scripting and Programming - Applications – C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 011253318" << endl;
    cout << "Name: Joshua Vincent" << endl;
    cout << endl;

    Roster classRoster;

    classRoster.printAll();
    classRoster.printInvalidEmails();

    for (int i = 0; i < classRoster.rosterSize; i++) {

     string studentID = classRoster.classRosterArray[i]->GetStudentID();

     classRoster.printAverageDaysInCourse(studentID);
    }

    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}