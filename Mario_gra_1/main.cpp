/**
* \mainpage
* \par Gra Mario
* Program oparty na grze Super Mario Bros z 1985r.
* \author Natalia Karpowicz
* \date 2019.06.10
*/

#include "menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    //w.show();

    return a.exec();
}
