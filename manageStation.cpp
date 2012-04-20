#include "manageStation.h"
using namespace std;

ManageStation::ManageStation( HelloModule * he)
{
  hello = he; 
}
void ManageStation::addStation(Station s)
{
  liste.append(s);
}

Station ManageStation::getStation(int index)
{
  return liste.at(index);
}
int ManageStation::getNbStation()
{
  return liste.size();
}
void ManageStation::processMessage(QByteArray& data)
{
  // exctraction des information
  cout << " traitement du message recu" << endl;
  QStringList parametre;
  QString chaine(data.data());
  parametre = chaine.split('#');
  cout << "[ip]:" << parametre[0].toStdString() << endl;
  cout << "[port]:" << parametre[1].toStdString() << endl;
  cout << "[etat]:" << parametre[2].toStdString() << endl;
  // ordre des information:  check#info1#info2#....#
  // check if station already exist
  for (int i = 0; i < liste.size(); ++i)
    {
      // cout << "parcour " <<  i << parametre[0].toStdString() << endl;
		if(liste.at(i).ip.toString().compare(parametre[0])==0)
		  {
		    cout << "existe deja" <<endl;
		    return ;
		  }
    }
  
  addStation(Station(QHostAddress(parametre[0]),parametre[1].toInt(),parametre[2].toInt()));
  hello->SendHelloIP(QString(parametre[0]));
  //emit sendHelloIP()
  emit updateListeEvent();
  
}
