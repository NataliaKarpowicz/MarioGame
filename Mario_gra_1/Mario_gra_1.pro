#-------------------------------------------------
#
# Project created by QtCreator 2019-05-10T14:41:08
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mario_gra_1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        menu.cpp \
    obiekt.cpp \
    przeszkoda.cpp \
    mario.cpp \
    wrog.cpp \
    cegla.cpp \
    rura.cpp \
    ustawienia.cpp \
    chmurka.cpp \
    ziemia.cpp \
    postac.cpp \
    wzgorze.cpp \
    ceglagrafika.cpp \
    zlyzolw.cpp \
    chmurkagrafika.cpp \
    stworzonepoziomy.cpp \
    rysunektlo.cpp \
    ruragrafika.cpp \
    przeszkodaznakzapytania.cpp \
    zlygrzybgrafika.cpp \
    zlyzolwgrafika.cpp \
    mariografika.cpp \
    wroggrafika.cpp \
    wzgorzegrafika.cpp \
    rysunektlografika.cpp \
    obiektgrafika.cpp \
    postacgrafika.cpp \
    ziemiagrafika.cpp \
    przeszkodagrafika.cpp \
    przeszkodaznakzapytaniagrafika.cpp \
    zlygrzyb.cpp \
    gra.cpp \
    moneta.cpp \
    zamek.cpp \
    zamekgrafika.cpp \
    grzybek.cpp \
    gwiazda.cpp \
    dozebrania.cpp \
    grzybekgraficzny.cpp \
    gwiazdagraficzna.cpp \
    monetagraficzna.cpp \
    dozebraniagrafika.cpp

HEADERS += \
        menu.h \
    obiekt.h \
    przeszkoda.h \
    mario.h \
    wrog.h \
    cegla.h \
    rura.h \
    ustawienia.h \
    chmurka.h \
    ziemia.h \
    postac.h \
    wzgorze.h \
    ceglagrafika.h \
    zlyzolw.h \
    chmurkagrafika.h \
    stworzonepoziomy.h \
    rysunektlo.h \
    ruragrafika.h \
    przeszkodaznakzapytania.h \
    zlygrzybgrafika.h \
    zlyzolwgrafika.h \
    mariografika.h \
    wroggrafika.h \
    wzgorzegrafika.h \
    rysunektlografika.h \
    obiektgrafika.h \
    postacgrafika.h \
    ziemiagrafika.h \
    przeszkodagrafika.h \
    przeszkodaznakzapytaniagrafika.h \
    zlygrzyb.h \
    gra.h \
    moneta.h \
    zamek.h \
    zamekgrafika.h \
    grzybek.h \
    gwiazda.h \
    dozebrania.h \
    grzybekgraficzny.h \
    gwiazdagraficzna.h \
    monetagraficzna.h \
    dozebraniagrafika.h

FORMS += \
        menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
