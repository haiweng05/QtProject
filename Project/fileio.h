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
#include <QAxObject>
#include <QApplication>



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

    // 课程时间的数组
    QTime classstart[13]{{8,0,0},{9,0,0},{10,10,0},{11,10,0},{13,0,0},{14,0,0},{15,10,0},{16,10,0},{17,10,0},{18,40,0},{19,40,0},{20,40,0}};
    QTime classend[13]{{8,50,0},{9,50,0},{11,0,0},{12,0,0},{13,50,0},{14,50,0},{16,0,0},{17,0,0},{18,0,0},{19,30,0},{20,30,0},{21,30,0}};

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

    void getClass(const QString& filename,std::vector<Event>* week);
};

#endif // FILEIO_H
