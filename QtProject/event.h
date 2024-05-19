#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <QDate>
#include <QTime>

class Event
{
private:
    std::wstring Sname;
    std::wstring Sposition;
    int iposition;
    QDate date;
    QTime begin;
    QTime end;
    int dayidx; // 星期几
    bool activate;
public:
    Event();
};

#endif // EVENT_H
