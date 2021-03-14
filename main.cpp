/*
	Developed by : Md. Mehrab Haque
	Developed on : 14.03.2021
*/

#include <iostream>
#include<string>
#include<sstream>
#include "Node.h"
#include "CircularDoublyLinkedList.h"
#include "PillowGame.h"

using namespace std;

int main(){
	
	int N;
	cin>>N;
	int responseTimes[N];
	for(int i=0;i<N;i++)
		cin>>responseTimes[i];
	
	PillowGame *pillowGame=new PillowGame(responseTimes,N);
	
	string command;
	getline(cin,command); //clear the buffer
	
	while(getline(cin,command)){
		if (command.empty()) {
	      break;
	    }
	    istringstream iss(command);
	    string subCommand;
	    int commandSerial=0;
	    char commandLiteral;
	    while(iss >> subCommand) {
	        if(commandSerial==0){
	        	int timestamp;
	        	sscanf(subCommand.c_str(),"%d", &timestamp);
				commandSerial++; 
				pillowGame->playTill(timestamp);
	        }
	        else if(commandSerial==1){
	        	sscanf(subCommand.c_str(),"%c",&commandLiteral);
	        	commandSerial++;
	        	switch(commandLiteral){
	        		case 'M':
	        			pillowGame->endMusic();
	        			break;
	       			case 'R':
	       				pillowGame->reverse();
	       				break;
	       			case 'P':
	       				pillowGame->printCurrentPlayer();
	       				break;
	       			case 'F':
	       				pillowGame->endGame();
	       				
				}
			}else if(commandLiteral=='I' && commandSerial==2){
				int responseTime;
	        	sscanf(subCommand.c_str(),"%d", &responseTime);
				commandSerial++;
				pillowGame->addPlayer(responseTime);
			}
	    }
	}
	
	return 0;
}
