#ifndef MARIOGRAFIKA_H
#define MARIOGRAFIKA_H

#include "postacgrafika.h"
#include "mario.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "moneta.h"
#include "monetagraficzna.h"

/** \brief Klasa MarioGrafika
*
* Zawiera metody graficzne ludzika Mario, rysuje go, jest połączona z klasą Mario, skąd bierze parametry.
* Umożliwia sterowanie ludzikiem Mario
*/
class MarioGrafika :public QGraphicsPixmapItem, public PostacGrafika
{
public:
    /** \brief Konstruktor MarioGrafika
    */
    MarioGrafika(QGraphicsItem *parent=nullptr);
    /** \brief Metoda do sterowania ludzikiem Mario
    *
    * Po naciśnieciu strzałiki w prawo wywołuje metode z klasy Mario - idz_w_prawo().
    * Po naciśnieciu strzałiki w lewo wywołuje metode z klasy Mario - idz_w_lewo().
    * Po naciśnieciu strzałiki w góre wywołuje metode z klasy Mario - skacz().
    * Po naciśnieciu spacji wywołuje metode z klasy Mario - skacz().
    * Po naciśnieciu strzałiki w dół wywołuje metode z klasy Mario - kucaj().
    */
    void keyPressEvent(QKeyEvent *event);
    /** \brief Rysuje ludzika Mario
    */
    void rysuj();
    /** \brief Łączy klase MarioGrafika z klasą Mario, skąd bierze parametry
    */
    void setLogic(Mario* _m);
private:
    ///wskaźnik na klase Mario
    Mario* mario;
    /// dźwięk podczas skoku
    QMediaPlayer *skacz_dzwiek;
    /// wskaźnik na klase MonetaGraficzna
    MonetaGraficzna *moneta_graf;
};

#endif // MARIOGRAFIKA_H
