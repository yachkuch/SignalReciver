#include "network.h"
#include <QMessageBox>
#include <QNetworkDatagram>
network::network(dataBase *db, QObject *parent)
    : QObject{parent}
{
    this->db = db;
    soket = new QUdpSocket(this);
    soket->bind(QHostAddress::LocalHost,(quint16) port);
    soket->open(QIODevice::ReadOnly);
    if (soket->isOpen()){
        connect(soket,SIGNAL(readyRead()),this,SLOT(read()));

    } else {
        QMessageBox MB;
        MB.setText("Сокет не был открыт");
        MB.exec();
    }
}

void network::read()
{
    while (soket->hasPendingDatagrams()) {
     QNetworkDatagram datagram = soket->receiveDatagram();
     QByteArray bite(datagram.data());
     union hranil{
         __int16  a[4096];
         char buf [8196];
     };
     hranil b;
     memcpy(&b.buf,bite.data(),8192);
     db->setInformation(b.a);
     emit(update1());
    }
}
