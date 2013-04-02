// TripPlanner.cpp
#include "TripPlanner.h"
#include <QTimer>
#include <QtNetwork/QHostAddress>
#include <sstream>
#include "../Shared.h"
#include <math.h>

TripPlanner::TripPlanner(char *name,char *id, QMutex *inmutex, QObject *parent):QTcpSocket(parent)
{
  std::stringstream strValue;
  strValue << id;
  strValue >> busID;
  
  busName = QString(name);
  finished = false;
  lastStation = -1;
  
  mutex = inmutex;
  
  // Determine Start Station
  station = 0.0;
  
  peopleGettingOff = 0;
  space = BUS_SPACE;
  
 // ... // Create widgets.
  //connectButton = new QPushButton("Connect");
  //exitButton = new QPushButton("Exit");
  //layout = new QHBoxLayout(this);
  
  
  // Connect button signals.
 // connect(connectButton, SIGNAL(clicked()),
  //this, SLOT(startSending()));
  
  /*connect(stopButton, SIGNAL(clicked()),
  this, SLOT(stopSearch()));
  connect(quitButton, SIGNAL(clicked()),
  this, SLOT(close()));*/

 // connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
  
  // Connect TCP socket signals.
  connect(this, SIGNAL(connected()),
  this, SLOT(sendRequest()));
  
  connect(this, SIGNAL(disconnected()),
  this, SLOT(connectionClosedByServer()));
  
  //connect(this, SIGNAL(readyRead()),
  //this, SLOT(updateTableWidget()));
  
  connect(this,
  SIGNAL(error(QAbstractSocket::SocketError)),
  this, SLOT(error()));
  
  //layout->addWidget(connectButton);
  //layout->addWidget(exitButton);

  //startSending();
}

void TripPlanner::startSending()
{
  QTimer *timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()), this, SLOT(connectToServer()));
  timer->start(50);
}

void TripPlanner::connectToServer()
{
  this->connectToHost(QHostAddress::LocalHost,60000);
  qDebug() << "Connecting to server";
  nextBlockSize = 0;
}

void TripPlanner::sendRequest()
  {
  QByteArray block;
  QDataStream out(&block, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_4_1);
  qDebug() << "Bus Name is " << busName;
  // Bus has arrived at a station - Check if last station
  if (floor(station) != floor(lastStation))
  {
    bool reached = false;
    int arrivedStation = (int) station;
    qDebug() << "Bus has arrived at station" << station;
    
    if (station != 0.0) {
      if (busName.startsWith("A1") && arrivedStation == ROUTE_A1 - 1) reached = true;
      else if (busName.startsWith("A2") && arrivedStation == ROUTE_A2 - 1) reached = true;
      else if (busName.startsWith("B") && arrivedStation == ROUTE_B - 1) reached = true;
      else if (busName.startsWith("C") && arrivedStation == ROUTE_C - 1) reached = true;
      else if (busName.startsWith("D1") && arrivedStation == ROUTE_D1 - 1) reached = true;
      else if (busName.startsWith("D2") && arrivedStation == ROUTE_D2 - 1) reached = true;
    }
    
    // Reached last station
    if (reached == true) {
      qDebug() << "Bus arrived at last station";
      finished = true;
      peopleGettingOff = BUS_SPACE - space;
      out << quint16(0) << quint8('E') << busID << busName << station << peopleGettingOff << space;
      out.device()->seek(0); // Go to beginning of block.
      out << quint16(block.size() - sizeof(quint16));
      this->write(block);
      stopSearch();
    }
    
    // Not reached last station
    else 
    {
      if (space != BUS_SPACE) peopleGettingOff = qrand() % (BUS_SPACE - space);

      peopleGettingOn = stationRemove(station,busName,space);
      
      // Decrement space on bus
      space = space - peopleGettingOn;
      space = space + peopleGettingOff;
      qDebug() << "space = " << space;
      
      //statusLabel->setText(tr("Sending request..."));
      qDebug() << "Sending request...";
      qDebug() << "Message is " << quint16(0) << quint8('B') << busID << busName << station << peopleGettingOff << space;
      
      out << quint16(0) << quint8('B') << busID << busName << station << peopleGettingOff << space;

      out.device()->seek(0); // Go to beginning of block.
      out << quint16(block.size() - sizeof(quint16));
      this->write(block);
    }
  }
  
  // Bus has not arrived at a station yet
  else
  {
    peopleGettingOn = 0;
    peopleGettingOff = 0;
    qDebug() << "Bus is not at a station, currently at " << station;
    out << quint16(0) << quint8('N') << busID << busName << station << peopleGettingOff << space;
    out.device()->seek(0); // Go to beginning of block.
    out << quint16(block.size() - sizeof(quint16));
    this->write(block);
  }
  
  // Store lastStation (to check if the bus is at a new station)
  lastStation = station;
  // Increment station
  station = station + BUS_INCREMENT;
  
  stopSearch();
}

int TripPlanner::stationRemove(double station, QString busName, int space)
{
  int peopleGettingOn = 0;
  
  int astation = (int)station;
  qDebug() << "astation " << astation;
  int peopleAtStationGettingOn = 0;
  
  // Randomly add people to the bus
  if (busName.startsWith("A1"))
  {
    if (peopleAtStation[stationA1[astation]] != 0) peopleAtStationGettingOn = qrand() % peopleAtStation[stationA1[astation]];
  }
  else if (busName.startsWith("A2"))
  {
    if (peopleAtStation[stationA2[astation]] != 0) peopleAtStationGettingOn = qrand() % peopleAtStation[stationA2[astation]];
  }
  else if (busName.startsWith("B")) 
  {
    if (peopleAtStation[stationB[astation]] != 0) peopleAtStationGettingOn = qrand() % peopleAtStation[stationB[astation]];
  }
  else if (busName.startsWith("C"))
  {
    if (peopleAtStation[stationC[astation]] != 0) peopleAtStationGettingOn = qrand() % peopleAtStation[stationC[astation]];
  }
  else if (busName.startsWith("D1")) 
  {
    if (peopleAtStation[stationD1[astation]] != 0) peopleAtStationGettingOn = qrand() % peopleAtStation[stationD1[astation]];
  }
  else if (busName.startsWith("D2")) 
  {
    if (peopleAtStation[stationD2[astation]] != 0) peopleAtStationGettingOn = qrand() % peopleAtStation[stationD2[astation]];
  }
  
  qDebug() << "peopleAtStationGettingOn " << peopleAtStationGettingOn;
  
  // Check if more people than the bus can take want to get on
  if (peopleAtStationGettingOn <= space) peopleGettingOn = peopleAtStationGettingOn;
  else peopleGettingOn = space;

  qDebug() << "peopleGettingOn " << peopleGettingOn;
  
  
  // Decrement station
  mutex->lock();
  if (busName.startsWith("A1")) peopleAtStation[stationA1[astation]] = peopleAtStation[stationA1[astation]] - peopleGettingOn;
  else if (busName.startsWith("A2")) peopleAtStation[stationA2[astation]] = peopleAtStation[stationA2[astation]] - peopleGettingOn;
  else if (busName.startsWith("B")) peopleAtStation[stationB[astation]] = peopleAtStation[stationB[astation]] - peopleGettingOn;
  else if (busName.startsWith("C")) peopleAtStation[stationC[astation]] = peopleAtStation[stationC[astation]] - peopleGettingOn;
  else if (busName.startsWith("D1")) peopleAtStation[stationD1[astation]] = peopleAtStation[stationD1[astation]] - peopleGettingOn;
  else if (busName.startsWith("D2")) peopleAtStation[stationD2[astation]] = peopleAtStation[stationD2[astation]] - peopleGettingOn;
 mutex->unlock();
  
  return peopleGettingOn;
}

/*void TripPlanner::updateTableWidget()
{
  QDataStream in(this);
  in.setVersion(QDataStream::Qt_4_1);
  forever
  {
    
    //int row = tripTable->rowCount();
    if (nextBlockSize == 0) // New block.
    {
      if (this->bytesAvailable()<sizeof(quint16))
      return; // Wait for block size to arrive.
      in >> nextBlockSize; // Get new block size.
      qDebug() << "Got some data";
    }
    if (nextBlockSize == 0xFFFF) // End of block.
    {
      closeConnection();
      //statusLabel->setText(tr("Found %1 trip(s)").
      qDebug() << "Received a message";
      //arg(row));
      return;
    }
    if (this->bytesAvailable() < nextBlockSize) return; // Wait for complete block to arrive.
    
    QString received;
    in >> received;
   
    qDebug() << "received " << received;
    
    nextBlockSize = 0; // Have read block. Reset.
  }
}*/

void TripPlanner::closeConnection()
{
  this->close();
}

void TripPlanner::stopSearch()
{
  qDebug() << "Finished";
  closeConnection();
  
}

void TripPlanner::connectionClosedByServer()
{
  if (nextBlockSize != 0xFFFF)
  qDebug() << "Connection closed by server";
  closeConnection();
  if (finished == true) {
    workFinished();
    removeBus(busID);
  }
}
void TripPlanner::error()
{
  qDebug() << "ERROR: " << this->errorString();
  // Try connecting again after 500ms
  closeConnection();
  exit(1);
}
