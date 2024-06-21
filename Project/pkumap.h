#ifndef PKUMAP_H
#define PKUMAP_H

#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include "event.h"
#include <vector>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QWheelEvent>
#include <unordered_map>

namespace Ui {
class PKUMap;
}

class PKUMap : public QWidget
{
    Q_OBJECT

public:
    explicit PKUMap(QWidget *parent = nullptr, std::vector<Event> events = {},QHash<int, QPair<int, int>> mp = {},QPair<int,int> ori = {2126,2752} );
    std::vector<Event> &GetEvent();
    ~PKUMap();
    void ShowPath(int idx);
    void HidePath(int idx);
    QPair<int,int> IdxToPos(int idx);
    void DeleteNode(int idx);
    void AddNode(int idx,int x,int y);
    void Update();

private slots:
    void Prev();
    void Next();
    void Showall();
    void Removeall();

private:
    Ui::PKUMap *ui;
    std::vector<Event> _events;
    std::vector<QGraphicsLineItem*> _edges;
    int current;
    QGraphicsScene* _scene;
    QHash<int, QPair<int, int>> _idx_to_pos;
    QPair<int,int> origin;
};

#endif // PKUMAP_H
