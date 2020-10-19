#include "rura.h"

Rura::Rura()
{
    x_pos = 0;
    y_pos = 740;
    skala = 2;
    wysokosc = skala*32;
    szerokosc = skala*32;
}

Rura::Rura(int x_pos1, int y_pos1)
{
    x_pos = x_pos1;
    y_pos = y_pos1;
}

void Rura::update()
{

}
