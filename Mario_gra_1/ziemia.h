#ifndef ZIEMIA_H
#define ZIEMIA_H

#include "przeszkoda.h"
#include "ziemiagrafika.h"

#include <QGraphicsScene>
#include <QObject>

/** \brief Klasa Ziemia
*
* Zawiera parametry i metody logiczne ziemi
*/
class Ziemia :public Przeszkoda
{
public:
    Ziemia();
    /** \brief Tworzy podłoże z ziemi.
    */
    void tworz_podloze(QGraphicsScene *scene);
    void update();
    Ziemia(int x_pos1, int y_pos1);
};

#endif // ZIEMIA_H
