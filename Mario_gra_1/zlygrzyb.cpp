#include "zlygrzyb.h"

ZlyGrzyb::ZlyGrzyb()
{
    skala = 2;
    x_pos = 0;
    y_pos = 868;
    wysokosc = 16*skala;
    szerokosc = 16*skala;
    ktory_obraz = 0;
    kierunek = 0;
    czy_spadaj=0;
    szybkosc=10;
    predkosc_spadania=0;
}

ZlyGrzyb::ZlyGrzyb(int x_1, int y_1)
{
    skala = 2;
    x_pos = x_1;
    y_pos = y_1;
    wysokosc = 16*skala;
    szerokosc = 16*skala;
    ktory_obraz = 0;
    kierunek = 0;
    czy_spadaj=0;
    szybkosc=10;
    predkosc_spadania=0;
}

void ZlyGrzyb::umrzyj()
{

}

void ZlyGrzyb::idz_w_lewo()
{
    x_pos=x_pos-szybkosc;
}

void ZlyGrzyb::idz_w_prawo()
{
    x_pos=x_pos+szybkosc;
}

void ZlyGrzyb::spadnij()
{
    if(czy_spadaj==0)
    {
        predkosc_spadania=0;
    }
    else if(czy_spadaj==1 && predkosc_spadania<65)
    {
        predkosc_spadania=predkosc_spadania+4;
    }
    y_pos = y_pos+predkosc_spadania;
}

void ZlyGrzyb::zadaj_obrazenia()
{

}

int ZlyGrzyb::zmniejsz_predkosc(int ile)
{
    if(szybkosc>(ile+10))
    {
        szybkosc=szybkosc-ile;
    }
    return szybkosc;
}

int ZlyGrzyb::zwieksz_predkosc(int ile)
{
    if(szybkosc<(50-ile))
    {
        szybkosc=szybkosc+ile;
    }
    return szybkosc;
}

void ZlyGrzyb::update(QList<Obiekt *> &lista_obiektow)
{
    czy_spada(1);

    if(ktory_obraz<2)
    {
        ktory_obraz++;
    }
    else
    {
        ktory_obraz=0;
    }

    for (int j=0;j<lista_obiektow.size();j++){
        Obiekt* obj = lista_obiektow.at(j);

        if(zwroc_wspolrzedne_y()>=obj->zwroc_wspolrzedne_y()-zwroc_wysokosc())
        {
            if(zwroc_wspolrzedne_y()<=obj->zwroc_wspolrzedne_y()+obj->zwroc_wysokosc()-zwroc_wysokosc()-2)
            {
                if(zwroc_wspolrzedne_x()>obj->zwroc_wspolrzedne_x()-zwroc_szerokosc())
                {
                    if(zwroc_wspolrzedne_x()<obj->zwroc_wspolrzedne_x()+obj->zwroc_szerokosc())
                    {
                        czy_spada(0);
                        korekcja_polozenia(obj->zwroc_wspolrzedne_y());
                    }
                }
            }
        }

        if(zwroc_wspolrzedne_x()+zwroc_szerokosc()>=obj->zwroc_wspolrzedne_x())
        {
            if(zwroc_wspolrzedne_x()+zwroc_szerokosc()<obj->zwroc_wspolrzedne_x()+obj->zwroc_szerokosc()-2)
            {
                if(zwroc_wspolrzedne_y()+zwroc_wysokosc()>obj->zwroc_wspolrzedne_y()+3)
                {
                    if(zwroc_wspolrzedne_y()+zwroc_wysokosc()<=obj->zwroc_wspolrzedne_y()+obj->zwroc_wysokosc())
                    {
                        zmien_kierunek();
                        korekcja_polozenia_prawo(obj->zwroc_wspolrzedne_x());
                    }
                }
            }
        }

        if(zwroc_wspolrzedne_x()>obj->zwroc_wspolrzedne_x()+5)
        {
            if(zwroc_wspolrzedne_x()<=obj->zwroc_wspolrzedne_x()+obj->zwroc_szerokosc())
            {
                if(zwroc_wspolrzedne_y()+zwroc_wysokosc()>obj->zwroc_wspolrzedne_y()+3)
                {
                    if(zwroc_wspolrzedne_y()+zwroc_wysokosc()<=obj->zwroc_wspolrzedne_y()+obj->zwroc_wysokosc())
                    {
                        zmien_kierunek();
                        korekcja_polozenia_lewo(obj->zwroc_wspolrzedne_x(), obj->zwroc_szerokosc());
                    }
                }
            }
        }

    }

    if(kierunek==0)
    {
        idz_w_lewo();
    }
    else if(kierunek==1)
    {
        idz_w_prawo();
    }

}

int ZlyGrzyb::zwroc_ktory_obraz()
{
    return ktory_obraz;
}

void ZlyGrzyb::update()
{

}

bool ZlyGrzyb::zwroc_czy_spada()
{
    return czy_spadaj;
}

void ZlyGrzyb::zmien_kierunek()
{
    if(kierunek==0)
    {
        kierunek=1;
    }
    if(kierunek==1)
    {
        kierunek=0;
    }
}
