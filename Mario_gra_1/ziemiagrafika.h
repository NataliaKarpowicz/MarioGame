#ifndef ZIEMIAGRAFIKA_H
#define ZIEMIAGRAFIKA_H

#include "przeszkodagrafika.h"
#include "ziemia.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>


/** \brief Klasa ZiemiaGrafika
*
* Klasa zawierająca metody graficzne, rysuje ziemie.
*/
class ZiemiaGrafika :public PrzeszkodaGrafika, public QGraphicsPixmapItem
{
public:
    ZiemiaGrafika(QGraphicsItem *parent=0);
    void rysuj(QGraphicsScene*scene, int x_p, int y_p);
    void rysuj();
};

#endif // ZIEMIAGRAFIKA_H
