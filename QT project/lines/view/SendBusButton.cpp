#include "SendBusButton.h"

SendBusButton::SendBusButton(const QString & text, QWidget *parent, Lines * lines, const int busType)
	: QPushButton(parent)
{
	ui = lines;
	setText(text);
	id = busType;
	crowd = 0;
	
	connect(this, SIGNAL(highlight(int)), ui, SLOT(updateHighlightVar(int)));
	connect(this, SIGNAL(highlight(int)), ui, SLOT(updateHighlightVar(int)));	
}

float SendBusButton::getCrowd() { return crowd; }

void SendBusButton::setCrowd(float c) { crowd = c; }

void SendBusButton::leaveEvent(QEvent * e) 
{
	qDebug() << "===== leave button =====";
	emit highlight(0);
	QPushButton::leaveEvent(e);
}

void SendBusButton::enterEvent(QEvent * e)
{
	qDebug() << "===== enter button =====";
	emit highlight(id);
	QPushButton::enterEvent(e);	
}
