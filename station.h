#ifndef _STATION_H_
#define _STATION_H_
#include <QHostAddress>

class Station
{
 public:
  QHostAddress ip;
  int port;
  int etat;
  // ior par exemple
  Station(QHostAddress ip,int port, int etat);
  // void setInformation()
};


#endif /* _STATION_H_ */
