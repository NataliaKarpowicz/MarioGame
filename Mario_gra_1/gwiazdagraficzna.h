#ifndef GWIAZDAGRAFICZNA_H
#define GWIAZDAGRAFICZNA_H

#include "dozebraniagrafika.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class GwiazdaGraficzna: public DoZebraniaGrafika, public QGraphicsPixmapItem
{
public:
    GwiazdaGraficzna(QGraphicsItem *parent=0);
    void rysuj();
};

#endif // GWIAZDAGRAFICZNA_H
