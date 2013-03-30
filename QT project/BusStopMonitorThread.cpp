
#include "BusStopMonitorThread.h"
#include <iostream>
using namespace std;


BusStopMonitorThread::BusStopMonitorThread(BusStopControl *bstopControl)
{
	control=bstopControl;
    done=false;
}

void BusStopMonitorThread::run()
{
	while(!done){
		if((control -> bstop -> getDemand()) >10)
			control ->overPopulate(control ->mapUI-> bstopArray[0]);
		if((control -> bstop -> getDemand()) <=10)
			control ->normal(control ->mapUI-> bstopArray[0]);
	}
}

bool BusStopMonitorThread::isDone(){
	return done;
}
