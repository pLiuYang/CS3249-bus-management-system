#include "StationUpdater.h"
#include "../Shared.h"
#include "TripPlanner.h"
#include "ClientSocket.h"
#include "NumberOfPeopleUpdate.h"
#include <QTimer>
#include <QThread>
#include <stdio.h>
#include <stdlib.h>

StationUpdater::StationUpdater(QObject *parent): QTcpServer(parent)
{
  initialiseStations();
  initialiseBuses();
  initialisePeopleAtStations();
  updateStationTimer();
  //startA1Timer();
  //startA2Timer();
}

void StationUpdater::incomingConnection(int socketId)
{
  ClientSocket *socket = new ClientSocket(this);
  connect(socket,SIGNAL(newBus(int,char *)),this,SLOT(createBus(int,char *)));
  socket->setSocketDescriptor(socketId);
}

void StationUpdater::createBus(int busID, char* busName)
{
  busMutex.lock();
  arrayOfBuses[busID] = 0;
  busMutex.unlock();
  
  char bus_id[10];
  snprintf(bus_id, sizeof(bus_id), "%d", busID);
  QThread *bus = new QThread();
  TripPlanner *newBus = new TripPlanner(busName,bus_id);
  newBus->moveToThread(bus);
  connect(bus, SIGNAL(started()), newBus, SLOT(startSending()));
  connect(newBus, SIGNAL(workFinished()), bus, SLOT(quit()));
  connect(newBus, SIGNAL(removeBus(int)), this, SLOT(removeBus(int)));
  connect(bus, SIGNAL(finished()), newBus, SLOT(deleteLater()) );
  connect(bus, SIGNAL(finished()), bus, SLOT(deleteLater()) );
  bus->start();

}

void StationUpdater::initialiseBuses()
{
  for (int i = 0; i < 30; i++)
  {
    busMutex.lock();
    arrayOfBuses[i] = 1;
    busMutex.unlock();
  }
}

void StationUpdater::startA1Timer()
{
  QTimer *A1Timer = new QTimer(this);
  connect(A1Timer,SIGNAL(timeout()), this, SLOT(createBusA1()));
  A1Timer->start(5000);
}

void StationUpdater::startA2Timer()
{
  QTimer *A2Timer = new QTimer(this);
  connect(A2Timer,SIGNAL(timeout()), this, SLOT(createBusA2()));
  A2Timer->start(5000);
}

void StationUpdater::createBusA1()
{
  char bus_id[10];
  int id = addBus();
  snprintf(bus_id, sizeof(bus_id), "%d", id);
  QThread *bus = new QThread();
  TripPlanner *newBus = new TripPlanner("A1",bus_id);
  newBus->moveToThread(bus);
  connect(bus, SIGNAL(started()), newBus, SLOT(startSending()));
  connect(newBus, SIGNAL(workFinished()), bus, SLOT(quit()));
  connect(newBus, SIGNAL(removeBus(int)), this, SLOT(removeBus(int)));
  connect(bus, SIGNAL(finished()), newBus, SLOT(deleteLater()) );
  connect(bus, SIGNAL(finished()), bus, SLOT(deleteLater()) );
  bus->start();
}

void StationUpdater::createBusA2()
{
  char bus_id[10];
  int id = addBus();
  snprintf(bus_id, sizeof(bus_id), "%d", id);
  QThread *bus = new QThread();
  TripPlanner *newBus = new TripPlanner("A2",bus_id);
  newBus->moveToThread(bus);
  connect(bus, SIGNAL(started()), newBus, SLOT(startSending()));
  connect(newBus, SIGNAL(workFinished()), bus, SLOT(quit()));
  connect(newBus, SIGNAL(workFinished()), this, SLOT(removeBus(bus_id)));
  connect(bus, SIGNAL(finished()), newBus, SLOT(deleteLater()) );
  connect(bus, SIGNAL(finished()), bus, SLOT(deleteLater()) );
  bus->start();
}

void StationUpdater::initialiseStations()
{
  stationA1[0] = 2;
  stationA1[1] = 0;
  stationA1[2] = 20;
  stationA1[3] = 18;
  stationA1[4] = 17;
  stationA1[5] = 12;
  stationA1[6] = 10;
  stationA1[7] = 8;
  stationA1[8] = 5;
  stationA1[9] = 3;
  stationA1[10] = 2;
  
  stationA2[0] = 2;
  stationA2[1] = 4;
  stationA2[2] = 5;
  stationA2[3] = 6;
  stationA2[4] = 7;
  stationA2[5] = 9;
  stationA2[6] = 11;
  stationA2[7] = 13;
  stationA2[8] = 16;
  stationA2[9] = 19;
  stationA2[10] =21;
  stationA2[11] = 1;
  stationA2[12] = 2;
  
  stationB[0] = 15;
  stationB[1] = 12;
  stationB[2] = 10;
  stationB[3] = 8;
  stationB[4] = 5;
  stationB[5] = 6;
  stationB[6] = 7;
  stationB[7] = 9;
  stationB[8] = 11;
  stationB[9] = 13;
  stationB[10] = 15;
  
  stationC[0] = 15;
  stationC[1] = 16;
  stationC[2] = 19;
  stationC[3] = 21;
  stationC[4] = 20;
  stationC[5] = 18;
  stationC[6] = 17;
  stationC[7] = 15;
  
  stationD1[0] = 4;
  stationD1[1] = 5;
  stationD1[2] = 6;
  stationD1[3] = 7;
  stationD1[4] = 9;
  stationD1[5] = 11;
  stationD1[6] = 13;
  stationD1[7] = 14;
  stationD1[8] = 16;
  stationD1[9] = 19;
  stationD1[10] = 21;
  
  stationD2[0] = 20;
  stationD2[1] = 18;
  stationD2[2] = 17;
  stationD2[3] = 14;
  stationD2[4] = 12;
  stationD2[5] = 10;
  stationD2[6] = 8;
  stationD2[7] = 5;
  stationD2[8] = 3;
}

// Add a new bus to running
int StationUpdater::addBus()
{
  int bus_id;
  for (int i = 0; i < 30; i++)
  {
    if (arrayOfBuses[i] == 1)
    {
      busMutex.lock();
      arrayOfBuses[i] = 0;
      busMutex.unlock();
      bus_id = i;
      break;
    }
  }
  return bus_id;
}

// Remove bus - not running
void StationUpdater::removeBus(int bus_id)
{
  busMutex.lock();
  arrayOfBuses[bus_id] = 1;
  busMutex.unlock();

}


void StationUpdater::initialisePeopleAtStations()
{
  for (int i = 0; i < TOTAL_STATION; i++)
  {
    this->mutex.lock();
    peopleAtStation[i] = rand() % BUS_SPACE;
    this->mutex.unlock();
  }
}

void StationUpdater::updateStationTimer()
{
  QTimer *stationTimer = new QTimer(this);
  connect(stationTimer,SIGNAL(timeout()), this, SLOT(updateStation()));
  stationTimer->start(qrand() % 5000);
}

void StationUpdater::updateStation()
{
  for (int i = 0; i < TOTAL_STATION; i++)
  { 
    this->mutex.lock();
    peopleAtStation[i] = peopleAtStation[i] + (qrand() % 5);
    this->mutex.unlock();
    qDebug() << "Number of people at station[" << i << "] = " << peopleAtStation[i];
    updateNumberOfPeople(i,peopleAtStation[i]);
  }
  
}

void StationUpdater::updateNumberOfPeople(int stationNumber, int people)
{
  QThread *station = new QThread();
  NumberOfPeopleUpdate *updateStation = new NumberOfPeopleUpdate(stationNumber,people);
  updateStation->moveToThread(station);
  connect(station, SIGNAL(started()), updateStation, SLOT(connectToServer()));
  connect(updateStation, SIGNAL(workFinished()), station, SLOT(quit()));
  connect(station, SIGNAL(finished()), updateStation, SLOT(deleteLater()) );
  connect(station, SIGNAL(finished()), station, SLOT(deleteLater()) );
  station->start();
}
