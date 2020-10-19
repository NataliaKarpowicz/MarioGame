#ifndef RURA_H
#define RURA_H

#include "przeszkoda.h"

class Rura :public Przeszkoda
{
public:
    Rura();
    Rura(int x_pos1, int y_pos1);
    void update();
};

#endif // RURA_H
