#ifndef STOPINFO_H
#define STOPINFO_H

#include <QWidget>
#include <QCloseEvent>
#include <QLabel>
#include <QPushButton>

class QLabel;
class QPushButton;

class StopInfo : public QWidget
{
  Q_OBJECT  

  public:
    StopInfo(QString stopName, QWidget *parent = 0);
   	QString getName();
  protected:
	void closeEvent(QCloseEvent *event);
	
  private:
  	QString name;
  	QLabel *demand;
  	QPushButton *hint;
};
#endif
