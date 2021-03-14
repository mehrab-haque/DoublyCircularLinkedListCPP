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
	bool isOver;
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
	currentTime=1;
	remainingTime=responseTimes[0]-1;
	forwardDirection=true;
	isOver=false;
	
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
}

void PillowGame :: playTill(int time){
	if(!isOver){
		while(currentTime+remainingTime<time){
			currentTime+=remainingTime+1;
			forwardDirection?linkedList->gotoNextNode():linkedList->gotoPreviousNode();
			remainingTime=linkedList->getCurrentNode()->getValue()->getResponseTime()-1;
		}
		remainingTime=currentTime+remainingTime-time;
		currentTime=time;
	}
}

void PillowGame :: endMusic(){
	if(!isOver){
		cout<<"Player "<<linkedList->getCurrentNode()->getValue()->getSerial()<<" has been eliminated at t="<<currentTime<<endl;
		linkedList->deleteCurrentNode(this->forwardDirection);
		if(linkedList->getSize()==1){
			this->isOver=true;
			cout<<"Game over : Player "<<linkedList->getCurrentNode()->getValue()->getSerial()<<" wins!!"<<endl;
			return;
		}
		this->remainingTime=linkedList->getCurrentNode()->getValue()->getResponseTime()-1;
		cout<<"remaining time : "<<remainingTime<<endl;
	}
}

void PillowGame :: reverse(){
	this->forwardDirection=!this->forwardDirection;
}

void PillowGame :: addPlayer(int responseTime){
	Player *player=new Player(++totalNPlayers,responseTime);
	Node *node=new Node(player);
	this->forwardDirection?linkedList->addPreviousNode(node):linkedList->addNextNode(node);
}

void PillowGame :: printCurrentPlayer(){
	if(!isOver)
		cout<<"Player "<<linkedList->getCurrentNode()->getValue()->getSerial()<<" is holding the pillow at t="<<currentTime<<endl;
}

void PillowGame :: endGame(){
	if(!isOver){
		this->isOver=true;
		cout<<"Game over : Player "<<linkedList->getCurrentNode()->getValue()->getSerial()<<" is holding the pillow at t="<<currentTime<<", pillow passing sequence = Player ";
		for(int i=0;i<linkedList->getSize();i++){
			cout<<linkedList->getCurrentNode()->getValue()->getSerial();
			if(i<linkedList->getSize()-1){
				cout<<", ";
				this->forwardDirection?linkedList->gotoNextNode():linkedList->gotoPreviousNode();
			}
		}
		cout<<endl;
	}
}


#endif
