#ifndef WZGORZEGRAFIKA_H
#define WZGORZEGRAFIKA_H

#include "rysunektlografika.h"
#include "wzgorze.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

/** \brief Klasa WzgorzeGrafika
*
* Klasa zawierająca metody graficzne, rysuje wzgórze.
*/
class WzgorzeGrafika :public RysunekTloGrafika, public QGraphicsPixmapItem
{
public:
    WzgorzeGrafika(QGraphicsItem *parent=0);
    void rysuj(QGraphicsScene*scene);
    void rysuj();
};

#endif // WZGORZEGRAFIKA_H
