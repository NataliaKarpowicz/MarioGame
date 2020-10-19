#include "ruragrafika.h"

RuraGrafika::RuraGrafika(QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/pipe-small.png"));
}

void RuraGrafika::rysuj(Rura*rura1)
{
    setScale(rura1->zwroc_skale());
    setPos(rura1->zwroc_wspolrzedne_x(), rura1->zwroc_wspolrzedne_y());
}

void RuraGrafika::rysuj()
{
    rura = new Rura(3650,740);
    setScale(rura->zwroc_skale());
    setPos(rura->zwroc_wspolrzedne_x(), rura->zwroc_wspolrzedne_y());
}
