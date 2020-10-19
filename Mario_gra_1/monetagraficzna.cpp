#include "monetagraficzna.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

MonetaGraficzna::MonetaGraficzna(QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/coin-1.png"));
}

void MonetaGraficzna::rysuj()
{
    if(moneta->zwroc_ktory_obraz()==0)
    {
        setPixmap(QPixmap(":/images/images/coin-0.png"));
    }
    else if(moneta->zwroc_ktory_obraz()==1)
    {
        setPixmap(QPixmap(":/images/images/coin-1.png"));
    }
    else if(moneta->zwroc_ktory_obraz()==2)
    {
        setPixmap(QPixmap(":/images/images/coin-2.png"));
    }
    else if(moneta->zwroc_ktory_obraz()==3)
    {
        setPixmap(QPixmap(":/images/images/coin-3.png"));
    }

    setScale(moneta->zwroc_skale());
    setPos(moneta->zwroc_wspolrzedne_x(), moneta->zwroc_wspolrzedne_y());
    update();
}

void MonetaGraficzna::setLogic(Moneta *moneta_1)
{
    moneta = moneta_1;
}
