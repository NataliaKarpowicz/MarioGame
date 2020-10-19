#ifndef ZLYGRZYBGRAFIKA_H
#define ZLYGRZYBGRAFIKA_H

#include "wroggrafika.h"
#include "zlygrzyb.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

/** \brief Klasa ZlyGrzybGrafika
*
* Rysuje złego grzyba.
*/
class ZlyGrzybGrafika :public WrogGrafika, public QGraphicsPixmapItem
{
public:
    /**
    * \brief Konstruktor klasy ChmurkaGrafika
    * Jest w nim zadeklarowana ścieżka do pliku graficznego w formacie .png
    */
    ZlyGrzybGrafika(QGraphicsItem *parent=nullptr);
    /**
    * \brief Metoda rysuj
    * Rysuje złego grzyba, ustawia odpowiedni obraz w zależności od wartości parametru który_obraz.
    */
    void rysuj();
    /**
    * \brief Metoda setLogic
    * Ustawia wskaźnik na klase ZlyGrzyb, z której pobierane są dane na temat położenia, skali obiektu graficznego.
    */
    void setLogic(ZlyGrzyb *zly_grzyb_1);
private:
    /// wskaźnik na klase ZlyGrzyb
    ZlyGrzyb *zly_grzyb;
};

#endif // ZLYGRZYBGRAFIKA_H
