#include "zlygrzybgrafika.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

ZlyGrzybGrafika::ZlyGrzybGrafika(QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/enemy-0.png"));
}

void ZlyGrzybGrafika::rysuj()
{
    if(zly_grzyb->zwroc_ktory_obraz()==0)
    {
        setPixmap(QPixmap("C:/Users/natal/Documents/Automatyka i Robotyka/semestr 6/Programowanie w Języku C++/images/enemy-0.png"));
    }
    else if(zly_grzyb->zwroc_ktory_obraz()==1)
    {
        setPixmap(QPixmap("C:/Users/natal/Documents/Automatyka i Robotyka/semestr 6/Programowanie w Języku C++/images/enemy-1.png"));
    }
    setScale(zly_grzyb->zwroc_skale());
    setPos(zly_grzyb->zwroc_wspolrzedne_x(), zly_grzyb->zwroc_wspolrzedne_y());
    update();
}

void ZlyGrzybGrafika::setLogic(ZlyGrzyb *zly_grzyb_1)
{
    zly_grzyb = zly_grzyb_1;
}
