#include "StationUpdater.h"
#include "QCoreApplication"
#include <iostream>

int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv); // Non-GUI app.
  StationUpdater updater;
  return app.exec();
}
