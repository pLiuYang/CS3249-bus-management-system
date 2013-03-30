#include "BusStop.h"

BusStop::BusStop(int ID, QString Name, int Population, Lines *UI){
	id=ID;
	name=Name;
	population=Population;
	ui = UI;
	QObject::connect(this,SIGNAL(populationChanged(float, int)),ui,SLOT(updateBusStop(int, int)));
}

int BusStop::getID(){
	return id;
}

QString BusStop::getName(){
	return name;
}
int BusStop::getPopulation(){
	return population;
}

void BusStop::setPopulation (int newPopulation){
	if(population!=newPopulation){
		population=newPopulation;
		emit populationChanged(population, id);
	}
}
