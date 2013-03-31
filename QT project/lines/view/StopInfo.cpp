#include "StopInfo.h"

StopInfo::StopInfo(QString stopName, QWidget *parent)
         : QWidget(parent)
{
	name = stopName;
	this -> setWindowTitle(name);
	QLabel * processingMessage = new QLabel("Bus Stop Info");
	this -> setWindowFlags(Qt::WindowStaysOnTopHint);
	this -> setFixedSize(400, 200);
	this -> setGeometry (400, 200, 30, 30 );
}
QString StopInfo::getName(){
	return name;
}

void StopInfo::closeEvent(QCloseEvent *event){
	event->accept();
}
