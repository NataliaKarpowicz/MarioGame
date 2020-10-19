#ifndef RURAGRAFIKA_H
#define RURAGRAFIKA_H

#include "przeszkodagrafika.h"
#include "rura.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>

class RuraGrafika :public PrzeszkodaGrafika, public QGraphicsPixmapItem
{
public:
    RuraGrafika(QGraphicsItem *parent=0);
    void rysuj(Rura* rura);
    void rysuj();
private:
    Rura *rura;
};

#endif // RURAGRAFIKA_H
