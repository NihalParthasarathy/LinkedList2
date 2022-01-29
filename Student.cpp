//Inclusions
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"

using namespace std;


void Student::printStudent() {//Prints out what the student has
  cout << "Name:" << first << " " << last << " ID:" << id << " GPA:"<< fixed << showpoint << setprecision(2) << gpa << endl;
}
