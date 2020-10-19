#include "zamekgrafika.h"

ZamekGrafika::ZamekGrafika(QGraphicsItem *parent) :QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/castle.png"));
}

void ZamekGrafika::rysuj()
{
    Zamek*zamek = new Zamek;
    setScale(zamek->zwroc_skale());
    setPos(zamek->zwroc_wspolrzedne_x(), zamek->zwroc_wspolrzedne_y());
}
