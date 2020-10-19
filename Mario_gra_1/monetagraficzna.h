#ifndef MONETAGRAFICZNA_H
#define MONETAGRAFICZNA_H

#include "dozebraniagrafika.h"
#include "moneta.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

/** \brief Klasa MonetaGraficzna
*
* Rysuje monete, na podstawie danych z klasy Moneta
*/
class MonetaGraficzna: public DoZebraniaGrafika, public QGraphicsPixmapItem
{
public:
    MonetaGraficzna(QGraphicsItem *parent=nullptr);
    /** \brief Rysuje monete
    */
    void rysuj();
    /** \brief Łączy klase MonetaGraficzna z klasą Moneta, skąd bierze parametry
    */
    void setLogic(Moneta *moneta_1);
private:
    ///wskaźnik na klase Moneta
    Moneta *moneta;
};

#endif // MONETAGRAFICZNA_H
