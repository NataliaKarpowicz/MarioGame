#include "chmurkagrafika.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

ChmurkaGrafika::ChmurkaGrafika(QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/cloud-big.png"));
}

void ChmurkaGrafika::rysuj(QGraphicsScene*scene)
{
    int odl_chm=0;
    for(int i=50; i<scene->height()-200; i=i+140)
    {
        for (int j=10; j<scene->width()*5; j=j+450)
        {
        ChmurkaGrafika* chmurka_graf = new ChmurkaGrafika;
        scene->addItem(chmurka_graf);
        chmurka_graf->setScale(2);
        chmurka_graf->setPos(j+odl_chm, i);
        odl_chm = rand()%440+10;
        }
    }
}

void ChmurkaGrafika::rysuj()
{
    setScale(chmurka->zwroc_skale());
    setPos(chmurka->zwroc_wspolrzedne_x(), chmurka->zwroc_wspolrzedne_y());
}

void ChmurkaGrafika::setLogic(Chmurka *chmurka_1)
{
    chmurka = chmurka_1;
}
