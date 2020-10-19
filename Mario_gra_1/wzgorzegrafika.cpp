#include "wzgorzegrafika.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

WzgorzeGrafika::WzgorzeGrafika(QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/hill-big.png"));
}

void WzgorzeGrafika::rysuj(QGraphicsScene*scene)
{
    int x_pos = 0;
    int y_pos = 0;
    int skala = 1;
    int odl = 0;
    int j = int(scene->width()/50);
    for (int i=0; i<j; i++)
    {
        WzgorzeGrafika* wzgorze = new WzgorzeGrafika;
        scene->addItem(wzgorze);
        skala = rand()%4+1;
        wzgorze->setScale(skala);
        int x_pos_2 = x_pos + odl;
        y_pos = 804 - wzgorze->pixmap().height()*skala;
        wzgorze->setPos(x_pos_2, y_pos);
        odl = rand()%100+200;
        x_pos = int(wzgorze->x());
    }
}

void WzgorzeGrafika::rysuj()
{

}

