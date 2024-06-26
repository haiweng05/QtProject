#include "fileio.h"

FileIO::FileIO()
{

}

void FileIO::initUserInfo(int type){


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

void FileIO::saveUserInfo(QString idx,QString filename,int type,QString message) {
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

QString FileIO::readUserInfo(QString idx,QString filename ,int type) {
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

void FileIO::getClass(const QString& filename,std::vector<Event>* week){

    for(int i = 0; i < 8; ++ i){
        week[i] = {};
    }
    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false);

    QAxObject *work_books = excel.querySubObject("WorkBooks");
    work_books->dynamicCall("Open (const QString&)", filename);
    QAxObject *work_book = excel.querySubObject("ActiveWorkBook");
    QAxObject *work_sheets = work_book->querySubObject("Sheets");  //Sheets也可换用WorkSheets
    int sheet_count = work_sheets->property("Count").toInt();  //获取工作表数目
    if(sheet_count > 0)
    {
        QAxObject *work_sheet = work_book->querySubObject("Sheets(int)", 1);
        QAxObject *used_range = work_sheet->querySubObject("UsedRange");
        QAxObject *rows = used_range->querySubObject("Rows");
        int row_count = rows->property("Count").toInt();  //获取行数
        for(int i=2;i<=8;i++){
            int j=2;
            while(j<=13){
                QString txtt = work_sheet->querySubObject("Cells(int,int)",j,i)->dynamicCall("Value2()").toString(); //获取单元格内容
                if(txtt=="" ){
                    j++;
                    continue;
                }
                int leftbracket=0,rightbracket=0;
                int len=txtt.length();
                int f=0;
                Event t;

                for(int k=0;k<len;k++){
                    if(txtt[k]=='(') leftbracket=k;

                    if(txtt[k]==')') {
                        f=0;
                        rightbracket=k;
                        t.Sposition=txtt.mid(leftbracket+1,rightbracket-leftbracket-1);
                        for(auto u = nameTint.begin();u!=nameTint.end();u++){
        //                    qDebug() << u.key() << u.value();
                            if(t.Sposition.contains(u.key())){
                                t.Sposition=u.key();
                                t.iposition=u.value();
                                f=1;
                                break;
                            }
                        }
                        if(f==0){
                            leftbracket=0;
                            continue;
                        }
                        rightbracket=k;
                        break;
                    }
                }
                //qDebug()<<leftbracket<<' '<<rightbracket<<endl;

                t.Sname=txtt.left(leftbracket);
                t.begin=classstart[j-2];
                t.end=classend[j-2];
                t.dayidx=i-1;
                while(j<=13 and work_sheet->querySubObject("Cells(int,int)",j,i)->dynamicCall("Value2()").toString()==txtt){
                    t.end=classend[j-2];
                    j++;
                }
                week[i-2].push_back(t);
            }
        }


        work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
        excel.dynamicCall("Quit(void)");  //退出

        for(int i = 0; i < 7; ++ i){
            QString Info;
            for(auto u : week[i]){
                Info = Info + u.ToInfo();
            }
            qDebug() << Info;
            saveUserInfo(QString::number(i),"../Project/course.json",2,Info);
        }

        return ;
    }

}
