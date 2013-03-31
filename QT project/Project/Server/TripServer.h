// TripServer.h
#ifndef TRIPSERVER_H
#define TRIPSERVER_H

#include <QtNetwork/QTcpServer>
#include "../../lines/view/lines.h"
class Lines;
class TripServer: public QTcpServer
{
  Q_OBJECT
  public:
    TripServer(QObject *parent = 0);
   	Lines *window;
   	void sendBus(char* busName, char* busID);
  private slots:
  private:
    void incomingConnection(int socketId);
    void initialiseStations();
    
  
};

#endif
