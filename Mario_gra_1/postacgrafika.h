#ifndef POSTACGRAFIKA_H
#define POSTACGRAFIKA_H

#include "obiektgrafika.h"
#include <QObject>

/** \brief Klasa PostacGrafika
*
* Klasa abstrakcyjna, zawiera metodę rysuj(). Dziedziczy po ObiektGrafika
*/
class PostacGrafika :public ObiektGrafika
{
    //Q_OBJECT
public:
    PostacGrafika();
    virtual void rysuj()=0;
};

#endif // POSTACGRAFIKA_H
