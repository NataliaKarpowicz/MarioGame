#ifndef ZAMEKGRAFIKA_H
#define ZAMEKGRAFIKA_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include "rysunektlografika.h"
#include "zamek.h"

/** \brief Klasa ZamekGrafika
*
* Klasa zawierająca metody graficzne, rysuje wzgórze.
*/
class ZamekGrafika: public RysunekTloGrafika, public QGraphicsPixmapItem
{
public:
    ZamekGrafika(QGraphicsItem *parent=0);
    void rysuj();
private:
    Zamek*zamek;
};

#endif // ZAMEKGRAFIKA_H
