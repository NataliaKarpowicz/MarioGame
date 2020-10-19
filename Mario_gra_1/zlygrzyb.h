#ifndef ZLYGRZYB_H
#define ZLYGRZYB_H

#include "wrog.h"
#include <QList>

/** \brief Klasa Ziemia
*
* Zawiera parametry i metody logiczne złego grzyba.
*/
class ZlyGrzyb :public Wrog
{
public:
    /** \brief Konstruktor złego grzyba
    */
    ZlyGrzyb();
    /** \brief Konstruktor złego grzyba z możliwością ustawienia położenia.
    *
    * \param współrzędna x
    * \param współrzędna y
    */
    ZlyGrzyb(int x_1, int y_1);

    /** \brief Wywołuje się, gdy grzyb został zabity przez Mario.
    */
    void umrzyj();
    /** \brief Zmienia kierunek ruchu.
    */
    void zmien_kierunek();
    /** \brief Inicjalizuje procedure spadania.
    */
    void spadnij();
    /** \brief Zmniejsza prędkość
    */
    void zmniejsz_predkosc();
    /** \brief Zwiększa prędkość
    */
    void zwieksz_predkosc();
    /** \brief Zadaje obrażenia Mario
    */
    void zadaj_obrazenia();
    /** \brief Przemieszcza obiekt w lewo
    */
    void idz_w_lewo();
    /** \brief Przemieszcza obiekt w prawo
    */
    void idz_w_prawo();
    /** \brief Zmniejsza prędkość
    *
    * \param o ile zmiejsza prędkość
    */
    int zmniejsz_predkosc(int ile);
    /** \brief Zwiększa prędkość
    *
    * \param o ile zwiększa prędkość
    */
    int zwieksz_predkosc(int ile);
    /** \brief Zwraca parametr ktory_obraz
    */
    int zwroc_ktory_obraz();
    void update();
    /** \brief Zwraca parametr czy_spadaj
    */
    bool zwroc_czy_spada();
    /** \brief Aktualizuje parametry.
    */
    void update(QList<Obiekt *> &lista_obiektow);
};

#endif // ZLYGRZYB_H


