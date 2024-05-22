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

class PKUMap : public QMainWindow
{
    Q_OBJECT

public:
    explicit PKUMap(QWidget *parent = nullptr, std::vector<Event> events = {});
    std::vector<Event> &GetEvent();
    ~PKUMap();
    void ShowPath(int idx);
    void HidePath(int idx);
    std::pair<int,int> IdxToPos(int idx);
    void DeleteNode(int idx);
    void AddNode(int idx,int x,int y);

private slots:
    void Prev();
    void Next();
    void Showall();

private:
    Ui::PKUMap *ui;
    std::vector<Event> _events;
    std::vector<QGraphicsLineItem*> _edges;
    int current;
    QGraphicsScene* _scene;
    std::unordered_map<int,std::pair<int,int>> _idx_to_pos;
};

#endif // PKUMAP_H
