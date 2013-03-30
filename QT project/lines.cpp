#include "lines.h"
#include <QPainter>
//#include <iostream>
//using namespace std;

Lines::Lines(QWidget *parent)
    : QWidget(parent)
{
	stop=NULL;
	
	//instanciate controllers
	//bstopControl = new BusStopControl(this);
	
	//create bus stops
	bstopArray[0] = new QPushButton (tr("MRT"),this);
	bstopArray[1] = new QPushButton (tr("oppMRT"),this);
	bstopArray[2] = new QPushButton (tr("PGP"),this);
	bstopArray[3] = new QPushButton (tr("Biz"),this);
	bstopArray[4] = new QPushButton (tr("oppBiz"),this);
	bstopArray[5] = new QPushButton (tr("Com2"),this);
	bstopArray[6] = new QPushButton (tr("Temasek"),this);
	bstopArray[7] = new QPushButton (tr("Eusoff"),this);
	bstopArray[8] = new QPushButton (tr("Arts"),this);
	bstopArray[9] = new QPushButton (tr("oppArts"),this);
	bstopArray[10] = new QPushButton (tr("Central"),this);
	bstopArray[11] = new QPushButton (tr("oppCentral"),this);
	bstopArray[12] = new QPushButton (tr("YIH"),this);
	bstopArray[13] = new QPushButton (tr("oppYIH"),this);
	bstopArray[14] = new QPushButton (tr("Utown"),this);
	bstopArray[15] = new QPushButton (tr("E3A"),this);
	bstopArray[16] = new QPushButton (tr("MPSH"),this);
	bstopArray[17] = new QPushButton (tr("oppMPSH"),this);
	bstopArray[18] = new QPushButton (tr("Uhall"),this);
	bstopArray[19] = new QPushButton (tr("oppUhall"),this);
	bstopArray[20] = new QPushButton (tr("Science"),this);
	bstopArray[21] = new QPushButton (tr("oppScience"),this);
	//set object name
	bstopArray[0]->setObjectName("MRT");
	bstopArray[1]->setObjectName("oppMRT");
	bstopArray[2]->setObjectName("PGP");
	bstopArray[3]->setObjectName("Biz");
	bstopArray[4]->setObjectName("oppBiz");
	bstopArray[5]->setObjectName("Com2");
	bstopArray[6]->setObjectName("Temasek");
	bstopArray[7]->setObjectName("Eusoff");
	bstopArray[8]->setObjectName("Arts");
	bstopArray[9]->setObjectName("oppArts");
	bstopArray[10]->setObjectName("central");
	bstopArray[11]->setObjectName("oppCentral");
	bstopArray[12]->setObjectName("YIH");
	bstopArray[13]->setObjectName("oppYIH");
	bstopArray[14]->setObjectName("Utown");
	bstopArray[15]->setObjectName("E3A");
	bstopArray[16]->setObjectName("MPSH");
	bstopArray[17]->setObjectName("oppMPSH");
	bstopArray[18]->setObjectName("Uhall");
	bstopArray[19]->setObjectName("oppUhall");
	bstopArray[20]->setObjectName("Science");
	bstopArray[21]->setObjectName("oppScience");
	//set busstop location
	bstopArray[0] -> setGeometry (860, 235, 30, 30 );
	bstopArray[1] ->setGeometry (910, 235, 30, 30 );
	bstopArray[2] -> setGeometry (800, 385, 30, 30 );
	bstopArray[3] -> setGeometry (635, 360, 30, 30 );
	bstopArray[4] -> setGeometry (635, 410, 30, 30 );
	bstopArray[5] -> setGeometry (485, 285, 30, 30 );
	bstopArray[6] -> setGeometry (500, 500, 30, 30 );
	bstopArray[7] -> setGeometry (370, 500, 30, 30 );
	bstopArray[8] -> setGeometry (310, 360, 30, 30 );
	bstopArray[9] -> setGeometry (265, 405, 30, 30 );
	bstopArray[10] -> setGeometry (310, 285, 30, 30 );
	bstopArray[11] -> setGeometry (260, 285, 30, 30 );
	bstopArray[12] -> setGeometry (310, 185, 30, 30 );
	bstopArray[13] -> setGeometry (260, 185, 30, 30 );
	bstopArray[14] -> setGeometry (180,   5, 30, 30 );
	bstopArray[15] -> setGeometry ( 35,  85, 30, 30 );
	bstopArray[16] -> setGeometry (385,  60, 30, 30 );
	bstopArray[17] -> setGeometry (385, 110, 30, 30 );
	bstopArray[18] -> setGeometry (585, 110, 30, 30 );
	bstopArray[19] -> setGeometry (585,  60, 30, 30 );
	bstopArray[20] -> setGeometry (785, 110, 30, 30 );
	bstopArray[21] -> setGeometry (785,  60, 30, 30 );
	
	//apply custom style to buttons
	int i;
	for(i=0;i<22;i++){
		bstopArray[i] -> setStyleSheet("* { background-color: rgb(135,206,250); font: 9px; border-radius: 15px; }");
	}
	
	
	createActions();
    //drawStops();
}

void Lines::createActions(){
	int i;
	for(i=0;i<22;i++){
		QObject::connect(bstopArray[i], SIGNAL(clicked()),this,SLOT(popup()));
	}
}

void Lines::popup(){
	//if(QString::compare(stop->getName(),QObject::sender() -> objectName())){
	//bstopControl->eventHandler();
		stop = new StopInfo(QObject::sender() -> objectName());
		stop->show();
	//}
}

//paint map
void Lines::paintEvent(QPaintEvent *e)
{
  Q_UNUSED(e);
  QPainter qp(this);
  drawLines(&qp);
}

void Lines::drawLines(QPainter *qp)
{ 
  //BUS B route
  QPen pen(Qt::green, 4, Qt::SolidLine);  
  qp->setPen(pen);
  qp->drawLine( 50, 106, 205, 106);
  qp->drawLine(205, 105, 300, 200);
  qp->drawLine(300, 200, 300, 400);
  qp->drawLine(300, 400, 500, 400);
  qp->drawLine(500, 300, 500, 500);
  qp->drawLine(500, 500, 400, 500);
  qp->drawLine(400, 500, 300, 400);
  
  //BUS D1/D2 route
  QColor blue = QColor (102,204,255,255);
  QPen pen2(blue, 4, Qt::SolidLine);  
  qp->setPen(pen2);
  qp->drawLine(196, 102, 196,  20);
  qp->drawLine(196,  94, 800,  94);
  qp->drawLine(197, 104, 293, 200);
  qp->drawLine(294, 202, 294, 402);
  qp->drawLine(294, 402, 396, 504);
  qp->drawLine(396, 505, 502, 505);
  qp->drawLine(505, 505, 505, 300);
  qp->drawLine(295, 405, 650, 405);
  
  //BUS A1/A2 route
  QColor orange = QColor (255,204,0,225);
  QPen pen3(orange, 4, Qt::SolidLine);  
  qp->setPen(pen3);
  qp->drawLine(900, 250, 820, 106);
  qp->drawLine(820, 106, 214, 106);
  qp->drawLine(214, 106, 306, 198);
  qp->drawLine(306, 200, 306, 396);
  qp->drawLine(306, 394, 820, 394);
  qp->drawLine(820, 394, 900, 250);
  qp->drawLine(306, 398, 402, 494);
  qp->drawLine(402, 494, 494, 494);
  qp->drawLine(494, 494, 494, 300);
  
  //BUS C route
  QColor pink = QColor (255,204,203,255);
  QPen pen4(pink, 4, Qt::SolidLine);  
  qp->setPen(pen4);
  qp->drawLine( 50, 100, 800, 100);
  
  //connect oppsite busstops
  QColor brown = QColor (135,206,250,255);
  QPen pen5(brown, 4, Qt::SolidLine);
  //pen4.setStyle(Qt::DashLine);  
  qp->setPen(pen5);
  qp->drawLine(650, 420, 650, 380);
  qp->drawLine(290, 410, 315, 385);
  qp->drawLine(290, 300, 310, 300);
  qp->drawLine(290, 200, 310, 200);
  qp->drawLine(400,  90, 400, 110);
  qp->drawLine(600,  90, 600, 110);
  qp->drawLine(800,  90, 800, 110);
  qp->drawLine(890, 250, 910, 250);
  
  
}
