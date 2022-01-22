#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

void add(Student* s, Node* &head, Node* prev, Node* curr, int compareID);
void print(Node* next);
void deleteStudent();
void avarage();
void printIT(Node* next);

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
    cin >> input;
    if (strcmp(input, "ADD") == 0) {//Calls the add function
      Student* temp = new Student();
      cout << "Enter first name" << endl;
      cin >> temp->first;
      cout << "Enter last name" << endl;
      cin >> temp->last;
      cout << "Enter id number" << endl;
      cin >> temp->id;
      cout << "Enter GPA" << endl;
      cin >> temp->gpa;
      //temp->setStudent(first, last, id, gpa);
      //temp->printStudent();
      int value = temp->id;
      add(temp, head, head, head, value);
    }
    else if (strcmp(input, "PRINT") == 0) {//Calls the print function
      print(head);
      //printIT(head);
    }
    else if (strcmp(input, "DELETE") == 0) {//Calls the delete function
      //delete();
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
    head->setNext(NULL);
  }
  else if (curr == NULL) {
    cout << "daso" << endl;
    prev->setNext(new Node(s));
    prev->getNext()->setNext(NULL);
  }
  else if (compareID < head->getStudent()->id) {
    Node* temp = head;
    head = new Node(s);
    head->setNext(temp);// = temp;
  }
  else if (compareID < curr->getStudent()->id) {
    prev->setNext(new Node(s)); //= new Node(s);
    prev->getNext()->setNext(curr);// = curr;
  }
  else {
    cout << "Going again" << endl;
    add(s, head, curr, curr->getNext(), compareID);
  }
}

void printIT(Node* next) {
  Node* current = next;
  while (current != NULL) {
    current->getStudent()->printStudent();
    current = current->getNext();
  }
}
void print(Node* next) {
  /*if (next == head) {
    cout << "List:" << endl;
  }*/
  if (next != NULL) {
    //next->printStudent();
    next->getStudent()->printStudent();
    print(next->getNext());
  }
}

