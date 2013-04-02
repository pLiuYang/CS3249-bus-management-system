// TripPlanner.h
//asdfsaf
#include <QtNetwork/QTcpSocket>
#include <QMutex>

#define BUS_INCREMENT 0.01

class TripPlanner: public QTcpSocket
{
  Q_OBJECT
  public:
    TripPlanner(char *name, char *id, QMutex *inmutex, QObject *parent = 0);
  public slots:
    void startSending();
  private slots:
    void connectToServer();
    void stopSearch();
    void sendRequest();
    void connectionClosedByServer();
    //void updateTableWidget();
    void error();
  
  signals:
    void workFinished();
    void removeBus(int bus_id);

  private:
    int stationRemove(double station, QString busName, int space);

    int busID;
    QString busName;
    double station;
    double lastStation;
    int peopleGettingOff;
    int peopleGettingOn;
    int space;
    
    QMutex *mutex;
    
    bool finished;
    
    int direction;
    void closeConnection();
    quint16 nextBlockSize;
};
