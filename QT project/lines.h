#ifndef LINES_H
#define LINES_H

#include <QWidget>
#include<QPushButton>
#include "StopInfo.h"
//#include "BusStopControl.h"

class StopInfo;
class QPushButton;

class Lines : public QWidget
{
  Q_OBJECT  

  public:
    Lines(QWidget *parent = 0);
    QPushButton *bstopArray[22];
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

  protected:
    void paintEvent(QPaintEvent *event);
    void drawLines(QPainter *qp);
    void drawStops();
    void createActions();

  private slots:
    void popup();
     	
  private:	
  	StopInfo    *stop;
  	//BusStopControl *bstopControl;
};
#endif
