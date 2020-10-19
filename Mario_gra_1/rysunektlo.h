#ifndef RYSUNEKTLO_H
#define RYSUNEKTLO_H

#include "obiekt.h"

/** \brief Klasa RysunekTlo
*
* Klasa, po której dziedziczą chmurki, wzgórza.
*/
class RysunekTlo :public Obiekt
{
public:
    RysunekTlo();
    virtual void update()=0;
};

#endif // RYSUNEKTLO_H
