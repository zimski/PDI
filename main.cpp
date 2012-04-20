#include <QtGui>
#include "mainframe.h"

#include "HelloModule.h"


int main(int argc, char *argv[])
{
  QApplication app( argc , argv);
  MainFrame fenetre;
  //HelloModule hello;
  fenetre.show();
  //QObject::connect(fenetre.sendButton, SIGNAL(clicked()),hello,SLOT(SendHelloBCast()));
  return app.exec();
}

