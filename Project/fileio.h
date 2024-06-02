#ifndef FILEIO_H
#define FILEIO_H

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QHash>
#include <QPair>
#include <QDebug>
#include <vector>
#include <event.h>
#include <QJsonDocument>
#include <QJsonObject>



class FileIO
{
public:
    FileIO();
    QHash<QString, int> nameTint;
    QHash<int, QPair<int, int>> intTpos;
    QHash<int,QString> intTname;
    // 第一个索引对应类型，分别为StudyPos，FoodPos，ActivityPos，RestPos，ExercisePos
    std::vector<std::vector<int>> TypePos;
    std::vector<std::vector<Event>> events;

    void getNodes(const QString& name);

    void getActivities(const QString& name);

    //
    void initUserInfo(int type = 0){


        // 打开一个文件并将 JSON 数据写入其中
        if(type == 0){
            // 创建一个 QJsonObject 对象
            QJsonObject jsonObject;
            for(auto u: nameTint){
                QString key = QString::number(u);
                jsonObject.insert(key,0);
            }

            // 创建一个 QJsonDocument 对象并设置 jsonObject 为其主要对象
            QJsonDocument jsonDoc;
            jsonDoc.setObject(jsonObject);

            QFile file("../Project/UserInfo.json");
            if (!file.open(QIODevice::WriteOnly)) {
                qWarning("Couldn't open file.");
                return ;
            }
            file.write(jsonDoc.toJson());
            file.close();
        }
        else if(type == 1){
            QJsonObject jsonObject;
            QJsonDocument jsonDoc;
            jsonDoc.setObject(jsonObject);

            QFile file("../Project/activities.json");
            if (!file.open(QIODevice::WriteOnly)) {
                qWarning("Couldn't open file.");
                return ;
            }
            file.write(jsonDoc.toJson());
            file.close();
        }
        else if(type == 2){
            QJsonObject jsonObject;
            for(int i = 0; i < 7; ++ i){
                QString key = QString::number(i);
                jsonObject.insert(key,"");
            }

            QJsonDocument jsonDoc;
            jsonDoc.setObject(jsonObject);

            QFile file("../Project/course.json");
            if (!file.open(QIODevice::WriteOnly)) {
                qWarning("Couldn't open file.");
                return ;
            }
            file.write(jsonDoc.toJson());

            file.close();
        }

    }

    void saveUserInfo(QString idx,QString filename = "../Project/UserInfo.json",int type = 0,QString message = "") {
        QFile file(filename);

        // 先以只读模式打开文件，读取现有的内容
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open file.");
            return;
        }

        QByteArray data = file.readAll();
        QJsonDocument doc(QJsonDocument::fromJson(data));
        QJsonObject userInfoObject = doc.object();

        if(type == 0){
            QString posStr = idx;

            int cur = userInfoObject[posStr].toInt();
            int to = cur + 1;

            // 修改你想要改变的部分
            userInfoObject[posStr] = to;

        }
        else if(type == 1){
            userInfoObject[idx] = message;
        }

        else if(type == 2){
            userInfoObject[idx] = message;
        }


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
    QString readUserInfo(QString idx,QString filename = "../Project/UserInfo.json",int type = 0) {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open file.");
            return 0;
        }

        QByteArray data = file.readAll();
        QJsonDocument doc(QJsonDocument::fromJson(data));
        QString result;

        if (doc.isObject()) {
            if(type == 0){
                QJsonObject userInfoObject = doc.object();
                result = QString::number(userInfoObject[idx].toInt());
            }
            else if(type == 1){
                QJsonObject userInfoObject = doc.object();
                QJsonValue value = userInfoObject.value(idx);
                if(value.isNull()){
                    result = "Nothing;";
                }
                else{
                    result = userInfoObject[idx].toString();
                }

            }

            else if(type == 2){
                QJsonObject userInfoObject = doc.object();
                result = userInfoObject[idx].toString();
            }
        }
        return result;
    }

};

#endif // FILEIO_H
