// TripPlanner.h

#include <QtNetwork/QTcpSocket>
#include <QDialog>
#include <QPushButton>
#include <QMainWindow>
#include <QHBoxLayout>

#define BUS_INCREMENT 0.5

class TripPlanner: public QTcpSocket
{
  Q_OBJECT
  public:
    TripPlanner(char *name, char *id, QObject *parent = 0);
  private slots:
    void startSending();
    void connectToServer();
    void stopSearch();
    void sendRequest();
    void connectionClosedByServer();
    void updateTableWidget();
    void error();

  private:
 // ... // Widgets
    //QPushButton *connectButton;
    //QPushButton *exitButton;
    //QHBoxLayout *layout;

    int busID;
    QString busName;
    double station;
    double lastStation;
    int peopleGettingOff;
    int peopleGettingOn;
    int space;
    
    bool finished;
    
    int direction;
    
    QTcpSocket tcpSocket;
    quint16 nextBlockSize;
    void closeConnection();
};
