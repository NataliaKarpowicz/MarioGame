#include "ceglagrafika.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

CeglaGrafika::CeglaGrafika(QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/block.png"));
}

void CeglaGrafika::rysuj()
{
    //CeglaGrafika* cegla = new CeglaGrafika;
    //scene->addItem(cegla);
    setScale(cegla->zwroc_skale());
    setPos(cegla->zwroc_wspolrzedne_x(), cegla->zwroc_wspolrzedne_y());
}

void CeglaGrafika::setLogic(Cegla *cegla_1)
{
    cegla = cegla_1;
}

