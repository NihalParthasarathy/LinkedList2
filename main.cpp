#include <iostream>
#include <cstring>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

void add(Student* s, Node* &head, Node* prev, Node* curr, int compareID);
void print(Node* next);
void deleteStudent(Node* &head, Node* prev, Node* curr, int nInput);
void avarage(Node* next, int count, float nSum);
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
    Student* temp = new Student();
    if (strcmp(input, "ADD") == 0) {//Calls the add function
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
       int input;
       cout << "Enter the ID of the student you want to delete" << endl;
       cin >>input;
       deleteStudent(head, head, head, input);
    }
    else if (strcmp(input, "AVARAGE") == 0) {
      int avarageCount = 0;
      int sum = 0;
      avarage(head, avarageCount, sum);
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

void deleteStudent(Node* &head, Node* prev, Node* curr, int nInput) {
  if (head == NULL) {
    cout << "No students to delete" << endl;
  }
  else if (nInput == curr->getStudent()->id) {
    if (curr == head) {
      head = head->getNext();
      curr->setNext(NULL);
      curr->~Node();
      return;
    }
    else {
      prev->setNext(curr->getNext());
      curr->setNext(NULL);
      curr->~Node();
      return;
    }
    //curr = prev->next->next;
    //prev = pre->next;
  }
  else {
    deleteStudent(head, curr, curr->getNext(), nInput);
  }
}

void avarage(Node* next, int count, float nSum) {
  if (next != NULL) {
    count++;
    nSum += next->getStudent()->gpa;
    avarage(next->getNext(), count, nSum);
  }
  else {
    nSum = nSum/count;
    cout << fixed << showpoint << setprecision(2) << nSum << endl;
  }

}
