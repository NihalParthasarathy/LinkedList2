#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

void Student::setStudent(char* newfirst, char* newlast, int newid, float newgpa) {
  strcpy(first, newfirst);
  strcpy(last, newlast);
  id = newid;
  gpa = newgpa;
}

void Student::printStudent() {//Prints out what the student has
  cout << "First Name:" << first << " Last Name:" << last << " ID:" << id << " GPA:"<< gpa << endl;
}
