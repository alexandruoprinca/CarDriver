#pragma once

#include <variant>
#include <QTcpSocket>
#include "movement_direction.h"
#include "engine_status.h"
#include "connection_handler.h"
#include "server_adapter.h"

class CommandReceiver : public QObject{

    Q_OBJECT

public:
    explicit CommandReceiver(ServerAdapter& connecter, QObject* parent=0);
public slots:
    std::variant<MovementDirection,EngineStatus> getCommand(const QByteArray data);

private:
    ServerAdapter& connexion;
};

