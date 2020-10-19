#ifndef MARIO_H
#define MARIO_H

#include "postac.h"
//#include "gra.h"
#include "moneta.h"
#include "monetagraficzna.h"
//#include "mariografika.h"
#include "postacgrafika.h"
#include "dozebrania.h"
#include "dozebraniagrafika.h"

#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMediaPlayer>

using namespace std;

class Gra;

/** \brief Klasa Mario
*
* Zawiera metody logiczne ludzika Mario, jak również jego parametry - wysokość, szerokość, itp..
*/
class Mario :public QObject, public Postac //, public QGraphicsItem
{
    Q_OBJECT
public:
    /** \brief Konstruktor klasy Mario
    * Zawiera domyślne parametry.
    */
    Mario();
    /** \brief Sprawia, że Mario kuca, po naciśnięciu strzałki w dół
    */
    void kucaj();
    /** \brief Sprawia, że Mario skacze
    * Wysokość skoku jest równa czterokrotności wysokości Mario.
    */
    void skacz();
    void wejdz_do_rury();
    void zjedz_grzyba();
    void zwieksz_skok();
    void zmniejsz_skok();
    void uderz_glowa();
    void zabij_wroga();
    void doznan_obrazen();
    void umrzyj();
    /** \brief Mario przemieszcza się w lewo
    */
    void idz_w_lewo();
    /** \brief Mario przemieszcza się w prawo
    */
    void idz_w_prawo();
    /** \brief Mario spada, gdy nie stoi na obiektach
    * Przyśpieszenie grawitacyjne równe 4pix/timer^2
    */
    void spadnij();
    int zmniejsz_predkosc(int ile);
    int zwieksz_predkosc(int ile);
    void zbierz_gwiazde();
    /** \brief Sygnalizuje, że zebrano monete.
    */
    void zbierz_monete(MonetaGraficzna *moneta_graficzna);
    /** \brief Zwraca parametr czy_spadaj
    */
    bool zwroc_czy_spada();
    /** \brief Przesuwa trochę do góry Mario po rozpoczęciu skoku, aby parametr czy_spadaj był równy 1.
    */
    void troche_przesun_w_gore();
    /** \brief Aktualizuje parametry
    * Przechodzi po listach i sprawdza, czy Mario może spadać, czy może iść w lewo, w prawo, itp.
    */
    void update(QList<PostacGrafika *> &lista_obiektow_ruch_graf,
                QList<Obiekt *> &lista_obiektow);
    /// wskaźnik na klase MonetaGraficzna, wykorzystywany w klasie Gra
    MonetaGraficzna *moneta_graf;
    /// określa czy zebrano monete, jeżeli tak to w grze zwięksa się liczba monet i wynik
    bool zebrano_monete;
    void update();
    /// zmniejsza ilość żyć o 1
    void zmniejsz_liczbe_zyc();
    /// zwraca ilość żyć
    int zwroc_liczbe_zyc();
    /// ustawia Mario na początku planszy
    void wroc_do_poczatku();
    ///koryguje położenie Mario po uderzeniu w coś głową
    void korekcja_polozenia_uderz_glowa(int obiekt_y_pos, int obiekt_wysokosc);
    void update(QList<Obiekt *> &lista_obiektow);

private:
    /// wysokość skoku równa czterokrotności wysokości Mario
    int wys_skoku;
    /// czy ranny ludzik Mario jest ranny
    bool czy_ranny;
    /// wielkość ludzika Mario, "maly" lub "duzy", domyslnie "maly"
    string wielkosc;
    /// scena z gry
    QGraphicsScene* FScene;
    /// wskaźnik na klase Gra
    Gra* gra;
    /// muzyka po śmierci Mario
    QMediaPlayer *smierc_muzyka;
};

#endif // MARIO_H
