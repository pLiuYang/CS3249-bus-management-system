#ifndef BUSSTOP_H
#define BUSSTOP_H

#include <QString>
#include <QObject>
#include "lines.h"

class BusStop: public QObject{

	Q_OBJECT
	
public:
	BusStop(int ID, QString Name, int Population, Lines *UI);
	int getID();
	QString getName();
	int getPopulation();
	void setPopulation (int newPopulation);
	
signals:
	void populationChanged(int population, int id);
	
private:
	int id;
	QString name;
	int population;
	Lines *ui;
};

#endif
