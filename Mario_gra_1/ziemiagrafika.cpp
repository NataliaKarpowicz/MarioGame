#include "ziemiagrafika.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

ZiemiaGrafika::ZiemiaGrafika(QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/wall.png"));
}

void ZiemiaGrafika::rysuj(QGraphicsScene *scene, int x_p, int y_p)
{
    ZiemiaGrafika* ziemia = new ZiemiaGrafika;
    scene->addItem(ziemia);
    ziemia->setScale(2);
    ziemia->setPos(x_p, y_p);
}

void ZiemiaGrafika::rysuj()
{

}
