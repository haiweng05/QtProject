#ifndef EVENT_H
#define EVENT_H

#include <QDate>
#include <QTime>

class Event
{
public:
    QString Sname;
    QString Sposition;
    int iposition;
    QDate date;
    QTime begin;
    QTime end;
    int dayidx; // 星期几
    bool activate;
public:
    Event();
    bool operator <(const Event&u)const{
        return begin<u.begin;
    }
    Event(const Event& e);
    Event(QString name,QString Spos,int ipos,QTime beg,QTime ed);
};

#endif // EVENT_H
