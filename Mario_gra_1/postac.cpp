#include "postac.h"

Postac::Postac()
{

}

bool Postac::czy_spada(bool czy_spadaj1)
{
    czy_spadaj=czy_spadaj1;
    return czy_spadaj;
}

void Postac::korekcja_polozenia(int y_obiektu)
{
    y_pos = y_obiektu-wysokosc;
}

bool Postac::zwroc_czy_moze_isc_w_lewo()
{
    return czy_moze_isc_w_lewo;
}

bool Postac::zwroc_czy_moze_isc_w_prawo()
{
    return czy_moze_isc_w_prawo;
}

void Postac::korekcja_polozenia_prawo(int obiekt_x_pos)
{
    x_pos = obiekt_x_pos - szerokosc;
}

void Postac::korekcja_polozenia_lewo(int obiekt_x_pos, int obiekt_szerokosc)
{
    x_pos = obiekt_x_pos +obiekt_szerokosc;
}

