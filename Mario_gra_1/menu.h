#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "ui_menu.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtCore>
#include <QtGui>
#include <QPushButton>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QLabel>
#include "chmurkagrafika.h"
#include "ziemiagrafika.h"
#include "wzgorze.h"
#include "ziemia.h"
#include "gra.h"
#include "mario.h"
#include <QKeyEvent>

class Gra;

namespace Ui {
class Menu;
}

/** \brief Klasa Menu
*
* Wyświetla menu, w którym znajdują się 5 przycisków.
* Możliwość wybrania kontynuacji gry, nowej gry, tworzenia nowych poziomów, zobaczenia stworzonych poziomów i ustawień.
*/
class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    /** \brief Dołącza przyciski do sceny i nadaje im wygląd.
    */
    void button_wyglad(QGraphicsView *view);
    /** \brief Odtwarza muzykę.
    */
    void dzwiek_menu();
    /** \brief Ustawia dźwięk dla przycisku.
    */
    void wydaj_dzwiek_button();
    /** \brief Rysuje chmurki.
    */
    void rysuj_chmurki_w_tle();
    /** \brief Zatrzymuje muzykę.
    */
    void muzyka_stop();
    ~Menu();

private slots:
    void on_button_kontynuuj_clicked();
    void on_button_nowa_gra_clicked();
    void on_button_tworzenie_poziomu_clicked();
    void on_button_stworzone_poziomy_clicked();
    void on_button_ustawienia_clicked();

private:
    Ui::Menu *ui;
    /// playlista, wykorzystuje music
    QMediaPlaylist *playlist;
    /// muzyka odtwarzana w kółko
    QMediaPlayer *music;
    /// dźwięk przycisku
    QMediaPlayer *button_dzwiek;
    /// scena
    QGraphicsScene *scene;
    /// widok
    QGraphicsView *view;
    /// przycisk kontynuuj
    QPushButton *button_kontynuuj;
    /// przycisk nowa gra
    QPushButton *button_nowa_gra;
    /// przycisk tworzenie poziomu
    QPushButton *button_tworzenie_poziomu;
    /// przycisk stworzone poziomy
    QPushButton *button_stworzone_poziomy;
    /// przycisk ustawienia
    QPushButton *button_ustawienia;
    /// wskaźnik na klase ChmurkaGrafika
    ChmurkaGrafika *chmurka;
    /// wskaźnik na klase Ziemia
    Ziemia *ziemia;
    /// wskaźnik na klase WzgorzeGrafika
    WzgorzeGrafika *wzgorze;
    /// wskaźnik na klase Gra
    Gra* gra;
    /// wskaźnik na klase Mario
    Mario*mario;
};

#endif // MENU_H
