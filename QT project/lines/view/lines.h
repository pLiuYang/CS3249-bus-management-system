#ifndef LINES_H
#define LINES_H

#include <QWidget>
#include <QPushButton>
#include "StopInfo.h"
//#include "BusStopControl.h"
#include "../model/Bus.h"
#include <QDebug>
#include "../../Project/Shared.h"

#define MAX_NUM_OF_BUS 30

class StopInfo;
class QPushButton;
class Bus;
//class BusStopControl;

class Lines : public QWidget
{
  Q_OBJECT  

  public:
    Lines(QWidget *parent = 0);
    QPushButton *bstopArray[22];
    QPushButton *busBtnArray[MAX_NUM_OF_BUS];
    float incremental;

    int routeD1x[ROUTE_D1];
    int routeD1y[ROUTE_D1];
    int routeD2x[ROUTE_D2];
    int routeD2y[ROUTE_D2];
    int routeCx[ROUTE_C];
    int routeCy[ROUTE_C];
    int routeDx[ROUTE_B];
    int routeDy[ROUTE_B];
   /* QPushButton *MRT;
  	QPushButton *oppMRT;
  	QPushButton *Science;
  	QPushButton *oppScience;
  	QPushButton *Uhall;
  	QPushButton *oppUhall;
  	QPushButton *MPSH;
  	QPushButton *oppMPSH;
  	QPushButton *Utown;
  	QPushButton *E3A;
  	QPushButton *YIH;
  	QPushButton *oppYIH;
  	QPushButton *Central;
  	QPushButton *oppCentral;
  	QPushButton *Arts;
  	QPushButton *oppArts;
  	QPushButton *Eusoff;
  	QPushButton *Temasek;
  	QPushButton *Com2;
  	QPushButton *Biz;
  	QPushButton *oppBiz;
  	QPushButton *PGP;*/

  public slots:
	void updateBus(float location, int busID, QString busName);
	void updateStation(int population, int stationID);

  protected:
    void paintEvent(QPaintEvent *event);
    void drawLines(QPainter *qp);
    void createActions();

  private slots:
    void popup();
    void sendBus();
    
     	
  private:	
  	StopInfo    *stop;
  	Bus *bus[MAX_NUM_OF_BUS];
  	//BusStopControl *bstopControl;
};
#endif
