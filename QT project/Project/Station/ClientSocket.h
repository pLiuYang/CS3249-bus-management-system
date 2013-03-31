// ClientSocket.h

#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H
#include <QtNetwork/QTcpSocket>

class ClientSocket : public QTcpSocket
{
  Q_OBJECT
  
  public:
    ClientSocket(QObject *parent = 0);
  signals:
  	void newBus(int busID, char *busName);
  
  private slots:
    void readClient();
    
  private:
    quint16 nextBlockSize;
    void sendData(const QString &received);
};

#endif
