#include "grzybekgraficzny.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

GrzybekGraficzny::GrzybekGraficzny(QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/mushroom-red.png"));
}

void GrzybekGraficzny::rysuj()
{

}
