#include "network.h"

NetWork::NetWork() {}

void NetWork::GetHTML(){
    QNetworkAccessManager manager;
    QNetworkRequest request(QUrl("https://resource.pku.edu.cn/index.php?r=lecturepre%2Findex"));
    QNetworkReply *response = manager.get(request);

    // 创建事件循环等待请求结束并接收响应
    QEventLoop event;
    QObject::connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec(); // 开始事件循环

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
    return ;
}
