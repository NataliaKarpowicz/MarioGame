#ifndef DOZEBRANIA_H
#define DOZEBRANIA_H

#include "obiekt.h"

/** \brief Klasa DoZebrania
*
* Klasa abstrakcyjna, zawiera obiekty, które po kontakcie z ludzikiem Mario znikają i wywołują pewną funkcję.
*/
class DoZebrania: public Obiekt
{
public:
    /** \brief Konstruktor klasy DoZebrania
    */
    DoZebrania();
    virtual void update()=0;
};

#endif // DOZEBRANIA_H
