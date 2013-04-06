#ifndef SENDBUSBUTTON_H
#define SENDBUSBUTTON_H

#include <QPushButton>
#include <QEvent>
#include <QDebug>
#include "lines.h"

class Lines;

class SendBusButton : public QPushButton
{
Q_OBJECT
public:
	SendBusButton(const QString & text, QWidget * parent = 0, Lines * lines = 0, const int busType=0);
	float getCrowd();
	void setCrowd(float c);
	
signals:
	void highlight(int id);
	
protected:
	void enterEvent(QEvent * e);
	void leaveEvent(QEvent * e);
	
	Lines * ui;
	int id;
	volatile float crowd;
};

#endif // SENDBUSBUTTON_H

