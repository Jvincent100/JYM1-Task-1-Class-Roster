#include "degree.h"
#include <iostream> 

using namespace std;

class Student {

private:
	string StudentID;
	string FirstName;
	string LastName;
	string Email;
	int Age;
	int DaysInCourse[3];
	DegreeProgram degreeProgram;

public:
	
	Student(string, string, string, string, int, int*, DegreeProgram);

	//Accesors
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmail();
	int GetAge();
	int* GetDaysInCourse();
	DegreeProgram GetDegreeProgram();

	//Mutator
	void SetStudentID(std::string);
	void SetFirstName(std::string);
	void SetLastName(std::string);
	void SetEmail(std::string);
	void SetAge(int);
	void SetDaysInCourse(int, int);
	void SetDegreeProgram(DegreeProgram);
    
	void print();
};