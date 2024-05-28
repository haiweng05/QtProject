#include "fileio.h"

FileIO::FileIO()
{

}

void FileIO::getNodes(const QString& name){
    QFile file(name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    in.setCodec("UTF-8"); // 设置编码为UTF-8

    int cnt = 0;
    TypePos.resize(8,{});
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList row = line.split(',');

        cnt ++;
        QString word = row[0];
        qDebug() << cnt;
        qDebug() << word;
        nameTint[word] = cnt;
        intTname[cnt] = word;


        int x = 0, y = 0;
        if(row.size() > 1 && row[1] != "") x = row[1].toInt();
        qDebug() << x;
        if(row.size() > 2 && row[2] != "") y = row[2].toInt();
        qDebug() << y;
        if(x && y)
        intTpos[cnt] = qMakePair(x, y);

        int type;
        if(row.size() > 3 && row[3] != "") type = row[3].toInt();
        // 将其从1-idx转化为0-idx
        type --;

        TypePos[type].push_back(cnt);
    }
    for(auto ele:TypePos[1]){
        qDebug() << ele;
    }
}

void FileIO::getActivities(const QString& name){
    QFile file(name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    in.setCodec("UTF-8"); // 设置编码为UTF-8

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList row = line.split(',');

        events.resize(8,{});

        QString name = row[0];
        QString pos = row[1];
        int ipos = nameTint[pos];
        int type = row[2].toInt();

        int dates = row[3].toInt();

        QTime beg = QTime::fromString("00:00:05","hh:mm:ss");

        QTime end = QTime::fromString("00:00:05","hh:mm:ss");
        if(type == 1){
            beg = QTime::fromString(row[4],"hh:mm:ss");
            end = QTime::fromString(row[5],"hh:mm:ss");
        }

        Event eve(name,pos,ipos,beg,end);
        for(int i = 1, bi = 1; i <= 7; ++ i, bi <<= 1){
            if(bi & dates){
                FileIO::events[i].push_back(eve);
            }
        }
    }
    for(int i = 1; i <= 7; ++ i){
        for(auto ele: events[i]){
            qDebug() << ele.Sname << ele.iposition;
        }
    }
}
