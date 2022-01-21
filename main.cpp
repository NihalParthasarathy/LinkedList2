#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

void add(Student* s, Node* next);
void print(Node* next);

Node* head = NULL;

int main() {
  bool playing = true;
  cout << "Welcome to StudentList" << endl;
  
  while (playing == true) {
    char input[10];
    char first[50];
    char last[50];
    int id;
    float gpa;
    cout << "Would you like to ADD, PRINT, DELETE, AVARAGE, or QUIT" << endl;
    if (strcmp(input, "ADD") == 0) {//Calls the add function
      Student* student;
      cout << "Enter first name" << endl;
      cin >> first;
      cout << "Enter last name" << endl;
      cin >> last;
      cout << "Enter id number" << endl;
      cin >> id;
      cout << "Enter GPA" << endl;
      cin >> gpa;
      student->setStudent(first, last, id, gpa);
      add(student);
    }
    else if (strcmp(input, "PRINT") == 0) {//Calls the print function
      print();
    }
    else if (strcmp(input, "DELETE") == 0) {//Calls the delete function
      delete();
    }
    else if (strcmp(input, "AVARAGE") == 0) {

    }
    else if (strcmp(input, "QUIT") == 0) {//Returns false
      playing = false;
    }
  }

}

void add(Student* s, Node* next) {
  Node* current = head;
  if (current == NULL) {
   next = new Node(s);
  }
  else {
    
  }
}

void print(Node* next) {
  if (next == head) {
    cout << "List:" << endl;
  }
  if (next != NULL) {
    next->getStudent()->printStudent();
    print(next->getNext());
  }
}

