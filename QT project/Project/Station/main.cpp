#include "StationUpdater.h"
#include "QCoreApplication"
#include <iostream>

int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv); // Non-GUI app.
  StationUpdater updater;
  if (!updater.listen(QHostAddress::Any, 80000))
  {
    std::cerr << "Failed to bind to port" << endl;
    return 1;
  }
  std::cout << "Server running...\n";
  return app.exec();
}
