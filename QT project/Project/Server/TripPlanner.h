// TripPlanner.h

#include <QtNetwork/QTcpSocket>
#include <QMutex>

#define BUS_INCREMENT 0.1

class TripPlanner: public QTcpSocket
{
  Q_OBJECT
  public:
    TripPlanner(char *name, char *id, QObject *parent = 0);
  public slots:
    void startSending();
  private slots:
    void stopSearch();
    void sendRequest();
    void connectionClosedByServer();
    //void updateTableWidget();
    void error();
  
  signals:
    void workFinished();

  private:
    int busID;
    char *busName;
    double station;
    double lastStation;
    int peopleGettingOff;
    int peopleGettingOn;
    int space;
    
    bool finished;
    
    int direction;
    void closeConnection();
    quint16 nextBlockSize;
};
