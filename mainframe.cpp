#include "mainframe.h"




MainFrame::MainFrame(QWidget * parent): QMainWindow(parent), Ui::MainWindow()
{
  setupUi(this);
  //      liste des adresse Ip
  QStringList items; 
  QStandardItemModel * modelIp;
   modelIp = new QStandardItemModel();

  foreach(QNetworkInterface interface, QNetworkInterface::allInterfaces())
    {
      if (interface.flags().testFlag(QNetworkInterface::IsRunning))
	foreach (QNetworkAddressEntry entry, interface.addressEntries()) 
	  {
	    if ( interface.hardwareAddress() != "00:00:00:00:00:00" &&     entry.ip().toString().contains("."))
	      {
		//items << interface.name() + entry.ip().toString(); 
		QStandardItem *itemIp;
		itemIp = new QStandardItem();
		itemIp->setData( QString("interface[%1] %2 ").arg(interface.name()).arg(entry.ip().toString()), Qt::DisplayRole );
		itemIp->setData( QImage("image/station.png"), Qt::DecorationRole );
		itemIp->setEditable( false );
		listeInterface.append(entry.ip());
		modelIp->appendRow( itemIp );
	      }
     }
}
ipList->setModel(modelIp);


  // =========================================

  hello = new HelloModule();
  manageS = new ManageStation( hello );
  model = new QStandardItemModel();
  
  listeStation->setModel( model);
  updateList();
  
  



  connect(sendButton,SIGNAL(clicked()),this,SLOT(SendBCast()));
  connect(hello,SIGNAL(getSomthing(QByteArray &)),manageS,SLOT(processMessage(QByteArray &))); // lien entre hello module et manage station
  connect(manageS,SIGNAL(updateListeEvent()),this, SLOT(updateList()));
  connect(appliquerIpLocale,SIGNAL(clicked()),this,SLOT(setLocalIp()));
  connect(ipList,SIGNAL(activated(QModelIndex)),this,SLOT(setInterface(QModelIndex)));
  connect(addStation,SIGNAL(clicked()),this,SLOT(addStationIp())); // ajout de station par IP
}

MainFrame::~MainFrame(){}


void MainFrame::SendBCast()
{
  hello->SendHelloBCast();
}
/*void MainFrame::showStationInfo(int index)// mise a jour de l affichage
{
  ip->setText( "sdsqd");//manageS.getStation(index).ip.toString());
  port->setText( QString(manageS->getStation(index).port));
  //etat.setText( manageS.getStation(index).etat);
}
*/
void MainFrame::updateList()
{
  model->clear();
  int nb = manageS->getNbStation();
  for (int i = 0; i < nb; ++i)
    {
      QStandardItem *item;
      item = new QStandardItem();
      item->setData( QString("Station %1 [%2] {port: %3} == %4 ").arg(i).arg(manageS->getStation(i).ip.toString()).arg(manageS->getStation(i).port).arg(manageS->getStation(i).etat), Qt::DisplayRole );
      item->setData( QImage("image/station.png"), Qt::DecorationRole );
      item->setEditable( false );
     
      model->appendRow( item );
  
    }
}
void MainFrame::setLocalIp()
{
  hello->setLocalIP(ipLocal->text());
}
void MainFrame::setInterface(QModelIndex index)
{
  
  ipLocal->setText(listeInterface.at(index.row()).toString());
  setLocalIp();
}
void MainFrame::addStationIp()
{
  //cout << " Ajout de station par IP" << endl;
  hello->SendHelloIP(ipStation->text());
}
