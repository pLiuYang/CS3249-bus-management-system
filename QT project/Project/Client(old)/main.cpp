// main.cpp for Client side
#include <QApplication>
#include "TripPlanner.h"

int start(int argc, char *argv[])
{
  QCoreApplication app(argc, argv); //Non - GUI app.
  TripPlanner planner(argv[1],argv[2]);
  return app.exec();
}


int main(int argc, char *argv[])
{
  start(argc,argv);
}
