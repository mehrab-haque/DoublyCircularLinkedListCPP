/*
	Developed by : Md. Mehrab Haque
	Developed on : 14.03.2021
*/

#include <iostream>
#include "Node.h"
#include "CircularDoublyLinkedList.h"

using namespace std;

class PillowGame{
	CircularDoublyLinkedList *linkedList;
	int totalNPlayers;
	int currentTime;
	int remainingTime;
	bool forwardDirection;
	public:
		PillowGame(int responseTimes[]);
		void playTill(int time);
		void endMusic();
		void reverse();
		void addPlayer(int responseTime);
		void printCurrentPlayer();
		void endGame();
};

int main(){
	
	Player *p1 = new Player(1,100);
	Player *p2 = new Player(2,200);
	Player *p3 = new Player(3,300);
	
	Node *n1 = new Node(p1);
	Node *n2 = new Node(p2);
	Node *n3 = new Node(p3);
	
	n1->setNextNode(n2);
	n1->setPrevNode(n3);
	n2->setNextNode(n3);
	n2->setPrevNode(n1);
	n3->setNextNode(n1);
	n3->setPrevNode(n2);
	
	CircularDoublyLinkedList *l = new CircularDoublyLinkedList(n1,3);
	
	cout<<"size : "<<l->getSize()<<endl;
	cout<<l->getCurrentNode()->getValue()->getSerial()<<endl<<endl;
	
	l->gotoNextNode();
	
	cout<<"size : "<<l->getSize()<<endl;
	cout<<l->getCurrentNode()->getValue()->getSerial()<<endl<<endl;

	l->deleteCurrentNode(true);
	
	cout<<"size : "<<l->getSize()<<endl;
	cout<<l->getCurrentNode()->getValue()->getSerial()<<endl<<endl;
	
	l->gotoNextNode();
	
	cout<<"size : "<<l->getSize()<<endl;
	cout<<l->getCurrentNode()->getValue()->getSerial()<<endl<<endl;
	
	l->gotoNextNode();
	
	cout<<"size : "<<l->getSize()<<endl;
	cout<<l->getCurrentNode()->getValue()->getSerial()<<endl<<endl;
	
	l->gotoPreviousNode();
	
	cout<<"size : "<<l->getSize()<<endl;
	cout<<l->getCurrentNode()->getValue()->getSerial()<<endl<<endl;

	l->gotoPreviousNode();
	
	cout<<"size : "<<l->getSize()<<endl;
	cout<<l->getCurrentNode()->getValue()->getSerial()<<endl<<endl;
	
	l->gotoPreviousNode();
	
	cout<<"size : "<<l->getSize()<<endl;
	cout<<l->getCurrentNode()->getValue()->getSerial()<<endl<<endl;
	
	return 0;
}
