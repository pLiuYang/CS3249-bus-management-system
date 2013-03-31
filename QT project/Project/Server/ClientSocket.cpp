#include "ClientSocket.h"
#include "../Shared.h"
#include "QTimer"
#include <math.h>

// ClientSocket.cpp
ClientSocket::ClientSocket(Lines *window ,QObject *parent):
QTcpSocket(parent)
{
  ui=window;
  //ui -> move(0,0);
  connect(this, SIGNAL(readyRead()),
  this, SLOT(readClient()));
  connect(this, SIGNAL(disconnected()),
  this, SLOT(deleteLater()));
  nextBlockSize = 0;
  connect(this,SIGNAL(locationChanged(float, int ,QString)), ui, SLOT(updateBus(float, int, QString)));
  connect(this,SIGNAL(populationChanged(int, int)), ui, SLOT(updateStation(int, int)));
  connect(this,SIGNAL(terminalReached(int)), ui, SLOT(terminateBus(int)));
}

void ClientSocket::readClient()
{
  QDataStream in (this);
  in.setVersion(QDataStream::Qt_4_1);
  if (nextBlockSize == 0)
  {
  if (
    bytesAvailable() < sizeof(quint16))
    return; // Wait for block size to arrive.
    in >> nextBlockSize; // Get new block size.
  }
  if (bytesAvailable() < nextBlockSize)
  return; // Wait for complete block to arrive.

  quint8 requestType;
  //QString name, from, to;
  //QDate date;
  //QTime time;
  //int interval;
  //quint8 flag;
  int busID;
  QString busName;
  double qstation;
  int station;
  int peopleGettingOff;
  int space;
  
  QString received;
  
  in >> requestType;
  if (requestType == 'B')
  {
    received = 'B';
    in >> busID >> busName >> qstation >> peopleGettingOff >> space;
    emit locationChanged(qstation, busID,busName);
    
    qDebug() << "busID " << busID;
    qDebug() << "busName " << busName;
    qDebug() << "bus is at station number " << qstation;
    qDebug() << "peopleGettingOff " << peopleGettingOff;
    qDebug() << "space " << space;
    
    
    qDebug() << "Bus has reached station";
    
    int station = (int) qstation;
    
    // Check actual station

    if (busName.startsWith("A1"))
    {
      qDebug() << "Actual station is " << stationA1[station];
    }
    else if (busName.startsWith("A2"))
    {
      qDebug() << "Actual station is " << stationA2[station];
    }
    else if (busName.startsWith("B"))
    {
      qDebug() << "Actual station is " << stationB[station];
    }
    else if (busName.startsWith("C"))
    {
      qDebug() << "Actual station is " << stationC[station];
    }
    else if (busName.startsWith("D1"))
    {
      qDebug() << "Actual station is " << stationD1[station];
    }
    else if (busName.startsWith("D2"))
    {
      qDebug() << "Actual station is " << stationD2[station];
    }
    
    //sendData(received);
    //QDataStream out(this);
    //out << quint16(0xFFFF); // End of block flag.
    
  }
  
  // Bus has not reached station yet
  else if (requestType == 'N') {
    received = 'N';
    qDebug() << "Bus has not arrived at a station yet";
    in >> busID >> busName >> qstation;
     emit locationChanged(qstation, busID, busName);
    //sendData(received);
    //QDataStream out(this);
    //out << quint16(0xFFFF); // End of block flag.
  }
  
  // Bus has reached last station
  else if (requestType == 'E') {
    received = 'E';
    qDebug() << "Bus has arrived at last station";
    in >> busID >> busName >> qstation >> peopleGettingOff >> space;
     emit locationChanged(qstation, busID,busName);
     emit terminalReached(busID);
    //sendData(received);
    //QDataStream out(this);
    //out << quint16(0xFFFF); // End of block flag.
    qDebug() << "Number of people getting off = " << peopleGettingOff;
  }
  
  else if (requestType == 'S') {
    int peopleAtStation = 0;
    int stationNumber;
    qDebug() << "Got station update";
    in >> stationNumber >> peopleAtStation;
    emit populationChanged(peopleAtStation, stationNumber);
    qDebug() << "People At Station " << stationNumber << peopleAtStation;
  }
}


void ClientSocket::sendData(const QString &received)
{
  QByteArray block;
  QDataStream out(&block, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_4_1);
  //FlightDB flightDB;
  //QList<Flight> flights = flightDB.getFlights(
  //from, to, date, time, interval, flag);
  //out << quint16(0);
  //if (flights.isEmpty())
  out << quint16(0) ;
  //else
  //{
  //out << quint16(flights.size()); // row count.
  //for (int i = 0; i < flights.size(); ++i)
  //{
  //Flight flight = flights[i];
  //out << flight.getDate() << flight.getFlightNo()
  //<< flight.getDepartureTime()
  //<< flight.getArrivalTime();
  //}
  //}
  out.device()->seek(0);
  out << quint16(block.size() - sizeof(quint16));
  write(block);
  qDebug() << "Sending Data..." << received;
}
