#include "Node.h"

// implementation for methods in Node.h

Node* Node::getNext(){
	return this->next;
}

Student* Node::getStudent(){
	return this->value;
}

void Node::setNext(Node* next){
	this->next = next;
}

Node::Node(Student* s){
	this->value = s;
}

Node::~Node(){
	delete this->value;
}
