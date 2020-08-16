#pragma once

#include <variant>
#include <QTcpSocket>
#include "movement_direction.h"
#include "engine_status.h"
#include "server_adapter.h"

class CommandReceiver : public QObject{

    Q_OBJECT

public:
    explicit CommandReceiver(ServerAdapter& connecter, QObject* parent=0);

signals:
    void newMovementCommand(MovementDirection);
    void newEngineCommand(EngineStatus);

public slots:
    void getCommand(const QByteArray data);

private:
    ServerAdapter& connexion;
};

