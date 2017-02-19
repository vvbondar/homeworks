#include <QCoreApplication>
#include "myclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyClient c;
    QThread cli_thread;
    c.moveToThread(&cli_thread);
    c.connect(&cli_thread, SIGNAL(started()), &c, SLOT(onThreadStarted()));
    cli_thread.start();

    return a.exec();
}
