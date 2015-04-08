#include "simplependulum.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimplePendulum w;
    w.show();

    return a.exec();
}
