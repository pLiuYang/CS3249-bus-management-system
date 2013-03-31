#include "ClientSocket.h"
#include "../Shared.h"
#include "QTimer"
#include <math.h>

// ClientSocket.cpp
ClientSocket::ClientSocket(QObject *parent):
QTcpSocket(parent)
{
  //ui -> move(0,0);
  connect(this, SIGNAL(readyRead()),
  this, SLOT(readClient()));
  connect(this, SIGNAL(disconnected()),
  this, SLOT(deleteLater()));
  nextBlockSize = 0;
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
  char *busName;
  
  QString received;
  
  in >> requestType;
  if (requestType == 'B')
  {
    in >> busID >> busName;
    emit newBus(busID,busName);
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
