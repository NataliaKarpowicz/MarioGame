#ifndef ZLYZOLWGRAFIKA_H
#define ZLYZOLWGRAFIKA_H

#include "wroggrafika.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class ZlyZolwGrafika :public WrogGrafika, public QGraphicsPixmapItem
{
public:
    ZlyZolwGrafika(QGraphicsItem *parent=0);
    void rysuj();
};

#endif // ZLYZOLWGRAFIKA_H
