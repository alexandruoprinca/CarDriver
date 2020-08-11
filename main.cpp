#include <QCoreApplication>
#include <wiringPi.h>
#include "server_adapter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    wiringPiSetup();

//    ConnectionHandler connection{};
//    CommandReceiver receiver{connection};

//    while(1){

//    }

    ServerAdapter server{};


    return a.exec();
}
