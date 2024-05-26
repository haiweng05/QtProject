#include "network.h"

NetWork::NetWork(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &NetWork::replyFinished);
}

void NetWork::GetHTML(){
    QNetworkRequest request(QUrl("https://pkuhall.pku.edu.cn/index.htm"));
    manager->get(request);
}

void NetWork::replyFinished(QNetworkReply *response){
    // 假设你已经有了一个QByteArray对象，名为data
    QByteArray data;

    // 当请求结束后，我们就退出事件循环，并处理响应
    if (response->error() == QNetworkReply::NoError) {
        // 请求成功，读取响应
        data = response->readAll();
        qDebug() << data;
    } else {
        // 请求失败，输出错误信息
        qDebug() << response->errorString();
    }

    response->deleteLater();

    // 创建一个QFile对象
    QFile file("C:\\code\\C++\\Qt\\output.txt");

    // 打开文件，准备写入。如果文件打开失败，打印错误信息并返回
    if(!file.open(QIODevice::WriteOnly)) {
        qDebug() << file.errorString();
    }

    // 将数据写入文件
    file.write(data);

    // 关闭文件
    file.close();
}
