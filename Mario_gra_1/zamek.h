#ifndef ZAMEK_H
#define ZAMEK_H

#include "rysunektlo.h"

/** \brief Klasa Wzgorze
*
* Zawiera parametry i metody logiczne zamku
*/
class Zamek: public RysunekTlo
{
public:
    Zamek();
    void update();
};

#endif // ZAMEK_H
