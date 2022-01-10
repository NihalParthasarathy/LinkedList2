#ifndef NODE_H
#define NODE_H
#include "Student.h"


class Node{
	Student* value; // holds the student
	Node* next; // pointer to next node
public:	
	Node* getNext(); // getter for next
	Student* getStudent(); // getter for student
	void setNext(Node*); // setter for next
	Node(Student*); // constructor
	~Node(); // destructor

};

#endif
