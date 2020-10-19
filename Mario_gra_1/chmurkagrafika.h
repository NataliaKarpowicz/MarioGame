#ifndef CHMURKAGRAFIKA_H
#define CHMURKAGRAFIKA_H

#include "rysunektlografika.h"
#include "chmurka.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

/** \brief Klasa CeglaGrafika
*
* Rysuje chmurki
*/
class ChmurkaGrafika :public RysunekTloGrafika, public QGraphicsPixmapItem
{
public:
    /**
    * \brief Konstruktor klasy ChmurkaGrafika
    * Jest w nim zadeklarowana ścieżka do pliku graficznego w formacie .png
    */
    ChmurkaGrafika(QGraphicsItem *parent=nullptr);
    /**
    * \brief Metoda rysuj
    * Zawiera pętle, która nadaje chmurkom losowe położenia i umieszcza je na scenie.
    */
    void rysuj(QGraphicsScene*scene);
    /**
    * \brief Metoda rysuj
    * Ustawia pozycję obiektu graficznego i jego skale.
    */
    void rysuj();
    /**
    * \brief Metoda setLogic
    * Ustawia wskaźnik na klase Cmurka, z której pobierane są dane na temat położenia, skali obiektu graficznego.
    */
    void setLogic(Chmurka *chmurka_1);
private:
    /**
    * \brief Wskaźnik na klase Chmurka
    */
    Chmurka *chmurka;
};

#endif // CHMURKAGRAFIKA_H
