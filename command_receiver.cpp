#include "command_receiver.h"

CommandReceiver::CommandReceiver(ServerAdapter& connection, QObject* parent):
    QObject(parent),
    connexion{connection}
{
     const bool signalConnected = connect(&connexion, SIGNAL(newMessage(QByteArray)), this, SLOT(getCommand(QByteArray)));
     Q_ASSERT(signalConnected);
}
//might want to use a signal instead
std::variant<MovementDirection, EngineStatus> CommandReceiver::getCommand(const QByteArray data){
    qDebug() << "Got here";
    char command = data.at(0);
    qDebug() << command << '\n';
    if(command == 'f' || command == 'b' || command == 'l' || command == 'r'){
        return MovementDirection{command};
    }

    return EngineStatus{command};
}
