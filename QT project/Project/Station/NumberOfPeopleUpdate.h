#include <QtNetwork/QTcpSocket>
#include "../Shared.h"

class NumberOfPeopleUpdate: public QTcpSocket
{
  Q_OBJECT
  public:
    NumberOfPeopleUpdate(int numberOfPeople, int numberOfStation, QObject *parent = 0);
  public slots:
    void connectToServer();
  private slots:
    void stopSearch();
    void sendRequest();
    void connectionClosedByServer();
    void error();
  
  signals:
    void workFinished();

  private:
    int number;
    int stationNumber;
    
    void closeConnection();
    quint16 nextBlockSize;
};
