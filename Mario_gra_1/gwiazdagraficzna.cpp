#include "gwiazdagraficzna.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

GwiazdaGraficzna::GwiazdaGraficzna(QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/star.png"));
}

void GwiazdaGraficzna::rysuj()
{

}
