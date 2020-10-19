#ifndef WROG_H
#define WROG_H

#include "postac.h"


/** \brief Klasa Wrog
*
* Klasa, po której dziedziczą zły grzyb i zły żółw.
*/
class Wrog :public Postac
{
public:
    Wrog();

    //void idz();
    //void umrzyj();
    //void zmien_kierunek();
    //void spadnij();
    //void zmniejsz_predkosc();
    //void zwieksz_predkosc();

    //void zadaj_obrazenia();
    virtual void update()=0;
    virtual void update(QList<Obiekt *> &lista_obiektow)=0;

protected:
    /// kierunek ruchu obiektu
    bool kierunek;
};

#endif // WROG_H
