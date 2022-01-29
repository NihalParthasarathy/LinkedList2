//Nihal Parthasarathy
//1/29/2022
//This code runs a studentlist where you can add, print, delete and avarage students. This is acomplished using linkedlists
//Header gaurd
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student {//Student class
public:
  //Initlizes varubles
  char first[20];
  char last[20];
  int id;
  float gpa;
  
  //Print student Function
  void printStudent();
};

#endif
