/*
	Developed by : Md. Mehrab Haque
	mehrab.haque.0001@gmail.com
*/

#ifndef PILLOWGAME_H
#define PILLOWGAME_H


//Dependencies
#include "Node.h"
#include "CircularDoublyLinkedList.h"

//Class Signatures

//This class represents the pillowgame that uses doubly linked list.
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

#endif
