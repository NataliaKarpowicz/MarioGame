#ifndef WZGORZE_H
#define WZGORZE_H

#include "rysunektlo.h"
#include "wzgorzegrafika.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsScene>

/** \brief Klasa Wzgorze
*
* Zawiera parametry i metody logiczne wzgórza
*/
class Wzgorze :public RysunekTlo
{
public:
    Wzgorze();
    void rysuj(QGraphicsScene *scene);
    void update();
};

#endif // WZGORZE_H
