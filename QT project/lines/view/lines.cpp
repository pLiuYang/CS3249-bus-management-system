#include "lines.h"
#include <QPainter>
#include <QString>

//routes
int routeA1x[ROUTE_A1]={820,900,800,600,400,305,305,305,494,650,820};
int routeA1y[ROUTE_A1]={396,250,106,106,106,200,300,396,300,396,396};
int routeA2x[ROUTE_A2]={820,650,494,494,402,305,305,305,400,600,800,900,820};
int routeA2y[ROUTE_A2]={396,396,300,494,494,396,300,200,106,106,106,250,396};
int routeD1x[ROUTE_D1]={650,505,505,396,295,294,294,196,400,600,800};
int routeD1y[ROUTE_D1]={405,300,505,505,405,300,200, 20, 94, 94, 94};
int routeD2x[ROUTE_D2]={800,600,400,196,294,294,295,505,650};
int routeD2y[ROUTE_D2]={ 94, 94, 94, 20,200,300,405,300,405};
int routeBx[ROUTE_B]  ={ 50,300,300,300,500,500,400,300,300,300, 50};
int routeBy[ROUTE_B]  ={106,200,300,400,300,500,500,400,300,200,106};
int routeCx[ROUTE_C]  ={ 50,400,600,800,800,600,400, 50};
int routeCy[ROUTE_C]  ={100,100,100,100,100,100,100,100};

int busID[MAX_NUM_OF_BUS]={0};

//buses stop at stations
int bss[22][6] = {
	{1},
	{0,2},
	{1,2},
	{1,0,0,4},
	{0,2,3},
	{1,2,3,4,5},
	{0,2,3,0,5},
	{0,2,3,0,5},
	{1,0,0,4,5},
	{0,2,3,0,5},
	{1,0,0,4,5},
	{0,2,3,0,5},
	{1,0,0,4,5},
	{0,2,3,0,5},
	{0,0,4,3},
	{0,0,0,0,5,6},
	{0,2,3,0,0,6},
	{1,0,0,4,0,6},
	{1,0,0,4,0,6},
	{0,2,3,0,0,6},
	{1,0,0,4,0,6},
	{0,2,3,0,0,6}
};

// station location on the route of buses
float staLoc[22][6] = {
	{1,0,0,0,0,0},
	{0,11,0,0,0,0},
	{0,0,0,0,0,0},
	{9,0,0,8,0,0},
	{0,2,0,0,0,0},
	{8,1,2,7,4,0},
	{0,3,2,0,5,0},
	{0,4,3,0,6,0},
	{7,0,0,6,3,0},
	{0,5,4,0,7,0},
	{6,0,0,5,2,0},
	{0,6,5,0,8,0},
	{5,0,0,4,1,0},
	{0,7,6,0,9,0},
	{0,0,7,3,0,0},
	{0,0,0,0,0,0},
	{0,8,8,0,0,1},
	{4,0,0,2,0,2},
	{3,0,0,1,0,5},
	{0,9,9,0,0,2},
	{2,0,0,0,0,4},
	{0,10,10,0,0,3}
};


//**************** init **************//

Lines::Lines(TripServer *trip, QWidget *parent)
    : QWidget(parent)
{
	server = trip;
	stop=NULL;
	highlight = 0;
	
	//create button for sending a bus
	sendBus[0] = new SendBusButton (tr("Send Bus A1"),this,this,1);
	sendBus[1] = new SendBusButton (tr("Send Bus A2"),this,this,2);
	sendBus[2] = new SendBusButton (tr("Send Bus D1"),this,this,3);
	sendBus[3] = new SendBusButton (tr("Send Bus D2"),this,this,4);
	sendBus[4] = new SendBusButton (tr("Send Bus B"),this,this,5);
	sendBus[5] = new SendBusButton (tr("Send Bus C"),this,this,6);
	//set button names
	sendBus[0] -> setObjectName("SendA1");
	sendBus[1] -> setObjectName("SendA2");
	sendBus[2] -> setObjectName("SendD1");
	sendBus[3] -> setObjectName("SendD2");
	sendBus[4] -> setObjectName("SendB");
	sendBus[5] -> setObjectName("SendC");
	//set button locations
	for(int i=0;i<6;i++){
		sendBus[i] -> setGeometry (10, 300+i*40, 100, 30 );
	}

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
	bstopArray[0]->setObjectName("Kent Ridge MRT");
	bstopArray[1]->setObjectName("opp Kent Ridge MRT");
	bstopArray[2]->setObjectName("PGP");
	bstopArray[3]->setObjectName("Business School");
	bstopArray[4]->setObjectName("opp Business School");
	bstopArray[5]->setObjectName("Com2");
	bstopArray[6]->setObjectName("Temasek Hall");
	bstopArray[7]->setObjectName("Eusoff Hall");
	bstopArray[8]->setObjectName("Arts");
	bstopArray[9]->setObjectName("opp Arts");
	bstopArray[10]->setObjectName("Central Library");
	bstopArray[11]->setObjectName("opp Central Library");
	bstopArray[12]->setObjectName("YIH");
	bstopArray[13]->setObjectName("opp YIH");
	bstopArray[14]->setObjectName("Utown");
	bstopArray[15]->setObjectName("E3A");
	bstopArray[16]->setObjectName("MPSH");
	bstopArray[17]->setObjectName("opp MPSH");
	bstopArray[18]->setObjectName("University Hall");
	bstopArray[19]->setObjectName("opp University Hall");
	bstopArray[20]->setObjectName("Science");
	bstopArray[21]->setObjectName("opp Science");
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
	
	//create buses
	for (int i = 0; i < MAX_NUM_OF_BUS ; i++) {
		if(i<5){
			//QPixmap pixmap("../../lines/view/bus2.png");
			//QIcon icon(pixmap);
			
			busBtnArray[i] = new QPushButton (QIcon ("../../lines/view/A1.png"), "", this);
			//busBtnArray[i]->setIcon(icon);
			
			//busBtnArray[i] -> setStyleSheet("image: url(:../../lines/view/A2.png)");
		}else if(i<10){
			busBtnArray[i] = new QPushButton (QIcon ("../../lines/view/A2.png"), "", this);
		}else if(i<15){
			busBtnArray[i] = new QPushButton (QIcon ("../../lines/view/D1.png"), "", this);
		}else if(i<20){
			busBtnArray[i] = new QPushButton (QIcon ("../../lines/view/D2.png"), "", this);
		}else if(i<25){
			busBtnArray[i] = new QPushButton (QIcon ("../../lines/view/B.png"), "", this);
		}else{
			busBtnArray[i] = new QPushButton (QIcon ("../../lines/view/C.png"), "", this);
		}
		busBtnArray[i] -> setGeometry (i*30, 0, 20, 20 );
		busBtnArray[i]->setIconSize(QSize(25,25));
		//disable bustop click
		//busBtnArray[i]->setEnabled(false);
		//hide bus first
		busBtnArray[i]-> hide();
		
		busLocation[i] = 0.0;
	}
	
	//apply custom style to buttons
	int i;
	for(i=0;i<22;i++){
		bstopArray[i] -> setStyleSheet("* { background-color: rgb(135,206,250); font: 9px; border-radius: 15px; }");
		
		QString tooltip = QString("<h2 style=\"margin-bottom:0px\">"+bstopArray[i]->objectName()+"</h2>") + QString("<span style=\"font:20px\">0</span> people waiting");
		bstopArray[i] -> setToolTip(tooltip);
	}
	
	//initialize 
	
	//connect signals
	createActions();
}

//connect signal slots
void Lines::createActions(){
	for(int i=0;i<22;i++){
		//QObject::connect(bstopArray[i], SIGNAL(clicked()),this,SLOT(popup()));
	}
	for(int i=0;i<6;i++){
		QObject::connect(sendBus[i], SIGNAL(clicked()),this,SLOT(send()));
	}
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
  //color
  QColor blue = QColor (102,204,255,255);
  QColor orange = QColor (255,204,0,225);
  QColor pink = QColor (255,204,203,255);
  QColor brown = QColor (135,206,250,255);
  QColor gray = QColor (224, 224, 224, 224);
  
  //bus color
  QColor colorArr[7];
  
  //route width
  int wid[7];
  
  for (int i = 1; i<7; i++) {
  	colorArr[i] = gray;
  	wid[i] = 4;
  }
  
  switch (highlight) {
  case 1:
  case 2:
  	colorArr[1] = orange;
  	wid[1] = 6;
  	break;
  case 3:
  case 4:
  	colorArr[3] = blue;
  	wid[3] = 8;
  	break;	
  case 5:
  	colorArr[5] = Qt::green;
  	wid[5] = 8;
  	break;
  case 6:
  	colorArr[6] = pink;
  	wid[6] = 6;
  	break;
  default: // highlight == 0
  	colorArr[1] = orange;
    colorArr[3] = blue;
    colorArr[5] = Qt::green;
    colorArr[6] = pink;
    break;
  }  
  
  //BUS B route  
  QPen pen(colorArr[5], wid[5], Qt::SolidLine); 
  qp->setPen(pen);
  qp->drawLine( 50, 106, 205, 106);
  qp->drawLine(205, 105, 300, 200);
  qp->drawLine(300, 200, 300, 400);
  qp->drawLine(300, 400, 500, 400);
  qp->drawLine(500, 300, 500, 500);
  qp->drawLine(500, 500, 400, 500);
  qp->drawLine(400, 500, 300, 400);
  
  //BUS D1/D2 route
  QPen pen2(colorArr[3], wid[3], Qt::SolidLine);  
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
  QPen pen3(colorArr[1], wid[1], Qt::SolidLine);  
  qp->setPen(pen3);
  qp->drawLine(900, 250, 800, 106);
  qp->drawLine(800, 106, 214, 106);
  qp->drawLine(214, 106, 306, 198);
  qp->drawLine(306, 200, 306, 396);
  qp->drawLine(306, 394, 820, 394);
  qp->drawLine(820, 394, 900, 250);
  qp->drawLine(306, 398, 402, 494);
  qp->drawLine(402, 494, 494, 494);
  qp->drawLine(494, 494, 494, 300);
  
  //BUS C route
  QPen pen4(colorArr[6], wid[6], Qt::SolidLine);  
  qp->setPen(pen4);
  qp->drawLine( 50, 100, 800, 100);
  
  //connect oppsite busstops
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
  
  update();
}

//********************** controller *********************//

void Lines::send(){
	qDebug()<<"send bus";
	if(QObject::sender()-> objectName().compare("SendA1")==0){
		for(int i=0;i<5;i++){
			if(busID[i]==0){
				server->sendBus("A1",itos(i));
				busID[i]=1;
				break;
			}
		}
		sendBus[0]->setCrowd(sendBus[0]->getCrowd()-2);
	}else if(QObject::sender()-> objectName().compare("SendA2")==0){
		for(int i=5;i<10;i++){
			if(busID[i]==0){
				server->sendBus("A2",itos(i));
				busID[i]=1;
				break;
			}
		}
		sendBus[1]->setCrowd(sendBus[1]->getCrowd()-2);
	}else if(QObject::sender()-> objectName().compare("SendD1")==0){
		for(int i=10;i<15;i++){
			if(busID[i]==0){
				server->sendBus("D1",itos(i));
				busID[i]=1;
				break;
			}
		}
		sendBus[2]->setCrowd(sendBus[2]->getCrowd()-2);
	}else if(QObject::sender()-> objectName().compare("SendD2")==0){
		for(int i=15;i<20;i++){
			if(busID[i]==0){
				server->sendBus("D2",itos(i));
				busID[i]=1;
				break;
			}
		}
		sendBus[3]->setCrowd(sendBus[3]->getCrowd()-2);
	}else if(QObject::sender()-> objectName().compare("SendB")==0){
		for(int i=20;i<25;i++){
			if(busID[i]==0){
				server->sendBus("B",itos(i));
				busID[i]=1;
				break;
			}
		}
		sendBus[4]->setCrowd(sendBus[4]->getCrowd()-2);
	}else{
		for(int i=25;i<30;i++){
			if(busID[i]==0){
				server->sendBus("C",itos(i));
				busID[i]=1;
				break;
			}
		}
		sendBus[5]->setCrowd(sendBus[5]->getCrowd()-2);
	}
}
//got better way to convert int to string?
char* Lines::itos(int i){
	switch(i){
		case 0: return "0";
		case 1: return "1";
		case 2: return "2";
		case 3: return "3";
		case 4: return "4";
		case 5: return "5";
		case 6: return "6";
		case 7: return "7";
		case 8: return "8";
		case 9: return "9";
		case 10: return "10";
		case 11: return "11";
		case 12: return "12";
		case 13: return "13";
		case 14: return "14";
		case 15: return "15";
		case 16: return "16";
		case 17: return "17";
		case 18: return "18";
		case 19: return "19";
		case 20: return "20";
		case 21: return "21";
		case 22: return "22";
		case 23: return "23";
		case 24: return "24";
		case 25: return "25";
		case 26: return "26";
		case 27: return "27";
		case 28: return "28";
		case 29: return "29";
		
	}
}

void Lines::popup(){
	qDebug()<<"popup";
	stop = new StopInfo(QObject::sender() -> objectName());
	stop->show();
}

void Lines::updateBus(float location, int busID , QString busName) {
	qDebug() << "bus "<<busID<<" updated at location "<<location;
	busBtnArray[busID] -> show();
	busLocation[busID] = location;
	//check bus type
	if(QString::compare(busName,"A1")==0){
		int t = static_cast<int>(location);
		int t2 = t+1; 
		float p=location-t;
		
		if(location>4 && location<4.5){
			p*=2;
			busBtnArray[busID] -> setGeometry (routeA1x[t]*(1-p)+214*p, routeA1y[t]*(1-p)+106*p, 20, 20 );
		}else if (location>=4.5 && location<5){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (214*(1-p)+routeA1x[t2]*p, 106*(1-p)+routeA1y[t2]*p, 20, 20 );
		}else if (location>7 && location<7.5){
			p*=2;
			busBtnArray[busID] -> setGeometry (routeA1x[t]*(1-p)+494*p, routeA1y[t]*(1-p)+396*p, 20, 20 );
		}else if (location>=7.5 && location<8){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (494*(1-p)+routeA1x[t2]*p, 396*(1-p)+routeA1y[t2]*p, 20, 20 );
		}else if (location>8 && location<8.5){
			p*=2;
			busBtnArray[busID] -> setGeometry (routeA1x[t]*(1-p)+494*p, routeA1y[t]*(1-p)+396*p, 20, 20 );
		}else if (location>=8.5 && location<9){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (494*(1-p)+routeA1x[t2]*p, 396*(1-p)+routeA1y[t2]*p, 20, 20 );
		}else {	
			busBtnArray[busID] -> setGeometry (routeA1x[t]*(1-p)+routeA1x[t2]*p, routeA1y[t]*(1-p)+routeA1y[t2]*p, 20, 20 );
			qDebug()<<"x "<<routeA1x[t]*(1-p)<<" y "<<routeA1x[t2]*p;
		}
		if (location > 9.9) busLocation[busID] = 0;
	}
	if(QString::compare(busName,"A2")==0){
		int t = static_cast<int>(location); //floor
		int t2 = t+1; //ceiling
		float p=location-t; //fraction
		
		if(location>1 && location<1.5){
			p*=2;
			busBtnArray[busID] -> setGeometry (routeA2x[t]*(1-p)+494*p, routeA2y[t]*(1-p)+396*p, 20, 20 );
		} else if(location>=1.5 && location<2){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (494*(1-p)+routeA2x[t2]*p, 396*(1-p)+routeA2y[t2]*p, 20, 20 );
		} else if(location>7 && location<7.5){
			p*=2;
			busBtnArray[busID] -> setGeometry (routeA2x[t]*(1-p)+214*p, routeA2y[t]*(1-p)+106*p, 20, 20 );
		} else if(location>=7.5 && location<8){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (214*(1-p)+routeA2x[t2]*p, 106*(1-p)+routeA2y[t2]*p, 20, 20 );
		} else {
			busBtnArray[busID] -> setGeometry (routeA2x[t]*(1-p)+routeA2x[t2]*p, routeA2y[t]*(1-p)+routeA2y[t2]*p, 20, 20 );
			qDebug()<<"x "<<routeA2x[t]*(1-p)<<" y "<<routeA2x[t2]*p;
		}
		if (location > 11.9) busLocation[busID] = 0;
	}
	if(QString::compare(busName,"D1")==0){
		int t = static_cast<int>(location); //floor
		int t2 = t+1; //ceiling
		float p=location-t; //fraction
		if(location>0 && location<0.5){
			p*=2;
			busBtnArray[busID] -> setGeometry (routeD1x[t]*(1-p)+505*p, routeD1y[t]*(1-p)+405*p, 20, 20 );
		}else if(location>=0.5 && location<1){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (505*(1-p)+routeD1x[t2]*p, 405*(1-p)+routeD1y[t2]*p, 20, 20 );
		}else if(location>6 && location<6.5){
			p*=2;
			busBtnArray[busID] -> setGeometry (routeD1x[t]*(1-p)+197*p, routeD1y[t]*(1-p)+104*p, 20, 20 );
		}else if(location>=6.5 && location<7){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (197*(1-p)+routeD1x[t2]*p, 104*(1-p)+routeD1y[t2]*p, 20, 20 );
		}else if(location>7 && location<7.5){
			p*=2;
			busBtnArray[busID] -> setGeometry (routeD1x[t]*(1-p)+196*p, routeD1y[t]*(1-p)+94*p, 20, 20 );
		}else if(location>=7.5 && location<8){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (196*(1-p)+routeD1x[t2]*p, 94*(1-p)+routeD1y[t2]*p, 20, 20 );
		}else{
			busBtnArray[busID] -> setGeometry (routeD1x[t]*(1-p)+routeD1x[t2]*p, routeD1y[t]*(1-p)+routeD1y[t2]*p, 20, 20 );
			qDebug()<<"x "<<routeD1x[t]*(1-p)<<" y "<<routeD1x[t2]*p;
		}
		if (location > 9.9) busLocation[busID] = 0;
	}
	if(QString::compare(busName,"D2")==0){
		int t = static_cast<int>(location); //floor
		int t2 = t+1; //ceiling
		float p=location-t; //fraction
		if(location>2 && location<2.5){
			p*=2;
			busBtnArray[busID] -> setGeometry (routeD2x[t]*(1-p)+196*p, routeD2y[t]*(1-p)+94*p, 20, 20 );
		}else if(location>=2.5 && location<3){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (196*(1-p)+routeD2x[t2]*p, 94*(1-p)+routeD2y[t2]*p, 20, 20 );
		}else if(location>3 && location<3.5){
			busBtnArray[busID] -> setGeometry (routeD2x[t]*(1-p)+197*p, routeD2y[t]*(1-p)+104*p, 20, 20 );
			p*=2;
		}else if(location>=3.5 && location<4){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (197*(1-p)+routeD2x[t2]*p, 104*(1-p)+routeD2y[t2]*p, 20, 20 );
		}else if(location>6 && location<6.5){
			p*=2;
			busBtnArray[busID] -> setGeometry (routeD2x[t]*(1-p)+505*p, routeD2y[t]*(1-p)+405*p, 20, 20 );
		}else if(location>=6.5 && location<7){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (505*(1-p)+routeD2x[t2]*p, 405*(1-p)+routeD2y[t2]*p, 20, 20 );
		}else if(location>7 && location<7.5){
			p*=2;
			busBtnArray[busID] -> setGeometry (routeD2x[t]*(1-p)+505*p, routeD2y[t]*(1-p)+405*p, 20, 20 );
		}else if(location>=7.5 && location<8){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (505*(1-p)+routeD2x[t2]*p, 405*(1-p)+routeD2y[t2]*p, 20, 20 );
		}else{
			busBtnArray[busID] -> setGeometry (routeD2x[t]*(1-p)+routeD2x[t2]*p, routeD2y[t]*(1-p)+routeD2y[t2]*p, 20, 20 );
			qDebug()<<"x "<<routeD2x[t]*(1-p)<<" y "<<routeD2x[t2]*p;
		}
		if (location > 7.9) busLocation[busID] = 0;
	}
	if(QString::compare(busName,"B")==0){
		int t = static_cast<int>(location); //floor
		int t2 = t+1; //ceiling
		float p=location-t; //fraction
		
		if(location>0 && location<0.5){
			p*=2;
			busBtnArray[busID] -> setGeometry (routeBx[t]*(1-p)+205*p, routeBy[t]*(1-p)+106*p, 20, 20 );
		}else if(location>=0.5 && location<1){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (205*(1-p)+routeBx[t2]*p, 106*(1-p)+routeBy[t2]*p, 20, 20 );
		}else if(location>3 && location<3.5){
			p*=2;
			busBtnArray[busID] -> setGeometry (routeBx[t]*(1-p)+500*p, routeBy[t]*(1-p)+400*p, 20, 20 );
		}else if(location>=3.5 && location<4){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (500*(1-p)+routeBx[t2]*p, 400*(1-p)+routeBy[t2]*p, 20, 20 );
		}else if(location>9 && location<9.5){
			p*=2;
			busBtnArray[busID] -> setGeometry (routeBx[t]*(1-p)+205*p, routeBy[t]*(1-p)+106*p, 20, 20 );
		}else if(location>=9.5 && location<10){
			p=(p-0.5)*2;
			busBtnArray[busID] -> setGeometry (205*(1-p)+routeBx[t2]*p, 106*(1-p)+routeBy[t2]*p, 20, 20 );
		}else{
			busBtnArray[busID] -> setGeometry (routeBx[t]*(1-p)+routeBx[t2]*p, routeBy[t]*(1-p)+routeBy[t2]*p, 20, 20 );
			qDebug()<<"x "<<routeBx[t]*(1-p)<<" y "<<routeBx[t2]*p;
		}
		if (location > 9.9) busLocation[busID] = 0;
	}
	if(QString::compare(busName,"C")==0){
		int t = static_cast<int>(location); //floor
		int t2 = t+1; //ceiling
		float p=location-t; //fraction
		
		busBtnArray[busID] -> setGeometry (routeCx[t]*(1-p)+routeCx[t2]*p, routeCy[t]*(1-p)+routeCy[t2]*p, 20, 20 );
		qDebug()<<"x "<<routeCx[t]*(1-p)<<" y "<<routeCx[t2]*p;
		
		if (location > 6.9) busLocation[busID] = 0;
	}
}

void Lines::terminateBus(int busid){
	busBtnArray[busid] -> hide();
	busID[busid]=0;
}

void Lines::updateHighlightVar(int id) {
	highlight = id;
}

void Lines::highlightRoute(QPainter *qp) {
	//BUS B route
  	QPen pen(Qt::green, 100, Qt::SolidLine);  
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
	qp->drawLine(900, 250, 800, 106);
	qp->drawLine(800, 106, 214, 106);
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

void Lines::updateStation(int population, int stationID){
	qDebug()<<"station "<<bstopArray[stationID]-> objectName() <<" population "<<population;
	
	QString p = QString::number(population);
	QString tooltip = QString("<h2 style=\"margin-bottom:0px\">"+bstopArray[stationID]->objectName()+"</h2>") + QString("<span style=\"font:20px\">"+p+"</span> people waiting");
	
	//float crowdLevel[7] = {0.0};
	QString busName[6] = {"A1","A2","D1","D2","B","C"};
	for (int i = 0; i<6; i++) {
		if (bss[stationID][i] != 0) {
			//crowdLevel[bss[stationID][i]] = sendBus[bss[stationID][i]-1]->getCrowd();
		
			float d = 100.0;
			for (int j = i*5; j < i*5+5; j++) {
				float dTemp = staLoc[stationID][i] - busLocation[j];
				if (dTemp > 0 && dTemp < d && busLocation[j] > 0.05)
					d = dTemp;
			}
			
			if (d > 80)
				tooltip += QString("<h2 style=\"margin-bottom:0px\">"+busName[i]+"</h2>") + QString("<span style=\"font:20px\">""</span> is not coming!");
			else {
				QString t;
				t.setNum(d * 3);
				tooltip += QString("<h2 style=\"margin-bottom:0px\">"+busName[i]+"</h2>") + QString("<span style=\"font:20px\">""</span> coming in ") + QString("<span style=\"font:15px\">"+t+"</span>") + QString("<span style=\"font:20px\">""</span> mins");
			}
		}
	}
	
	if(population >50){
		//over-populated warning
		bstopArray[stationID] -> setStyleSheet("* { background-color: rgb(255,50,0); font: 9px; border-radius: 15px; }");
	}else if(population>30){
		bstopArray[stationID] -> setStyleSheet("* { background-color: rgb(255,128,0); font: 9px; border-radius: 15px; }");
	}else{
		//normal
		bstopArray[stationID] -> setStyleSheet("* { background-color: rgb(135,206,250); font: 9px; border-radius: 15px; }");
	}
	/*
	// update sending buttons
	for (int i = 1; i<7; i++) {
		if (crowdLevel[i] < 0.1)
			continue;
		
		crowdLevel[i] = sendBus[i-1]->getCrowd();
		
		if (crowdLevel[i] < 0.1)
			sendBus[i-1] -> setStyleSheet("* { background-color: rgb(135,206,250); font: 9px; border-radius: 15px; }");
		else if (crowdLevel[i] < 1.1)
			sendBus[i-1] -> setStyleSheet("* { background-color: rgb(255,128,0); font: 9px; border-radius: 15px; }");
		else
			sendBus[i-1] -> setStyleSheet("* { background-color: rgb(255,50,0); font: 9px; border-radius: 15px; }");
	}*/
	
	bstopArray[stationID] -> setToolTip(tooltip);
}

