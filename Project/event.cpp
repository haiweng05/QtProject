#include "event.h"

Event::Event():date(2024,1,1),begin(QTime::currentTime()),end(QTime::currentTime()),dayidx(date.dayOfWeek()) {
    activate = 0;
    Sname = "默认名称";
    Sposition = "默认地点";
    iposition = 0; // 星期几
}
