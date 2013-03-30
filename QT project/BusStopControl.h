#ifndef BUSSTOPCONTROL_H
#define BUSSTOPCONTROL_H

#include <string>
#include <iostream>
#include "BusStop.h"
#include "lines.h"
using namespace std;

class Lines;
class BusStop;

class BusStopControl{

public:
	BusStopControl(Lines *map);
	void eventHandler();
	BusStop *bstop;
	Lines *mapUI;
	
	void overPopulate(QPushButton *UIBusStop);
	void normal(QPushButton *UIBusStop);
	
};

#endif
