#include <QCoreApplication>
#include <wiringPi.h>
#include "server_adapter.h"
#include "command_receiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    wiringPiSetup();

    ServerAdapter server{};
    CommandReceiver commandReceiver{server};




    return a.exec();
}
