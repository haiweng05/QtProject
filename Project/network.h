#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QDebug>

class NetWork : public QObject
{
    Q_OBJECT
public:
    explicit NetWork(QObject *parent = 0);
    void GetHTML();

public slots:
    void replyFinished(QNetworkReply *response);

private:
    QNetworkAccessManager *manager;
};


#endif // NETWORK_H
