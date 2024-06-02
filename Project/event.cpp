#include "event.h"

Event::Event():date(2024,1,1),begin(QTime::currentTime()),end(QTime::currentTime()),dayidx(date.dayOfWeek()) {
    activate = 0;
    Sname = "默认名称";
    Sposition = "默认地点";
    iposition = 0; // 星期几
}

Event::Event(const Event& e){
    activate = e.activate;
    Sname = e.Sname;
    Sposition = e.Sposition;
    iposition = e.iposition;
    begin = e.begin;
    end = e.end;
    dayidx = e.dayidx;
}

Event::Event(QString name,QString Spos,int ipos,QTime beg,QTime ed):Sname(name),Sposition(Spos),iposition(ipos),begin(beg),end(ed){}

Event::Event(QString Info){
    QStringList list = Info.split(',');
    Sname = list[0];
    Sposition = list[1];
    iposition = list[2].toInt();
    begin = QTime::fromString(list[3],"hh:mm:ss");
    end = QTime::fromString(list[4],"hh:mm:ss");
}

QString Event::ToInfo(){
    QString res;
    res = this->Sname + ',' + this->Sposition + ',' + QString::number(this->iposition) + ',' + this->begin.toString() + ',' + this->end.toString() + ';';
    return res;
}
