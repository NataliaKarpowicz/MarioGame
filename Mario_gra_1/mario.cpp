#include "mario.h"
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include <QPixmap>
#include <cmath>

Mario::Mario()
{
    zycia=3;
    szybkosc=10;
    skala=2;
    czy_ranny=0;
    x_pos=75;
    y_pos=600;
    wysokosc=16*skala;
    szerokosc=16*skala;
    wys_skoku=4*wysokosc;
    czy_skacz=0;

    czy_spadaj=0;
    zebrano_monete=0;
    czy_moze_isc_w_lewo=1;
    czy_moze_isc_w_prawo=1;
}

void Mario::update(QList<PostacGrafika *> &lista_obiektow_ruch_graf, QList<Obiekt *> &lista_obiektow)
{
    czy_spada(1);
    czy_moze_isc_w_prawo=1;
    czy_moze_isc_w_lewo=1;

//    for (int i=0;i<lista_obiektow_ruch_log.size();i++){
//        Postac* p = lista_obiektow_ruch_log.at(i);

//        for (int j=0;j<lista_obiektow.size();j++){
//            Obiekt* obj = lista_obiektow.at(j);

//            if(p->zwroc_wspolrzedne_y()>obj->zwroc_wspolrzedne_y()+obj->zwroc_wysokosc()/2)
//            {
//                if(p->zwroc_wspolrzedne_y()<obj->zwroc_wspolrzedne_y()+obj->zwroc_wysokosc())
//                {
//                    if(p->zwroc_wspolrzedne_x()>obj->zwroc_wspolrzedne_x()-p->zwroc_szerokosc())
//                    {
//                        if(p->zwroc_wspolrzedne_x()<obj->zwroc_wspolrzedne_x()+obj->zwroc_szerokosc())
//                        {
//                            czy_skacz=0;
//                            korekcja_polozenia_uderz_glowa(obj->zwroc_wspolrzedne_y(), obj->zwroc_wysokosc());
//                        }
//                    }
//                }
//            }

//            if(p->zwroc_wspolrzedne_y()>=obj->zwroc_wspolrzedne_y()-p->zwroc_wysokosc())
//            {
//                if(p->zwroc_wspolrzedne_y()<=obj->zwroc_wspolrzedne_y()+obj->zwroc_wysokosc()-p->zwroc_wysokosc()-2)
//                {
//                    if(p->zwroc_wspolrzedne_x()>obj->zwroc_wspolrzedne_x()-p->zwroc_szerokosc())
//                    {
//                        if(p->zwroc_wspolrzedne_x()<obj->zwroc_wspolrzedne_x()+obj->zwroc_szerokosc())
//                        {
//                            p->czy_spada(0);
//                            p->korekcja_polozenia(obj->zwroc_wspolrzedne_y());
//                        }
//                    }
//                }
//            }

//            if(p->zwroc_wspolrzedne_x()+p->zwroc_szerokosc()>=obj->zwroc_wspolrzedne_x())
//            {
//                if(p->zwroc_wspolrzedne_x()+p->zwroc_szerokosc()<obj->zwroc_wspolrzedne_x()+obj->zwroc_szerokosc()-2)
//                {
//                    if(p->zwroc_wspolrzedne_y()+p->zwroc_wysokosc()>obj->zwroc_wspolrzedne_y()+3)
//                    {
//                        if(p->zwroc_wspolrzedne_y()+p->zwroc_wysokosc()<=obj->zwroc_wspolrzedne_y()+obj->zwroc_wysokosc())
//                        {
//                            czy_moze_isc_w_prawo=0;
//                            korekcja_polozenia_prawo(obj->zwroc_wspolrzedne_x());
//                        }
//                    }
//                }
//            }

//            if(p->zwroc_wspolrzedne_x()>obj->zwroc_wspolrzedne_x()+5)
//            {
//                if(p->zwroc_wspolrzedne_x()<=obj->zwroc_wspolrzedne_x()+obj->zwroc_szerokosc())
//                {
//                    if(p->zwroc_wspolrzedne_y()+p->zwroc_wysokosc()>obj->zwroc_wspolrzedne_y()+3)
//                    {
//                        if(p->zwroc_wspolrzedne_y()+p->zwroc_wysokosc()<=obj->zwroc_wspolrzedne_y()+obj->zwroc_wysokosc())
//                        {
//                            czy_moze_isc_w_lewo=0;
//                            korekcja_polozenia_lewo(obj->zwroc_wspolrzedne_x(), obj->zwroc_szerokosc());
//                        }
//                    }
//                }
//            }

//        }

//    }

        for (int j=0;j<lista_obiektow.size();j++){
            Obiekt* obj = lista_obiektow.at(j);

            if(zwroc_wspolrzedne_y()>obj->zwroc_wspolrzedne_y()+obj->zwroc_wysokosc()/2)
            {
                if(zwroc_wspolrzedne_y()<obj->zwroc_wspolrzedne_y()+obj->zwroc_wysokosc())
                {
                    if(zwroc_wspolrzedne_x()>obj->zwroc_wspolrzedne_x()-zwroc_szerokosc())
                    {
                        if(zwroc_wspolrzedne_x()<obj->zwroc_wspolrzedne_x()+obj->zwroc_szerokosc())
                        {
                            czy_skacz=0;
                            korekcja_polozenia_uderz_glowa(obj->zwroc_wspolrzedne_y(), obj->zwroc_wysokosc());
                        }
                    }
                }
            }

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
                            czy_moze_isc_w_prawo=0;
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
                            czy_moze_isc_w_lewo=0;
                            korekcja_polozenia_lewo(obj->zwroc_wspolrzedne_x(), obj->zwroc_szerokosc());
                        }
                    }
                }
            }

        }

    skacz();

    for (int i=0;i<lista_obiektow_ruch_graf.size();i++){
        ObiektGrafika* obj_graf = lista_obiektow_ruch_graf.at(i);
        obj_graf->rysuj();
    }

}

void Mario::update()
{


}

void Mario::zmniejsz_liczbe_zyc()
{
    zycia = zycia - 1;
}

int Mario::zwroc_liczbe_zyc()
{
    return zycia;
}

void Mario::wroc_do_poczatku()
{
    x_pos=70;
    y_pos=500;
}

void Mario::korekcja_polozenia_uderz_glowa(int obiekt_y_pos, int obiekt_wysokosc)
{
    y_pos = obiekt_y_pos + obiekt_wysokosc;
}

void Mario::update(QList<Obiekt *> &lista_obiektow)
{

}

void Mario::kucaj()
{

}

void Mario::skacz()
{
//    skacz_dzwiek = new QMediaPlayer();
//    skacz_dzwiek->setMedia(QUrl("C:/users/natal/Mario_Game/sounds/smb_jump.wav"));
//    skacz_dzwiek->play();

    if(czy_skacz==1 && czy_spadaj==1)
    {
        y_pos=y_pos-int(sqrt(2*4*wys_skoku));
    }
//     else if(czy_spadaj==0)
//    {
//       czy_skacz=0;
//    }
   else if(czy_spadaj==0 && czy_skacz==1)
      {
           czy_skacz=0;
      }

}

void Mario::wejdz_do_rury()
{

}

void Mario::zjedz_grzyba()
{

}

void Mario::zbierz_gwiazde()
{

}

void Mario::zbierz_monete(MonetaGraficzna *moneta_graficzna)
{
    moneta_graf = moneta_graficzna;

    zebrano_monete=1;
}


void Mario::uderz_glowa()
{

}

void Mario::zabij_wroga()
{

}

void Mario::doznan_obrazen()
{
    if(czy_ranny==0)
    {
        czy_ranny=1;
    }
    else if(czy_ranny==1)
    {
        umrzyj();
    }
}

void Mario::umrzyj()
{
    zmniejsz_liczbe_zyc();

//    smierc_muzyka = new QMediaPlayer();
//    smierc_muzyka->setMedia(QUrl("C:/users/natal/Mario_Game/sounds/death.wav"));
//    smierc_muzyka->play();

//    if(smierc_muzyka->state()!=1){
        wroc_do_poczatku();
    //}
}

void Mario::idz_w_lewo()
{
    x_pos=x_pos-szybkosc;
}

void Mario::idz_w_prawo()
{
    x_pos=x_pos+szybkosc;
}

void Mario::spadnij()
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

/*bool Mario::czy_spada(bool czy_spadaj1)
{
    czy_spadaj=czy_spadaj1;
    return czy_spadaj;
}*/

int Mario::zmniejsz_predkosc(int ile)
{
    if(szybkosc>(ile+10))
    {
        szybkosc=szybkosc-ile;
    }
    return szybkosc;
}

int Mario::zwieksz_predkosc(int ile)
{
    if(szybkosc<(50-ile))
    {
        szybkosc=szybkosc+ile;
    }
    return szybkosc;
}

bool Mario::zwroc_czy_spada()
{
    return czy_spadaj;
}

void Mario::troche_przesun_w_gore()
{
    y_pos = y_pos-5;
}
