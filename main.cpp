/*
	Developed by : Md. Mehrab Haque
	Developed on : 14.03.2021
*/

#include <iostream>
#include "Node.h"
#include "CircularDoublyLinkedList.h"
#include "PillowGame.h"

using namespace std;

int main(){
	
	int responseTimes[]={4,5,2};
	PillowGame *pillowGame=new PillowGame(responseTimes,3);
	
	
	pillowGame->playTill(5);
	pillowGame->reverse();
	pillowGame->playTill(6);
	
	
	pillowGame->endGame();
	
	return 0;
}
