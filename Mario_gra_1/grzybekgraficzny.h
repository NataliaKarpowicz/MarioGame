#ifndef GRZYBEKGRAFICZNY_H
#define GRZYBEKGRAFICZNY_H

#include "dozebraniagrafika.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class GrzybekGraficzny: public DoZebraniaGrafika, public QGraphicsPixmapItem
{
public:
    GrzybekGraficzny(QGraphicsItem *parent=0);
    void rysuj();
};

#endif // GRZYBEKGRAFICZNY_H
