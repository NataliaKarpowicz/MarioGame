#ifndef MONETA_H
#define MONETA_H

#include "dozebrania.h"

/** \brief Klasa Moneta
*
* Zawiera metody i parametry logiczne monety.
*/
class Moneta: public DoZebrania
{
public:
    /** \brief Konstruktor klasy Moneta
    */
    Moneta();
    /** \brief Konstruktor klasy Moneta
    * Umożliwia ustawienie pozycji monety.
    */
    Moneta(int x_pos_1, int y_pos_1);
    /** \brief Metoda aktualizująca parametry monety
    */
    void update();
    /** \brief Zwraca parametr ktory_obraz
    */
    int zwroc_ktory_obraz();
};

#endif // MONETA_H
