#ifndef PRZESZKODAGRAFIKA_H
#define PRZESZKODAGRAFIKA_H

#include "obiektgrafika.h"

/** \brief Klasa PostacGrafika
*
* Klasa abstrakcyjna, zawiera metodę rysuj(). Dziedziczy po ObiektGrafika
*/
class PrzeszkodaGrafika :public ObiektGrafika
{
public:
    PrzeszkodaGrafika();
    virtual void rysuj()=0;
};

#endif // PRZESZKODAGRAFIKA_H
