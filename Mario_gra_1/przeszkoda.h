#ifndef PRZESZKODA_H
#define PRZESZKODA_H

#include "obiekt.h"

/** \brief Klasa Przeszkoda
*
* Klasa, po której dziedziczą cegła, rura, przeszkoda znak zapytania i ziemia.
*/
class Przeszkoda :public Obiekt
{
public:
    Przeszkoda();
    virtual void update()=0;
};

#endif // PRZESZKODA_H
