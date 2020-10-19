#ifndef GRA_H
#define GRA_H

#include "obiekt.h"
#include "mario.h"
#include "mariografika.h"
#include "gra.h"
#include "ziemia.h"
#include "rura.h"
#include "ruragrafika.h"
#include "zamekgrafika.h"
#include "ceglagrafika.h"
#include "dozebrania.h"
#include "dozebraniagrafika.h"
#include "moneta.h"
#include "monetagraficzna.h"
#include "zlygrzyb.h"
#include "zlygrzybgrafika.h"

#include <iostream>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtCore>
#include <QtGui>
#include <QPushButton>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QEvent>
#include <QKeyEvent>
#include <QLabel>
#include <QObject>
#include <QTimer>
#include <QListIterator>
#include <QList>
#include <QWidget>

using namespace std;

class Menu;

/** \brief Klasa Gra
*
* Tworzy grę.
*/
class Gra: public QObject//, public QWidget
{
    Q_OBJECT

public:
    /**
    * \brief Konstruktor klasy Gra
    * \param scena z klasy Menu
    * \param view z klasy Menu
    * \param music z klasy Menu
    */
    Gra(QGraphicsScene* scene, QGraphicsView *view, QMediaPlayer *music);
    /**
    * \brief Zwiększenie wyniku, wywoływane po zebraniu obiektu z klasy DoZebrania, zabiciu wroga
    * \param określa co zrobił ludzik Mario i przypisuje temu działaniu konkretną liczbę
    */
    int zwieksz_wynik(string co_zebral);
    /**
    * \brief Zwiększenie liczby monet o 1.
    */
    int zwieksz_liczbe_monet();
    /**
    * \brief Zlicza czas.
    */
    void licznik();
    /**
    * \brief Oznacza przejście poziomu.
    */
    void wygrana();
    /**
    * \brief Przegrana.
    * Uruchamiana, gry ilość żyć Mario jest równa zero, bądź skończył się czas
    */
    bool przegrana();
    /**
    * \brief Wyświetla wynik na ekranie.
    */
    void wyswietl_wynik();
    /**
    * \brief Wyświetla pozostały czas na ekranie.
    */
    void wyswietl_czas();
    /**
    * \brief Wyświetla zebraną liczbę monet.
    */
    void wyswietl_l_monet();
    /**
    * \brief Wyświetla pozostałą ilość żyć
    */
    void wyswietl_zycia();
    /**
    * \brief Umieszcza wszystkie obiekty na scenie.
    */
    void rysuj_plansze();
    /**
    * \brief Dodaje nową monetę do sceny.
    * \param współrzędna x monety
    * \param współrzędna y monety
    */
    void dodawanie_monety(int x_1, int y_1);
    /**
    * \brief Dodaje nową cegłę do sceny.
    * \param współrzędna x cegły
    * \param współrzędna y cegły
    */
    void dodawanie_cegly(int x_1, int y_1);
//    /**
//    * \brief Dodaje złego grzyba do sceny.
//    */
//    void dodaj_zlego_grzyba(int x_1, int y_1);

public slots:
    /**
    * \brief Metoda update.
    * Wywołuje się co 100ms poprzez timer i updatuje położenia i stan obiektów.
    */
    void update();
    /**
    * \brief Licznik do czasu.
    * Co sekunde zmniejsza pozostały czas w grze o 1.
    */
    int zmniejsz_licznik();

private:
    /// scena gry
    QGraphicsScene* FScene;
    /// wynik gry
    int score;
    /// liczba zebranych monet
    int monety;
    /// pozostaly czas gry
    int czas;
    /// aktualny poziom
    int poziom;
    /// wskaźnik na klase obiekt
    Obiekt* obiekt;
    /// wskaźnik na klase QMediaPlayer, deklaracja muzyki uruchamianej po wygranej
    QMediaPlayer *wygrana_muzyka;
    /// wskaźnik na klase QMediaPlayer, deklaracja muzyki uruchamianej po przegranej
    QMediaPlayer *przegrana_muzyka;
    /// text "GAME OVER", wyświetlany po przegranej
    QGraphicsTextItem *text_game_over;
    /// text "SCORE", wyświetlany w lewym, górnym rogu ekranu
    QGraphicsTextItem *text_wynik;
    /// text "COINS", wyświetlany w lewym, górnym rogu ekranu
    QGraphicsTextItem *text_monety;
    /// text "LIVES", wyświetlany w lewym, górnym rogu ekranu
    QGraphicsTextItem *text_zycia;
    /// text "TIME", wyświetlany w lewym, górnym rogu ekranu
    QGraphicsTextItem *text_czas;
    /// wartość parametru score, wyświetlana w lewym, górnym rogu ekranu
    QGraphicsTextItem *text_wynik_liczba;
    /// wartość parametru monety, wyświetlana w lewym, górnym rogu ekranu
    QGraphicsTextItem *text_monety_liczba;
    /// wartość parametru czas, wyświetlana w lewym, górnym rogu ekranu
    QGraphicsTextItem *text_czas_liczba;
    /// ilość żyć ludzika Mario, wyświetlana w lewym, górnym rogu ekranu
    QGraphicsTextItem *text_zycia_liczba;
    /// przechowuje muzyke z Menu
    QMediaPlayer *music_menu;
//    /// muzyka po śmierci Mario
//    QMediaPlayer *smierc_muzyka;
    /// dźwięk monety, uruchamiany po zebraniu monety
    QMediaPlayer *moneta_dzwiek;
    /// wskaźnik na klase CeglaGrafika
    CeglaGrafika* cegla_graf;
    /// wskaźnik na klase Cegla
    Cegla* cegla_log;
    /// wskaźnik na klase Ziemia
    Ziemia* ziemia_1;
    /// wskaźnik na klase ZiemiaGrafika
    ZiemiaGrafika* ziemia;
    /// timer do metody update()
    QTimer *timer_update;
    /// timer do metody zmniejsz_licznik()
    QTimer *timer;
    /// wskaźnik na klase Rura
    Rura*rura;
    /// wskaźnik na klase RuraGrafika
    RuraGrafika*rura_grafika;
    /// lista obiektów graficznych nieruchomych w grze
    QList<ObiektGrafika *> lista_obiektow_graficznych;
    /// lista obiektów logicznych nieruchomych w grze
    QList<Obiekt *> lista_obiektow;
    /// wskaźnik na klase Mario
    Mario* mario_logika;
    /// wskaźnik na klase MarioGrafika
    MarioGrafika* mario_grafika;
    /// wskaźnik na klase ZamekGrafika
    ZamekGrafika *zamek_grafika;
    /// lista obiektów logicznych ruchomych w grze
    QList<Postac *> lista_obiektow_ruch_log;
    /// lista obiektów graficznych ruchomych w grze
    QList<PostacGrafika *> lista_obiektow_ruch_graf;
    /// lista obiektów logicznych, które można zebrać w grze
    QList<DoZebrania *> lista_do_zebrania_log;
    /// lista obiektów graficznych, które można zebrać w grze
    QList<DoZebraniaGrafika *> lista_do_zebrania_graf;
    /// ustawia view z klasy Menu
    QGraphicsView *view_1;
    /// wskaźnik na klase MonetaGraficzna
    MonetaGraficzna *moneta_graf;
    /// wskaźnik na klase Moneta
    Moneta *moneta_log;
//    /// wskaźnik na klase ZlyGrzyb
//    ZlyGrzyb *zly_grzyb_log;
//    /// wskaźnik na klase ZlyGrzybGrafika
    //ZlyGrzybGrafika *zly_grzyb_graf;
//    QList<Postac *> lista_obiektow_ruch_log_2;
//    QList<PostacGrafika *> lista_obiektow_ruch_graf_2;
};

#endif // GRA_H
