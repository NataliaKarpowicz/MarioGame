#ifndef CEGLAGRAFIKA_H
#define CEGLAGRAFIKA_H

#include "przeszkodagrafika.h"
#include "cegla.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

/** \brief Klasa CeglaGrafika
*
* Jej glownym zadaniem jest rysowanie cegly na scenie.
*/
class CeglaGrafika :public PrzeszkodaGrafika, public QGraphicsPixmapItem
{
public:
    /**
    * \brief Konstruktor klasy CeglaGrafika
    * Jest w nim zadeklarowana ścieżka do pliku graficznego w formacie .png
    */
    CeglaGrafika(QGraphicsItem *parent=nullptr);
    /**
    * \brief Metoda rysuj
    * Ustawia pozycję obiektu graficznego i jego skale.
    */
    void rysuj();
    /**
    * \brief Metoda setLogic
    * Ustawia wskaźnik na klase Cegla, z której pobierane są dane na temat położenia, skali obiektu graficznego.
    */
    void setLogic(Cegla *cegla_1);
private:
    /**
    * \brief Wskaźnik na klase Cegla
    */
    Cegla* cegla;
};

#endif // CEGLAGRAFIKA_H
