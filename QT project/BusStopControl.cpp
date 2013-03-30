#include "BusStopControl.h"
#include "BusStopMonitorThread.h"

BusStopControl::BusStopControl(Lines *map){
	mapUI=map;
	string s="MRT";
	bstop = new BusStop(s,11);
	
}
void BusStopControl::eventHandler(){
	//BusStopMonitorThread thread(this);
	//thread.start();
	if((bstop -> getDemand()) >10)
			overPopulate(mapUI-> bstopArray[0]);
	if((bstop -> getDemand()) <=10)
			normal(mapUI-> bstopArray[0]);
}

void BusStopControl::overPopulate(QPushButton *UIBusStop){
	UIBusStop->setStyleSheet("* { background-color: rgb(255,125,100); border-radius: 10px; }");
}

void BusStopControl::normal(QPushButton *UIBusStop){
	UIBusStop->setStyleSheet("* { background-color: rgb(228,145,53); border-radius: 10px; }");
}

