#ifndef OBIEKT_H
#define OBIEKT_H

#include <string>

/** \brief Klasa Obiekt
*
* Klasa, po której dziedziczą postacie, obiekty do zebrania i przeszkody.
*/
class Obiekt
{

public:
    Obiekt();
    virtual void update()=0;
    /** \brief Zwraca parametr x_pos
    */
    int zwroc_wspolrzedne_x();
    /** \brief Zwraca parametr y_pos
    */
    int zwroc_wspolrzedne_y();
    /** \brief Zwraca parametr szerokosc
    */
    int zwroc_szerokosc();
    /** \brief Zwraca parametr wysokosc
    */
    int zwroc_wysokosc();
    /** \brief Zwraca parametr skala
    */
    int zwroc_skale();

protected:
    /// współrzędna x
    int x_pos;
    /// współrzędna y
    int y_pos;
    /// wysokość
    int wysokosc;
    /// szerokość
    int szerokosc;
    /// skala
    int skala;
    /// nazwa
    std::string nazwa;
    /// ilość żyć
    int zycia;
    /// który obraz jest wyświetlany
    int ktory_obraz;
};

#endif // OBIEKT_H
