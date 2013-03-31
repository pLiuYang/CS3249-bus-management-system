#include "lines.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);  
    
  Lines window;
  
  window.setMinimumSize(1050, 550);
  window.move(0, 0);
  window.setWindowTitle("Real-time NUS Bus Manager");
  window.show();

  return app.exec();
}
