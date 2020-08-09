#include <QCoreApplication>
#include <wiringPi.h>
#include "command_receiver.h"
#include "connection_handler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    wiringPiSetup();

    ConnectionHandler connection{};
    CommandReceiver receiver{connection};

    while(1){

    }


    return a.exec();
}
