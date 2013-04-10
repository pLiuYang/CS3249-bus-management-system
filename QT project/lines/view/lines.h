#ifndef LINES_H
#define LINES_H

#include <QWidget>
#include <QPushButton>
#include "StopInfo.h"
#include "SendBusButton.h"
#include <QDebug>
#include <QLabel>
#include "../../Project/Shared.h"
#include "../../Project/Server/TripServer.h"
//#include <iostream>
//#include <sstream>
//using namespace std;

#define MAX_NUM_OF_BUS 30

class StopInfo;
class QPushButton;
class QLabel;
class SendBusButton;

//class BusStopControl;
class TripServer;
class Lines : public QWidget
{
  Q_OBJECT  

  public:
    Lines(TripServer *trip, QWidget *parent = 0);
    QPushButton *bstopArray[22];
    QPushButton *busBtnArray[MAX_NUM_OF_BUS];
    SendBusButton *sendBus[6];
	TripServer *server;
	QLabel *freeBus[6];
	float busLocation[30];

  public slots:
	void updateBus(float location, int busID, QString busName);
	void updateStation(int population, int stationID);
	void terminateBus(int busid);
	void updateHighlightVar(int id);
	
  protected:
    void paintEvent(QPaintEvent *event);
    void drawLines(QPainter *qp);
    void highlightRoute(QPainter *qp);

  private slots:
    void popup();
    //void sendBus();
    void send();    
     	
  private:	
  	StopInfo    *stop;
    void createActions();
   //ostringstream convert;   // stream used for the conversion
    char* itos(int i);
  	//BusStopControl *bstopControl;
  	int highlight;
};
#endif
