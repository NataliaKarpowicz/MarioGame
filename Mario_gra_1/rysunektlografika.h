#ifndef RYSUNEKTLOGRAFIKA_H
#define RYSUNEKTLOGRAFIKA_H

#include "obiektgrafika.h"

/** \brief Klasa PostacGrafika
*
* Klasa abstrakcyjna, zawiera metodę rysuj(). Dziedziczy po ObiektGrafika.
* Dzieciczą po niej ChmurkaGrafika i WzgorzeGrafika.
*/
class RysunekTloGrafika :public ObiektGrafika
{
public:
    RysunekTloGrafika();
    virtual void rysuj()=0;
};

#endif // RYSUNEKTLOGRAFIKA_H
