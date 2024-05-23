#ifndef FILEIO_H
#define FILEIO_H

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QHash>
#include <QPair>
#include <QDebug>
#include <vector>

#include <QJsonDocument>
#include <QJsonObject>



class FileIO
{
public:
    FileIO();
    QHash<QString, int> nameTint;
    QHash<int, QPair<int, int>> intTpos;
    std::vector<int>  FoodPos;
    std::vector<int> StudyPos;

    void getNodes(const QString& name);

    //
    void initUserInfo(){

    }

    void saveUserInfo(int pos) {
        QFile file("../Project/UserInfo.json");

        // 先以只读模式打开文件，读取现有的内容
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open file.");
            return;
        }

        QByteArray data = file.readAll();
        QJsonDocument doc(QJsonDocument::fromJson(data));
        QJsonObject userInfoObject = doc.object();

        QString posStr = QString::number(pos);

        int cur = userInfoObject[posStr].toInt();
        int to = cur + 1;
//        qDebug() << cur << to;

        // 修改你想要改变的部分
        userInfoObject[posStr] = to;

        // 关闭文件，准备以写入模式重新打开
        file.close();

        // 以写入模式打开文件，将修改后的内容写回文件
        if (!file.open(QIODevice::WriteOnly)) {
            qWarning("Couldn't open file.");
            return;
        }

        doc.setObject(userInfoObject);
        file.write(doc.toJson());
    }



    // 从JSON文件读取用户信息
    int readUserInfo(int pos) {
        QFile file("../Project/UserInfo.json");
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open file.");
            return 0;
        }

        int num = 0;
        QByteArray data = file.readAll();
        QJsonDocument doc(QJsonDocument::fromJson(data));

        if (doc.isObject()) {
            QString posStr = QString::number(pos);
            QJsonObject userInfoObject = doc.object();
            num = userInfoObject[posStr].toInt();
        }
        return num;
    }

};

#endif // FILEIO_H
