#include "zlyzolwgrafika.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

ZlyZolwGrafika::ZlyZolwGrafika(QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/turtle-walk-0.png"));
}

void ZlyZolwGrafika::rysuj()
{

}
