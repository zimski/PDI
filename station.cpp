#include "station.h"

Station::Station(QHostAddress ip_p,int port_p, int etat_p)
{
  ip.setAddress(ip_p.toString());
  port  =port_p;
  etat = etat_p;
  //port = port_p;
}
