#include "pkumap.h"
#include "ui_pkumap.h"
#include <QDebug>

class WheelEventFilter : public QObject
{
protected:
    bool eventFilter(QObject *obj, QEvent *event) override
    {
        if (event->type() == QEvent::Wheel)
        {
            QWheelEvent *wheelEvent = static_cast<QWheelEvent*>(event);
            QGraphicsView *view = qobject_cast<QGraphicsView*>(obj);
            QPoint angle = wheelEvent->angleDelta() / 8;
            int numDegrees = angle.y();
            if(numDegrees > 0)
            {
                // Zoom in
                view->scale(1.11111, 1.11111);
            }
            else
            {
                // Zooming out
                view->scale(0.9, 0.9);
            }
            return true;
        }
        else
        {
            // standard event processing
            return QObject::eventFilter(obj, event);
        }
    }
};


class ArrowLine : public QGraphicsLineItem
{
public:
    ArrowLine(int x1, int y1, int x2, int y2)
        : QGraphicsLineItem(x1, y1, x2, y2)
    {
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
    {
        // 设置线段样式
        QPen pen = this->pen();
        pen.setWidth(5);
        pen.setStyle(Qt::DashLine);
        pen.setColor(Qt::red);
        painter->setPen(pen);

        // 绘制线段
        QLineF line = this->line();
        painter->drawLine(line);

        // 计算箭头的位置和角度
        double angle = std::atan2(-line.dy(), line.dx());
        qreal arrowSize = pen.width() * 1.5;  // 箭头的大小与线条宽度成比例
        QPointF arrowPoint = line.p2(); // 箭头的顶点
        QPointF arrowP1 = arrowPoint - QPointF(sin(angle + M_PI / 3) * arrowSize, cos(angle + M_PI / 3) * arrowSize);
        QPointF arrowP2 = arrowPoint - QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize, cos(angle + M_PI - M_PI / 3) * arrowSize);

        // 绘制箭头
        painter->setBrush(pen.color()); // 设置箭头颜色
        painter->drawPolygon(QPolygonF() << arrowPoint << arrowP1 << arrowP2 << arrowPoint);
    }
};



PKUMap::PKUMap(QWidget *parent, std::vector<Event> events,QHash<int, QPair<int, int>> mp,QPair<int,int> ori)
    : QMainWindow(parent)
    , ui(new Ui::PKUMap)
    , _events(events)
    , current(0)
    , _idx_to_pos(mp)
    , origin(ori)
{
    for(Event e: _events){
        qDebug() << e.iposition << e.Sposition;
    }
    // 一天内有n个事件,那么就有n + 1个节点存在,形成一个环路,共有n + 1条边
    _edges.resize(_events.size() + 1,0);
    // 链接ui中的元件与信号槽
    ui->setupUi(this);
    connect(ui->_prev, &QPushButton::clicked, this, &PKUMap::Prev);
    connect(ui->_next, &QPushButton::clicked, this, &PKUMap::Next);
    connect(ui->_showall, &QPushButton::clicked, this, &PKUMap::Showall);
    connect(ui->_removeall,&QPushButton::clicked,this,&PKUMap::Removeall);


    // 处理图像的部分

    // 创建一个QGraphicsScene对象
    _scene = new QGraphicsScene(this);

    WheelEventFilter *filter = new WheelEventFilter();
    ui->_graph->installEventFilter(filter);

    // 使用QPixmap加载图片
    QPixmap pixmap("../Project/map.jpg");


    // 将图片添加到QGraphicsScene中
    _scene->addPixmap(pixmap);

    // 将QGraphicsScene设置到QGraphicsView中
    ui->_graph->setScene(_scene);

    // 设置渲染提示，使得图片在缩放时不会失真
    ui->_graph->setRenderHint(QPainter::SmoothPixmapTransform);

    // 设置滚动条，使得你可以查看图片的不同部分
    ui->_graph->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->_graph->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    // 设置交互，使得你可以通过鼠标滚轮来缩放图片
    ui->_graph->setInteractive(true);
    ui->_graph->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->_graph->setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing);
    ui->_graph->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->_graph->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    ui->_graph->setResizeAnchor(QGraphicsView::AnchorUnderMouse);

    // 导入默认节点

    Update();
}

QPair<int,int> PKUMap::IdxToPos(int idx){
    return _idx_to_pos.operator [](idx);
}

void PKUMap::DeleteNode(int idx){
//    _idx_to_pos.erase(idx);
}

void PKUMap::AddNode(int idx,int x,int y){
//    _idx_to_pos[idx] = {x,y};
}
PKUMap::~PKUMap()
{
    delete ui;
}

std::vector<Event> &PKUMap::GetEvent()
{
    return _events;
}

void PKUMap::HidePath(int idx) {
    qDebug() << "Hide "<< idx;
    if(_edges[idx] != NULL){
        _scene->removeItem((QGraphicsItem*)(_edges[idx]));
        _edges[idx] = NULL;

    }
}
void PKUMap::ShowPath(int idx) {
    if(GetEvent().size() == 0){return;}

    qDebug() << "Show " << idx;
    if(idx == 0){
        int to = GetEvent()[idx].iposition;
        ArrowLine* line = new ArrowLine(origin.first,origin.second,IdxToPos(to).first,IdxToPos(to).second);
        _scene->addItem(line);

        _edges[idx] = line;
    }

    else if(idx == int(GetEvent().size())){
        int from = GetEvent()[idx - 1].iposition;
        ArrowLine* line = new ArrowLine(IdxToPos(from).first,IdxToPos(from).second,origin.first,origin.second);
        _scene->addItem(line);

        _edges[idx] = line;
    }

    else{
        int from = GetEvent()[idx - 1].iposition;
        int to = GetEvent()[idx].iposition;

        ArrowLine* line = new ArrowLine(IdxToPos(from).first, IdxToPos(from).second, IdxToPos(to).first, IdxToPos(to).second);
        _scene->addItem(line);

        _edges[idx] = line;
    }
}
void PKUMap::Prev()
{
    if (current <= 0) {
        return;
    }
    current --;
    HidePath(current);
    if(current != 0 && _edges[current - 1] == NULL){
        ShowPath(current - 1);
    }
    Update();
}

void PKUMap::Next()
{

    if (current == int(GetEvent().size()) + 1) {
        return;
    }
    if(current != 0){
          HidePath(current - 1);
    }
    ShowPath(current);
    current ++;
    Update();
}

void PKUMap::Showall()
{
    qDebug() << GetEvent().size();

    for (int i = 0; i <= int(GetEvent().size()); ++i) {
        HidePath(i);
    }
    for (int i = 0; i <= int(GetEvent().size()); ++i) {
        if(i)
        qDebug() << GetEvent()[i - 1].iposition;
        ShowPath(i);
    }
    current = GetEvent().size() + 1;
    Update();
}
void PKUMap::Removeall(){
    for(int i = 0; i <= int(GetEvent().size()); ++ i){
        HidePath(i);
    }
    current = 0;
    Update();
}

void PKUMap::Update(){
    if(GetEvent().size() == 0){
        QString cur = "当前没有任何事件!请先点击任意一天进行规划!";
        ui->_label->setText(cur);
        return;
    }
    QString cur = "当前第";
    cur += QString::number(current);
    cur += "步，共";
    cur += QString::number(int(GetEvent().size()) + 1);
    cur += "步";
    ui->_label->setText(cur);
}
