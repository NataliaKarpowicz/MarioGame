#include "mariografika.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <QObject>
#include <QDebug>

MarioGrafika::MarioGrafika(QGraphicsItem* parent) :QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/images/mario-small-stand.png"));
}

void MarioGrafika::rysuj()
{

    QList<QGraphicsItem *> list = collidingItems() ;

    foreach(QGraphicsItem * i , list)
    {
        MonetaGraficzna * moneta_graf_1= dynamic_cast<MonetaGraficzna *>(i);
        if (moneta_graf_1)
        {
            qDebug()<<"jest moneta";
            mario->zbierz_monete(moneta_graf_1);
        }
        else
        {
            qDebug()<<"nie ma";
        }
    }

    setScale(mario->zwroc_skale());
    setPos(mario->zwroc_wspolrzedne_x(), mario->zwroc_wspolrzedne_y());
    update();

}

void MarioGrafika::setLogic(Mario *_m)
{
    mario = _m;
}

void MarioGrafika::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(mario->zwroc_wspolrzedne_x()>=0 && mario->zwroc_czy_moze_isc_w_lewo()==1)
        {
            mario->idz_w_lewo();
        }

    }
    else if(event->key() == Qt::Key_Right)
    {
        if(mario->zwroc_czy_moze_isc_w_prawo()==1)
        {
            mario->idz_w_prawo();
        }

        //qDebug()<<"prawy";
    }
    else if(event->key() == Qt::Key_Space || event->key() == Qt::Key_Up)
    {
        if(mario->zwroc_czy_spada()==0)
        {
            mario->czy_skacz=1;
            mario->troche_przesun_w_gore();

                skacz_dzwiek = new QMediaPlayer();
                skacz_dzwiek->setMedia(QUrl("qrc:/sounds/sounds/smb_jump.wav"));
                skacz_dzwiek->play();
        }
    }
    else if(event->key() == Qt::Key_Down)
    {
        mario->kucaj();
    }
}
