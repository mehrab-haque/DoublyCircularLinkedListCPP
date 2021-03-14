/*
	Developed by : Md. Mehrab Haque
	mehrab.haque.0001@gmail.com
*/

#ifndef NODE_H
#define NODE_H

//Dependencies
#include<iostream>

//Class Signatures

//This class represents a player, which is the value of a node in the linked list.
class Player{
	int serial;
	int responseTime;
	public:
		Player(int serial,int responseTime);
		int getSerial();
		int getResponseTime();	
};

//This class is a node in the linked list.
class Node{
	Player *value;
	Node *prev;
	Node *next;
	public:
		Node(Player *value);
		Node(Player *value,Node *prev);
		Node(Player *value,Node *prev,Node *next);
		Node *getPreviousNode();
		Node *getNextNode();
		void setPrevNode(Node *prev);
		void setNextNode(Node *next);
		Player *getValue();
};



//Function Definitions
Player :: Player(int serial,int responseTime){
	this->serial=serial;
	this->responseTime=responseTime;
}
int Player :: getSerial(){
	return serial;
}
int Player :: getResponseTime(){
	return responseTime;
}


Node :: Node(Player *value){
	this->value=value;
	this->prev=NULL;
	this->next=NULL;
}
Node :: Node(Player *value,Node *prev){
	this->value=value;
	this->prev=prev;
	this->next=NULL;
}
Node :: Node(Player *value,Node *prev,Node *next){
	this->value=value;
	this->prev=prev;
	this->next=next;
}

Node *Node :: getPreviousNode(){
	return this->prev;
}

Node *Node :: getNextNode(){
	return this->next;
}

void Node :: setPrevNode(Node *prev){
	this->prev=prev;
}
void Node :: setNextNode(Node *next){
	this->next=next;
}
Player *Node :: getValue(){
	return value;
}

#endif
