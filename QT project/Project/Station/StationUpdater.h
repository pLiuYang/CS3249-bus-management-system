// TripServer.h
#include <QtNetwork/QTcpServer>
#include <QMutex>

class StationUpdater: public QTcpServer
{
  Q_OBJECT
  public:
    StationUpdater(QObject *parent = 0);
  protected:
    QMutex mutex;
    QMutex busMutex;

  private slots:
    void updateStation();
    void updateServer();
    void updateStationTimer();
    void initialiseStations();
    void initialisePeopleAtStations();
    void createBusA1();
    void createBusA2();
    void createBusB();
    void createBusC();
    void createBusD1();
    void createBusD2();
    void removeBus(int bus_id);
    void createBus(int busID, char *busName);
    
  private :
    void incomingConnection(int socketId);
    void initialiseBuses();
    void startA1Timer();
    void startA2Timer();
    void startBTimer();
    void startCTimer();
    void startD1Timer();
    void startD2Timer();
    void updateNumberOfPeople(int stationNumber, int people);
    char *route;
    int addBus();
    int arrayOfBuses[30];
    
    
  
};
