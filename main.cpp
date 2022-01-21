#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

void add(Student* s, Node* &head, Node* prev, Node* curr, int compareID);
void print(Node* next);
void deleteStudent();
void avarage();

int main() {
  Node* head = NULL;
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
      Student* temp;
      cout << "Enter first name" << endl;
      cin >> temp->first;
      cout << "Enter last name" << endl;
      cin >> temp->last;
      cout << "Enter id number" << endl;
      cin >> temp->id;
      cout << "Enter GPA" << endl;
      cin >> temp->gpa;
      temp->setStudent(first, last, id, gpa);
      int value = temp->id;
      add(temp, head, value);
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

void add(Student* s, Node* &head, Node* prev, Node* curr, int compareID) {
  if (head == NULL) {
    head = new Node(s);
  }
  else if (curr == NULL) {
    prev->setNext() = new Node(s);
  }
  else if (compareID < curr->getStudent()->id) {
    prev->setNext() = new Node(s);
    prev->setNext()->setNext() = curr;
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

