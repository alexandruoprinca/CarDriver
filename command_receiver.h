#pragma once

#include <variant>
#include <QTcpSocket>
#include "movement_direction.h"
#include "engine_status.h"
#include "connection_handler.h"

class CommandReceiver{
public:
    CommandReceiver(ConnectionHandler& connecter):connexion{connecter}{}
    std::variant<MovementDirection,EngineStatus> getCommand();

private:
    ConnectionHandler& connexion;
};

