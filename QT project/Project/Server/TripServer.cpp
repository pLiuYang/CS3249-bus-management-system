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
  
  stationA1[0] = 0;
  stationA1[1] = 21;
  stationA1[2] = 18;
  stationA1[3] = 16;
  stationA1[4] = 15;
  stationA1[5] = 14;
  stationA1[6] = 10;
  stationA1[7] = 8;
  stationA1[8] = 4;
  stationA1[9] = 0;
  
  stationA2[0] = 0;
  stationA2[1] = 1;
  stationA2[2] = 3;
  stationA2[3] = 4;
  stationA2[4] = 5;
  stationA2[5] = 6;
  stationA2[6] = 8;
  stationA2[7] = 10;
  stationA2[8] = 13;
  stationA2[9] = 14;
  stationA2[10] = 16;
  stationA2[11] =18;
  stationA2[12] = 21;
  stationA2[13] = 0;

}

void TripServer::incomingConnection(int socketId)
{
  ClientSocket *socket = new ClientSocket(window, this);
  socket->setSocketDescriptor(socketId);
}
