#ifndef PRZESZKODAZNAKZAPYTANIA_H
#define PRZESZKODAZNAKZAPYTANIA_H

#include "przeszkoda.h"
#include <string>

class PrzeszkodaZnakZapytania :public Przeszkoda
{

public:
    PrzeszkodaZnakZapytania();
    void losuj_zawartosc();
    void wyrzuc_cos();
    void update();

private:
    std::string co_ukryte;

};

#endif // PRZESZKODAZNAKZAPYTANIA_H
