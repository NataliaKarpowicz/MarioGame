#ifndef CEGLA_H
#define CEGLA_H

#include "przeszkoda.h"

/** \brief Klasa Cegla
*
* Przechowuje podstawowe informacje o kwadratowym obiekcie cegła, m.in. położenie, skala, itp.
*/
class Cegla :public Przeszkoda
{
public:
    /**
    * \brief Konstruktor domyślny
    */
    Cegla();
    /**
    * \brief Konstruktor ustawiający pozycję cegły
    * \param współrzędna x
    * \param współrzędna y
    */
    Cegla(int x_pos, int y_pos);
    void update();
};

#endif // CEGLA_H
