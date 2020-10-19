#include "cegla.h"

Cegla::Cegla()
{
    x_pos = 0;
    y_pos = 0;
    skala = 2;
    wysokosc = 16*skala;
    szerokosc = 16*skala;
    nazwa = "cegla";
}

Cegla::Cegla(int x_pos_1, int y_pos_1)
{
    x_pos = x_pos_1;
    y_pos = y_pos_1;
    skala = 2;
    wysokosc = 16*skala;
    szerokosc = 16*skala;
    nazwa = "cegla";
}

void Cegla::update()
{

}
