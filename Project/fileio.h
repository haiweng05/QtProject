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

    // 各类数据通过哈希表转换
    QHash<QString, int> nameTint;
    QHash<int, QPair<int, int>> intTpos;
    QHash<int,QString> intTname;

    std::vector<std::vector<int>> TypePos; // 第一个索引对应类型，分别为StudyPos，FoodPos，ActivityPos，RestPos，ExercisePos
    std::vector<std::vector<Event>> events;

    // 读入地图上的可选节点
    void getNodes(const QString& name);

    // 读入默认事件池
    void getActivities(const QString& name);

    // 初始化节点和事件两个文件,用于设置中的清楚本地记录
    void initUserInfo(int type = 0);

    // 保存一条用户信息至特定文件
    void saveUserInfo(QString idx,QString filename = "../Project/UserInfo.json",int type = 0,QString message = "");

    // 从JSON文件读取一条用户信息
    QString readUserInfo(QString idx,QString filename = "../Project/UserInfo.json",int type = 0);
};

#endif // FILEIO_H
