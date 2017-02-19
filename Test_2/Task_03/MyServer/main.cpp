#include <QCoreApplication>
#include "myserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyServer s;
    QThread srv_thrd;
    s.moveToThread(&srv_thrd);
    s.connect(&srv_thrd, SIGNAL(started()), &s, SLOT(start()));
    srv_thrd.start();

    return a.exec();
}
