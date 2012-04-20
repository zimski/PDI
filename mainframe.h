#ifndef _MAINFRAME_H_
#define _MAINFRAME_H_
#include <QStandardItemModel>
#include <QStandardItem>
#include "ui_interface.h"
#include "HelloModule.h"
#include "manageStation.h"

class MainFrame : public QMainWindow , private Ui::MainWindow
{
  Q_OBJECT

  
public:
  ManageStation * manageS;
  HelloModule * hello;
  QList<QHostAddress> listeInterface;
  QStandardItemModel * model;
  MainFrame(QWidget *parent = 0);
  ~MainFrame();
  void showStationInfo(int index);
 
public slots:
  void SendBCast();
  void updateList();
  void setLocalIp();
  void setInterface(QModelIndex index);
  void addStationIp();
};



#endif /* _MAINFRAME_H_ */
