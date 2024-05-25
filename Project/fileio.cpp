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
    TypePos.resize(5,{});
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList row = line.split(',');

        cnt ++;
        QString word = row[0];
        qDebug() << cnt;
        qDebug() << word;
        if(word == "未湖"){
            word = "未名湖";
        }
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
