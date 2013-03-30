
#ifndef BUSSTOPMONITORTHREAD_H
#define BUSSTOPMONITORTHREAD_H
 
#include "QThread"
#include "BusStopControl.h"

class BusStopControl;

class BusStopMonitorThread : public QThread
{
    Q_OBJECT

public:
	BusStopMonitorThread(BusStopControl *bstopControl);
	bool isDone();
	
protected:
	void run();
	
private:
	bool done;
	BusStopControl *control;
};

#endif
