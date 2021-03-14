/*
	Developed by : Md. Mehrab Haque
	mehrab.haque.0001@gmail.com
*/

#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

//Dependencies
#include "Node.h"

//Class Signatures

//This class represents the circular doubly linked list.
class CircularDoublyLinkedList{
	Node *currentNode;
	int size;
	public:
		CircularDoublyLinkedList(Node *currentNode,int size);
		void addPreviousNode(Node *node);
		void addNextNode(Node *node);
		int getSize();
		Node *getCurrentNode();
		void deleteCurrentNode(bool forwardDirection);
		void gotoNextNode();
		void gotoPreviousNode();
};


//Function Definitions
CircularDoublyLinkedList :: CircularDoublyLinkedList(Node *currentNode,int size){
	this->currentNode=currentNode;
	this->size=size;
}
void CircularDoublyLinkedList :: addPreviousNode(Node *newNode){
	Node *next = currentNode;
	Node *prev = currentNode->getPreviousNode();
	next->setPrevNode(newNode);
	newNode->setNextNode(next);
	newNode->setPrevNode(prev);
	prev->setNextNode(newNode);
	size++;
}
void CircularDoublyLinkedList :: addNextNode(Node *newNode){
	Node *prev=currentNode;
	Node *next=currentNode->getNextNode();
	prev->setNextNode(newNode);
	newNode->setPrevNode(prev);
	newNode->setNextNode(next);
	next->setPrevNode(newNode);
	size++;
}
int CircularDoublyLinkedList :: getSize(){
	return size;
}
Node *CircularDoublyLinkedList :: getCurrentNode(){
	return currentNode;
}

void CircularDoublyLinkedList :: deleteCurrentNode(bool forwardDirection){
	Node *prev=currentNode->getPreviousNode();
	Node *next=currentNode->getNextNode();
	prev->setNextNode(currentNode->getNextNode());
	next->setPrevNode(currentNode->getPreviousNode());
	forwardDirection?gotoNextNode():gotoPreviousNode();
	size--;
}

void CircularDoublyLinkedList :: gotoNextNode(){
	currentNode=currentNode->getNextNode();
}

void CircularDoublyLinkedList :: gotoPreviousNode(){
	currentNode=currentNode->getPreviousNode();
}

#endif
