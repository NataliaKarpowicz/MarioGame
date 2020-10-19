#ifndef ZLYZOLW_H
#define ZLYZOLW_H

#include "wrog.h"

class ZlyZolw :public Wrog
{
public:
    ZlyZolw();
    void schowaj_do_skorupy();
    virtual void update(QList<Obiekt *> &lista_obiektow)=0;

    void idz();
    void umrzyj();
    void zmien_kierunek();
    void spadnij();
    void zmniejsz_predkosc();
    void zwieksz_predkosc();

    void zadaj_obrazenia();
    void update();
};

#endif // ZLYZOLW_H
