#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"

using namespace std;

void Student::setStudent(char* newfirst, char* newlast, int newid, float newgpa) {
  strcpy(first, newfirst);
  strcpy(last, newlast);
  id = newid;
  gpa = newgpa;
}

void Student::printStudent() {//Prints out what the student has
  cout << "Name:" << first << " " << last << " ID:" << id << " GPA:"<< fixed << showpoint << setprecision(2) << gpa << endl;
}
