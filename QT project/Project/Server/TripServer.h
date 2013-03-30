// TripServer.h
#include <QtNetwork/QTcpServer>
#include "../../lines/view/lines.h"

class TripServer: public QTcpServer
{
  Q_OBJECT
  public:
    TripServer(QObject *parent = 0);
   	Lines *window;
  private slots:
  private:
    void incomingConnection(int socketId);
    void initialiseStations();
  
};
