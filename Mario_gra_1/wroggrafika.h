#ifndef WROGGRAFIKA_H
#define WROGGRAFIKA_H

#include "postacgrafika.h"

/** \brief Klasa PostacGrafika
*
* Klasa dziedzicząca po PostactGrafika. Dziedziczą po niej ZlyGrzybGrafika i ZyZolwGrafika.
*/
class WrogGrafika :public PostacGrafika
{
public:
    WrogGrafika();
    virtual void rysuj()=0;
};

#endif // WROGGRAFIKA_H
