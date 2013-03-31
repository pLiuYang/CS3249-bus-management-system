// TripPlanner.cpp
#include "TripPlanner.h"
#include <QTimer>
#include <QtNetwork/QHostAddress>
#include <sstream>
#include "../Shared.h"
#include <math.h>

TripPlanner::TripPlanner(char *name,char *id, QObject *parent):QTcpSocket(parent)
{
  std::stringstream strValue;
  strValue << id;
  strValue >> busID;
  
  busName = name;
  
  // Connect TCP socket signals.
  connect(this, SIGNAL(connected()),
  this, SLOT(sendRequest()));
  
  connect(this, SIGNAL(disconnected()),
  this, SLOT(connectionClosedByServer()));
  
  connect(this,
  SIGNAL(error(QAbstractSocket::SocketError)),
  this, SLOT(error()));
}

void TripPlanner::startSending()
{
  this->connectToHost(QHostAddress::LocalHost,80000);
  qDebug() << "Connecting to server";
  nextBlockSize = 0;
}

void TripPlanner::sendRequest()
  {
  QByteArray block;
  QDataStream out(&block, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_4_1);


  out << quint16(0) << quint8('B') << busID << busName;
  out.device()->seek(0); // Go to beginning of block.
  out << quint16(block.size() - sizeof(quint16));
  this->write(block);
  stopSearch();
}

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
  }
}
void TripPlanner::error()
{
  qDebug() << "ERROR: " << this->errorString();
  //closeConnection();
  // Try connecting again after 500ms
  QTimer::singleShot(500,this,SLOT(startSending()));
}
