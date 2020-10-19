#include "menu.h"
#include "ui_menu.h"
#include "menu.h"
#include "ui_menu.h"
#include "gra.h"
#include "chmurkagrafika.h"
#include "ziemiagrafika.h"
#include "wzgorze.h"
#include "ziemia.h"
#include "stdlib.h"

#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtCore>
#include <QtGui>
#include <QPushButton>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QLabel>
#include <QGraphicsPixmapItem>

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    // ustawienie sceny, widoku i ich wygladu, polozenia
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 900, 900);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    view = new QGraphicsView(scene);
    view->setMaximumSize(900,900);
    view->setMinimumSize(900,900);
    view->setGeometry(500,50,900,900);
    view->setBackgroundBrush(Qt::blue);
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Mario"));
    view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->resize(500, 500);

    //pokazanie chmurek
    chmurka->rysuj(scene);

    //pokazanie wzgorz
    wzgorze->rysuj(scene);

    //stworzenie podloza
    ziemia->tworz_podloze(scene);

    button_wyglad(view); // ustawia wyglad przyciskow i je dodaje
    dzwiek_menu(); // dodaje dzwiek do menu

    view->show();

}

void Menu::button_wyglad(QGraphicsView *view)
{
    // deklaracja
    button_kontynuuj = new QPushButton(view);
    button_nowa_gra = new QPushButton(view);
    button_stworzone_poziomy = new QPushButton(view);
    button_tworzenie_poziomu = new QPushButton(view);
    button_ustawienia = new QPushButton(view);

    // podlaczenie do slotow
    connect(button_kontynuuj, SIGNAL (clicked()),this, SLOT (on_button_kontynuuj_clicked()));
    connect(button_nowa_gra, SIGNAL (clicked()),this, SLOT (on_button_nowa_gra_clicked()));
    connect(button_stworzone_poziomy, SIGNAL (clicked()),this, SLOT (on_button_stworzone_poziomy_clicked()));
    connect(button_tworzenie_poziomu, SIGNAL (clicked()),this, SLOT (on_button_tworzenie_poziomu_clicked()));
    connect(button_ustawienia, SIGNAL (clicked()),this, SLOT (on_button_ustawienia_clicked()));

    // ustawienie pozycji
    button_kontynuuj->setGeometry(300,150,300,50);
    button_nowa_gra->setGeometry(300,210,300,50);
    button_stworzone_poziomy->setGeometry(300,270,300,50);
    button_tworzenie_poziomu->setGeometry(300,330,300,50);
    button_ustawienia->setGeometry(300,390,300,50);

    // edycja tekstu
    button_kontynuuj->setText("KONTUNUUJ");
    button_kontynuuj->setFont(QFont("Comic Sans MS"));
    button_kontynuuj->setCursor(Qt::PointingHandCursor);

    button_nowa_gra->setText("NOWA GRA");
    button_nowa_gra->setFont(QFont("Comic Sans MS"));
    button_nowa_gra->setCursor(Qt::PointingHandCursor);

    button_stworzone_poziomy->setText("STWORZONE POZIOMY");
    button_stworzone_poziomy->setFont(QFont("Comic Sans MS"));
    button_stworzone_poziomy->setCursor(Qt::PointingHandCursor);

    button_tworzenie_poziomu->setText("TWORZENIE POZIOMU");
    button_tworzenie_poziomu->setFont(QFont("Comic Sans MS"));
    button_tworzenie_poziomu->setCursor(Qt::PointingHandCursor);

    button_ustawienia->setText("USTAWIENIA");
    button_ustawienia->setFont(QFont("Comic Sans MS"));
    button_ustawienia->setCursor(Qt::PointingHandCursor);

    // wyglad przycisku
    button_kontynuuj->setStyleSheet("font-weight: bold; border-style: outset; border-width: 3px; border-color: red; border-radius: 7px; color: white; background-color:rgb(235,30,30);");
    button_nowa_gra->setStyleSheet("font-weight: bold; border-style: outset; border-width: 3px; border-color: red; border-radius: 7px; color: white; background-color:rgb(235,30,30);");
    button_stworzone_poziomy->setStyleSheet("font-weight: bold; border-style: outset; border-width: 3px; border-color: red; border-radius: 7px; color: white; background-color:rgb(235,30,30);");
    button_tworzenie_poziomu->setStyleSheet("font-weight: bold; border-style: outset; border-width: 3px; border-color: red; border-radius: 7px; color: white; background-color:rgb(235,30,30);");
    button_ustawienia->setStyleSheet("font-weight: bold;border-style: outset; border-width: 3px; border-color: red; border-radius: 7px; color: white; background-color:rgb(235,30,30);");
}

void Menu::dzwiek_menu(){

    // odtwarzanie muzyki menu

    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/sounds/glowny.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
}

void Menu::wydaj_dzwiek_button()
{
    button_dzwiek = new QMediaPlayer();
    button_dzwiek->setMedia(QUrl("qrc:/sounds/sounds/smb_sc.wav"));
    button_dzwiek->play();
}


void Menu::on_button_kontynuuj_clicked()
{
    //music->stop();
    wydaj_dzwiek_button();
}

void Menu::on_button_nowa_gra_clicked()
{
    //music->stop();
    wydaj_dzwiek_button();
    scene->setSceneRect(0, 0, 4750, 900);
    view->setMaximumSize(1400,900);
    view->setFixedSize(1400,900);
    //scene->removeItem(chmurka);
    //rysuj_chmurki_w_tle();
    delete button_nowa_gra;
    delete button_kontynuuj;
    delete button_ustawienia;
    delete button_stworzone_poziomy;
    delete button_tworzenie_poziomu;
    //gra = new Gra(scene);
    //mario = new Mario;
    gra = new Gra(scene, view, music);
}

void Menu::on_button_stworzone_poziomy_clicked()
{
    music->stop();
    wydaj_dzwiek_button();
}

void Menu::on_button_tworzenie_poziomu_clicked()
{
    music->stop();
    wydaj_dzwiek_button();
}

void Menu::on_button_ustawienia_clicked()
{
    music->stop();
    wydaj_dzwiek_button();
}

void Menu::muzyka_stop()
{
    music->stop();
}

/*void Menu::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        mario->idz_w_lewo();
        qDebug()<<"lewy";
    }
    else if(event->key() == Qt::Key_Right)
    {
        mario->idz_w_prawo();
    }
    else if(event->key() == Qt::Key_Space || event->key() == Qt::Key_Up)
    {
        mario->skacz();
    }
    else if(event->key() == Qt::Key_Down)
    {
        mario->kucaj();
    }
}*/


Menu::~Menu()
{
    delete ui;
}
