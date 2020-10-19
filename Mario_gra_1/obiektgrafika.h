#ifndef OBIEKTGRAFIKA_H
#define OBIEKTGRAFIKA_H

#include <QObject>

/** \brief Klasa ObiektGrafika
*
* Klasa abstrakcyjna, zawiera metodę rysuj().
*/
class ObiektGrafika :public QObject
{
    //Q_OBJECT
public:
    ObiektGrafika();
    virtual void rysuj()=0;
};

#endif // OBIEKTGRAFIKA_H
