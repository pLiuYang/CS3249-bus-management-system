#include "Bus.h"

Bus::Bus(int ID, QString Name, float Location, int Freeseats, Lines *UI){
	id=ID;
	name=Name;
	location=Location;
	freeseats=Freeseats;
	ui=UI;
	QObject::connect(this,SIGNAL(locationChanged(float, int)),ui,SLOT(updateBus(float, int)));
}

void Bus::setLocation(float newLocation){
	if(location!=newLocation){
		location=newLocation;
		emit locationChanged(newLocation, id);
	}
}

int Bus::getID(){
	return id;
}
QString Bus::getName(){
	return name;
}
float Bus::getLocation(){
	return location;
}
int Bus::getFreeseats(){
	return freeseats;
}
