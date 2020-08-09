#pragma once

#include <variant>
#include <QTcpSocket>
#include "direction.h"
#include "engine_status.h"
#include "connection_handler.h"

class CommandReceiver{
public:
    CommandReceiver(ConnectionHandler& connecter):connexion{connecter}{}
    std::variant<Direction,EngineStatus> getCommand();

private:
    ConnectionHandler& connexion;
};

