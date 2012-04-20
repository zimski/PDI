/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created: Sun Apr 1 22:31:31 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QListView *listeStation;
    QPushButton *sendButton;
    QGroupBox *groupBox_2;
    QLineEdit *ipStation;
    QPushButton *addStation;
    QGroupBox *groupBox_3;
    QListView *ipList;
    QLineEdit *ipLocal;
    QLabel *label_2;
    QPushButton *appliquerIpLocale;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(607, 408);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 551, 171));
        listeStation = new QListView(groupBox);
        listeStation->setObjectName(QString::fromUtf8("listeStation"));
        listeStation->setGeometry(QRect(10, 20, 331, 101));
        sendButton = new QPushButton(groupBox);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(20, 130, 80, 26));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(350, 20, 191, 101));
        ipStation = new QLineEdit(groupBox_2);
        ipStation->setObjectName(QString::fromUtf8("ipStation"));
        ipStation->setGeometry(QRect(10, 30, 161, 25));
        addStation = new QPushButton(groupBox_2);
        addStation->setObjectName(QString::fromUtf8("addStation"));
        addStation->setGeometry(QRect(10, 60, 161, 26));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 200, 311, 161));
        ipList = new QListView(groupBox_3);
        ipList->setObjectName(QString::fromUtf8("ipList"));
        ipList->setGeometry(QRect(10, 20, 291, 71));
        ipLocal = new QLineEdit(groupBox_3);
        ipLocal->setObjectName(QString::fromUtf8("ipLocal"));
        ipLocal->setGeometry(QRect(10, 120, 201, 25));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 100, 57, 15));
        appliquerIpLocale = new QPushButton(groupBox_3);
        appliquerIpLocale->setObjectName(QString::fromUtf8("appliquerIpLocale"));
        appliquerIpLocale->setGeometry(QRect(220, 120, 80, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 607, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Stations connect\303\251es:", 0, QApplication::UnicodeUTF8));
        sendButton->setText(QApplication::translate("MainWindow", "Send Hello", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Ajout de Station par Ip:", 0, QApplication::UnicodeUTF8));
        addStation->setText(QApplication::translate("MainWindow", "Ajouter", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "IPs Disponibles:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "IP utilis\303\251e", 0, QApplication::UnicodeUTF8));
        appliquerIpLocale->setText(QApplication::translate("MainWindow", "Appliquer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
