// TripPlanner.cpp
#define NUMCOL 4
#define NUMROW 5

#include "TripPlanner.h"
#include <QTimer>
#include <QtNetwork/QHostAddress>
#include <sstream>
#include "../Shared.h"
#include "../Station/StationUpdater.h"
#include <math.h>

TripPlanner::TripPlanner(char *name,char *id, QObject *parent):QTcpSocket(parent)
{
  std::stringstream strValue;
  strValue << id;
  strValue >> busID;
  
  busName = QString(name);
  finished = false;
  lastStation = -1;
  
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
  connect(&tcpSocket, SIGNAL(connected()),
  this, SLOT(sendRequest()));
  connect(&tcpSocket, SIGNAL(disconnected()),
  this, SLOT(connectionClosedByServer()));
  connect(&tcpSocket, SIGNAL(readyRead()),
  this, SLOT(updateTableWidget()));
  connect(&tcpSocket,
  SIGNAL(error(QAbstractSocket::SocketError)),
  this, SLOT(error()));
  
  //layout->addWidget(connectButton);
  //layout->addWidget(exitButton);
  
  startSending();
}

void TripPlanner::startSending()
{
  QTimer *timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()), this, SLOT(connectToServer()));
  timer->start(qrand() % 2000);

}

void TripPlanner::connectToServer()
{
  // tcpSocket.connectToHost(hostname, port);
  tcpSocket.connectToHost(QHostAddress::LocalHost,60000);
  //tripTable->setRowCount(0); // Init and clear table.
  //searchButton->setEnabled(false);
  //stopButton->setEnabled(true);
  //stopButton->setFocus(Qt::OtherFocusReason);
  //statusLabel->setText(tr("Connecting to server..."));
  qDebug() << "Connecting to server";
  //progressBar->show();
  nextBlockSize = 0;
}

void TripPlanner::sendRequest()
  {
  QByteArray block;
  QDataStream out(&block, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_4_1);
 
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
      tcpSocket.write(block);
      stopSearch();
    }
    
    // Not reached last station
    else 
    {
      if (space != BUS_SPACE) peopleGettingOff = qrand() % (BUS_SPACE - space);
      out << quint16(0) << quint8('S') << busID << busName << station << peopleGettingOff << space;

      out.device()->seek(0); // Go to beginning of block.
      out << quint16(block.size() - sizeof(quint16));
      tcpSocket.write(block);
      //statusLabel->setText(tr("Sending request..."));
      qDebug() << "Sending request...";
      qDebug() << "Message is " << quint16(0) << quint8('S') << busID << busName << station << peopleGettingOff << space;
      
      peopleGettingOn = StationUpdater::stationRemove(station,busName,space);
      
      // Decrement space on bus
      space = space - peopleGettingOn;
      space = space + peopleGettingOff;
      qDebug() << "space = " << space;
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
    tcpSocket.write(block);
  }
  
  // Store lastStation (to check if the bus is at a new station)
  lastStation = station;
  // Increment station
  station = station + BUS_INCREMENT;
}

void TripPlanner::updateTableWidget()
{
  QDataStream in(&tcpSocket);
  in.setVersion(QDataStream::Qt_4_1);
  forever
  {
    
    //int row = tripTable->rowCount();
    if (nextBlockSize == 0) // New block.
    {
      if (tcpSocket.bytesAvailable()<sizeof(quint16))
      break; // Wait for block size to arrive.
      in >> nextBlockSize; // Get new block size.
      qDebug() << "Got some data";
    }
    if (nextBlockSize == 0xFFFF) // End of block.
    {
      closeConnection();
      //statusLabel->setText(tr("Found %1 trip(s)").
      qDebug() << "Received a message";
      //arg(row));
      break;
    }
    if (tcpSocket.bytesAvailable() < nextBlockSize) break; // Wait for complete block to arrive.
    QString received;
    in >> received;
   
    qDebug() << "received " << received;
    
    nextBlockSize = 0; // Have read block. Reset.
    
    
  }
}

void TripPlanner::closeConnection()
{
  tcpSocket.close();
  //searchButton->setEnabled(true);
  //searchButton->setFocus(Qt::OtherFocusReason);
  //stopButton->setEnabled(false);
  //progressBar->hide();
}

void TripPlanner::stopSearch()
{
 // statusLabel->setText(tr("Search stopped"));
  qDebug() << "Finished";
  closeConnection();
  
}

void TripPlanner::connectionClosedByServer()
{
  if (nextBlockSize != 0xFFFF)
 // statusLabel->setText(tr(
  //"Error: Connection closed by server"));
  qDebug() << "Connection closed by server";
  closeConnection();
  if (finished == true) exit(0);
}
void TripPlanner::error()
{
 //statusLabel->setText(tcpSocket.errorString());
  qDebug() << "ERROR: " << tcpSocket.errorString();
  closeConnection();
  exit(1);
}
