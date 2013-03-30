// TripPlanner.cpp
#include "NumberOfPeopleUpdate.h"
#include <QtNetwork/QHostAddress>
#include <sstream>
#include "../Shared.h"


NumberOfPeopleUpdate::NumberOfPeopleUpdate(int numberOfPeople, int numberOfStation, QObject *parent):QTcpSocket(parent)
{
  number = numberOfPeople;
  stationNumber = numberOfStation;
  
  // Connect TCP socket signals.
  connect(this, SIGNAL(connected()),
  this, SLOT(sendRequest()));
  
  connect(this, SIGNAL(disconnected()),
  this, SLOT(connectionClosedByServer()));
  
  connect(this,
  SIGNAL(error(QAbstractSocket::SocketError)),
  this, SLOT(error()));
}

void NumberOfPeopleUpdate::connectToServer()
{
  this->connectToHost(QHostAddress::LocalHost,60000);
  qDebug() << "Connecting to server";
  nextBlockSize = 0;
}

void NumberOfPeopleUpdate::sendRequest()
{
  QByteArray block;
  QDataStream out(&block, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_4_1);
  qDebug() << "Sending Stations";
  out << quint16(0) << quint8('S') << number << stationNumber;
  out.device()->seek(0); // Go to beginning of block.
  out << quint16(block.size() - sizeof(quint16));
  this->write(block);
  stopSearch();
}


void NumberOfPeopleUpdate::closeConnection()
{
  this->close();
}

void NumberOfPeopleUpdate::stopSearch()
{
  qDebug() << "Sending Stations Finished";
  closeConnection();
  
}

void NumberOfPeopleUpdate::connectionClosedByServer()
{
  if (nextBlockSize != 0xFFFF)
  qDebug() << "Connection closed by server";
  closeConnection();
  workFinished();
}
void NumberOfPeopleUpdate::error()
{
  qDebug() << "ERROR: " << this->errorString();
  closeConnection();
  exit(1);
}
