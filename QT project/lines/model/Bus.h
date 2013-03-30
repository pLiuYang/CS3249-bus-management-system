#ifndef BUS_H
#define BUS_H

#include <QString>
#include <QObject>
#include "../view/lines.h"

class Lines;

class Bus: public QObject{

	Q_OBJECT

public:
	Bus(int ID, QString Name, float Location, int Freeseats, Lines *UI);
	int getID();
	QString getName();
	float getLocation();
	int getFreeseats();
	void setLocation(float newLocation);

signals:
	void locationChanged(float newLocation, int id);
	
private:
	int id;
	QString name;
	float location;
	int freeseats;
	Lines *ui;
};

#endif
