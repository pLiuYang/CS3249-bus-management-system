// TripServer.h
#include <QtNetwork/QTcpServer>
#include <QMutex>

class StationUpdater: public QObject
{
  Q_OBJECT
  public:
    StationUpdater();
  protected:
    QMutex mutex;

  private slots:
    void updateStation();
    void updateStationTimer();
    void initialiseStations();
    void initialisePeopleAtStations();
    void createBusA1();
    void createBusA2();
    
  private :
    void startA1Timer();
    void startA2Timer();
    void updateNumberOfPeople(int stationNumber, int people);
    char *route;
    int id;
    
    
  
};
