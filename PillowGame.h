/*
	Developed by : Md. Mehrab Haque
	mehrab.haque.0001@gmail.com
*/

#ifndef PILLOWGAME_H
#define PILLOWGAME_H


//Dependencies
#include<iostream>
#include "Node.h"
#include "CircularDoublyLinkedList.h"
using namespace std;

//Class Signatures

//This class represents the pillowgame that uses circular doubly linked list.
class PillowGame{
	CircularDoublyLinkedList *linkedList;
	int totalNPlayers;
	int currentTime;
	int remainingTime;
	bool forwardDirection;
	public:
		PillowGame(int responseTimes[],int n);
		void playTill(int time);
		void endMusic();
		void reverse();
		void addPlayer(int responseTime);
		void printCurrentPlayer();
		void endGame();
};


//Function definitions
PillowGame :: PillowGame(int responseTimes[],int n){
	totalNPlayers=0;
	currentTime=0;
	remainingTime=responseTimes[0];
	
	//Initializing circular doubly linked list with the first node
	Player *player=new Player(++totalNPlayers,responseTimes[0]);
	Node *node=new Node(player);
	node->setPrevNode(node); //single element circular doubly linked list
	node->setNextNode(node); //single element circular doubly linked list
	linkedList=new CircularDoublyLinkedList(node,1);
	
	//Adding all other nodes
	for(int i=1;i<n;i++){
		player=new Player(++totalNPlayers,responseTimes[i]);
		node=new Node(player);
		linkedList->addNextNode(node);
		linkedList->gotoNextNode(); //moving on to the newly created node
	}
	
	linkedList->gotoNextNode(); //moving to next of the last node, that is the first node (circular)
	
	
	//Test
	cout<<"size : "<<linkedList->getSize()<<endl;
	cout<<linkedList->getCurrentNode()->getValue()->getSerial()<<endl<<endl;
	
	linkedList->gotoNextNode();
	cout<<"size : "<<linkedList->getSize()<<endl;
	cout<<linkedList->getCurrentNode()->getValue()->getSerial()<<endl<<endl;
	
	linkedList->gotoNextNode();
	cout<<"size : "<<linkedList->getSize()<<endl;
	cout<<linkedList->getCurrentNode()->getValue()->getSerial()<<endl<<endl;
	
	linkedList->gotoNextNode();
	cout<<"size : "<<linkedList->getSize()<<endl;
	cout<<linkedList->getCurrentNode()->getValue()->getSerial()<<endl<<endl;
	
	linkedList->gotoNextNode();
	cout<<"size : "<<linkedList->getSize()<<endl;
	cout<<linkedList->getCurrentNode()->getValue()->getSerial()<<endl<<endl;
}


#endif
