// main.cpp
#include "TripServer.h"
#include "ClientSocket.h"
//#include "QCoreApplication"
#include <iostream>
#include <QApplication>
//#include "../../lines/view/lines.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv); // Non-GUI app.
  TripServer server;
  if (!server.listen(QHostAddress::Any, 60000))
  {
    std::cerr << "Failed to bind to port" << endl;
    return 1;
  }
  std::cout << "Server running...\n";
 
  
  return app.exec();
}
