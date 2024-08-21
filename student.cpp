#include "student.h"
#include "degree.h"
#include <iostream> 

using namespace std;

Student::Student(string studentIDEntry, string firstNameEntry, string lastNameEntry, string email, int age, int* daysInCourses, DegreeProgram degreeProgramEntry) {

    StudentID = studentIDEntry;
    FirstName = firstNameEntry;
    LastName = lastNameEntry;
    Email = email;
    Age = age;
    DaysInCourse[0] = daysInCourses[0];
    DaysInCourse[1] = daysInCourses[1];
    DaysInCourse[2] = daysInCourses[2];
    degreeProgram = degreeProgramEntry;

}

string Student::GetStudentID() {
    return StudentID;
}

string Student::GetFirstName() {
    return FirstName;
}

string Student::GetLastName() {
    return LastName;
}

string Student::GetEmail() {
    return Email;
}

int Student::GetAge() {
    return Age;
}

int* Student::GetDaysInCourse() {
    return DaysInCourse;
}

DegreeProgram Student::GetDegreeProgram() {
    return degreeProgram;
}

void Student::SetStudentID(string studentID) {
    StudentID = studentID;
}

void Student::SetFirstName(string firstNameEntry) {
    FirstName = firstNameEntry;
}

void Student::SetLastName(string lastNameEntry) {
    LastName = lastNameEntry;
}

void Student::SetEmail(string emailEntry) {
    Email = emailEntry;
}

void Student::SetAge(int ageEntry) {
    Age = ageEntry;
}

void Student::SetDaysInCourse(int DayEntry, int CourseNumber) {
    DaysInCourse[CourseNumber - 1] = DayEntry;
}

void Student::SetDegreeProgram(DegreeProgram degreeEntry) {
    degreeProgram = degreeEntry;
}

void Student::print() {

    DegreeProgram degreeProgram = GetDegreeProgram();
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

    cout << GetStudentID() << " First Name: " << GetFirstName() << "    Last Name: " << GetLastName() << "  Age: " << GetAge() << "   daysInCourse: {" << DaysInCourse[0] << "," << DaysInCourse[1] << "," << DaysInCourse[2] << "}" << "    Degree Program: " << degreeProgramString << endl;

};