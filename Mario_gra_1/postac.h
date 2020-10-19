#ifndef POSTAC_H
#define POSTAC_H

#include "obiekt.h"
#include <QObject>

/** \brief Klasa Postac
*
* Klasa, po której dziedziczą Mario i wrogowie.
*/
class Postac :public Obiekt
{
public:
    /** \brief Konstruktor klasy Postac
    */
    Postac();
    virtual void update()=0;
    virtual void update(QList<Obiekt *> &lista_obiektow)=0;
   /* void idz();
    void umrzyj();
    void zmien_kierunek();
    void spadnij();
    void zmniejsz_predkosc();
    void zwieksz_predkosc();*/
    /** \brief Ustawia, czy obiekt ma spadać.
    */
    bool czy_spada(bool czy_spadaj1);
    /** \brief Po spadnięciu, koryguje wysokość obiektu
    */
    void korekcja_polozenia(int y_obiektu);
    /// czy można skakać
    bool czy_skacz;
    /** \brief Zwraca czy można iść w lewo
    */
    bool zwroc_czy_moze_isc_w_lewo();
    /** \brief Zwraca czy można iść w prawo
    */
    bool zwroc_czy_moze_isc_w_prawo();
    /** \brief Koryguje położenie po zderzeniu z prawej strony
    */
    void korekcja_polozenia_prawo(int obiekt_x_pos);
    /** \brief Koryguje położenie po zderzeniu z lewej strony
    */
    void korekcja_polozenia_lewo(int obiekt_x_pos, int obiekt_szerokosc);

protected:
    /// szybkość
    int szybkosc;
    /// czy obiekt ma spadać
    bool czy_spadaj;
    /// prędkość spadania
    int predkosc_spadania;
    /// czy obiekt może poruszać się w lewą stronę
    bool czy_moze_isc_w_lewo;
    /// czy obiekt może poruszać się w prawą stronę
    bool czy_moze_isc_w_prawo;
};

#endif // POSTAC_H
