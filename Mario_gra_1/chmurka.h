#ifndef CHMURKA_H
#define CHMURKA_H

#include "rysunektlo.h"

/** \brief Klasa Chmurka
*
* Przechowuje podstawowe informacje o obiekcie chmurka, m.in. polozenie, skala, itp.
*/
class Chmurka :public RysunekTlo
{
public:
    /**
    * \brief Konstruktor klasy Chmurka
    */
    Chmurka();
    /** \brief Konstruktor klasy chmurka
    *
    * Umożliwia ustawienie położenia obiektu
    */
    Chmurka(int x_pos_1, int y_pos_1);
    void update();
};

#endif // CHMURKA_H
