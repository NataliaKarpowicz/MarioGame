#ifndef DOZEBRANIAGRAFIKA_H
#define DOZEBRANIAGRAFIKA_H

#include "obiektgrafika.h"

/** \brief Klasa DoZebraniaGrafika
*
* Klasa abstrakcyjna, zawiera obiekty graficzne, które po kontakcie z ludzikiem Mario znikają i wywołują pewną funkcję.
*/
class DoZebraniaGrafika: public ObiektGrafika
{
public:
    /** \brief Konstruktor klasy DoZebraniaGrafika
    */
    DoZebraniaGrafika();
    virtual void rysuj()=0;
};

#endif // DOZEBRANIAGRAFIKA_H
