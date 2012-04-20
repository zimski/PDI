#ifndef _MANAGESTATION_H_
#define _MANAGESTATION_H_
#include "station.h"
#include <iostream>


#include <QList>
#include <QStringList>
#include "HelloModule.h"


class ManageStation : public QObject
{
  Q_OBJECT
 private:
  QList<Station> liste;
  HelloModule * hello;
 public:
  ManageStation( HelloModule*);
  void addStation(Station s);
  int getNbStation();
  Station getStation(int index);
  
  public slots:
  void processMessage(QByteArray& data);
 signals :
  void updateListeEvent();
};


#endif /* _MANAGESTATION_H_ */
