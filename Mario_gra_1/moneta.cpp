#include "moneta.h"

Moneta::Moneta()
{
    skala = 2;
    wysokosc = 16*skala;
    szerokosc = 16*skala;
    x_pos = 0;
    y_pos = 0;
    ktory_obraz=1;
}

Moneta::Moneta(int x_pos_1, int y_pos_1)
{
    x_pos = x_pos_1;
    y_pos = y_pos_1;
    skala = 2;
    wysokosc = 16*skala;
    szerokosc = 16*skala;
    ktory_obraz=1;
}

void Moneta::update()
{
    if(ktory_obraz<4)
    {
        ktory_obraz++;
    }
    else
    {
        ktory_obraz=0;
    }
}

int Moneta::zwroc_ktory_obraz()
{
    return ktory_obraz;
}

