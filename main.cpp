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
	
	int responseTimes[]={2,4,2};
	PillowGame *pillowGame=new PillowGame(responseTimes,3);
	
	pillowGame->printCurrentPlayer();
	
	pillowGame->playTill(2);
	pillowGame->printCurrentPlayer();
	
	pillowGame->playTill(3);
	pillowGame->printCurrentPlayer();
	
	return 0;
}
