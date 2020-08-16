#include "command_receiver.h"

using namespace Car::Network;

CommandReceiver::CommandReceiver(ServerAdapter& connection, QObject* parent):
    QObject(parent),
    connexion{connection}
{
     const bool signalConnected = connect(&connexion, SIGNAL(newMessage(QByteArray)), this, SLOT(getCommand(QByteArray)));
     Q_ASSERT(signalConnected);
}

void CommandReceiver::getCommand(const QByteArray data){
    char command = data.at(0);
    qDebug() <<"CommandReceiver::getCommand"<< command << '\n';
    if(command == 'f' || command == 'b' || command == 'l' || command == 'r')
    {
        emit newMovementCommand(Car::Motion::MovementDirection{command});
    }
    else
    {
        emit newEngineCommand(Car::Motion::EngineStatus{command});
    }
}
