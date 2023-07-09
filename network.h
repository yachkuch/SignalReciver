#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>

#include <QUdpSocket>
#include "database.h"

class network : public QObject
{
    Q_OBJECT
public:
    explicit network(dataBase *db, QObject *parent = nullptr);
    QUdpSocket *soket;
    QByteArray data;
    dataBase *db;

    const int datagrammSize = 8192;
    const int port = 10002;

private slots:
    void read();

signals:
    void update1();

};

#endif // NETWORK_H
