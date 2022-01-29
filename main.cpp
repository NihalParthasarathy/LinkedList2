//Nihal Parthasarathy
//1/29/2022
//This code runs a studentlist where you can add, print, delete and avarage students. This is acomplished using linkedlists

//Inclusions
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

//Function Prototypes
void add(Student* s, Node* &head, Node* prev, Node* curr, int compareID);
void print(Node* next);
void deleteStudent(Node* &head, Node* prev, Node* curr, int nInput);
void avarage(Node* next, int count, float nSum);
void printIT(Node* next);

int main() {
  
  Node* head = NULL; //Initilizes head
  bool playing = true;
  
  cout << "Welcome to StudentList" << endl;
  
  while (playing == true) {//While loop to see if user still going
    //Varubles
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
      cin >> temp->first; //Adds first to temp
      cout << "Enter last name" << endl;
      cin >> temp->last; //Adds last to temp
      cout << "Enter id number" << endl;
      cin >> temp->id; //Adds Id to temp
      cout << "Enter GPA" << endl;
      cin >> temp->gpa; //Adds gpa to temp
      
      int value = temp->id;
      
      add(temp, head, head, head, value);//Calls add function
    }
    else if (strcmp(input, "PRINT") == 0) {//Calls the print function
      print(head);
    }
    else if (strcmp(input, "DELETE") == 0) {//Calls the delete function
       int input;
       cout << "Enter the ID of the student you want to delete" << endl;
       cin >>input;
       deleteStudent(head, head, head, input);
    }
    else if (strcmp(input, "AVARAGE") == 0) {//Calls the avarage function
      int avarageCount = 0;
      int sum = 0;
      avarage(head, avarageCount, sum);
    }
    else if (strcmp(input, "QUIT") == 0) {//Returns false
      playing = false;//Exits while Loop stopping game
    }
  }

}

void add(Student* s, Node* &head, Node* prev, Node* curr, int compareID) {//Adds student
  if (head == NULL) {//Checks if head is null
    head = new Node(s); //Makes new node
    head->setNext(NULL); //Sets next to NUll
  }
  else if (curr == NULL) {//Checks if adding to end of list
    prev->setNext(new Node(s));//Sets prev next to new node
    prev->getNext()->setNext(NULL);//Sets new nodes nest to NULL
  }
  else if (compareID < head->getStudent()->id) {//Checks to see if the id number is less than head id
    Node* temp = head;
    head = new Node(s);//New node
    head->setNext(temp);
  }
  else if (compareID < curr->getStudent()->id) {//Checks to see if id number less than curr id
    prev->setNext(new Node(s)); //sets next to new node
    prev->getNext()->setNext(curr);
  }
  else {
    add(s, head, curr, curr->getNext(), compareID);//recalls it
  }
}

void print(Node* next) {
  if (next != NULL) {//If next is not equal to null
    next->getStudent()->printStudent(); //Prints next's student
    print(next->getNext());//Recalls function
  }
}

void deleteStudent(Node* &head, Node* prev, Node* curr, int nInput) {//Deletes student
  if (head == NULL) {
    cout << "No students to delete" << endl;
  }
  else if (nInput == curr->getStudent()->id) {//If the input is equal to curr student
    if (curr == head) {//If your deleting the first node
      head = head->getNext();//Sets head to its next
      curr->setNext(NULL);//Next to null
      curr->~Node();//Deletes
      return;//Returns
    }
    else {
      prev->setNext(curr->getNext());
      curr->setNext(NULL);
      curr->~Node();//Deletes
      return;//Returns
    }
  }
  else {
    deleteStudent(head, curr, curr->getNext(), nInput);//Recalls function
  }
}

void avarage(Node* next, int count, float nSum) {//Avarages
  if (next != NULL) {
    count++;
    nSum += next->getStudent()->gpa;//Adds the gpas
    avarage(next->getNext(), count, nSum);//Recalls function
  }
  else {
    nSum = nSum/count;//Divides
    cout << fixed << showpoint << setprecision(2) << nSum << endl;//Prints it and sets percision
  }

}
