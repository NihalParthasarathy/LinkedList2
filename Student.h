#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student {
public:
  char first[20];
  char last[20];
  int id;
  float gpa;
  
  void setStudent(char* newfirst, char* newlast, int newid, float newgpa);
  void printStudent();
};

#endif
