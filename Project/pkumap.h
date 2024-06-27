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
#include <QDebug>

namespace Ui {
class PKUMap;
}

class PKUMap : public QWidget
{
    Q_OBJECT

public:
    explicit PKUMap(QWidget *parent = nullptr, std::vector<Event> events = {},QHash<int, QPair<int, int>> mp = {},QPair<int,int> ori = {2126,2752} );
    ~PKUMap();

    // 绘图需要,将节点序号转换为节点坐标
    QPair<int,int> IdxToPos(int idx);
    std::vector<Event> &GetEvent();

private slots:
    // 对应于四个按钮
    void Prev(); //上一步
    void Next(); // 下一步
    void Showall(); // 显示全部
    void Removeall(); // 移除全部

private:
    Ui::PKUMap *ui;
    QGraphicsScene* _scene;

    // 显示的路径信息
    std::vector<Event> _events;
    // 已经绘制的边,用于之后删除
    std::vector<QGraphicsLineItem*> _edges;
    // 当前的序号
    int current;

    QHash<int, QPair<int, int>> _idx_to_pos;
    // 路径起点
    QPair<int,int> origin;

    // 内部接口
    void ShowPath(int idx);
    void HidePath(int idx);
    void Update();
};

#endif // PKUMAP_H
