#include "ziemia.h"
#include "ziemiagrafika.h"
#include <QGraphicsScene>

Ziemia::Ziemia()
{
 x_pos = 0;
 y_pos = 0;
 skala = 2;
 szerokosc = 16*skala;
 wysokosc = 16*skala;
}

Ziemia:: Ziemia(int x_pos1, int y_pos1)
{
    x_pos = x_pos1;
    y_pos = y_pos1;
    skala = 2;
    szerokosc = 16*skala;
    wysokosc = 16*skala;
}

void Ziemia::tworz_podloze(QGraphicsScene *scene)
{
    ZiemiaGrafika *ziemia;
    //pokazanie ziemi
    for(int i=0; i<scene->width(); i=i+32){
        for(int j=868; j>800;j=j-32){
            //if((i<1888 || i>1984)&&(i<2784 || i>3168))
            //{
                ziemia = new ZiemiaGrafika;
                scene->addItem(ziemia);
                ziemia->setScale(2);
                ziemia->setPos(i, j);

            //}
        }
    }
}

void Ziemia::update()
{

}

