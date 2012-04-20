#ifndef _HELLOMODULE_H_
#define _HELLOMODULE_H_




#include <QtNetwork>
#include <iostream>
#include <QByteArray>


class HelloModule : public QObject
{
  Q_OBJECT
  
  private:
  QHostAddress localIp;
  int localPort;
  int localEtat;
  QUdpSocket * udpSocket;
  public :
  HelloModule();
  void InitServer();
  void SendHelloBCast();
  void SendHelloIP(QString );
  void setLocalIP(QString ip);
 public slots:
  void RecieveHello();
 
 signals:
  void getSomthing(QByteArray& data);
};

#endif /* _HELLOMODULE_H_ */
