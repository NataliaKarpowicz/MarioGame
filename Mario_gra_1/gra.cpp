 #include "gra.h"
#include "mariografika.h"
#include "zamek.h"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtCore>
#include <QtGui>
#include <QPushButton>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QTimer>
#include <QDebug>

Gra::Gra(QGraphicsScene *scene, QGraphicsView *view, QMediaPlayer *music)
{
    score = 0;
    monety = 0;
    czas = 90;

    music_menu = new QMediaPlayer;
    music_menu = music;
    //QGraphicsScene*scene;
    //scene=new QGraphicsScene;
    FScene = scene;

    view_1 = view;

    //ziemia->tworz_podloze(FScene);

    //pokazanie ziemi
    for(int i=0; i<FScene->width(); i=i+32){
        for(int j=868; j>800;j=j-32){
            if((i<1888 || i>2016)&&(i<2784 || i>3168))
            {
                ziemia->rysuj(FScene, i, j);
                ziemia_1 = new Ziemia(i,j);
                lista_obiektow.append(ziemia_1);
            }
        }
    }

    rysuj_plansze();
    licznik();

    text_czas = FScene->addText("TIME");
    text_czas_liczba = FScene->addText(QString::number(czas));
    text_wynik = FScene->addText("SCORE");
    text_wynik_liczba = FScene->addText(QString::number(score));
    text_monety = FScene->addText("COINS");
    text_monety_liczba = FScene->addText(QString::number(monety));
    text_zycia = FScene->addText("LIVES");
    text_zycia_liczba = FScene->addText(QString::number(mario_logika->zwroc_liczbe_zyc()));

    mario_logika = new Mario;
    mario_grafika = new MarioGrafika;
    mario_grafika->setLogic(mario_logika);
    FScene->addItem(mario_grafika);
    lista_obiektow_ruch_log.append(mario_logika);
    lista_obiektow_ruch_graf.append(mario_grafika);

    mario_grafika->setFlag(QGraphicsItem::ItemIsFocusable);
    mario_grafika->setFocus();

   // QListIterator<Obiekt*> Iter_Obiekty_ruch_log(lista_obiektow_ruch_log);
   // QListIterator<ObiektGrafika*> Iter_Obiekty_ruch_graf(lista_obiektow_ruch_graf);

    timer_update = new QTimer(this);

    connect(timer_update, SIGNAL(timeout()), this, SLOT(update()));
    timer_update->start(100);

}

int Gra::zwieksz_wynik(string co_zebral)
{
    if(co_zebral=="gwiazda")
    {
        score = score+1000;
    }
    else if(co_zebral=="moneta")
    {
        score = score+100;
    }
    else if(co_zebral=="grzyb")
    {
        score = score+500;
    }
    else if(co_zebral=="zabil_grzyba")
    {
        score = score+200;
    }
    else if(co_zebral=="zabil_zolwia")
    {
        score = score+300;
    }
    return score;
}

int Gra::zwieksz_liczbe_monet()
{
    monety++;
    return monety;
}

int Gra::zmniejsz_licznik()
{
    czas--;
    return czas;
}

//void Gra::dodaj_zlego_grzyba(int x_1, int y_1)
//{
    //ZlyGrzybGrafika *zly_grzyb_graf = new ZlyGrzybGrafika;
    //ZlyGrzyb *zly_grzyb_log = new ZlyGrzyb(x_1, y_1);
    //zly_grzyb_graf->setLogic(zly_grzyb_log);
//    FScene->addItem(zly_grzyb_graf);
//    lista_obiektow_ruch_log_2.append(zly_grzyb_log);
//    lista_obiektow_ruch_graf_2.append(zly_grzyb_graf);

//}

void Gra::dodawanie_monety(int x_1, int y_1)
{
    moneta_graf = new MonetaGraficzna;
    moneta_log = new Moneta(x_1, y_1);
    moneta_graf->setLogic(moneta_log);
    FScene->addItem(moneta_graf);
    lista_do_zebrania_log.append(moneta_log);
    lista_do_zebrania_graf.append(moneta_graf);
}

void Gra::dodawanie_cegly(int x_1, int y_1)
{
    cegla_graf = new CeglaGrafika;
    cegla_log = new Cegla(x_1, y_1);
    cegla_graf->setLogic(cegla_log);
    cegla_graf->rysuj();
    FScene->addItem(cegla_graf);
    lista_obiektow_graficznych.append(cegla_graf);
    lista_obiektow.append(cegla_log);
}

void Gra::update()
{
    wyswietl_czas();
    wyswietl_l_monet();
    wyswietl_wynik();
    wyswietl_zycia();

    mario_logika->spadnij();

    view_1->centerOn(mario_grafika);

    if(czas<=-1 || mario_logika->zwroc_liczbe_zyc()==0)
    {
        przegrana();
    }

    if(czas>88 && mario_logika->zwroc_wspolrzedne_y()>900)
    {
        mario_logika->wroc_do_poczatku();
    }

       if(mario_logika->zwroc_wspolrzedne_y()>900)
       {
           mario_logika->umrzyj();
       }

    if(czas>=89)
    {
        monety=0;
        score=0;
    }

    if(mario_logika->zwroc_wspolrzedne_x()>=4060)
    {
        wygrana();
    }

    for (int i=0;i<lista_do_zebrania_log.size();i++)
    {
        DoZebrania* obj_do_zebr_log = lista_do_zebrania_log.at(i);
        obj_do_zebr_log->update();
    }

    for (int i=0;i<lista_do_zebrania_graf.size();i++)
    {
        DoZebraniaGrafika* obj_do_zebr_graf = lista_do_zebrania_graf.at(i);
        obj_do_zebr_graf->rysuj();
    }

//    for (int i=0;i<lista_obiektow_ruch_log_2.size();i++)
//    {
//        Postac* post = lista_obiektow_ruch_log_2.at(i);
//        post->update(lista_obiektow);
//    }

//    for (int i=0;i<lista_obiektow_ruch_graf_2.size();i++)
//    {
//        PostacGrafika* post_graf = lista_obiektow_ruch_graf_2.at(i);
//        post_graf->rysuj();
//    }

    //zly_grzyb_log->update(lista_obiektow);
    //zly_grzyb_graf->rysuj();

    mario_logika->update(lista_obiektow_ruch_graf, lista_obiektow);

    if(mario_logika->zebrano_monete==1)
    {
        moneta_dzwiek = new QMediaPlayer();
        moneta_dzwiek->setMedia(QUrl("qrc:/sounds/sounds/coin.wav"));
        moneta_dzwiek->play();
        FScene->removeItem(mario_logika->moneta_graf);
        zwieksz_liczbe_monet();
        zwieksz_wynik("moneta");
        mario_logika->zebrano_monete=0;
    }

}

void Gra::licznik()
{
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(zmniejsz_licznik()));
    timer->start(1000);
}

void Gra::wygrana()
{
    music_menu->stop();

    wygrana_muzyka = new QMediaPlayer();
    wygrana_muzyka->setMedia(QUrl("qrc:/sounds/sounds/levelend.wav"));
    wygrana_muzyka->play();

    FScene->removeItem(mario_grafika);

    timer_update->stop();
    timer->stop();

    FScene->removeItem(text_czas);
    FScene->removeItem(text_czas_liczba);
    FScene->removeItem(text_wynik);
    FScene->removeItem(text_wynik_liczba);
    FScene->removeItem(text_monety_liczba);
    FScene->removeItem(text_monety);
    FScene->removeItem(text_zycia_liczba);
    FScene->removeItem(text_zycia);
}

bool Gra::przegrana()
{
//    if(czas<=-1 || mario_logika->zwroc_wspolrzedne_y()>900)
//    {

        //menu->muzyka_stop();

        music_menu->stop();

        timer_update->stop();
        timer->stop();

        przegrana_muzyka = new QMediaPlayer();
        przegrana_muzyka->setMedia(QUrl("qrc:/sounds/sounds/gameover.wav"));
        przegrana_muzyka->play();

        //FScene->clear();
        view_1->setBackgroundBrush(Qt::black);
        //FScene->setBackgroundBrush(Qt::black);
        text_game_over = FScene->addText("GAME OVER");
        text_game_over->setFont(QFont("Comic Sans MS", 30));
        text_game_over->setDefaultTextColor(Qt::white);
        text_game_over->setPos(mario_logika->zwroc_wspolrzedne_x(), view_1->height()/2);
        //return 0;

//        for (int i=0;i<lista_do_zebrania_graf.size();i++)
//        {
//            DoZebraniaGrafika* obj_do_zebr_graf = lista_do_zebrania_graf.at(i);
//            //ObiektGrafika *ob;
//            DoZebraniaGrafika do_zebr_gr;

//            MonetaGraficzna *m;
//            m=&do_zebr_gr;
//            obj_do_zebr_graf = dynamic_cast<DoZebraniaGrafika*>(m);

//            //ob=p;
//            FScene->removeItem(obj_do_zebr_graf);
//            //delete obj_do_zebr_graf;
//        }

////        for (int i=0;i<lista_do_zebrania_log.size();i++)
////        {
////            DoZebrania* obj_do_zebr_log = lista_do_zebrania_log.at(i);
////            obj_do_zebr_log->~DoZebrania();
////        }

//        for (int i=0;i<lista_obiektow_graficznych.size();i++)
//        {
//            ObiektGrafika* obj_nieruszajacy_graf = lista_obiektow_graficznych.at(i);

//            //FScene->removeItem(obj_nieruszajacy_graf)
//            //delete obj_nieruszajacy_graf;
//        }

//    }
        FScene->removeItem(mario_grafika);

        FScene->removeItem(text_czas);
        FScene->removeItem(text_czas_liczba);
        FScene->removeItem(text_wynik);
        FScene->removeItem(text_wynik_liczba);
        FScene->removeItem(text_monety_liczba);
        FScene->removeItem(text_monety);
        FScene->removeItem(text_zycia_liczba);
        FScene->removeItem(text_zycia);

    return 1;
}

void Gra::wyswietl_wynik()
{
    text_wynik->setFont(QFont("Comic Sans MS", 16));
    text_wynik->setDefaultTextColor(Qt::white);
    //text_wynik->setPos(5, 5);
    if(mario_logika->zwroc_wspolrzedne_x()>=view_1->width()/2)
    {
        text_wynik->setPos(mario_logika->zwroc_wspolrzedne_x()-view_1->width()/2+5+10, 5);
    }
    else
    {
         text_wynik->setPos(5, 5);
    }
    text_wynik->update();

    text_wynik_liczba->setPlainText(QString::number(score));
    text_wynik_liczba->setFont(QFont("Comic Sans MS", 16));
    text_wynik_liczba->setDefaultTextColor(Qt::white);
   // text_wynik_liczba->setPos(5, 30);
    if(mario_logika->zwroc_wspolrzedne_x()>=view_1->width()/2)
    {
        text_wynik_liczba->setPos(mario_logika->zwroc_wspolrzedne_x()-view_1->width()/2+5+10, 30);
    }
    else
    {
         text_wynik_liczba->setPos(5, 30);
    }
    text_wynik_liczba->update();
}

void Gra::wyswietl_czas()
{
    text_czas->setFont(QFont("Comic Sans MS", 16));
    text_czas->setDefaultTextColor(Qt::white);
    //text_czas->setPos(300, 5);
    if(mario_logika->zwroc_wspolrzedne_x()>=view_1->width()/2)
    {
        text_czas->setPos(mario_logika->zwroc_wspolrzedne_x()-view_1->width()/2+300+10, 5);
    }
    else
    {
         text_czas->setPos(300, 5);
    }
    text_czas->update();

    //text_czas_liczba = FScene->addText(QString::number(czas));
    text_czas_liczba->setPlainText(QString::number(czas));
    text_czas_liczba->setFont(QFont("Comic Sans MS", 16));
    text_czas_liczba->setDefaultTextColor(Qt::white);
    if(mario_logika->zwroc_wspolrzedne_x()>=view_1->width()/2)
    {
        text_czas_liczba->setPos(mario_logika->zwroc_wspolrzedne_x()-view_1->width()/2+300+10, 30);
    }
    else
    {
         text_czas_liczba->setPos(300, 30);
    }
    text_czas_liczba->update();
}

void Gra::wyswietl_l_monet()
{
    //text_wynik = scene->addText("COINTS");
    text_monety->setFont(QFont("Comic Sans MS", 16));
    text_monety->setDefaultTextColor(Qt::white);
    //text_monety->setPos(150, 5);
    if(mario_logika->zwroc_wspolrzedne_x()>=view_1->width()/2)
    {
        text_monety->setPos(mario_logika->zwroc_wspolrzedne_x()-view_1->width()/2+150+10, 5);
    }
    else
    {
         text_monety->setPos(150, 5);
    }
    text_monety->update();

    //text_wynik_liczba = scene->addText(QString::number(monety));
    text_monety_liczba->setPlainText(QString::number(monety));
    text_monety_liczba->setFont(QFont("Comic Sans MS", 16));
    text_monety_liczba->setDefaultTextColor(Qt::white);
   // text_monety_liczba->setPos(150, 30);
    if(mario_logika->zwroc_wspolrzedne_x()>=view_1->width()/2)
    {
        text_monety_liczba->setPos(mario_logika->zwroc_wspolrzedne_x()-view_1->width()/2+150+10, 30);
    }
    else
    {
         text_monety_liczba->setPos(150, 30);
    }
    text_monety_liczba->update();
}

void Gra::wyswietl_zycia()
{
    text_zycia->setFont(QFont("Comic Sans MS", 16));
    text_zycia->setDefaultTextColor(Qt::white);
    if(mario_logika->zwroc_wspolrzedne_x()>=view_1->width()/2)
    {
        text_zycia->setPos(mario_logika->zwroc_wspolrzedne_x()-view_1->width()/2+450+10, 5);
    }
    else
    {
         text_zycia->setPos(450, 5);
    }
    text_zycia->update();

    text_zycia_liczba->setPlainText(QString::number(mario_logika->zwroc_liczbe_zyc()));
    text_zycia_liczba->setFont(QFont("Comic Sans MS", 16));
    text_zycia_liczba->setDefaultTextColor(Qt::white);
    if(mario_logika->zwroc_wspolrzedne_x()>=view_1->width()/2)
    {
        text_zycia_liczba->setPos(mario_logika->zwroc_wspolrzedne_x()-view_1->width()/2+450+10, 30);
    }
    else
    {
         text_zycia_liczba->setPos(450, 30);
    }
    text_zycia_liczba->update();
}

void Gra::rysuj_plansze()
{
    dodawanie_monety(288, 762);
    dodawanie_monety(342, 762);
    dodawanie_monety(396, 762);
    dodawanie_monety(450, 762);

    for(int i=544; i<746; i=i+32)
    {
        dodawanie_cegly(i, 676);
        dodawanie_monety(i, 634);
    }

    dodawanie_cegly(896, 772);
    dodawanie_cegly(928, 772);
    dodawanie_cegly(928, 740);

    dodawanie_monety(928, 698);
    dodawanie_monety(960, 646);
    dodawanie_monety(992, 614);
    dodawanie_monety(1024, 590);
    dodawanie_monety(1056, 614);
    dodawanie_monety(1088, 646);
    dodawanie_monety(1110, 698);

    //dodaj_zlego_grzyba(1000, 700);

    dodawanie_cegly(1120, 772);
    dodawanie_cegly(1152, 772);
    dodawanie_cegly(1120, 740);

    for(int i=1248; i<1377; i=i+32)
    {
       dodawanie_cegly(i, 676);
       dodawanie_monety(i, 634);
    }

    dodawanie_monety(1390, 568);

    for(int i=1440; i<1569; i=i+32)
    {
       dodawanie_cegly(i, 548);
       dodawanie_monety(i, 506);
    }

    dodawanie_monety(1632, 568);

    for(int i=1664; i<1761; i=i+32)
    {
        dodawanie_cegly(i, 676);
        dodawanie_monety(i, 634);
    }

    dodawanie_cegly(1856, 772);
    dodawanie_monety(1856, 732);

    dodawanie_monety(1900, 672);
    dodawanie_monety(1952, 634);
    dodawanie_monety(2004, 672);

    dodawanie_monety(2048, 762);


    for(int i=2176; i<2433; i=i+32)
    {
        dodawanie_cegly(i, 676);
        dodawanie_monety(i, 631);
    }

    for(int i=2240; i<2369; i=i+32)
    {
        dodawanie_cegly(i, 548);
        dodawanie_monety(i, 470);
    }

    dodawanie_cegly(2560, 772);
    dodawanie_cegly(2592, 772);
    dodawanie_cegly(2624, 772);
    dodawanie_cegly(2560, 740);
    dodawanie_cegly(2592, 740);
    dodawanie_cegly(2560, 708);

    dodawanie_monety(2560, 661);
    dodawanie_monety(2592, 693);
    dodawanie_monety(2624, 725);

    for(int i=2848; i<3073; i=i+32)
    {
        dodawanie_cegly(i, 676);
        dodawanie_monety(i, 636);
    }

    //rura = new Rura(3650, 760);
    //rura_grafika->rysuj();

    for(int i=3360; i<3601; i=i+48)
    {
        for(int j=757; j>629; j=j-42)
        {
            dodawanie_monety(i,j);
        }
    }

    zamek_grafika = new ZamekGrafika;
    FScene->addItem(zamek_grafika);
    zamek_grafika->rysuj();
}
