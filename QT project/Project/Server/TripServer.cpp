// TripServer.cpp
#include "TripServer.h"
#include "ClientSocket.h"
#include "../Shared.h"
#include <QTimer>
TripServer::TripServer(QObject *parent): QTcpServer(parent)
{
  initialiseStations();
}

void TripServer::initialiseStations()
{
  window = new Lines;
  //ui = &window;
  window->setMinimumSize(1050, 550);
  window->move(0, 0);
  window->setWindowTitle("Real-time NUS Bus Manager");
  window->show();
  
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
  stationA2[8] = 14;
  stationA2[9] = 16;
  stationA2[10] = 19;
  stationA2[11] =21;
  stationA2[12] = 1;
  stationA2[13] = 2;
  
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

void TripServer::incomingConnection(int socketId)
{
  ClientSocket *socket = new ClientSocket(window, this);
  socket->setSocketDescriptor(socketId);
}
