#include "HelloModule.h"
using namespace std;

HelloModule::HelloModule()
{
  InitServer();
}
void HelloModule::InitServer()
{
  udpSocket = new QUdpSocket(this);
  udpSocket->bind(45454, QUdpSocket::ShareAddress);
  connect(udpSocket, SIGNAL(readyRead()),this, SLOT(RecieveHello()));
  cout << "Serveur lancer sur le port 45454" << endl;
}
void HelloModule::SendHelloBCast()
{
  QByteArray datagram ;
  datagram.append(localIp.toString());
  datagram.append("#67677#0");// + QByteArray::number(messageNo);
   udpSocket->writeDatagram(datagram.data(), datagram.size(),QHostAddress::Broadcast, 45454);
   cout << "envois BCAST..." << endl;
}
void HelloModule::SendHelloIP(QString ipCible )
{
  QByteArray datagram;
  QHostAddress cible(ipCible);
  //QString data("%1#%2#%3").arg(localIp).arg(localPort).arg(localEtat);
  
  datagram.append(QString("%1#%2#%3").arg(localIp.toString()).arg(localPort).arg(localEtat));
  /*datagram.append("#");
  datagram.append(QString(localPort));
  datagram.append("#");
  datagram.append(QString(localEtat));
  */
  cout << "----" << datagram.data() << endl;
  sleep(1);
  
  //datagram = data.toAscii();
  int result = udpSocket->writeDatagram(datagram.data(),datagram.size(),cible, 45454);
  cout << "Send hello to: " << ipCible.toStdString() << " avc l etat " << result << endl;
  
}
void HelloModule::RecieveHello()
{
  cout << "qq chose reçu :" << endl;
  while (udpSocket->hasPendingDatagrams()) {
         QByteArray datagram;
         datagram.resize(udpSocket->pendingDatagramSize());
         udpSocket->readDatagram(datagram.data(), datagram.size());
	 cout << "[" << datagram.data() << "]" << endl;
	 emit getSomthing(datagram);
  }
}
void HelloModule::setLocalIP(QString ip)
{
  localIp.setAddress(ip);
  cout << "local Ip set : " << ip.toStdString() <<endl;
}
