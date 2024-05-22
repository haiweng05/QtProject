#ifndef NETWORK_H
#define NETWORK_H

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QDebug>
#include <QFile>
#include <QByteArray>

class NetWork
{
public:
    NetWork();
    static void GetHTML();

};

#endif // NETWORK_H
