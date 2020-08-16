#include "server_adapter.h"
#include <QtDebug>

ServerAdapter::ServerAdapter(QObject* parent):
    QObject(parent)
{
    connect(&server, SIGNAL(newConnection()), this, SLOT(connected()));
    if(!server.listen(QHostAddress::Any, 6789))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started!";
    }

}

void ServerAdapter::connected()
{
    activeConnection = server.nextPendingConnection();
    if(!activeConnection){
        return;
    }

    connect(activeConnection, SIGNAL(readyRead()),this,SLOT(readForData()));
    connect(activeConnection, SIGNAL(disconnected()), this, SLOT(discardSocket()));
}

void ServerAdapter::readForData()
{
    if(!activeConnection){
        return;
    }
    QByteArray receivedData = activeConnection->readAll();
    qDebug() << "ServerAdapter:: Received "<<receivedData<<"\n";
    emit newMessage(receivedData);
}

void ServerAdapter::discardSocket()
{
    if(!activeConnection){
        return;
    } else {
        activeConnection->deleteLater();
    }
}

void ServerAdapter::writeChar(QByteArray character)
{
    if(!activeConnection){
        return;
    }
    activeConnection->write(character);
}
